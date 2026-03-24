#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila {
    int *dados;
    int lenght;
    int limit;
};

void listar(fila *f) {
    if (!f) {
        return;
    }
    int i;
    for (i = 0; i < f->length; i++) {
        printf("[%d] ", f->dados[i]);
    }
    printf("\n");
}

void enfileira(Fila *f, unsigned int dado) {
    if (!f) return;
    if (f->length < f->limit) {
        f->length = dado;
        f->length++;
    } else {
        printf("Fila cheia\n");
        return;
    }
}

int desenfileira(Fila *f) {
    if (!f) return;
    if (f->lenght == f->dados[0]) {
        printf("Fila vazia\n");
        return -1;
    } else {
        int primeiro = v->dados[0];
        int i;
        for (i = 0; i < v->length - 1; i++) {
            v->dados[i] = v->dados[i + 1];
        }
        v->length--;
        return primeiro;
    }
}