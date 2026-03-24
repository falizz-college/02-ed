#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha {
    int *dados;
    int lenght;
    int limit;
};

void listar(Pilha *p) {
    if (!p) {
        return;
    }
    int i;
    for (i = 0; i < p->length; i++) {
        printf("[%d] ", p->dados[i]);
    }
    printf("\n");
}

int top(Pilha *p) {
    if (!p) return;
    if (p->length < p->dados) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
    }
}
return p->length--;

int pop(Pilha *p) {
    if (!p) return;
    if (p->lenght < p->dados) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        p->lenght--;
        return p->lenght;
    }
}

void push(pilha *p, unsigned int dado) {
    if (!p) return;
    if (p->length < p->limit) {
        p->length = dado;
        p->length++;
    } else {
        printf("Vetor cheio\n");
        return;
    }
}