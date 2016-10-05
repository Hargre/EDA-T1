#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pilha.h"
#include "calculadora.h"

void calcular(){
	char valor;
	int resultado;
	t_pilha *operandos = alocaPilha();

	imprimirPilha(operandos);
	__fpurge(stdin);
	while(1){
		scanf("%c", &valor);
		__fpurge(stdin);
		if(valor == '+'){
			if(operandos->topo->proximo != NULL){
				resultado = pop(operandos) + pop(operandos);
				push(operandos, resultado);
			}
			else{
				printf("No. insuficiente de operandos!\n");
				return;
			}
		}
		else if(valor == '-'){
			if(operandos->topo->proximo != NULL){
				resultado = pop(operandos) - pop(operandos);
				push(operandos, resultado);
			}
			else{
				printf("No. insuficiente de operandos!\n");
				return;
			}
		}
		else if(valor == '*'){
			if(operandos->topo->proximo != NULL){
				resultado = pop(operandos) * pop(operandos);
				push(operandos, resultado);
			}
			else{
				printf("No. insuficiente de operandos!\n");
				return;
			}
		}
		else if(valor == '/'){
			if(operandos->topo->proximo != NULL){
				resultado = pop(operandos) / pop(operandos);
				push(operandos, resultado);
			}
			else{
				printf("No. insuficiente de operandos!\n");
				return;
			}
		}
		else{
			push(operandos, ((int)valor - '0'));
		}
		printf("--------------\n");
		imprimirPilha(operandos);
		printf("--------------\n");
	}
}