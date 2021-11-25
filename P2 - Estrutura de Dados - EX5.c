/******************************************************************************

5-Crie uma lista duplamente encadeada que implemente dois TADs: um para armazenar os dados de um paciente 
de hospital que deve conter {documento, nome, idade, gênero} e outro TAD ficha {data, medico, obs} implemente 
todos os métodos de uma lista. (2,0)

*******************************************************************************/
#include <stdio.h>

typedef struct paciente{
 int doc;
 char nome[100];
 int idade;
 char genero[1];  
 struct paciente *anterior;
 struct paciente *proximo;
} Paciente;


typedef struct ficha{
 char data[12];
 char medico[50];
 char obs[100];
 struct ficha *anterior;
 struct ficha *proximo;
} Ficha;


typedef struct lista{
 Paciente *pacientePrimeiro;
 Ficha *fichaPrimeiro;
}Lista ;

void colocarNoFimPaciente(Lista *lista, int doc, char *n, int idade, char *g)
{

	Paciente *novo=(Paciente*)malloc(sizeof(Paciente));
	novo->doc = doc;
	strcpy(novo->nome, n);
	novo->idade = idade;
	strcpy(novo->genero, g);
	novo->anterior = NULL;
	novo->proximo = NULL;  
	
	if(lista->pacientePrimeiro==NULL){
		lista->pacientePrimeiro = novo;	
	} else {
		Paciente *aux = lista->pacientePrimeiro;
		while(aux->proximo != NULL){
			aux = aux->proximo;
		}
		novo->anterior = aux;
		aux->proximo = novo;
	}
}

void colocarNoFimFicha(Lista *lista, char *med, char *data, char *obs)
{
	
	Ficha *novo=(Ficha*)malloc(sizeof(Ficha));
	strcpy(novo->medico, med);
	strcpy(novo->data, data);
	strcpy(novo->obs, obs);
	novo->anterior = NULL;
	novo->proximo = NULL;  
	
	if(lista->fichaPrimeiro==NULL){
		lista->fichaPrimeiro = novo;	
	} else {
		Ficha *aux = lista->fichaPrimeiro;
		while(aux->proximo != NULL){
			aux = aux->proximo;
		}
		novo->anterior = aux;
		aux->proximo = novo;
	}
}


void colocarNoInicioPaciente(Lista *lista, int doc, char *n, int idade, char *g)
{
	
	Paciente *novo=(Paciente*)malloc(sizeof(Paciente));
	novo->doc = doc;
	strcpy(novo->nome, n);
	novo->idade = idade;
	strcpy(novo->genero, g);
	novo->anterior = NULL;
	novo->proximo = NULL;  
	
	if(lista->pacientePrimeiro==NULL){
		lista->pacientePrimeiro = novo;	
	} else {
		Paciente *antigo = lista->pacientePrimeiro;
		
		novo->proximo = antigo;		
		antigo->anterior = novo;
		
		lista->pacientePrimeiro = novo;
	}
}


void colocarNoInicioFicha(Lista *lista, char *med, char *data, char *obs)
{
	
	Ficha *novo=(Ficha*)malloc(sizeof(Ficha));
	strcpy(novo->medico, med);
	strcpy(novo->data, data);
	strcpy(novo->obs, obs);
	novo->anterior = NULL;
	novo->proximo = NULL;  
	
	if(lista->fichaPrimeiro==NULL){
		lista->fichaPrimeiro = novo;	
	} else {
		Paciente *antigo = lista->fichaPrimeiro;
		
		novo->proximo = antigo;		
		antigo->anterior = novo;
		
		lista->fichaPrimeiro = novo;
	}
}


void removerDoInicioPaciente(Lista *lista){
	
	if(lista->pacientePrimeiro==NULL){
		printf("Lista vazia\n");	
	} else {
		Paciente *aux = lista->pacientePrimeiro;
		
		aux->proximo->anterior = NULL;	
		lista->pacientePrimeiro = aux->proximo;	
		free(aux);
	}
}


void removerDoInicioFicha(Lista *lista){
	
	if(lista->fichaPrimeiro==NULL){
		printf("Lista vazia\n");	
	} else {
		Ficha *aux = lista->fichaPrimeiro;
		
		aux->proximo->anterior = NULL;	
		lista->fichaPrimeiro = aux->proximo;
		free(aux);
	}
}


void removerFimPaciente(Lista *lista){
	
	if(lista->pacientePrimeiro==NULL){
		printf("Lista vazia\n");	
	} else {
		Paciente *aux = lista->pacientePrimeiro;
		while(aux->proximo!=NULL){
			aux = aux->proximo;
		}
		Paciente *penultimo = aux->anterior;
		penultimo->proximo = NULL;
		printf("Ultimo removido");
		free(aux);
	}
}

void removerFimFicha(Lista *lista){
	
	if(lista->fichaPrimeiro==NULL){
		printf("Lista vazia\n");	
	} else {
		Ficha *aux = lista->fichaPrimeiro;
		while(aux->proximo!=NULL){
			aux = aux->proximo;
		}
		Ficha *penultimo = aux->anterior;
		penultimo->proximo = NULL;
		printf("Ultimo removido");
		free(aux);
	}
}

void removerPaciente(Lista *lista, int doc){
	
	printf("\nremoverPesquisa=");
	if(lista->pacientePrimeiro==NULL){
		printf("Lista vazia\n");	
	} else {
		Paciente *aux = lista->pacientePrimeiro;
		while(aux->proximo!=NULL){
			if(doc==aux->doc){
				if(aux->anterior==NULL){
					lista->pacientePrimeiro= aux->proximo;
					lista->pacientePrimeiro = NULL;	
				} else {
					aux->anterior->proximo = aux->proximo;
				}
				printf("%i \n", aux->doc);
				free(aux);	
				break;
			} else {
				aux = aux->proximo;
			}
		}
		
	}
}

void removerFicha(Lista *lista, char *obs){
	

	if(lista->fichaPrimeiro==NULL){
		printf("Lista vazia\n");	
	} else {
		Ficha *aux = lista->fichaPrimeiro;
		while(aux->proximo!=NULL){
			if(*obs == *aux->obs){
				if(aux->anterior==NULL){
					lista->fichaPrimeiro = aux->proximo;
					lista->fichaPrimeiro = NULL;	
				} else {
					aux->anterior->proximo = aux->proximo;
				}
				printf("%s %s \n", obs, aux->obs);
				free(aux);	
				
				break;
			} else {
				aux = aux->proximo;
			}
		}
		
	}
}

void listarPaciente(Lista *lista)
{
   	Paciente *aux = lista->pacientePrimeiro;
	while(aux != NULL){
		printf("Paciente:  Documento : %i,  Nome : %s, Idade : %i, Genero : %s\n", aux->doc, aux->nome, aux->idade, aux->genero);
		aux = aux->proximo;
	}
}
void listarFicha(Lista *lista)
{
   	Ficha *aux = lista->fichaPrimeiro;
	while(aux != NULL){
		printf("Ficha:%x, Medico : %s, Data : %s, Obs : %s\n", aux, aux->medico, aux->data, aux->obs);
		aux = aux->proximo;
	}
}


int main(int argc, char *argv[]) {
	Lista lpaciente = {NULL};
	Lista lficha = {NULL};
	
	
	colocarNoFimPaciente(&lpaciente, 12345, "Jaqueline", 24, "F");
	colocarNoFimPaciente(&lpaciente, 23564, "Juliana", 26, "F");
	
	listarPaciente(&lpaciente);
	removerPaciente(&lpaciente, 23564);
	listarPaciente(&lpaciente);

	removerFimPaciente(&lpaciente);
	printf("\n\n");
	listarPaciente(&lpaciente);
	
	
	removerDoInicioPaciente(&lpaciente);
	listarPaciente(&lpaciente);
	listarFicha(&lficha);
	listarFicha(&lficha);
	removerDoInicioFicha(&lficha);
	removerFimFicha(&lficha);

	listarFicha(&lficha);

	
	colocarNoInicioPaciente(&lpaciente,12345, "Jaque", 24, "F");
	listarPaciente(&lpaciente);
	
	colocarNoInicioFicha(&lficha,"Dra Juliana","23/11/2021","Hemograma Completo");
	listarFicha(&lficha);


	return 0;
}


