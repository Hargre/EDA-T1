#ifndef _CONVERSAO_H_
#define _CONVERSAO_H_

#include "pilha.h"

int validaExpressao(char *expressao);
int prioridade(char c);
void infixToPostfix(char *expressao, char *expressao_pos);
void avaliaExpressao(char *expressao_pos);
void resolucao(char *expressao);

#endif