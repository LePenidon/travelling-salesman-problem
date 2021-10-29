#ifndef LISTA_MOV_H
#define LISTA_MOV_H

#include "./it_mov/it_mov.h"

/*no da lista tipo mov*/
typedef struct no_mov_ NOM;

/*lista linear simplesmente encadeada nao ordenada*/
typedef struct lista_mov_ LISTA_MOV;

/*struct que guarda as listas de caminhos possiveis a partir de uma cidade*/
typedef struct guarda_lista_ MOV;

/*cria uma lista tipo mov*/
LISTA_MOV *lista_mov_criar();

/*retorna o tamanho de uma lista tipo mov*/
int lista_mov_tamanho(LISTA_MOV *lista);

/*verifica se uma lista tipo mov esta vazia*/
boolean lista_mov_vazia(LISTA_MOV *lista);

/*verifica se nao ha mais espaco para usar*/
boolean lista_mov_cheia(LISTA_MOV *lista);

/*insere um novo no ao fim de uma lista mov*/
boolean lista_mov_inserir_fim(LISTA_MOV *lista, IT_MOV *i);

/*recupera um item mov dada uma posicao de uma lista tipo mov*/
IT_MOV *lista_mov_busca_posicao(LISTA_MOV *lista, int index);

/*recupera um item mov dada uma cidade de uma lista tipo mov*/
IT_MOV *lista_mov_busca_cidade(LISTA_MOV *lista, int cidade);

/*imprime uma lista tipo mov*/
boolean lista_mov_imprimir(LISTA_MOV *lista);

/*esvazia uma lista tipo mov*/
void lista_mov_esvazia(NOM *ptr);

/*apaga uma lista tipo mov*/
void lista_mov_apagar(LISTA_MOV **ptr);

/*cria uma struct mov*/
MOV *mov_criar(int cidades);

/*retorna uma lista guardada em uma struct mov na posicao chave*/
LISTA_MOV *mov_get_lista(MOV *mov, int chave);

/*retorna o int cidade de uma struct mov em uma posicao chave*/
int mov_get_cidade(MOV *mov, int chave);

/*imprime uma struct mov*/
boolean mov_imprimir(MOV *mov, int cidades);

void mov_apagar(MOV *mov, int cidades);

#endif
