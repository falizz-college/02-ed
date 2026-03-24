#include <stdio.h>

int BuscaSequencial(int tamanho, int vet[tamanho], int valor) {
    int i;
    int contador = 1;

    for (i = 0; i < tamanho; i++) {
        if (valor != vet[i]) {
            contador++;
        } else {
            return contador;
        }
    }
    return -1; // Caso não encontre
}

int BuscaSequencialv2(int tamanho, int vet[tamanho], int valor) {
    int *i = vet;
    int *j = vet + tamanho - 1;
    int contador;

    for (contador = 1; contador < tamanho; contador++) {
        if (valor == *i || valor == *j) {
            return contador;
        } else {
            i++;
            j--;
        }
    }
    return -1; // Caso não encontre
}

int main(void) {
    int vet[] = {1, 5, 7, 8, 9, 11, 12, 15, 13, 21, 32, 35, 42};
    int tamanho = sizeof(vet) / sizeof(int);
    int valor;

    printf("\n\nValor a ser encontrado: ");
    scanf("%i", &valor);

    int achei = BuscaSequencial(tamanho, vet, valor);
    printf("\n\nForam feitas %i buscas (v1)", achei);

    int achei2 = BuscaSequencialv2(tamanho, vet, valor);
    printf("\n\nForam feitas %i buscas (v2)", achei2);

    return 0;
}