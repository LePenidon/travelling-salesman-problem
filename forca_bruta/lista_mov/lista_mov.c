#include "lista_mov.h"

// no da lista_mov
struct no_mov_ {
    IT_MOV *item;
    NOM *proximo;
};

// struct da lista_mov
struct lista_mov_ {
    NOM *inicio;
    NOM *fim;
    int tamanho;
};

/*strut criada para guardas as listas mov de cada casa, juntamente com a casa a que se refere*/
struct guarda_lista_ {
    int cidade;
    LISTA_MOV *adj;
};

/*funcoes basicas de uma lista linear simplesmente encadeada nao ordenada*/
LISTA_MOV *lista_mov_criar() {
    LISTA_MOV *lista = (LISTA_MOV *)malloc(sizeof(LISTA_MOV));

    if (lista != NULL) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }

    return (lista);
}

// retorna o tamanho da lista
int lista_mov_tamanho(LISTA_MOV *lista) {
    return ((lista != NULL) ? lista->tamanho : ERRO);
}

// verifica se a lista esta vazia
boolean lista_mov_vazia(LISTA_MOV *lista) {
    if ((lista != NULL) && lista->inicio == NULL)
        return (TRUE);
    return (FALSE);
}

// verifica se a lista esta cheia
boolean lista_mov_cheia(LISTA_MOV *lista) {
    // se der, coloca a condicao
    return (FALSE);
}

// insere o item no fim da fila
boolean lista_mov_inserir_fim(LISTA_MOV *lista, IT_MOV *item) {
    if ((!lista_mov_cheia(lista)) && (lista != NULL)) {
        NOM *pnovo = (NOM *)malloc(sizeof(NOM));
        if (lista->inicio == NULL) {
            pnovo->item = item;
            lista->inicio = pnovo;
            pnovo->proximo = NULL;
        } else {
            lista->fim->proximo = pnovo;
            pnovo->item = item;
            pnovo->proximo = NULL;
        }

        lista->fim = pnovo;
        lista->tamanho++;

        return (TRUE);
    } else {
        return (FALSE);
    }
}

// busca em uma posicao na lista
IT_MOV *lista_mov_busca_posicao(LISTA_MOV *lista, int index) {
    NOM *p;
    int count = 0;

    if ((lista != NULL) && (index < lista_mov_tamanho(lista))) {
        p = lista->inicio;
        while (count != index) {
            p = p->proximo;
            count++;
        }
        return (p->item);
    }
    return (NULL);
}

// busca por uma cidade na lista
IT_MOV *lista_mov_busca_cidade(LISTA_MOV *lista, int cidade) {
    NOM *p;
    int count = 0;

    if (lista != NULL) {
        p = lista->inicio;
        while ((it_mov_get_cidade(p->item) != cidade)) {
            p = p->proximo;
            count++;

            if (count == lista_mov_tamanho(lista)) {
                return (NULL);
            }
        }

        return (p->item);
    }

    return (NULL);
}

// imprime a lista
boolean lista_mov_imprimir(LISTA_MOV *lista) {
    NOM *no_aux;

    if ((lista == NULL) || (lista_mov_vazia(lista))) {
        printf("Lista invalida!\n");
        return (FALSE);
    }

    no_aux = lista->inicio;

    while (no_aux->proximo != NULL) {
        printf("%d %f\n", it_mov_get_cidade(no_aux->item), it_mov_get_distancia(no_aux->item));

        no_aux = no_aux->proximo;
    }
    printf("%d %f\n", it_mov_get_cidade(no_aux->item), it_mov_get_distancia(no_aux->item));

    printf("\n");

    return (TRUE);
}

// esvazia a lista
void lista_mov_esvazia(NOM *ptr) {
    if (ptr != NULL) {
        lista_mov_esvazia(ptr->proximo);
        it_mov_apagar(&ptr->item);
    }
    free(ptr);
    ptr = NULL;

    return;
}

// apaga a lista, com a funcao lista_mov_esvazia
void lista_mov_apagar(LISTA_MOV **ptr) {
    lista_mov_esvazia((*ptr)->inicio);
    free(*ptr);
    *ptr = NULL;

    return;
}

// cria o MOV
MOV *mov_criar(int cidades) {
    int i;

    MOV *mov = malloc(cidades * sizeof(MOV));

    for (i = 0; i < cidades; i++) {
        mov[i].cidade = (i + 1);
        mov[i].adj = lista_mov_criar();
    }

    // caso o ponteiro tenha valor "NULL", a alocacao deu errado e o programa de encerra
    if (mov == NULL) {
        printf("socorro! malloc retornou null!\n");
        exit(EXIT_FAILURE);
    }

    // retorna o ponteiro
    return (mov);
}

// pega a lista MOV, dada uma chave
LISTA_MOV *mov_get_lista(MOV *mov, int chave) {
    if (mov[chave].adj != NULL) {
        return (mov[chave].adj);
    }
    return (NULL);
}

// retorna a cidade de um MOV, dada uma chave
int mov_get_cidade(MOV *mov, int chave) {
    if (mov != NULL) {
        return (mov[chave].cidade);
    } else {
        return (-1);
    }
}

// imprime o MOV
boolean mov_imprimir(MOV *mov, int cidades) {
    int i;

    if (mov != NULL) {
        for (i = 0; i < cidades; i++) {
            printf("\ncidade: %d \n", mov_get_cidade(mov, i));
            // printf("tamanho: %d \n", lista_mov_tamanho(mov_get_lista(mov, i)));
            lista_mov_imprimir(mov_get_lista(mov, i));
        }

        return (TRUE);
    }

    return (FALSE);
}

// apaga o MOV
void mov_apagar(MOV *mov, int cidades) {
    int i;
    LISTA_MOV *aux;

    if (mov != NULL) {
        for (i = 0; i < cidades; i++) {
            aux = mov_get_lista(mov, i);
            lista_mov_apagar(&aux);
        }
    }

    free(mov);

    return;
}
