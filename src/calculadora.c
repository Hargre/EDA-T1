#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pilha.h"
#include "calculadora.h"

void calcular(){
	char valor;
	int op2;
	int resultado;
	t_pilha *operandos = alocaPilha();

	imprimirPilha(operandos);
	__fpurge(stdin);
	while(1){
		scanf("%c", &valor);
		__fpurge(stdin);
		if(valor == '+'){
			resultado = pop(operandos) + pop(operandos);
			push(operandos, resultado);
		}
		else if(valor == '-'){
			op2 = pop(operandos);
			resultado = pop(operandos) - op2;
			push(operandos, resultado);
		}
		else if(valor == '*'){
			resultado = pop(operandos) * pop(operandos);
			push(operandos, resultado);
		}
		else if(valor == '/'){
			op2 = pop(operandos);
			resultado = pop(operandos) / op2;
			push(operandos, resultado);
		}
		else{
			push(operandos, ((int)valor - '0'));
		}
		printf("--------------\n");
		imprimirPilha(operandos);
		printf("--------------\n");
	}
}