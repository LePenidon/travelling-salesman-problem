#include "functions.h"

void ler_arquivo(MATRIZ* m, char* arquivo) {
    // declaracao das variaveis
    FILE* file = fopen(arquivo, "r");
    LISTA* lista = lista_criar();
    ITEM* item;
    int aux, i, j, valores[3];

    // le a primeira linha do arquivo
    fscanf(file, "%d", &aux);
    m->numero_elementos = aux;

    // aloca a matriz
    m->elementos = malloc(m->numero_elementos * sizeof(int*));
    for (i = 0; i < m->numero_elementos; i++) {
        m->elementos[i] = malloc(m->numero_elementos * sizeof(int));
    }
    i = 0;

    // le todas as informacoes do arquivo
    while (!feof(file)) {
        fscanf(file, "%d", &aux);
        valores[i] = aux;

        // cria um item e insere na lista
        if (i == 2) {
            item = item_criar(valores[0], valores[1], valores[2]);
            lista_inserir_fim(lista, item);

            i = 0;
            continue;
        }

        i++;
    }

    // atribui 0 aos elementos da matriz na diagonal, 999 ao resto
    for (i = 0; i < m->numero_elementos; i++) {
        for (j = 0; j < m->numero_elementos; j++) {
            if (i != j) {
                m->elementos[i][j] = 999;
            } else {
                m->elementos[i][j] = 0;
            }
        }
    }

    // transforma a lista em uma matriz
    for (i = 0; i < lista_tamanho(lista); i++) {
        item = lista_busca(lista, i);

        m->elementos[item_get_cidade_A(item) - 1][item_get_cidade_B(item) - 1] = item_get_distancia(item);
        m->elementos[item_get_cidade_B(item) - 1][item_get_cidade_A(item) - 1] = item_get_distancia(item);
    }

    lista_apagar(&lista);
    fclose(file);
}

int calcular_custo(MATRIZ m, int* caminho) {
    // declaracao das variaveis
    int custo = 0, i;

    // percorre o caminho
    for (i = 0; i < m.numero_elementos; i++) {
        // soma os custos de cada cidade a outra
        custo = custo + m.elementos[caminho[i]][caminho[i + 1]];
    }

    return custo;
}

void construir_caminho(MATRIZ m, int* caminho, int cidade_origem) {
    // declaracao das variaveis
    int* inseridos = malloc(m.numero_elementos * sizeof(int));
    int i, j, valor_referencia, vizinho_selecionado;

    // atribui 0 aos elementos do vetor
    for (i = 0; i < m.numero_elementos; i++) {
        inseridos[i] = FALSE;
    }

    // valor da cidade inicial
    caminho[0] = cidade_origem;
    inseridos[cidade_origem] = TRUE;

    // percorre a matriz
    for (i = 0; i < m.numero_elementos; i++) {
        // salva a referencia
        valor_referencia = INT_MAX;
        vizinho_selecionado = 0;

        for (j = 0; j < m.numero_elementos; j++) {
            // verifica se nao foi inserido e se a referencia eh maior
            if (!inseridos[j] && valor_referencia > m.elementos[i][j]) {
                vizinho_selecionado = j;
                valor_referencia = m.elementos[i][j];
            }
        }
        // adiciona a cidade no caminho
        caminho[i + 1] = vizinho_selecionado;
        inseridos[vizinho_selecionado] = TRUE;
    }

    // cidade final
    caminho[m.numero_elementos] = cidade_origem;

    free(inseridos);
}

void realizar_movimento_troca(MATRIZ m, int* solucao_inicial, int* melhor_vizinho) {
    // declaracao das variaveis
    int* solucao_tmp = malloc((m.numero_elementos + 1) * sizeof(int));
    int custo_referencia = calcular_custo(m, solucao_inicial);
    int i, j, tmp, custo_solucao_tmp;

    // copia a solucao inicial para o melhor vizinho
    copiar_caminho(m, solucao_inicial, melhor_vizinho);

    // percorre a matriz
    for (i = 1; i < m.numero_elementos; i++) {
        // copia a solucao inicial para a solucao temporaria
        copiar_caminho(m, solucao_inicial, solucao_tmp);

        for (j = i + 1; j < m.numero_elementos; j++) {
            // troca os valores entre os vizinhos
            tmp = solucao_tmp[i];
            solucao_tmp[i] = solucao_tmp[j];
            solucao_tmp[j] = tmp;

            // calcula o valor do caminho com as trocas
            custo_solucao_tmp = calcular_custo(m, solucao_tmp);

            // verifica se o caminho com as trocas eh mais barato que a solucao anterior
            if (custo_solucao_tmp < custo_referencia) {
                custo_referencia = custo_solucao_tmp;
                copiar_caminho(m, solucao_tmp, melhor_vizinho);
            }
        }
    }
}

void copiar_caminho(MATRIZ m, int* origem, int* destino) {
    // declaracao da variavel
    int i;

    // percorre os vetores e copia cada casa
    for (i = 0; i <= m.numero_elementos; i++) {
        destino[i] = origem[i];
    }
}

void imprimir_caminho(int n, int* caminho) {
    // declaracao da variavel
    int i;

    // percorre o vetor e printa cada casa
    for (i = 0; i < n - 1; i++) {
        printf("%d - ", caminho[i] + 1);
    }
    printf("%d \n", caminho[i] + 1);
}

void imprimir_matriz(MATRIZ m) {
    // declaracao das variaveis
    int i = 0, j;

    printf("\nMatriz dos valores das distancias:\n\n");

    // pecorre a matriz e imprime cada casa
    for (i = 0; i < m.numero_elementos; i++) {
        for (j = 0; j < m.numero_elementos; j++) {
            printf("%3d ", m.elementos[i][j]);
        }

        printf("\n");
    }
    printf("\n");
}
