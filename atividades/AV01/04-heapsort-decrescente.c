#include <stdio.h>

/* NA HEAPSORT O VALOR DOS FILHOS DEVE SER SEMPRE MENOR 
   DO QUE O VALOR DO PAI */

int filho_esquerdo(int i) {
    return 2 * i + 1;
}

int filho_direito(int i) {
    return 2 * i + 2;
}

int pai(int i) {
    return (i - 1) / 2;
}

// AJUSTAR UM ÚNICO NÓ
void ajustar_heap(int n, int arr[n], int i) {
    int maior = i;
    int esq, dir, temp;

    while (maior < n) {
        esq = 2 * i + 1;
        dir = 2 * i + 2;

        if (esq < n && arr[esq] < arr[maior]) {
            maior = esq;
        }

        if (dir < n && arr[dir] < arr[maior]) {
            maior = dir;
        }

        if (maior != i) {
            temp = arr[i];
            arr[i] = arr[maior];
            arr[maior] = temp;
            i = maior;
        } else {
            break;
        }
    }
}

// CONSTRUIR HEAP
void construir_heap(int n, int arr[n]) {
    int i;
    for (i = (n / 2) - 1; i >= 0; i--) {
        ajustar_heap(n, arr, i);
    }
}

// HEAP SORT
void heap_sort(int n, int arr[n]) {
    int i, temp;
    construir_heap(n, arr);

    for (i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        ajustar_heap(i, arr, 0);
    }
}

void listar(int n, int arr[n]) {
    int i;
    for (i = 0; i < n; i++) {
        printf(" [%d] ", arr[i]);
    }
    printf("\n");
}

int main() {
    //          0 1 2 3 4 5 6 7
    int vet[] = {8, 6, 7, 4, 5, 3, 2, 1};
    int n = sizeof(vet) / sizeof(int);

    listar(n, vet);
    heap_sort(n, vet);
    listar(n, vet);

    return 0;
}