/**
	* @file calculadora.h
	*
	* @brief Calculadora para notação posfixa.
	*
*/
#ifndef _CALCULADORA_H_
#define _CALCULADORA_H_

#include "pilha.h"

/** 
 * @brief Função de implementação da calculadora.
 * 
 * Aceita qualquer valor real. Recebe valores e os empilha, exibindo o status da pilha a cada valor adicionado.
 * Ao receber um operador, realiza a operação e exibe a pilha atualizada. Possui duas operações especiais, sendo
 * estas de repetição de operação e cópia de operando. Continua realizando operações até o número de operandos
 * na pilha ser insuficiente ou até o usuário selecionar a opção de saída. Limpa o buffer de entrada a cada valor 
 * inserido para evitar leituras inválidas.
 */
void calcular();

#endif
