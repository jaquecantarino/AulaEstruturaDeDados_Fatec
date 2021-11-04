/******************************************************************************
ED10
*******************************************************************************/
#include <stdio.h>

/* 1-Implemente uma lista circular que represente o gerenciamento de processamento de
um sistema operacional, além das funções para adicionar, remover e listar, implemente 
uma função chamada de processar, que fara um laço enquanto tiver elementos na lista e 
deduzira -1 do atributo carga do TAD processo, quando carga for igual a 0 chame o metodo 
para remover o item da lista. Removendo todos os processos da lista encerre o laço */

typedef struct processo {
  int pid;
  int carga;
  struct processo *prox;
} Processo;

typedef struct lista{
 Processo *prim;
} Lista ;

void atualizaUltimo(Lista *lista, Processo *novo){
	Processo *auxiliar = lista->prim;
	while(auxiliar->prox != lista->prim){
		auxiliar = auxiliar->prox;
	}
	auxiliar->prox = novo;
}

void colocarNoFim(Lista *lista, int pid, int carga){
	printf("Alocar no Fim: PID = %i e CARGA = %i\n", pid, carga);
	Processo *novo = (Processo*)malloc(sizeof(Processo));
	novo->pid = pid;
	novo->carga = carga;
	novo->prox = lista->prim;  
	
	if(lista->prim==NULL){
		lista->prim = novo;
		novo->prox = novo;	
	} else {
		Processo *auxiliar = lista->prim;
		while(auxiliar->prox != lista->prim){ 
			auxiliar = auxiliar->prox;
		}
		auxiliar->prox = novo;
	}
}

void colocarNoInicio(Lista *lista, int pid, int carga){
	printf("Alocar no Início: PID = %i e CARGA = %i\n", pid, carga);
	Processo *novo=(Processo*)malloc(sizeof(Processo));
	novo->pid = pid;
	novo->carga = carga;
	novo->prox = NULL;  
	
	if(lista->prim==NULL){
		lista->prim = novo;	
		novo->prox = novo;
	} else {
		atualizaUltimo(lista, novo);
		novo->prox = lista->prim;
		lista->prim = novo;
	}
}

void removerInicio(Lista *lista){
	printf("Remover do Início = ");
	if(lista->prim==NULL){
		printf("Lista vazia\n");	
	} else {
		Processo *auxiliar = lista->prim;
		atualizaUltimo(lista, auxiliar->prox);
		printf("PID = %i e CARGA = %i\n", auxiliar->pid, auxiliar->carga);
		lista->prim = auxiliar->prox;
		free(auxiliar);
	}
}

void removerFim(Lista *lista){
	printf("Remover do Fim = ");
	if(lista->prim==NULL){
		printf("Lista vazia\n");	
	} else {
		Processo *auxiliar = lista->prim;
		Processo *auxiliar2 = auxiliar;
		while(auxiliar->prox != lista->prim){
			auxiliar2 = auxiliar;
			auxiliar = auxiliar->prox;
		}
		auxiliar2->prox = lista->prim;
	    printf("PID = %i e CARGA = %i\n", auxiliar->pid, auxiliar->carga);
		free(auxiliar);
	}
}

void removeItem(Lista *lista, int pid, int carga){
	printf("\nRemover Item = ");
	if(lista->prim==NULL){
		printf("Lista vazia\n");	
	} else {
	   Processo *auxiliar = lista->prim;
        Processo *penultimo = auxiliar;
        while(auxiliar->prox != NULL){
            if(pid == auxiliar->pid && carga == auxiliar->carga){
                if(auxiliar == penultimo){ //quando for o primeiro elemento
                    atualizaUltimo(lista, auxiliar->prox);
                    lista->prim = auxiliar->prox;
                } else {
                    penultimo->prox = auxiliar->prox;
                }
                printf("PID = %i e CARGA = %i\n", auxiliar->pid, auxiliar->carga);
                free(auxiliar); // removendo pesquisa
                break;
            } else {
                penultimo = auxiliar;
                auxiliar = auxiliar->prox;
            }
        }
	}
}

void processar(Lista *lista, int pid, int carga){
    printf("\nProcessando:");
    Processo *auxiliar = lista->prim;
	if(lista->prim==NULL){
		printf("Lista vazia\n");	
	} else {
	    do{
	        while(auxiliar->prox != lista->prim ){
                if(auxiliar->carga != 0){
                    auxiliar->carga--;
                    printf("\nPID = %i e CARGA = %i", auxiliar->pid, auxiliar->carga);
                    break;
                } 
            }
            printf("\nCarga Zerada");
    		removeItem(lista, auxiliar->pid, auxiliar->carga);
	    }while(auxiliar->carga != 0);
	     removeItem(lista, auxiliar->pid, auxiliar->carga);
	}
	removeItem(lista, auxiliar->pid, auxiliar->carga);
}

void listar(Lista *lista){
    if(lista->prim==NULL){
		printf("Lista vazia\n");	
	} else {
       	Processo *auxiliar = lista->prim;
       	printf("\nLista de Processos: \n");
    	do {
    	    printf("Processo: PID = %i e CARGA = %i\n", auxiliar->pid, auxiliar->carga);
    		// printf("Processo (%x) %i \n", aux, aux->valor);
    		auxiliar = auxiliar->prox;
    	} while(auxiliar != lista->prim);
	}
}

int main(int argc, char *argv[]) {
	Lista l1 = {NULL};
	
	
	colocarNoFim(&l1, 3, 9);
	colocarNoFim(&l1, 2, 8);
	colocarNoFim(&l1, 5, 7);
	colocarNoFim(&l1, 4, 6);
	listar(&l1);
	
	colocarNoInicio(&l1, 1, 6);
	colocarNoInicio(&l1, 3, 9);
	listar(&l1);
	
	removerInicio(&l1);
	listar(&l1);
	
	removerFim(&l1);
	listar(&l1);
		
	removeItem(&l1, 1, 5);
	listar(&l1);
	
	processar(&l1, 3, 7);
	listar(&l1);	
	
	return 0;
}