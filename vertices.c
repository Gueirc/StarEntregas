#include<stlib.h>
#include"staren.h"
int * vertices (int * distancias, int * expressao, int * menorCaminho, int menorCaminhoValor, int numero, plan ** grafo){
    int soma;
    if(numero >= qtdPlanetas){
        soma = 0;
        int z;
        for(z = 0; z + 1 < qtdPlanetas; z += 1){
            soma += dijkstra_pesototal(grafo, expressao[z], djistra[z+1]); // Suponho q no lugar dessse djistra seja na verdade expressao
        }

        soma += dijkstra_pesototal(grafo, expressao[qtdPlanetas-1], expressao[0]); // em vez de 0 ser expressao[0] pois nao necessariamente começamos no vertice de numero 0
        if(menorCaminho > soma || menorCaminho == NULL){
            menorCaminho = expressao;
            menorCaminhoValor = soma;
        }
    }else{
        int i;
        for(i = 0; i < qtdPlanetas; i += 1){
            if(numero >= distancias[i]){  // Como assim distancias[i]
                if(!estacontido(i, expressao, numero)){
                    expressao[numero] = i;
                    menorCaminho = vertices(distancias, expressao, menorCaminho, menorCaminhoValor, ++numero, grafo);

                }

            }

        }


    }
    return menorCaminho;

}
