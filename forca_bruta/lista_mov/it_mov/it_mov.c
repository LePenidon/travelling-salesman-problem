#include "it_mov.h"

// struct do it_mov
struct item_lista_mov_ {
    int cidade;
    float distancia;
};

// cria um it_mov
IT_MOV *it_mov_criar() {
    IT_MOV *item = (IT_MOV *)malloc(sizeof(IT_MOV));

    if (item != NULL) {
        item->cidade = 0;
        item->distancia = 0;
        return (item);
    }

    return (NULL);
}

// define os valores do item
boolean it_mov_set(IT_MOV *item, int cidade, float distancia) {
    if (item != NULL) {
        item->cidade = cidade;
        item->distancia = distancia;

        return (TRUE);
    }

    return (FALSE);
}

// retorna a cidade de um item
int it_mov_get_cidade(IT_MOV *item) {
    if (item != NULL) {
        return (item->cidade);
    }

    return (FALSE);
}

// retorna a distancia de um item
float it_mov_get_distancia(IT_MOV *item) {
    if (item != NULL) {
        return (item->distancia);
    }

    return (FALSE);
}

// imprime um item
boolean it_mov_imprimir(IT_MOV *item) {
    if (item != NULL) {
        printf("%d, %f\n", it_mov_get_cidade(item), it_mov_get_distancia(item));
        return (TRUE);
    }

    return (FALSE);
}

// apaga um item
boolean it_mov_apagar(IT_MOV **item) {
    if (*item != NULL) {
        free(*item);
        *item = NULL;
        return (TRUE);
    }

    return (FALSE);
}
