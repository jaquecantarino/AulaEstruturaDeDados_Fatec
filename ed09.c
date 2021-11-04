/*********************************************************************************
1- O que são listas e quais suas utilizações?
É uma representação de uma sequencia de objetos, onde cada elemento é armazenado em uma célula da lista.

2- Qual a diferença entre lista simplesmente ligada, circular e duplamente ligada?
Simples ligada: É uma estrutura de nós ligados por ponteiros.
Duplamente ligada: É como um extensão da lista ligada, tem a ligação por ponteiros e geralmente é usada
quando se tem muitas operações de remoção e adição de elementos.
Circular: É como a ligada ou duplamente ligada, porém ela não tem fim, ou seja, o ponteiro seguinte 
do ultimo elemento será o primeiro elemento da fila.


3-Escreva uma programa de lista encadeada simples que armazene dois valores no tad 
minimo e maximo.

4-Crie uma função para listar a menor valor para minimo de todas as ocorrencias e o 
maior valor para o maximo de todas as ocorrencias.
**********************************************************************************/
#include <stdio.h>

// 3-Escreva uma programa de lista encadeada simples que armazene dois valores no tad 
// minimo e maximo.

typedef struct num;

struct num {
	int valor;
	num *proximo;
	num *anterior;
};

num *inicio;
num *fim;
int tamanho;


//4-Crie uma função para listar a menor valor para minimo de todas as ocorrencias e o 
//maior valor para o maximo de todas as ocorrencias.

typedef struct valor;
