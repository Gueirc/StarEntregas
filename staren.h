#ifndef STAREN_H
#define STAREN_H

#define QPLANETAS 4  // Variável global com quantidade de planetas

typedef struct planeta{
    int gfIndice; // Indice do grafo
    int iTempo; // Tempo (i de quantidade de tempo) que demora pra chegar
    int tGuerIni; // Hora (t de horário) que o planeta fica bloqueado,
                  // -1 para nao ter bloqueio
    int iDura; // Duração do boqueio, se tGuerIni for -1, ignora-se
    struct planeta * prox; // próximo
}plan;

// Retorna um vertice de indice gfIndice, que tem um bloqueio começado às tGuerIni horas 
// (-1 para nao ter bloqueio)
// e esse bloqueio dura iDura horas
plan * grafo_inicia(int gfIndice, int tGuerIni, int iDura);

// Descontinuado, nao use.
void grafo_insere(plan * aInserir, int gfIndice, int iTempo, int tGuerIni, int iDura);

// Libera um vertice do grafo
void grafo_libera(plan * grafo);

// Faz uma conexao nao direcionada entre os vertices de indice prim e sec,
// Tendo uma distancia entre eles de iTempo
void grafo_insere_duplo(plan ** grafo, int prim, int sec, int iTempo);

// Faz o algoritimo dijkstra a partir do vertice gfInicio
// Os vetores previamente alocados com o tamanho de vertices
// retornarão com o custo de tempo para chegar a partir de 
// gfInicio para todos os outros vertices do grafo, sendo cada posicao
// do vetor respectivo ao indice do vertice; alem de retornar
// o vetor gfAnterior com cada posicao referente ao 
// indice do vertice anterior para se chegar no indice respectivo
void grafo_dijkstra(plan ** grafo, int gfInicio, int * iCusto, int * gfAnterior);

// Retorna o tempo total para se chegar de origem a destino
int dijkstra_pesototal(plan ** grafo, int origem, int destino);

// Retorna o proximo vertice a ir para chegar no destino
int dijkstra_proximo(plan ** grafo, int origem, int destino);

// Retorna um vetor de inteiros com a distancia em pulos da origem
// a todos os outros pontos, em ordem
int * dijkstra_distancias(plan ** grafo, int origem);

// Descontinuado
void nav_viajePara (plan ** grafo, int gfAtual, int * tempo, int gfDestino);

// Testa todas as possíveis formas de percorrer todo o grafo e retorna 
// por meio de menorCaminho[0] o vetor com a ordem a ser seguida,
// e em menorCaminho[1][0] o tempo total desse caminho
void nav_vertices (plan ** grafo, int * distancias, int * expressao, int ** menorCaminho, int numero);

// Printa no stdout a sequencia de vertices a serem seguidos a partir do 
// menorCaminho provido pelo nav_vertices 
void printaCaminhoInteiro(int ** menorCaminho, plan ** grafo);

#endif
