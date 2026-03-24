#include <stdio.h>
#include "fila.h"

int main(void){

    int f[6] = {1, 2, 3, 4, 5};

    listar(f);
    enfileira(f, 6);
    enfileira(f, 7);

    listar(f);
    desenfileira(f);

    listar(f);
    desenfileira(f);

    listar(f);
    desenfileira(f);

    listar(f);
    desenfileira(f);

    listar(f);
    desenfileira(f);

    listar(f);
    desenfileira(f);

    listar(f);
    desenfileira(f);

    return 0;
}