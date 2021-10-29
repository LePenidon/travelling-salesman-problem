#include "lista_info.h"

// no da lista_info
struct no_info_ {
    IT_INFO *item;
    NOI *proximo;
};

// struct da lista
struct lista_info_ {
    NOI *inicio;
    NOI *fim;
    int tamanho;
};

// cria uma LISTA_INFO
LISTA_INFO *lista_info_criar() {
    LISTA_INFO *lista = (LISTA_INFO *)malloc(sizeof(LISTA_INFO));

    if (lista != NULL) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }

    return (lista);
}

// informa o tamanho da lista
int lista_info_tamanho(LISTA_INFO *lista) {
    return ((lista != NULL) ? lista->tamanho : ERRO);
}

// verifica se a lista esta vazia
boolean lista_info_vazia(LISTA_INFO *lista) {
    if ((lista != NULL) && lista->inicio == NULL)
        return (TRUE);
    return (FALSE);
}

// verifica se a lista esta cheia
boolean lista_info_cheia(LISTA_INFO *lista) {
    return FALSE;
}

// insere um item no fim da fila
boolean lista_info_inserir_fim(LISTA_INFO *lista, IT_INFO *item) {
    if ((!lista_info_cheia(lista)) && (lista != NULL)) {
        NOI *pnovo = (NOI *)malloc(sizeof(NOI));
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
    } else
        return (FALSE);
}

// busca uma posicao na lista
IT_INFO *lista_info_busca(LISTA_INFO *lista, int posicao) {
    NOI *p;
    int count = 0;

    if (lista != NULL) {
        p = lista->inicio;
        while (p != NULL) {
            if (count == posicao) {
                return p->item;
            }

            p = p->proximo;
            count++;
        }
    }

    return (NULL);
}

// imprime a lista
void lista_info_imprimir(LISTA_INFO *lista) {
    NOI *no_aux;

    if ((lista == NULL) || (lista_info_vazia(lista))) {
        printf("Lista invalida!\n");
        return;
    }

    no_aux = lista->inicio;

    while (no_aux->proximo != NULL) {
        printf("\n%d %d %f", it_info_get_cidade_A(no_aux->item), it_info_get_cidade_B(no_aux->item), it_info_get_distancia(no_aux->item));

        no_aux = no_aux->proximo;
    }

    printf("\n%d %d %f", it_info_get_cidade_A(no_aux->item), it_info_get_cidade_B(no_aux->item), it_info_get_distancia(no_aux->item));

    printf("\n");
}

// esvazia a lista
void lista_info_esvazia(NOI *ptr) {
    if (ptr != NULL) {
        lista_info_esvazia(ptr->proximo);
        it_info_apagar(&ptr->item);
    }

    free(ptr);
    ptr = NULL;

    return;
}

// apaga a lista, com a funcao esvazia_lista
void lista_info_apagar(LISTA_INFO **ptr) {
    lista_info_esvazia((*ptr)->inicio);
    free(*ptr);
    *ptr = NULL;

    return;
}
