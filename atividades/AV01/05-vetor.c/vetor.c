#include <stdio.h>
#include <stdlib.h>

#include "vetor.h"

#define MAX_INT 0x7FFFFFFF

struct vetor {
  int *dados;     // ponteiro para array de inteiros
  int length;   // comprimento
  int limit;  // tamanho máximo
};

Vetor *criarVetor(int limit) {
  Vetor *v = malloc(sizeof(Vetor));
  if(v == NULL) return NULL; // Erro na alocação
  v->dados = malloc(sizeof(int) * limit);
  if(v->dados == NULL) {
    free(v);
    return NULL; // Erro na alocação
  }
  v->length = 0;
  v->limit = limit;
  return v;
}

void liberarVetor(Vetor *v) {
  // equivalente a (v == NULL)
  if (!v) return;
  free(v->dados);
  free(v);
}

void listar(Vetor *v) {
  if (!v){
    printf("Vetor vazio\n");
    return;
  }
  int i;
  for(i = 0; i < v->length; i++) {
    printf("%d ", v->dados[i]);
  }
  printf("\n");
}

void zerar(Vetor *v) {
  v->length = 0;
}

void inserir(Vetor *v, int dado){
  if (!v){
    return;
  }
  if (v->length < v->limit){
    v->dados[v->length] = dado;
    v->length++;
  } else {
    printf("Vetor cheio\n");
    return;
  }
}

void atualizarUm(Vetor *v, int dadoAntigo, int dadoNovo){
  if (!v){
    return;
  }
  int i;  
  for (i = 0; i < v->length; i++){
      if (v->dados[i] == dadoAntigo){
        v->dados[i] = dadoNovo;
        break;
    }
  }
}

void atualizarTodos(Vetor *v, int dadoAntigo, int dadoNovo){
  if (!v){
    return;
  }
  int i;  
  for (i = 0; i < v->length; i++){
      if (v->dados[i] == dadoAntigo){
        v->dados[i] = dadoNovo;
    }
  }
}

void atualizarIndice(Vetor *v, int indice, int dadoNovo){
  if (!v){
    return;
  }
  if (indice >= 0 && indice < v->length){
    v->dados[indice] = dadoNovo;
  } else {
    printf("Indice inválido\n");
  }
}

int buscarElemento(Vetor *v, int elemento){
  if (!v){
    printf("Vetor vazio\n");
    return -1;
  }
  int i;
  for (i = 0; i < v->length; i++){
    if (elemento == v->dados[i]){
    return i;
    }
  }
  printf("Elemento não encontrado\n");
  return -1;
}

int obterElemento(Vetor *v, int indice){
  if (!v){
    printf("Vetor vazio\n");
    return MAX_INT;
  }
  if (indice >= 0 && indice < v->length){
    return v->dados[indice];
  } else {
    printf("Indice inválido\n");
    return MAX_INT;
  }
}

void deletarElemento(Vetor *v, int elemento){
  int indice = buscarElemento(v, elemento);	// ja testa a existência do vetor
  if(indice == -1){
    printf("Elemento nao encontrado\n");
    return;
  }
  int i;
  for(i = indice; i < v->length-1; i++){
    v->dados[i] = v->dados[i+1];
  }
  v->length--;
}

void deletarIndice(Vetor *v, int indice){
  if(!v){
    return;
  }
  if (indice >= 0 && indice < v->length){
    int i;
    for(i = indice; i < v->length-1; i++){
      v->dados[i] = v->dados[i+1];
    }
    v->length--;
  } else {
    printf("Indice inválido\n");
    return;
  }
}
