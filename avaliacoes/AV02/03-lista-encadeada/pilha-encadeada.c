#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
struct no {
    unsigned int dado;
    struct no *prox;
};

typedef struct pilha Pilha;
struct pilha {
    No *topo;
    unsigned int length;
};

No *criar_no(int dado) {
    No *no = (No *)malloc(sizeof(No));
    if (no) {
        no->dado = dado;
        no->prox = NULL;
    }
    return no;
}

Pilha *criarPilha() {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    if (pilha) {
        pilha->topo = NULL;
        pilha->length = 0;
    }
    return pilha;
}

int topo(Pilha *pilha) {
    if (!pilha || pilha->length == 0) return -1;
    return pilha->topo->dado;
}

void empilha(Pilha *pilha, unsigned int dado) {
    if (!pilha) return;
    No *novo_no = criar_no(dado);
    if (!novo_no) return;
    
    novo_no->prox = pilha->topo;
    pilha->topo = novo_no;
    pilha->length++;
}

int pop(Pilha *pilha) {
    if (!pilha || pilha->length == 0) return -1;
    
    No *temp = pilha->topo;
    pilha->topo = pilha->topo->prox;
    unsigned int dado = temp->dado;
    free(temp);
    pilha->length--;
    
    return dado;
}

void listar(Pilha *pilha) {
    if (!pilha || pilha->length == 0) {
        printf("Pilha vazia.\n");
        return;
    }
    
    No *aux = pilha->topo;
    while (aux) {
        printf("(%d)->", aux->dado);
        aux = aux->prox;
    }
    printf("NULL\n");
}

int main(void) {
    Pilha *pilha = criarPilha();
    
    empilha(pilha, 10);
    empilha(pilha, 20);
    empilha(pilha, 30);
    
    printf("Pilha após empilhar 10, 20 e 30:\n");
    listar(pilha);
    
    printf("Topo da pilha: %d\n", topo(pilha));
    
    printf("Desempilhando: %d\n", pop(pilha));
    printf("Desempilhando: %d\n", pop(pilha));
    
    printf("Pilha após desempilhar dois elementos:\n");
    listar(pilha);
    
    printf("Desempilhando: %d\n", pop(pilha));
    
    printf("Pilha após desempilhar todos os elementos:\n");
    listar(pilha);
    
    free(pilha);
    return 0;
}