/**
	* @file conversao.h
	*
	* @brief Avaliação de expressões.
	*
	* Métodos para avaliação, conversão e resolução de expressões posfixas.
*/

#ifndef _CONVERSAO_H_
#define _CONVERSAO_H_

#include "pilha.h"

/** 
 * @brief Avalia uma expressão infixa recebida.
 *
 * Analisa os delimitadores de prioridade (parênteses, colchetes, chaves) em uma expressão aritmética
 * e informa se a expressão é vaĺida ou não. O critério é a correspondência entre inicializadores e 
 * finalizadores de escopo.
 * @param expressao Expressão a ser avaliada.
 * @return 1 caso válida, 0 caso contrário.
 */
int validaExpressao(char *expressao);
/** 
 * @brief Define prioridade entre operadores aritméticos e delimitadores.
 *
 * Função de apoio para a função de conversão infixa-posfixa. 
 * @param c Qualquer um dos 4 operadores básicos ou delimitadores ([{.
 * @return A prioridade estabelecida do caracter.
 */
int prioridade(char c);
/** 
 * @brief Passa uma expressão infixa para sua forma posfixa.
 *
 * A conversão gera uma expressão 100% equivalente com a original. Podem haver pequenas inconsistências de formatação
 * (ausência ou excesso de espaços). Ao final, imprime a expressão convertida.
 * @param expressao A expressão original, já validada.
 * @param expressao_pos Inicialmente uma string vazia, após a conversão contém a expressão posfixa.
 */
void infixToPostfix(char *expressao, char *expressao_pos);
/** 
 * @brief Resolve uma expressão no formato posfixo.
 *
 * A função recebe a string previamente convertida. Transforma os caracteres numéricos em valores do tipo double, com
 * cuidado necessário para tratar números de vários digitos. Ao detectar um operador realiza a operação com os dois
 * últimos valores encontrados. Trata como erro a presença de qualquer caracter não-numérico que não seja um operador.
 * Ao final, exibe o resultado da expressão.
 * @param expressao_pos String com a expressão no formato posfixo.
 */
void avaliaExpressao(char *expressao_pos);
/** 
 * @brief Processo completo de avaliação, conversão e resolução da expressão.
 *
 * Agrupa as funções já definidas em um único procedimento. Recebe apenas a expressão original e faz com ela todo o
 * tratamento especificado.
 * @param expressao String com a expressão a ser manipulada e resolvida.
 */
void resolucao(char *expressao);

#endif