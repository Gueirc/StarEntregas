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
            if(numero >= distancias[i]){  
                if(!estaContido(i, expressao, numero)){
                    expressao[numero] = i;
                    menorCaminho = nav_vertices(grafo, distancias, expressao, menorCaminho, ++numero);

                }

            }

        }


    }
    return menorCaminho;

}
