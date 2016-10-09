#include <stdio.h>
#include <stdio_ext.h> /* para usar __fpurge() */
#include <stdlib.h>
#include "pilha.h"
#include "conversao.h"
#include "calculadora.h"

int main(){
	char expressao[100];
	int sel;
	do{
		printf("Selecione modo de funcionamento:\n");
		printf("1. Resolução de Expressão\n");
		printf("2. Calculadora\n");
		printf("3. Sair\n");

		scanf("%d", &sel);
		__fpurge(stdin);
		switch(sel){
			case 1:
				printf("Digite expressão:\n");
				scanf("%[^\n]", expressao);
				resolucao(expressao);
				break;
			case 2: 
				calcular();
				break;
			case 3:
				break;
			default:
				printf("Entrada inválida!\n");
				break;
		}
	}while(sel != 3);
	return 0;
}