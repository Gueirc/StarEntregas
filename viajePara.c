#include<stdio.h>
#include"staren.h"

void viajePara (int * posicao, int situacaoPlanetas, plan ** planetas, int * tempo, int destino){
	int proximoPasso = dijkstra_proximo(planetas, posicao, destino);
	if(situacaoPlanetas[proximoPasso] == 0){
        // Somar distancia da pos atual com o proximopasso em relaçao a atual

        for 
		tempo += plantas[proximoPasso];

	}else{
		tempo++;
	}

	situacaoPlanetas=atualizeSituacao(situacaoPlanetas);

	if(posicao != destino){
		viajePara(posicao, situacaoPlanetas, planetas, tempo, destino);
	}

}
