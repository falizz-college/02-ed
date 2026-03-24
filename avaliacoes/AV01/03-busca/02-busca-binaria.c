#include <stdio.h>

int BuscaBinaria(int tamanho, int vet[tamanho], int valor) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;
    int divisoes = 1;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2; // divisão de inteiros já arredonda abaixo

        // valor == vet[meio]
        if (valor == vet[meio]) {
            return divisoes;
        }

        // valor != vet[meio]
        if (valor < vet[meio]) {
            fim = meio - 1;
            divisoes++;
        } else { // valor > vet[meio]
            inicio = meio + 1;
            divisoes++;
        }
    }
    return -1;
}

int main(void) {
    int vet[] = {1, 5, 7, 8, 9, 11, 12, 15, 13, 21, 32, 35, 42};
    int tamanho = sizeof(vet) / sizeof(int);
    int valor;

    printf("\n\nValor a ser encontrado: ");
    scanf("%i", &valor);

    int divisoes = BuscaBinaria(tamanho, vet, valor);

    if (divisoes != -1) {
        printf("\n\nForam feitas %i divisoes", divisoes);
    } else {
        printf("\n\nValor nao encontrado no vetor.");
    }

    return 0;
}