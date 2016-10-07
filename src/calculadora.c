#include <stdio.h>
#include <stdio_ext.h> /* para usar __fpurge() */
#include <stdlib.h>
#include <ctype.h>
#include "pilha.h"
#include "calculadora.h"

void calcular(){
	int valor, resultado;
	char operador[3];
	t_pilha *operandos = alocaPilha();

	imprimirPilha(operandos);
	__fpurge(stdin);
	while(1){
		if(scanf("%2[*/-+!c]", operador) == 1){
			__fpurge(stdin);

			if(pilhaVazia(operandos) || operandos->topo->proximo == NULL){
				printf("Quantidade insuficiente de operandos!\n");
				return;
			}

			if(operador[0] == 'c'){
				int numCopias = pop(operandos);
				int valorCopia = pop(operandos);
				int i;
				for(i = 0; i < numCopias; i++){
					push(operandos, valorCopia);
				}
			}

			else if(operador[0] == '+'){
				if(operador[1] == '!'){
					while(operandos->topo->proximo != NULL){
						resultado = pop(operandos) + pop(operandos);
						push(operandos, resultado);
					}
				}
				else{
					resultado = pop(operandos) + pop(operandos);
					push(operandos, resultado);
				}
			}
			else if(operador[0] == '-'){
				if(operador[1] == '!'){
					while(operandos->topo->proximo != NULL){
						resultado = pop(operandos) - pop(operandos);
						push(operandos, resultado);
					}
				}
				else{
					resultado = pop(operandos) - pop(operandos);
					push(operandos, resultado);
				}
			}
			else if(operador[0] == '*'){
				if(operador[1] == '!'){
					while(operandos->topo->proximo != NULL){
						resultado = pop(operandos) * pop(operandos);
						push(operandos, resultado);
					}
				}
				else{
					resultado = pop(operandos) * pop(operandos);
					push(operandos, resultado);
				}
			}
			else if(operador[0] == '/'){
				if(operador[1] == '!'){
					while(operandos->topo->proximo != NULL){
						resultado = pop(operandos) / pop(operandos);
						push(operandos, resultado);
					}
				}
				else{
					resultado = pop(operandos) / pop(operandos);
					push(operandos, resultado);
				}
			}
		}

		else if(scanf("%d", &valor) == 1){
			__fpurge(stdin);
			push(operandos, valor);
		}

		else{
			__fpurge(stdin);
			printf("Comando inválido!\n");
		}

		printf("--------------\n");
		imprimirPilha(operandos);
		printf("--------------\n");
	}
}