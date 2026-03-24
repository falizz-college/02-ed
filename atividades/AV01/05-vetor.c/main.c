#include "vetor.h"

int main() {
  Vetor *v = criarVetor(4);

  inserir(v,1);
  listar(v);
  printf("\n");
  
  inserir(v,2);
  listar(v);
  printf("\n");
  
  inserir(v,3);
  listar(v);
  printf("\n");
  
  inserir(v,4);
  listar(v);
  printf("\n");
  
  inserir(v, 5);
  printf("\n");
  listar(v);
  printf("\n");
  

  atualizarUm(v, 3, 1);
  listar(v);
  printf("\n");
  
  atualizarUm(v, 5, 1);
  listar(v);
  printf("\n");

  atualizarTodos(v, 1, 0);
  listar(v);
  printf("\n");
  
  atualizarTodos(v, 9, 1);
  listar(v);
  printf("\n");

  atualizarIndice(v, 2, 5);
  listar(v);
  printf("\n");
  
  atualizarIndice(v, 3, 1);
  listar(v);
  printf("\n");

  int indice = buscarElemento(v, 5);
  printf("Indice do elemento 5: %d\n", indice);
  listar(v);
  printf("\n");
  
  indice = buscarElemento(v, 7);
  printf("Indice do elemento 7: %d\n", indice);
  listar(v);
  printf("\n");


  int elemento = obterElemento(v, 0);
  printf("Elemento no indice 0: %d\n", elemento);
  listar(v);
  printf("\n");
  
  elemento = obterElemento(v, 6);
  printf("Elemento no indice 6: %d\n", elemento);
  listar(v);
  printf("\n");

  deletarElemento(v, 1);
  listar(v);
  printf("\n");
  
  deletarElemento(v, 7);
  listar(v);
  printf("\n");

  deletarIndice(v, 0);
  listar(v);
  printf("\n");
  
  deletarIndice(v, 3);
  listar(v);
  printf("\n");

  liberarVetor(v);
  return 0;
}
