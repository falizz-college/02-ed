#include <stdio.h>
#include <stdlib.h>

typedef struct arvore Arvore;
struct arvore{
    char dado;
    Arvore *esq;
    Arvore *dir;
};

Arvore *criar_arvore(char dado) {
    Arvore *arvore = malloc(sizeof(Arvore));
    if(arvore){
        arvore->esq = NULL;
        arvore->dir = NULL;
        arvore->dado = dado;
    }
    return arvore;
}

void exibir_nos_folha(Arvore *a){
    if(!a) return;
    if(!a->esq && !a->dir){ // nós da direita e da esquerda apontam para NULL
        printf("%c", a->dado);
        return;
    }
    exibir_nos_folha(a->esq);
    exibir_nos_folha(a->dir);
}

void exibir_nos_internos(Arvore *a){
    if(!a) return;
    if(!a->esq && !a->dir){ // a é nó folha
        return;
    }
    printf("%c", a->dado);
    exibir_nos_internos(a->esq);
    exibir_nos_internos(a->dir);
}

int contar_nos_folhas(Arvore *a){
    if(!a) return;
    if(!a->esq && !a->dir) { // a é nó folha
        return 1;
    }
    return contar_nos_folhas(a->dir) + contar_nos_folhas(a->esq);
}

int contar_nos_internos(Arvore *a){
    if(!a) return;
    if(!a->esq && !a->dir){ // a é nó folha
        return 0;
    }
    // a é nó interno
    return contar_nos_internos(a->esq) + contar_nos_internos(a->dir) + 1
}

void exibir_ordenado(Arvore *a){
    if(!a) return;
    exibir_ordenado(a->esq);
    printf("(%c)", a->dado);
    exibir_ordenado(a->dir);
}

void obter_altura_arv_bin_completa(int nos){
    if(nos <= 0) return 0;
    return (int)log2(nos);
}

int main(void){

    Arvore *raiz = criar_arvore('F');
    raiz->esq = criar_arvore('D');
        raiz->esq->esq = criar_arvore('A');
        raiz->esq->dir = criar_arvore('E');
    raiz->dir = criar_arvore('J');
        raiz->dir->esq = criar_arvore('H');
        raiz->dir->dir = criar_arvore('L');
  exibir_nos_folha(raiz); printf("\n");
  exibir_nos_internos(raiz); printf("\n");
  printf("Total de nós folha: %d\n", contar_nos_folha(raiz));
  printf("Total de nós internos: %d\n", contar_nos_internos(raiz));
  exibir_ordenado(raiz); printf("\n");
  printf("altura(4 nós): %d\n", obter_altura_arv_bin_completa(4)); // 2
  printf("altura(7 nós): %d\n", obter_altura_arv_bin_completa(7)); // 2
  printf("altura(8 nós): %d\n", obter_altura_arv_bin_completa(8)); // 3
    /*
                (  'F'  )
                /       \
            ('D')       ('J')
            /   \       /   \
        ('A')   ('E')('H')  ('L')
    */

    return 0;
}