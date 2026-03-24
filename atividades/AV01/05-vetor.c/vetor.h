#ifndef VETOR_H
#define VETOR_H

typedef struct vetor Vetor;

Vetor *criarVetor(int limit);
void liberarVetor(Vetor *v);
void listar(Vetor *v);
void zerar(Vetor *v);

#endif // VETOR_H
