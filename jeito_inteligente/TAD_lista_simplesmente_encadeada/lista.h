#ifndef LISTADINAMICA_H
#define LISTADINAMICA_H
#define TRUE 1 /*define valor booleano – não existe na linguagem C*/
#define FALSE 0
#define boolean int  //define um tipo booleano
#define inicial 0
#define ERRO -32000

#include <stdbool.h>

#include "./TAD_item/item.h"

// define o tipo LISTA
typedef struct lista_ LISTA;

// cria uma lista
LISTA *lista_criar(void);

// insere um item ao fim da lista
boolean lista_inserir_fim(LISTA *lista, ITEM *i);

// apaga a lista
void lista_apagar(LISTA **ptr);

// busca por uma posicao na lista
ITEM *lista_busca(LISTA *lista, int index);

// retorna o tamanho da lista
int lista_tamanho(LISTA *lista);

// verifica se a lista esta vazia
boolean lista_vazia(LISTA *lista);

// verifica se a lista esta cheia
boolean lista_cheia(LISTA *lista);

// imprime a lista
void lista_imprimir(LISTA *lista);

#endif
