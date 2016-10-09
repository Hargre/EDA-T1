#ifndef _PILHA_H_
#define _PILHA_H_

typedef struct elemento{
	double valor;
	struct elemento *proximo;
}t_elemento;

typedef struct{
	t_elemento *topo;
}t_pilha;

/* -----Assinaturas de funções----- */
t_pilha *alocaPilha();
void liberaPilha(t_pilha *pilha);
int pilhaVazia(t_pilha *pilha);

t_elemento *alocaElemento();

void push(t_pilha *pilha, double valor);
double pop(t_pilha *pilha);

void imprimirPilha(t_pilha *pilha);
/* -------------------------------- */
#endif