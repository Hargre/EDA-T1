#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/* Cria uma nova pilha vazia */
t_pilha *alocaPilha(){
	t_pilha *pilha = (t_pilha*)malloc(sizeof(t_pilha));
	pilha->topo = NULL;
	return pilha;
}

/* Remove uma pilha, desalocando memória */
void liberaPilha(t_pilha *pilha){
	t_elemento *ptr;
	for(ptr = pilha->topo; ptr != NULL; ptr = ptr->proximo){
		free(ptr);
	}
	free(pilha);
}

/* Indica se existe algum elemento na pilha */
int pilhaVazia(t_pilha *pilha){
	return(pilha->topo == NULL);
}

/* Cria um novo elemento sem dados definidos */
t_elemento *alocaElemento(){
	t_elemento *elemento = (t_elemento*)malloc(sizeof(t_elemento));
	elemento->valor = 0;
	elemento->proximo = NULL;
	return elemento;
}

/* Operação de push na pilha, empilha um elemento */
void push(t_pilha *pilha, int valor){
	t_elemento *elemento = alocaElemento();
	elemento->valor = valor;
	elemento->proximo = pilha->topo;
	pilha->topo = elemento;
}

/* Operação de pop, remove um elemento do topo e retorna seu valor */
int pop(t_pilha *pilha){
	t_elemento *temp;
	int valor;

	if(pilhaVazia(pilha)){
		printf("Stack Underflow!\n");
		exit(1);
	}

	temp = pilha->topo;
	valor = pilha->topo->valor;
	pilha->topo = pilha->topo->proximo;
	free(temp);
	return valor;

}

/* Imprime todos os elementos na pilha */
void imprimirPilha(t_pilha *pilha){
	t_elemento *ptr;
	int counter = 1;

	if(pilhaVazia(pilha)){
		printf("Pilha Vazia!\n");
		return;
	}
	
	for(ptr = pilha->topo; ptr != NULL; ptr = ptr->proximo){
		printf("%d. %d\n", counter++, ptr->valor);
	}
}