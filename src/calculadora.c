#include <stdio.h>
#include <stdio_ext.h> /* para usar __fpurge() */
#include <stdlib.h>
#include <ctype.h>
#include "pilha.h"
#include "calculadora.h"

void calcular(){
	double valor, resultado;
	char operador[3];
	t_pilha *operandos = alocaPilha();

	printf("Os valores digitados serão exibidos na pilha.\n");
	printf("Além das operações básicas, esta calculadora aceita dois operadores especiais:\n");
	printf(">Repetição de operação: ao inserir o caractere '!' após um operador.\n");
	printf(">Cópia de um operando: inserindo o caractere 'c'.\n");

	imprimirPilha(operandos);
	__fpurge(stdin);
	while(1){
		if(scanf("%2[*/-+!cq]", operador) == 1){
			__fpurge(stdin);

			if(operador[0] == 'q'){
				return;
			}

			if(pilhaVazia(operandos) || operandos->topo->proximo == NULL){
				printf("Quantidade insuficiente de operandos!\n");
				return;
			}

			if(operador[0] == 'c'){
				int numCopias = (int)pop(operandos);
				double valorCopia = pop(operandos);
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
				double op1, op2;
				if(operador[1] == '!'){
					while(operandos->topo->proximo != NULL){
						op1 = pop(operandos);
						op2 = pop(operandos);
						if(op2 == 0.0){
							printf("Não pode dividir por zero!\n");
							return;
						}
						else{
							resultado = op1 / op2;
							push(operandos, resultado);
						}
					}
				}
				else{
					op1 = pop(operandos);
					op2 = pop(operandos);
					if(op2 == 0){
						printf("Não pode dividir por zero!\n");
						return;
					}
					else{
						resultado = op1 / op2;
						push(operandos, resultado);
					}
				}
			}
		}

		else if(scanf("%lf", &valor) == 1){
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