#ifndef LISTA_INFO_H
#define LISTA_INFO_H

#include "./it_info/it_info.h"

/*no da lista tipo info*/
typedef struct no_info_ NOI;

/*lista linear simplesmente encadeada nao ordenada*/
typedef struct lista_info_ LISTA_INFO;

/*cria uma lista tipo info*/
LISTA_INFO *lista_info_criar();

/*retorna o tamanho de uma lista tipo info*/
int lista_info_tamanho(LISTA_INFO *lista);

/*verifica se uma lista info esta vazia*/
boolean lista_info_vazia(LISTA_INFO *lista);

/*verifica se nao ha mais espaco para usar*/
boolean lista_info_cheia(LISTA_INFO *lista);

/*insere um novo no ao fim de uma lista info*/
boolean lista_info_inserir_fim(LISTA_INFO *lista, IT_INFO *item);

/*recupera um item info dada uma posicao de uma lista tipo info*/
IT_INFO *lista_info_busca(LISTA_INFO *lista, int posicao);

/*imprime uma lista tipo info*/
void lista_info_imprimir(LISTA_INFO *lista);

/*esvazia uma lista tipo info*/
void lista_info_esvazia(NOI *ptr);

/*apaga uma lista tipo info*/
void lista_info_apagar(LISTA_INFO **ptr);

#endif
