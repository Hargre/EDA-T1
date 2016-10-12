# ED-T1
Projeto de conversão e cálculo de operações posfixas a partir de infixas, realizado para a disciplina de Estruturas de Dados da Universidade de Brasília.

## Instruções para compilação e execução do programa (em Linux): 

### Para compilar/executar:
* Abrir o terminal;
* Mudar para o diretório raiz do projeto;
* Limpar arquivos objeto já existentes com **$ make clean**
* Compilar com **$ make**
* Executar com **$ make run**

## Informações de Desenvolvimento:

* Sistema Operacional utilizado: Ubuntu 14.04 LTS
* Compilador: GCC 4.8.4
* Parâmetros de Compilação: -W -Wall -ansi -pedantic -g
* Bibliotecas utilizadas:
	* stdio.h - Para operações básicas de I/O;
	* stdio_ext.h - Para uso da função __fpurge();
	* stdlib.h - Para operações de gerenciamento de memória;
	* ctype.h - Para detecção de caracteres específicos em strings.
* Documentação adicional e relatório do projeto se encontram na pasta doc.
