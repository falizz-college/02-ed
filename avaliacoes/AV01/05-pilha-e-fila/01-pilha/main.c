#include <stdio.h>
#include "pilha.h"

int main(void) {
    int p[6] = {1, 2, 3, 4, 5};

    listar(p);
    top(p);
    pop(p);
    listar(p);
    pop(p);
    listar(p);

    push(p, 6);
    push(p, 7);
    listar(p);

    pop(p);
    pop(p);
    pop(p);
    pop(p);
    listar(p);

    top(p);
    push(p, 1);
    listar(p);

    return 0;
}