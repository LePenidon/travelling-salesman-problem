#include "lista.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no_ NO;

// struct do no da lista
struct no_ {
    ITEM *item;
    NO *proximo;
};

// struct da lista
struct lista_ {
    NO *inicio;
    NO *fim;
    int tamanho;
};

/*Cria	logicamente	uma	lista,	inicialmente	vazia*/
LISTA *lista_criar(void) {
    LISTA *lista = (LISTA *)malloc(sizeof(LISTA));
    if (lista != NULL) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }
    return (lista);
}

/*Insere um novo nó no fim da lista. PARA LISTAS NÃO ORDENADAS*/
boolean lista_inserir_fim(LISTA *lista, ITEM *item) {
    if ((!lista_cheia(lista)) && (lista != NULL)) {
        NO *pnovo = (NO *)malloc(sizeof(NO));
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

// esvazia a lista
void lista_esvazia(NO *ptr) {
    if (ptr != NULL) {
        lista_esvazia(ptr->proximo);
        item_apagar(&ptr->item);
    }
    free(ptr);
    ptr = NULL;

    return;
}

// apaga a lista com a funcao lista_esvazia
void lista_apagar(LISTA **ptr) {
    lista_esvazia((*ptr)->inicio);
    free(*ptr);
    *ptr = NULL;

    return;
}

// busca por uma posicao na lista
ITEM *lista_busca(LISTA *lista, int index) {
    NO *p;
    int count = 0;
    if (lista != NULL) {
        p = lista->inicio;
        while (p != NULL) {
            if (count == index)
                return (p->item);
            count++;
            p = p->proximo;
        }
    }
    return (NULL);
}

// retorna o tamanho da lista
int lista_tamanho(LISTA *lista) {
    return ((lista != NULL) ? lista->tamanho : ERRO);
}

// verifica se a lista esta vazia
boolean lista_vazia(LISTA *lista) {
    if ((lista != NULL) && lista->inicio == NULL)
        return (TRUE);
    return (FALSE);
}

// verifica se a lista esta cheia
boolean lista_cheia(LISTA *lista) {
    return FALSE;
}

// imprime a lista
void lista_imprimir(LISTA *lista) {
    NO *no_aux;

    if ((lista == NULL) || (lista_vazia(lista))) {
        printf("Lista invalida!\n");
        return;
    }

    no_aux = lista->inicio;

    while (no_aux->proximo != NULL) {
        printf("%d %d %d\n", item_get_cidade_A(no_aux->item), item_get_cidade_B(no_aux->item), item_get_distancia(no_aux->item));

        no_aux = no_aux->proximo;
    }

    printf("%d %d %d\n", item_get_cidade_A(no_aux->item), item_get_cidade_B(no_aux->item), item_get_distancia(no_aux->item));

    printf("\n");
}
