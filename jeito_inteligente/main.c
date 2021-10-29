#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "TAD_lista_simplesmente_encadeada/lista.h"
#include "functions/functions.h"

// define a cidade de origem do problema
#define CIDADE_ORIGEM 1

int main(int argc, char* argv[]) {
    // declaracao das variaveis
    clock_t tempo_inicio = clock();
    clock_t tempo_fim;
    MATRIZ m;
    int *solucao_inicial, *melhor_vizinho;
    int i, custo_solucao_melhor_vizinho;
    double tempo_gasto;

    // le o arquivo com as informações e imprime a matriz
    ler_arquivo(&m, "./casos_testes/teste.txt");
    imprimir_matriz(m);

    // cria uma solucao inicial
    solucao_inicial = malloc((m.numero_elementos + 1) * sizeof(int));
    construir_caminho(m, solucao_inicial, CIDADE_ORIGEM - 1);

    // melhora a solucao inicial uma vez
    melhor_vizinho = malloc((m.numero_elementos + 1) * sizeof(int));
    realizar_movimento_troca(m, solucao_inicial, melhor_vizinho);

    // melhora a solucao inicial m.numero_elementos vezes
    for (i = 0; i < m.numero_elementos; i++) {
        realizar_movimento_troca(m, melhor_vizinho, melhor_vizinho);
    }

    // imprime o caminho
    printf("Caminho a ser percorrido: \n");
    imprimir_caminho(m.numero_elementos + 1, melhor_vizinho);

    // imprime o custo do caminho
    custo_solucao_melhor_vizinho = calcular_custo(m, melhor_vizinho);
    printf("\nCusto do caminho: %d\n", custo_solucao_melhor_vizinho);

    // calcula o tempo gasto de execucao do programa e imprime
    tempo_fim = clock();
    tempo_gasto = (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %lf\n", tempo_gasto);
}
