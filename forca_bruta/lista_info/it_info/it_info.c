#include "it_info.h"

// struct do item
struct item_lista_info_ {
    int cidade_A;
    int cidade_B;
    float distancia;
};

// cria um item
IT_INFO *it_info_criar() {
    IT_INFO *item = (IT_INFO *)malloc(sizeof(IT_INFO));

    if (item != NULL) {
        item->cidade_A = 0;
        item->cidade_B = 0;
        item->distancia = 0;
        return (item);
    }

    return (NULL);
}

// define os valores do item
boolean it_info_set(IT_INFO *item, int cidade_A, int cidade_B, float distancia) {
    if (item != NULL) {
        item->cidade_A = cidade_A;
        item->cidade_B = cidade_B;
        item->distancia = distancia;

        return (TRUE);
    }

    return (FALSE);
}

// retorna a cidade A do item
int it_info_get_cidade_A(IT_INFO *item) {
    if (item != NULL)
        return (item->cidade_A);

    return (FALSE);
}

// retorna a cidade B do item
int it_info_get_cidade_B(IT_INFO *item) {
    if (item != NULL)
        return (item->cidade_B);

    return (FALSE);
}

// retorna a distancia do item
float it_info_get_distancia(IT_INFO *item) {
    if (item != NULL)
        return (item->distancia);

    return (FALSE);
}

// apaga o item
boolean it_info_apagar(IT_INFO **item) {
    if (*item != NULL) {
        free(*item);
        *item = NULL;
        return (TRUE);
    }
    return (FALSE);
}
