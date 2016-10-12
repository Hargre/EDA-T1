/*! \mainpage Estruturas de Dados - Trabalho 1
 *
 * Felipe de Oliveira Hargreaves - 15/0009313
 * 
 */

/**
	* @file pilha.h
	*
	* @brief Estrutura de Pilha
	*
	* Estrutura pilha e suas funções de manipulação.
*/

#ifndef _PILHA_H_
#define _PILHA_H_

/**
 * @brief Estrutura para elementos da pilha.
 *
 * A estrutura é implementada com base em uma lista encadeada, de forma dinâmica.
 */
typedef struct elemento{
	double valor; /**< Valor a ser armazenado no elemento */
	struct elemento *proximo; /**< Ponteiro para o proximo elemento da pilha */
}t_elemento;

/**
 * @brief Estrutura de inicialização da pilha.
 *
 * Contém um ponteiro para o elemento topo da estrutura, informação essencial em uma pilha.
 */
typedef struct{
	t_elemento *topo; /**< Indica o elemento no topo da pilha. */
}t_pilha;

/* -----Assinaturas de funções----- */
/** 
 * @brief Inicializa uma nova pilha.
 *
 * Cria uma pilha vazia, com <tt>pilha->topo = NULL</tt>.
 * @return Ponteiro para a pilha alocada.
 */
t_pilha *alocaPilha();
/** 
 * @brief Remove uma pilha.
 *
 * Libera a memória de todos os elementos alocados na pilha, e então libera a própria pilha.
 * @param pilha Pilha a ser desalocada.
 */
void liberaPilha(t_pilha *pilha);
/** 
 * @brief Indica se existem ou não elementos na pilha.
 *
 * @return 1 caso vazia, 0 caso contrário.
 */
int pilhaVazia(t_pilha *pilha);

/** 
 * @brief Inicializa um novo elemento da pilha.
 *
 * Cria um elemento com valor e ponteiro nulos.
 * @return Ponteiro para o elemento alocado.
 */
t_elemento *alocaElemento();

/** 
 * @brief Operação de push.
 *
 * Empilha um valor, criando um novo elemento e o colocando no topo da pilha.
 * @param pilha Pilha a se inserir o elemento.
 * @param valor Número a ser inserido na pilha.
 */
void push(t_pilha *pilha, double valor);
/** 
 * @brief Operação de pop.
 *
 * Desempilha um valor, removendo-o do topo da pilha. O valor anterior assume sua posição.
 * @param pilha Pilha a se remover o valor.
 * @return O valor removido.
 */
double pop(t_pilha *pilha);

/** 
 * @brief Impressão da pilha.
 *
 * Imprime todos os elementos da pilha, a partir de seu topo. É exibido um índice para cada valor.
 * @param pilha Pilha a ser imprimida.
 */
void imprimirPilha(t_pilha *pilha);
/* -------------------------------- */
#endif