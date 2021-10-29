#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#include "../TAD_lista_simplesmente_encadeada/lista.h"

// definicao do tipo MATRIZ
typedef struct matriz_ {
    int numero_elementos;
    int** elementos;
} MATRIZ;

// funcao que le o arquivo e transforma na matriz
void ler_arquivo(MATRIZ* m, char* arquivo);

// funcao que calcula o valor de um caminho dado
int calcular_custo(MATRIZ m, int* caminho);

// funcao que constroi um caminho
void construir_caminho(MATRIZ m, int* caminho, int cidade_origem);

// funcao que, se possivel, melhora um caminho dado
void realizar_movimento_troca(MATRIZ m, int* solucao_inicial, int* melhor_vizinho);

// funcao que copia um caminho para outro
void copiar_caminho(MATRIZ m, int* origem, int* destino);

// funcao que imprime um caminho
void imprimir_caminho(int n, int* caminho);

// funcao que imprime a matriz
void imprimir_matriz(MATRIZ m);

#endif
