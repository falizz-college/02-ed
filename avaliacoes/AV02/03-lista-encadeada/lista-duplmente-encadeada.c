#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
struct no {
    int dado;
    struct no *prox;
};

typedef struct lista Lista;
struct lista {
    No *inicio;
    No *fim;
    int length;
};

No *criar_no(int valor) {
    No *no = (No *)malloc(sizeof(No));
    if (no) {
        no->dado = valor;
        no->prox = NULL;
    }
    return no;
}

Lista *criarLista() {
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->length = 0;
    }
    return lista;
}

void listar(Lista *lista) {
    if (!lista)
        return;
    No *aux = lista->inicio;
    while (aux) {
        printf("(%d)->", aux->dado);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void inserirOrdenado(Lista *lista, int valor) {
    if (!lista)
        return;
    No *novo = criar_no(valor);
    if (!novo)
        return;
    
    // Inserir no início
    if (lista->length == 0 || valor < lista->inicio->dado) {
        novo->prox = lista->inicio;
        lista->inicio = novo;
        if (lista->length == 0)
            lista->fim = novo;
    } else { // Inserir no fim ou entre nós
        No *aux = lista->inicio;
        while (aux->prox && valor > aux->prox->dado)
            aux = aux->prox;
        novo->prox = aux->prox;
        aux->prox = novo;
        if (aux == lista->fim) {
            lista->fim = novo;
        }
    }
    lista->length++;
}

void deletarInicio(Lista *lista) {
    if (!lista || lista->length == 0)
        return;
    No *aux = lista->inicio;
    lista->inicio = lista->inicio->prox;
    if (lista->inicio == NULL) {
        lista->fim = NULL;
    }
    free(aux);
    lista->length--;
}

void deletarFim(Lista *lista) {
    if (!lista || lista->length == 0)
        return;
    No *aux = lista->inicio;
    if (lista->length == 1) {
        lista->inicio = NULL;
        lista->fim = NULL;
        free(aux);
    } else {
        while (aux->prox != lista->fim)
            aux = aux->prox;
        free(lista->fim);
        lista->fim = aux;
        aux->prox = NULL;
    }
    lista->length--;
}

int main(void) {
    Lista *lista = criarLista();
    
    inserirOrdenado(lista, 5);
    inserirOrdenado(lista, 1);
    inserirOrdenado(lista, 3);
    inserirOrdenado(lista, 2);
    inserirOrdenado(lista, 4);
    
    printf("Lista após inserções ordenadas:\n");
    listar(lista);
    
    deletarInicio(lista);
    printf("Lista após deletar o início:\n");
    listar(lista);
    
    deletarFim(lista);
    printf("Lista após deletar o fim:\n");
    listar(lista);
    
    deletarInicio(lista);
    deletarInicio(lista);
    deletarFim(lista);
    
    printf("Lista após deletar todos os elementos:\n");
    listar(lista);
    
    return 0;
}