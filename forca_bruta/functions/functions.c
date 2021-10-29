#include "functions.h"  // chamada do tad

boolean procura_caminhos(LISTA_INFO* input, MOV* mov, int cidades) {
    int i, j;

    IT_INFO* info_aux;
    IT_MOV* mov_aux;

    for (i = 0; i < lista_info_tamanho(input); i++) {
        info_aux = lista_info_busca(input, i);  // para cada item da lista info, verificamos

        for (j = 0; j < cidades; j++) {
            /*procura-se o local do mov correspondente as cidades do input e salvamos a cidade ligada 
            juntamente com a distancia entre elas*/
            if (mov_get_cidade(mov, j) == it_info_get_cidade_A(info_aux)) {
                mov_aux = it_mov_criar();
                it_mov_set(mov_aux, it_info_get_cidade_B(info_aux), it_info_get_distancia(info_aux));
                lista_mov_inserir_fim(mov_get_lista(mov, j), mov_aux);
            }

            if (mov_get_cidade(mov, j) == it_info_get_cidade_B(info_aux)) {
                mov_aux = it_mov_criar();
                it_mov_set(mov_aux, it_info_get_cidade_A(info_aux), it_info_get_distancia(info_aux));
                lista_mov_inserir_fim(mov_get_lista(mov, j), mov_aux);
            }
        }
    }

    return (TRUE);
}

int** guia_criar(int cidades, int cidade_origem) {
    int i;

    int** guia = malloc(3 * sizeof(int*));

    for (i = 0; i < 3; i++) {
        guia[i] = malloc((cidades + 1) * sizeof(int));
    }

    /*a estrutura guia contem cidades colunas e tres linhas de informacao*/
    guia[0][0] = cidade_origem;  // a linha zero guarda a cidade
    guia[1][0] = 0;              // a linha 1 guarda o numero de cidades que podem ser colocadas neste lugar
    guia[2][0] = 0;              // e a linha dois guarda a distancia da cidade anterior ate essa

    /*note que aqui a linha 1 e 2 foram zeradas ja que representam a cidade inicial, que eh imutavel*/

    return (guia);
}

int* final_criar(int cidades) {
    int i;

    int* final = malloc((cidades + 2) * sizeof(int));

    for (i = 0; i < cidades + 1; i++) {
        final[i] = 0;
    }

    /*o vetor final eh bem intuitivo: cada lugar do vetor guarda a cidade do caminho*/
    final[cidades + 1] = 0;  // mas foi adicionada mais uma casa para que a distancia total fosse guardada.

    return (final);
}

boolean pre_condicoes(IT_MOV* aux, int** guia, int cidades, int lugar) {
    int i;

    if (lugar != cidades) {  // caso essa condicao nao seja sobre a ultima cidade
        for (i = 0; i < lugar; i++) {
            if (guia[0][i] == it_mov_get_cidade(aux)) {  // verificamos a cidade ja apareceu antes
                return (FALSE);                          // e se tiver aparecido, nao eh valido
            }
        }
    } else {                                         // mas se estivermos falando da ultima cidade
        if (guia[0][0] != it_mov_get_cidade(aux)) {  // verifica-se a cidade inicial e a final diferentes
            return (FALSE);                          //se fim, nao cumpre a condicao e retorna-se falso
        }
    }

    return (TRUE);
}

int completa(MOV* mov, int** guia, int cidades, int k) {
    int i;
    IT_MOV* mov_aux;

    /*para a funcao completa, reseta-se o valor de possibilidades a cada casa atingida*/
    for (i = k; i < cidades + 1; i++) {
        guia[1][i] = lista_mov_tamanho(mov_get_lista(mov, guia[0][i - 1] - 1)) - 1;

        while (guia[1][i] > (-1)) {  // enquanto houver movimento possivel
            mov_aux = lista_mov_busca_posicao(mov_get_lista(mov, guia[0][i - 1] - 1), guia[1][i]);
            /*obs: note que para a obtencao da lista diminui-se duas vezes o valor de i
            guia[0][i-1] corresponde a cidade anterior
            como mov eh um vetor, sua contagem comeca do zero, 
            portanto o local da struct mov referente a cidade 3 corresponde a mov[2], por exemplo*/
            if (pre_condicoes(mov_aux, guia, cidades, i)) {  // caso o movimento seja valido
                guia[0][i] = it_mov_get_cidade(mov_aux);     // adiciona-se a informacao na guia
                guia[1][i]--;                                // e diminui-se a quantidade de possibilidades
                guia[2][i] = it_mov_get_distancia(mov_aux);

                break;  // e sai do while
            } else {
                guia[1][i]--;  // caso nao seja, retira-se uma possibilidade e tenta de novo

                if (guia[1][i] == (-1)) {  // caso tenha chegado aqui, significa que nao ha mais possiblidades para essa casa
                    return (i - 1);        // retorna-se o lugar anterior para uqe possamos tentar na funcao volta
                }
            }
        }
    }

    /*o return -99 foi escolhido arbitrariamente, de forma que o lugar retornado nunca fosse o mesmo valor da funcao terminada com sucesso*/
    return (-99);
}

int volta(MOV* mov, int** guia, int cidades, int lugar) {
    int i;
    IT_MOV* mov_aux;

    /*a logica do volta eh bem parecida com o do completa, entretanto aqui as possibilidades NAO sao resetadas*/
    for (i = lugar; i > 0; i--) {  // e, ao inves de avancar no caminho, procura-se um lugar anterior que possua outra possibilidade de movimento
        while (guia[1][i] > (-1)) {
            mov_aux = lista_mov_busca_posicao(mov_get_lista(mov, guia[0][i - 1] - 1), guia[1][i]);

            if ((pre_condicoes(mov_aux, guia, cidades, i))) {  // caso o movimento seja valido
                guia[0][i] = it_mov_get_cidade(mov_aux);       // adiciona as informacoes
                guia[1][i]--;                                  // e diminui as possibilidades
                guia[2][i] = it_mov_get_distancia(mov_aux);

                if (i < cidades) {  // caso ainda nao seja o fim, voltamos a casa encontrada para que seja completada pela funcao completa
                    return (i + 1);
                } else {
                    return (-99);  // e se for o fim, retornamos o -99 que representa um caminho encontrado com sucesso
                }
            } else {
                guia[1][i]--;  // e se o movimento nao for valido, tenta-se com o proximo movimento possivel
            }
        }
    }

    return (-99);
}

boolean pos_condicoes(int** guia, int* final, int cidades) {
    int i;
    int distancia = 0;

    /*caso tenha entrado no pos, significa que o caminho esta certo e foi concluido com sucesso
portanto calculamos o custo dele gaurdado na linha 2 da guia e comparamos com a previamente armazenada*/
    for (i = 1; i < cidades + 1; i++) {
        distancia = distancia + guia[2][i];
    }

    if (final[cidades + 1] > distancia || final[cidades + 1] == 0) {  // caso ela seja menor ou caso a distancia do final seja zero (ou seja, nao ha um caminho colocado no final ainda)
        final[cidades + 1] = distancia;                               // guarda-se as informacoes no final

        for (i = 0; i < cidades + 1; i++) {
            final[i] = guia[0][i];
        }
    }

    return (TRUE);
}

boolean verificador(int** guia, int cidades) {
    int i;

    for (i = 1; i < cidades; i++) {
        if (guia[1][i] > (-1)) {  // verifica se ha alguma casa intermediaria com possibilidade
            return (TRUE);        // se sim, retorna verdade para continuar o processo
        }
    }

    return (FALSE);
}

void printa_final(int* final, int cidades) {
    int i;

    if (final[cidades + 1] > 0) {
        printf("O caminho de menor custo encontrado foi: ");
        for (i = 0; i < cidades; i++) {
            printf("%d - ", final[i]);
        }

        printf("%d\n", final[i]);
        printf("Distancia: %d\n", final[cidades + 1]);
    } else {
        printf("Nao existe caminho final. \n\n");
    }

    return;
}

void resolve(MOV* mov, int** guia, int* final, int cidades) {
    int j = 1;
    int p, q;

    /*aqui, apenas chama-se as funcoes para a resolucao
    comecamos com o completa*/
    p = completa(mov, guia, cidades, j);

    while (p != (-99)) {
        q = volta(mov, guia, cidades, p);
        if (q == (-99)) {
            break;
        }

        p = completa(mov, guia, cidades, q);
    }

    pos_condicoes(guia, final, cidades);

    while (verificador(guia, cidades)) {
        j = cidades - 1;
        /*e aqui recomecamos o processo com o volta, ja que nao queremos resetar as possibilidades num primeiro momento*/
        q = volta(mov, guia, cidades, j);

        while (q != (-99)) {
            p = completa(mov, guia, cidades, q);

            if (p == (-99)) {
                break;
            }

            q = volta(mov, guia, cidades, p);
        }

        pos_condicoes(guia, final, cidades);
    }

    /*quando sair do while, significa que passou por todas as possibilidades e portanto, a melhor escolha esta armazenada no vetor final!*/
    printa_final(final, cidades);

    return;
}

int ler_arquivo(LISTA_INFO* input, char* arquivo) {
    // declaracao das variaveis
    FILE* file = fopen(arquivo, "r");
    IT_INFO* item;
    int aux_int, cidades, i = 0, valores[2];
    float aux_float, distancia;

    // le a primeira linha do arquivo
    fscanf(file, "%d", &aux_int);
    cidades = aux_int;

    // le todas as informacoes do arquivo
    while (!feof(file)) {
        // cria um item e insere na lista
        if (i == 2) {
            fscanf(file, "%f", &aux_float);
            distancia = aux_float;

            item = it_info_criar();
            it_info_set(item, valores[0], valores[1], distancia);
            lista_info_inserir_fim(input, item);

            i = 0;
            continue;
        } else {
            fscanf(file, "%d", &aux_int);

            valores[i] = aux_int;

            i++;
        }
    }

    fclose(file);

    return cidades;
}

void apaga_aux(int** guia, int* final) {
    int i;

    if (final != NULL) {
        free(final);
    }

    if (guia != NULL) {
        for (i = 0; i < 3; i++) {
            free(guia[i]);
        }

        free(guia);
    }

    return;
}
