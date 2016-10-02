#ifndef _CONVERSAO_H_
#define _CONVERSAO_H_

#include "pilha.h"

int validaExpressao(t_pilha *pilha, char *expressao);
int prioridade(char c);
void infixToPostfix(char *expressao);

#endif