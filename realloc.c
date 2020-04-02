#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int *pVetor;
int quant = 0;

void lrpont(){
	
	if(quant == 0){
		pVetor = (int *)(malloc(1*sizeof(int)));
	}else{
		pVetor = (int *)(realloc(pVetor, (quant)*sizeof(int)));
	}
	
	quant++;
}

void inserirElemento(){
	lrpont();
		
	printf("\nInforme um valor para o elemento [%d]: ", quant);
	scanf("%d", &pVetor[quant]);
	menu();
}

void listarElemento(){
	int i;
	
	printf("\nLista de elementos\n");
	
	printf("%d", quant);
	
	for(i=1; i<=quant; i++){
		printf("Pos. [%d] elemento [%d] \n", i, pVetor[i]);
	}
}

void menu(){
	int opc = 0;
	
	printf("\n1. Inserir Elemento\n2. Listar Elementos");
	printf("\nEscolha uma opção: ");
	scanf("%d", &opc);
	
	switch (opc){
		case 1:
			inserirElemento();
			break;
		
		case 2:
			listarElemento();
			break;
		
		default:
			printf("\nMenu inexistente!!!");
	}
}

int main(void){
	
	setlocale(LC_ALL, "");
	
	menu();
}
