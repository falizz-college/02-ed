#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;
} No;

No *criar_no(int dado) {
    No *novo_no = malloc(sizeof(No));

    if (novo_no) {
        novo_no->dado = dado;
        novo_no->prox = NULL;
    }
    return novo_no;
}

void listarIt(No *inicio) {
    No *aux = inicio;
    while (aux) { // aux != NULL
        printf("(%d)->", aux->dado);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void listarRec(No *no) {
    if (!no) // no == NULL // Critério de parada
        printf("NULL\n");
    else { // no != NULL // Passo recursivo
        printf("(%d)->", no->dado);
        listarRec(no->prox);
    }
}

void inserir_inicio(No **inicio, int dado) {
    if (*inicio == NULL) { // No == NULL
        *inicio = criar_no(dado);
        return;
    }
    // No != NULL / *inicio obtém para onde o nó está apontando
    No *novo_inicio = criar_no(dado);
    novo_inicio->prox = *inicio;
    *inicio = novo_inicio;
}

void listarRecInv(No *no) {
    static No *primeiro_no = NULL;
    if (primeiro_no == NULL)
        primeiro_no = no;
    if (!no) // no == NULL // Critério de parada
        printf("NULL");
    else { // no != NULL // Passo recursivo
        listarRecInv(no->prox);
        if (primeiro_no == no)
            printf("<-(%d)\n", no->dado);
        else
            printf("<-(%d)", no->dado);
    }
}

void deletar_inicio(No **inicio) {
    if (*inicio == NULL) { // Lista vazia
        printf("Lista vazia. Não é possível deletar.\n");
        return;
    }
    No *aux = *inicio;
    *inicio = (*inicio)->prox;
    free(aux);
}

void deletar_fim(No **inicio) {
    if (*inicio == NULL) { // Lista vazia
        printf("Lista vazia. Não é possível deletar.\n");
        return;
    }
    No *ant = NULL;
    No *atual = *inicio;
    while (atual->prox != NULL) {
        ant = atual;
        atual = atual->prox;
    }
    if (ant == NULL) { // A lista tem apenas um nó
        free(*inicio);
        *inicio = NULL;
    } else {
        ant->prox = NULL;
        free(atual);
    }
}

void deletar(No **inicio, int dado) {
    if (*inicio == NULL) { // Lista vazia
        printf("Lista vazia. Não é possível deletar.\n");
        return;
    }
    No *ant = NULL;
    No *atual = *inicio;
    while (atual != NULL && atual->dado != dado) {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL) { // Elemento não encontrado
        printf("Elemento %d não encontrado na lista.\n", dado);
        return;
    }
    if (ant == NULL) { // Elemento a ser deletado é o primeiro da lista
        *inicio = atual->prox;
    } else {
        ant->prox = atual->prox;
    }
    free(atual);
}

void inserir_fim(No **inicio, int dado) {
    if(*inicio == NULL) { // lista vazia
        *inicio = criar_no(dado);
        return;
    } // lista não vazia
    No *ant = NULL;
    No *atual = *inicio;
    while(atual != NULL) {
        ant = atual;
        atual = atual->prox;
    }
    // nó ant está apontando para o último nó da lista
    ant->prox = criar_no(dado);
}

void inserir_fimV2(No **inicio, int dado) {
    if(*inicio == NULL) { // lista vazia
        *inicio = criar_no(dado);
        return;
    } // lista não vazia
    No *aux = *inicio;
    while(aux->prox != NULL) {
        aux = aux->prox;
    }
    // nó aux está apontando para o último nó da lista
    aux->prox = criar_no(dado);
}

int main(void) {
    No *inicio = NULL;
    // Inserindo elementos
    inserir_inicio(&inicio, 1);
    inserir_inicio(&inicio, 2);
    inserir_inicio(&inicio, 3);
    inserir_inicio(&inicio, 4);
    printf("Lista: ");
    listarIt(inicio);
    // Inserindo elementos no fim
    inserir_fim(&inicio, 5);
    inserir_fim(&inicio, 6);
    printf("Lista: ");
    listarIt(inicio);
    // Deletando elementos
    deletar_inicio(&inicio);
    deletar_fim(&inicio);
    deletar(&inicio, 3);
    printf("Lista: ");
    listarIt(inicio);
    return 0;
}
