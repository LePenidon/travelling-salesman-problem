#include <time.h>

#include "./functions/functions.h"
#define CIDADE_ORIGEM 1

int main(int argc, char **argv) {
    // declaracao das variaveis
    clock_t tempo_inicio = clock();
    clock_t tempo_fim;
    int cidades;
    double tempo_gasto;

    /*declaracao das structs que usaremos*/
    int **guia;
    int *final;
    MOV *mov;
    LISTA_INFO *infos = lista_info_criar();

    /*leitura automatica dos dados*/
    cidades = ler_arquivo(infos, "./casos_testes/input_12.txt");

    /*criacao das estrutras*/
    mov = mov_criar(cidades);

    guia = guia_criar(cidades, CIDADE_ORIGEM);

    final = final_criar(cidades);

    /*usa a funcao para arrumar os dados scaneados em na lista info*/
    procura_caminhos(infos, mov, cidades);

    /*depois de arrumado, nao precisamos mais da lista info, portanto, liberamos a memoria dela!*/
    lista_info_apagar(&infos);

    /*chamamos a funcao para resolver o problema*/
    resolve(mov, guia, final, cidades);

    /*depois de resolvido, libera a meomria alocada para as estruturas*/
    mov_apagar(mov, cidades);

    apaga_aux(guia, final);

    // calcula o tempo gasto de execucao do programa e imprime
    tempo_fim = clock();
    tempo_gasto = (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %lf\n", tempo_gasto);

    /*e fin! :)*/
    return EXIT_SUCCESS;
}
