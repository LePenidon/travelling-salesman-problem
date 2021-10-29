#include "item.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// struct ITEM
struct item_ {
    int cidade_A;
    int cidade_B;
    int distancia;
};

// cria um item
ITEM *item_criar(int cidade_A, int cidade_B, int distancia) {
    ITEM *item;

    item = (ITEM *)malloc(sizeof(ITEM));

    if (item != NULL) {
        item->cidade_A = cidade_A;
        item->cidade_B = cidade_B;
        item->distancia = distancia;
        return (item);
    }
    return (NULL);
}

// apaga um item
bool item_apagar(ITEM **item) {
    if (*item != NULL) {
        free(*item);
        *item = NULL; /*Boa pr�tica!*/
        return (true);
    }
    return (false);
}

// retorna a cidade A de um item
int item_get_cidade_A(ITEM *item) {
    if (item != NULL)
        return (item->cidade_A);
    exit(1);
}

// retorna a cidade B de um item
int item_get_cidade_B(ITEM *item) {
    if (item != NULL)
        return (item->cidade_B);
    exit(1);
}

// retorna a distancia de um item
int item_get_distancia(ITEM *item) {
    if (item != NULL)
        return (item->distancia);
    exit(1);
}

// define os valores de um item
bool item_set_valores(ITEM *item, int cidade_A, int cidade_B, int distancia) {
    if (item != NULL) {
        item->cidade_A = cidade_A;
        item->cidade_B = cidade_B;
        item->distancia = distancia;
        return (true);
    }
    return (false);
}

// imprime um item
void item_imprimir(ITEM *item) {
    if (item != NULL)
        printf("\n-->item: %d %d %d\n", item->cidade_A, item->cidade_B, item->distancia);
}
