#ifndef ITEM_H
#define ITEM_H

#define TRUE 1 /*define valor booleano � n�o existe na linguagem C*/
#define FALSE 0
#define boolean int /*define um tipo booleano*/
#define ERRO -32000

#include <stdbool.h>

// define o tipo ITEM
typedef struct item_ ITEM;

// cria um item
ITEM *item_criar(int cidade_A, int cidade_B, int distancia);

// apaga um item
bool item_apagar(ITEM **item);

// imprime um item
void item_imprimir(ITEM *item);

// retorna a cidade A de um item
int item_get_cidade_A(ITEM *item);

// retorna a cidade B de um item
int item_get_cidade_B(ITEM *item);

// retorna a distancia de um item
int item_get_distancia(ITEM *item);

// define os valores de um item
bool item_set_valores(ITEM *item, int cidade_A, int cidade_B, int distancia);

#endif
