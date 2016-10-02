#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pilha.h"
#include "conversao.h"

/* analisa a equação inserida pelo usuário e confere se a mesma é válida */
int validaExpressao(t_pilha *pilha, char *expressao){
	int flag = 1;
	int i;
	char c;
	for(i = 0; expressao[i] != '\0'; i++){
		if((expressao[i] == '(') || (expressao[i] == '[') || (expressao[i] == '{')){
			push(pilha, expressao[i]);
		}

		if((expressao[i] == ')') || (expressao[i] == ']') || (expressao[i] == '}')){
			if(pilhaVazia(pilha)){
				flag = 0;
			}
			else{
				c = pop(pilha);
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

	return flag;
}

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
void infixToPostfix(char *expressao){
	int i = 0;
	int j = 0;
	char c;
	char expressao_pos[100];
	t_pilha *operadores = alocaPilha();

	for(i = 0; expressao[i] != '\0'; i++){
		if(isalnum(expressao[i])){
			expressao_pos[j++] = expressao[i];
		}
		else if(expressao[i] == '('){
			push(operadores, expressao[i]);
		}
		else if(expressao[i] == ')'){
			while((c = pop(operadores)) != '('){
				expressao_pos[j++] = c;
			}
		}
		else{
			while(!pilhaVazia(operadores) && prioridade(expressao[i]) <= prioridade(operadores->topo->valor)){
				expressao_pos[j++] = pop(operadores);
			}
			push(operadores, expressao[i]);
		}
	}
	while(!pilhaVazia(operadores)){
		expressao_pos[j++] = pop(operadores);
	}

	printf("%s\n", expressao_pos);
}
