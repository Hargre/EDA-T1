#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "conversao.h"

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