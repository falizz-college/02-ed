#ifndef PILHA_H
#define PILHA_H

typedef struct pilha Pilha;

int  top(Pilha *p);
int  pop(Pilha *p);
void push(Pilha *p, unsigned int dado);

#endif