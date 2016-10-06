#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pilha.h"
#include "calculadora.h"

void calcular(){
	int valor, resultado;
	char operador;
	t_pilha *operandos = alocaPilha();

	imprimirPilha(operandos);
	__fpurge(stdin);
	while(1){
		if(scanf("%1[*/-+]", &operador) == 1){
			__fpurge(stdin);

			if(pilhaVazia(operandos) || operandos->topo->proximo == NULL){
				printf("Quantidade insuficiente de operandos!\n");
				return;
			}

			if(operador == '+'){
				resultado = pop(operandos) + pop(operandos);
			}
			else if(operador == '-'){
				resultado = pop(operandos) - pop(operandos);
			}
			else if(operador == '*'){
				resultado = pop(operandos) * pop(operandos);
			}
			else if(operador == '/'){
				resultado = pop(operandos) / pop(operandos);
			}

			push(operandos, resultado);
		}
		else if(scanf("%d", &valor) == 1){
			__fpurge(stdin);
			push(operandos, valor);
		}
		printf("--------------\n");
		imprimirPilha(operandos);
		printf("--------------\n");
	}
}