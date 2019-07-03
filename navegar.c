#include<stdlib.h>
#include"staren.h"

static int estaContido(int procurado, int *vetor, int ateOndeProcurar){
    int i;
	for(i = 0; i < ateOndeProcurar; i += 1){
		if(vetor[i] == procurado){
			return 1;
		}

	}
	return 0;

}


void nav_viajePara (plan ** grafo, int gfAtual, int * tempo, int gfDestino){
	int proximoPasso = dijkstra_proximo(grafo, gfAtual, gfDestino);
	if(grafo[proximoPasso] == 0){
        // Somar distancia da pos atual com o proximopasso em relaçao a atual
        plan * aux = grafo[gfAtual];
        for (; aux->gfIndice != proximoPasso; aux = aux->prox); // Executa ate achar

        tempo += aux->iTempo; // Depois de achar incrementa o tempo
        gfAtual = proximoPasso;
    }else{
        tempo++;
    }

    //situacaografo=atualizeSituacao(situacaoPlanetas);

    if(gfAtual != gfDestino){
        nav_viajePara(grafo, gfAtual, tempo, gfDestino);
    }

}

int ** nav_vertices (plan ** grafo, int * distancias, int * expressao, int ** menorCaminho, int numero){
    // pelo que eu entendi numero eh a quantidade de planetas ja passados por
	// Menor caminho precisa ser um ponteiro duplo pra poder passar o valor do menor caminho e o menor caminho
	// pra recursiva, o menorCaminho[0] eh como se fosse o menorCaminho antigo,
	// o menorCaminho[1][0] eh onde ta o menorCaminhoValor
    int soma;
    if(numero >= QPLANETAS){
        soma = 0;
        int z;
        for(z = 0; z + 1 < QPLANETAS; z += 1){
            soma += dijkstra_pesototal(grafo, expressao[z], expressao[z+1]); 
        }

        soma += dijkstra_pesototal(grafo, expressao[QPLANETAS-1], expressao[0]); 
        if(menorCaminho[1][0] > soma || menorCaminho[0] == NULL){
            menorCaminho[0] = expressao;
            menorCaminho[1][0] = soma;
        }
    }else{
        int i;
        
        for(i = 0; i < QPLANETAS; i += 1){
		// Eh esses o for q n funciona, não sabendo o que ficar em distancias,
		// coloquei tudo em zero, o codigo passa direto e adiciona sequencialmente
		// um valor, o proximo inteiro, na expressao em cada recursiva chamada, no final
		// todas as recursivas estao no final do loop e o unico caminho calculado eh o primeiro
		// : 1 2 3 4 5 6 7 8 9 10 11 12 13
            if(numero >= distancias[i]){  // Como assim distancias[i]
                if(!estaContido(i, expressao, numero)){
                    expressao[numero] = i;
                    menorCaminho = nav_vertices(grafo, distancias, expressao, menorCaminho, ++numero);

                }

            }

        }


    }
    return menorCaminho;

}
