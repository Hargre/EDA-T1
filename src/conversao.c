#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pilha.h"
#include "conversao.h"

/* analisa a equação inserida pelo usuário e confere se a mesma é válida */
int validaExpressao(char *expressao){
	t_pilha *pilha = alocaPilha();
	int flag = 1;
	int i;
	char c;
	for(i = 0; expressao[i] != '\0'; i++){
		if((expressao[i] == '(') || (expressao[i] == '[') || (expressao[i] == '{')){
			push(pilha, (double)expressao[i]);
		}

		if((expressao[i] == ')') || (expressao[i] == ']') || (expressao[i] == '}')){
			if(pilhaVazia(pilha)){
				flag = 0;
			}
			else{
				c = (char)pop(pilha);
			}

			switch(expressao[i]){
				case ')':
					if(c != '('){
						flag = 0;
					}
					break;
				case ']':
					if(c != '['){
						flag = 0;
					}
					break;
				case '}':
					if(c != '{'){
						flag = 0;
					}
					break;
			}
		}
	}

	if (!pilhaVazia(pilha)){
		flag = 0;
	}

	liberaPilha(pilha);
	return flag;
}

/* definindo precedência de operadores */
int prioridade(char c){
	if(c == '('){
		return 0;
	}
	else if(c == '+' || c == '-'){
		return 1;
	}
	else if(c == '*' || c == '/'){
		return 2;
	}
	else return 3;
}

/* converte a expressão para o formato posfixo */
void infixToPostfix(char *expressao, char *expressao_pos){
	int i = 0;
	int j = 0;
	char c;
	t_pilha *operadores = alocaPilha();

	while(expressao[i] != '\0'){
		if(isdigit(expressao[i])){
			while(isdigit(expressao[i])){
				expressao_pos[j++] = expressao[i++];
			}
			if(!isspace(expressao[i]) && expressao[i] != '\0'){
				expressao_pos[j++] = ' ';
			}
		}
		else if(expressao[i] == '('){
			push(operadores, (double)expressao[i]);
			i++;
		}
		else if(expressao[i] == ')'){
			while((c = (char)pop(operadores)) != '('){
				expressao_pos[j++] = c;
			}
			i++;
		}
		else{
			while(!pilhaVazia(operadores) && prioridade(expressao[i]) <= prioridade(operadores->topo->valor)){
				expressao_pos[j++] = (char)pop(operadores);
			}
			push(operadores, (double)expressao[i]);
			i++;
		}
	}
	while(!pilhaVazia(operadores)){
		expressao_pos[j++] = (char)pop(operadores);
	}
	expressao_pos[j++] = '\0';

	printf("%s\n", expressao_pos);
	liberaPilha(operadores);
}

/* avalia e soluciona a expressão convertida */
void avaliaExpressao(char *expressao_pos){
	t_pilha *operandos = alocaPilha();
	int i = 0;
	double resultado = 0;

	while(expressao_pos[i] != '\0'){
		if(isdigit(expressao_pos[i])){
			int j = 0;
			double valor;
			char num[15];
			while(isdigit(expressao_pos[i])){
				num[j++] = expressao_pos[i++];
			}
			num[j] = '\0';
			valor = atof(num);
			push(operandos, valor);
		}
		else if((expressao_pos[i] == '+') || (expressao_pos[i] == '-') || (expressao_pos[i] == '*') || (expressao_pos[i] == '/')){
			double op2;
			switch(expressao_pos[i]){
				case '+':
					resultado = pop(operandos) + pop(operandos);
					push(operandos, resultado);
					break;
				case '-':
					op2 = pop(operandos);
					resultado = pop(operandos) - op2;
					push(operandos, resultado);
					break;
				case '*':
					resultado = pop(operandos) * pop(operandos);
					push(operandos, resultado);
					break;
				case '/':
					op2 = pop(operandos);
					resultado = pop(operandos)/op2;
					push(operandos, resultado);
					break;
			}
			i++;
		}
		else i++;
	}
	printf("Resultado: %.2lf\n", pop(operandos));
	liberaPilha(operandos);
}

void resolucao(char *expressao){
	char expressao_pos[100];
	if(validaExpressao(expressao)){
		printf("Expressão válida!\n");
	}

	else{
		printf("Expressão inválida!\n");
		exit(1);
	}

	infixToPostfix(expressao, expressao_pos);
	avaliaExpressao(expressao_pos);
}