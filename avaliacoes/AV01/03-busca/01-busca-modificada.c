void troca(int tamanho, int vet[tamanho], int valor_busca, int novo_valor) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2; // divisão de inteiros já arredonda abaixo

        // valor == vet[meio]
        if (valor_busca == vet[meio]) {
            vet[meio] = novo_valor;
        }

        // valor != vet[meio]
        if (valor_busca < vet[meio]) {
            fim = meio - 1;
        } else { // valor > vet[meio]
            inicio = meio + 1;
        }
    }
}

void listar(int vet[], int tamanho) {
    int i;
    printf("\n\n\n");

    // printando os indices
    printf("indice [ ");
    for (i = 0; i < tamanho; i++) {
        printf(" %i ", i);
    }
    printf(" ]\n");

    // printando o vetor
    printf("vetor { ");
    for (i = 0; i < tamanho; i++) {
        printf(" %i ", vet[i]);
    }
    printf(" }\n\n");
}

int main(void) {
    int vet[] = {1, 5, 7, 8, 2, 4};
    int tamanho = sizeof(vet) / sizeof(int);
    int valor_busca;
    int novo_valor;

    listar(vet, tamanho);

    printf("\n\nValor a ser alterado: ");
    scanf("%i", &valor_busca);

    printf("\nNovo valor: ");
    scanf("%i", &novo_valor);

    troca(tamanho, vet, valor_busca, novo_valor);
    listar(vet, tamanho);

    return 0;
}