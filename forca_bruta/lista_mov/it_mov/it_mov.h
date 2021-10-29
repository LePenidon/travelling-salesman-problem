#ifndef IT_MOV_H
#define IT_MOV_H

#define boolean int
#define ERRO -32000
#define FALSE 0
#define TRUE 1

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct item_lista_mov_ IT_MOV;

/*cria um item do tipo mov*/
IT_MOV *it_mov_criar();

/*atribui valores a um item do tipo mov*/
boolean it_mov_set(IT_MOV *item, int cidade, float distancia);

/*retorna a cidade guardada em um item mov*/
int it_mov_get_cidade(IT_MOV *item);

/*retorna a distancia ate a cidade guardada em um item mov*/
float it_mov_get_distancia(IT_MOV *item);

/*imprime um item do tipo mov*/
boolean it_mov_imprimir(IT_MOV *item);

/*apaga um item tipo mov*/
boolean it_mov_apagar(IT_MOV **item);

#endif
