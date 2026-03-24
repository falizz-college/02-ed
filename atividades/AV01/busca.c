#include <stdio.h>
int BuscaSequencial (int tamanho, int vet[tamanho], int valor){
  int i;
  for (i = 0; i < vet[tamanho]; i++){
    if (valor == vet[i]){
      return i;
    }
  }
  return -1;
}

int BuscaSequencialv2 (int tamanho, int vet[tamanho], int valor){
  int i;
  for (i = tamanho-1; i >= 0; i--){
    if (valor == vet[i]){
      return i;
    }
  }
  return -1;
}

int BuscaBinaria(int tamanho, int vet[tamanho], int valor){
  int inicio = 0;
  int fim = tamanho-1;
  int meio;
  while(inicio <= fim){
    meio = (inicio + fim)/2; // divisão de inteiros já arredonda abaixo
    // valor == vet[meio]
    if (valor == vet[meio]){
      return meio;
    }
    // valor != vet[meio]
    if (valor < vet[meio]){
      fim = meio-1;
    } else { // valor > vet[meio]
      inicio = meio+1;

    }
  }
  return -1;
}

int BuscaBinariav2(int tamanho, int vet[tamanho], int valor){
  int ini = 0;
  int fim = tamanho-1;
  int meio;
  while(ini <= fim){
      meio = (ini + fim)/2; // divisão de inteiros já arredonda abaixo
      // valor == vet[meio]
      if (valor == vet[meio]){
        return meio;
      }
      // valor != vet[meio]
      if (valor < vet[meio]){
        fim = meio+1;
      } else { // valor > vet[meio]
        ini = meio-1;

      }
    }
    return -1;
  }

int main(void) {
  
  int vet[] = {1, 5, 7, 8, 2, 4};
  int tamanho = sizeof(vet)/sizeof(int);
  int i;
  printf("vetor { ");
  for (i = 0; i < tamanho; i++){
  	printf(" %i ", vet[i]);
  }
  printf(" }\n\n");
  printf("o tamanho de vet: %d\n\n", tamanho);
  
  
  // BUSCA SEQUENCIAL
  
  int valor = 4;
  int indice = BuscaSequencial(tamanho, vet, valor);
  printf("Busca Sequencial \n");
  printf("o valor buscado e: %d\n", valor);
  printf("o indice do valor buscado: %d\n\n\n", BuscaSequencial(tamanho, vet, valor)+1);
  
  
  // BUSCA SEQUENCIAL COMÇANDO DO FINAL
  
  valor = 5;
  int indice2 = BuscaSequencialv2(tamanho, vet, valor);
  printf("Busca Sequencial partindo do final \n");
  printf("o valor buscado e: %d\n", valor);
  printf("o indice do valor buscado: %d\n\n\n", BuscaSequencialv2(tamanho, vet, valor)+1);
  
  
  // BUSCA BINARIA
  
  int vet2[] = {1, 2, 3, 4, 5, 6};
  printf("vetor { ");
  for (i = 0; i < tamanho; i++){
  	printf(" %i ", vet2[i]);
  }
  printf(" }\n\n");
  int tamanho2 = sizeof(vet2)/sizeof(int);
  
  printf("o tamanho de vet: %d\n\n", tamanho2);
  valor = 4;
  int indice3 = BuscaBinaria(tamanho, vet2, valor);
  printf("Busca Binaria \n");
  printf("o valor buscado e: %d\n", valor);
  printf("o indice do valor buscado: %d\n\n\n", BuscaBinaria(tamanho, vet2, valor)+1);
  
  
  // BUSCA BINARIA COM VETOR DECRESCENTE
  
  int vet3[] = {6, 5, 4, 3, 2, 1};
  printf("vetor { ");
  for (i = 0; i < tamanho; i++){
  	printf(" %i ", vet3[i]);
  }
  printf(" }\n\n");
  int tamanho3 = sizeof(vet3)/sizeof(int);
  
  printf("o tamanho de vet: %d\n\n", tamanho3);
  valor = 4;
  int indice4 = BuscaBinaria(tamanho, vet3, valor);
  printf("Busca Binaria \n");
  printf("o valor buscado e: %d\n", valor);
  printf("o indice do valor buscado: %d\n\n\n", BuscaBinaria(tamanho, vet3, valor)+1);

  return 0;
}
