#ifndef IT_INFO_H
#define IT_INFO_H

#define boolean int
#define ERRO -32000
#define FALSE 0
#define TRUE 1

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct item_lista_info_ IT_INFO;

/*cria um item tipo info*/
IT_INFO *it_info_criar();

/*insere valores em um item info*/
boolean it_info_set(IT_INFO *item, int cidade_A, int cidade_B, float distancia);

/*retorna a cidade A guardada em um item tipo info*/
int it_info_get_cidade_A(IT_INFO *item);

/*retorna a cidade B guardada em um item tipo info*/
int it_info_get_cidade_B(IT_INFO *item);

/*retorna a distancia entre as cidades guardadas em um item tipo info*/
float it_info_get_distancia(IT_INFO *item);

/*apaga um item tipo input*/
boolean it_info_apagar(IT_INFO **item);

#endif
