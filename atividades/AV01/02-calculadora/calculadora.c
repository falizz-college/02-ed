#include "calculadora.h"
#include <stdlib.h>

struct valores {
	float memoria;
};

// criar calculadora
Calculadora* criar(float c, float valor){
	Calculadora *c = (Calculadora *) malloc(sizeof memoria);
	if (c != NULL) {
		c -> memoria = 0;
	}
	return c;
}

// destruir memoria

void destruir(Calculadora *c) {
	free(c);
}

// exibir memoria

void exibir (Calculadora *c){
	if(!c) return 0;
	printf ("Memoria: %f\n", c->memoria);
}

// zerar memoria

int zerar (Calculadora *c){
	if (!c) return 0;
	Calculadora *c = 0;
	return 1;
}

// somar memoria

void somar (Calculadora *c, Calculadora valor){
	Calculadora *c += Calculadora valor;
}

// multiplicar memoria

void multiplicar (Calculadora *c, Calculadora valor){
	Calculadora *c *= Calculadora valor;
}

// dividir

void dividir (Calculadora *c, Calculadora valor){
	if (!c) return 0;
	if (Calculadora valor == 0){
		printf ("Error");
	}
	Calculadora *c /= Calculadora valor;
}
