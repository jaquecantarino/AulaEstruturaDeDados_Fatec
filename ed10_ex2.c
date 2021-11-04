#include <stdio.h>

/*2-Implemente uma lista duplamente encadeada para simular uma rede social de pessoas conhecidas, 
implemente todas as funções basicas, e adicione uma função adicional para contar quantas pessoas 
são necessarias para uma pessoa A, conhecer uma pessoa B somente atraves da navegação dos encadeamentos.*/

typedef struct pessoa {
  char[30] nome;
  struct pessoa *ant;
  struct pessoa *prox;
} Pessoa;

typedef struct lista{
    Pessoa *prim;
} Lista ;

void ligarPessoas(Lista *lista, char[] pessoa A, char[] pessoa B){
    
}

void colocarNoFim(Lista *lista, char* nome) {
	printf("colocarNoFim %s\n", nome);
	Pessoa *novo=(Pessoa*)malloc(sizeof(Pessoa));
	novo->nome = nome;
	novo->anterior = NULL;
	novo->prox = NULL;  
	
	if(lista->prim==NULL){
		lista->prim = novo;	
	} else {
		Pessoa *auxiliar = lista->prim;
		while(auxiliar->prox != NULL){
			auxiliar = auxiliar->prox;
		}
		novo->anterior = auxiliar;
		auxiliar->prox = novo;
	}
}

void colocarNoInicio(Lista *lista, char* nome)
{
	printf("colocarNoInicio %s\n", nome);
	Pessoa *novo=(Pessoa*)malloc(sizeof(Pessoa));
	novo->nome = nome;
	novo->prox = NULL;  
	novo->anterior = NULL;
	
	if(lista->prim==NULL){
		lista->prim = novo;	
	} else {
		Pessoa *antigo = lista->prim;
		
		novo->prox = antigo;		
		antigo->anterior = novo;
		
		lista->prim = novo;
	}
}

void removerInicio(Lista *lista){
	printf("removerInicio=");
	if(lista->prim==NULL){
		printf("Lista vazia\n");	
	} else {
		Pessoa *auxiliar = lista->prim;
		printf("%s\n", auxiliar->nome);
		auxiliar->prox->anterior = NULL;	
		lista->prim = auxiliar->prox;
		free(auxiliar);
	}
}

void removerFim(Lista *lista){
	printf("removerFim=");
	if(lista->prim==NULL){
		printf("Lista vazia\n");	
	} else {
		Pessoa *auxiliar = lista->prim;
		while(auxiliar->prox!=NULL){
			auxiliar = auxiliar->prox;
		}
		Pessoa *penultimo = auxiliar->anterior;
		penultimo->prox = NULL;
		printf("%s \n", auxiliar->nome);
		free(auxiliar);
	}
}

void removerPesquisa(Lista *lista, char* nome){
	printf("\nremoverPesquisa=");
	if(lista->prim==NULL){
		printf("Lista vazia\n");	
	} else {
		Pessoa *auxiliar = lista->prim;
		while(auxiliar->prox!=NULL){
			if(nome==auxiliar->nome){
				if(auxiliar->anterior==NULL){ //quando for o primeiro elemento
					lista->prim = auxiliar->prox;
					lista->prim->anterior = NULL;	
				} else {
					auxiliar->anterior->prox = auxiliar->prox;
				}
				printf("%s \n", auxiliar->nome);
				free(auxiliar);	
				break;
			} else {
				auxiliar = auxiliar->prox;
			}
		}
		
	}
}

void listar(Lista *lista)
{
   	Pessoa *auxiliar = lista->prim;
	while(auxiliar != NULL){
		printf("Pessoa %x %s \n", auxiliar, auxiliar->nome);
		auxiliar = auxiliar->prox;
	}
}

int main(int argc, char *argv[]) {
	Lista l1 = {NULL};
	
	
	colocarNoFim(&l1, 45);
	colocarNoFim(&l1, 78);
	colocarNoFim(&l1, 98);
	colocarNoFim(&l1, 10);
	listar(&l1);
	
	colocarNoInicio(&l1, 52);
	colocarNoInicio(&l1, 46);
	listar(&l1);

	removerInicio(&l1);
	listar(&l1);
	
	removerFim(&l1);
	listar(&l1);
	
	removerPesquisa(&l1, 52);
	
	removerPesquisa(&l1, 45);
	listar(&l1);	
	removerPesquisa(&l1, 10);
	listar(&l1);	
	return 0;
}



