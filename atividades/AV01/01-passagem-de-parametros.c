#include <stdio.h>
 
 // Procedimentos n�o retornam valor
 // Fun��es retornam valor
 
/* void exibir1 (int v[], int tamanho);
	outra froma de declarar: */
/* void exibir2 (int *v, int tamanho);
	na primeira fomra a declara��o de vetor � mais vis�vel */
void exibir3 (int tamanho, int v[tamanho]){
	// no c++ essa sintaxe pode dar erros
	// o procedimento exibir3 seria o mais intuitivo
	int i;
	for (i = 0; i < tamanho; i++){
		printf ("v[%d]: %d\n", i, v[i]);
	}
}

void zerarpares(int tamanho, int v[tamanho]){
	int i;
	for (i = 0; i<tamanho ;i++){
		if (v[i]%2==0){
			printf("v[%d]: 0\n", i);
		} else {
			printf("v[%d]: %d\n", i, v[i]);
		}
	}
}

int main (){
	
	// Declara��o de vetor
	int v1[] = {5, 2, 8, 2, 1, 9, 7, 6};
	int v2[10] = {5, 2, 8, 2, 1, 9, 7, 6}; 
	// elementos excedentes ser�o inicializados com 0
	int v3 [10] = {};
	// todos os elementos ser�o zero
	int v4[10]; 
	// os elementos n�o necessariamente ser�o 0, podem haver lixos de mem�ria
	exibir3(8, v1);
	printf("\n");
	exibir3(10, v2);
	printf("\n");
	exibir3(10, v3);
	printf("\n");
	exibir3(10, v4);
	printf("\n\n\n");
	printf("Pares zerados:\n");
	zerarpares(8, v1);
	return 0;
}
