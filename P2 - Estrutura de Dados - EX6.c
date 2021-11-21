/******************************************************************************

6-Crieuma arvore binaria de busca que armazene números reais, crie método para adicionar e remover itens, 
listar e pesquisar (2,0)

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
   int info;
   struct arvore *esquerda;
   struct arvore *direita;
} Arvore;

Arvore* cria_vazio () {
   return NULL;
}

int adicionar (Arvore *a, int v){
    if(a == NULL){
        a=(Arvore*)malloc(sizeof(Arvore));
        a->info = v;
        a->esquerda = NULL;
        a->direita = NULL;
        printf("\nAdicionando: %i\n", a->info);
    }
    else if(v < a->info){
    	printf("<- ");
        a->esquerda = adicionar(a->esquerda,v);
    }
    else{
    	printf("-> ");
        a->direita = adicionar(a->direita,v);
    }
    return a;
}

void listar (Arvore *a)
{
    if (!(a == NULL))
    {
    	 printf("%i", a->info);
    	 listar(a->esquerda); 
    	 listar(a->direita);
    }
}

int buscar(Arvore *a, int v){
    int nivel;
    if (a!=NULL){
	    if(a->info==v){
	        printf("\nElemento encontrado: %i \n", v);     
	        return 0;
	    } else {
	         int alt_esquerda, alt_direita;
    	    if((a->info)<v)
    	    {
    	        alt_direita = buscar(a->direita,v);
    	        nivel = alt_direita + 1;
    	        return nivel;
    	    }
    	    else 
    	    {
    	        alt_esquerda = buscar(a->esquerda, v);
    	        nivel = alt_esquerda + 1;
    	        return nivel;
    	    }
	      }
	    }
    return 0;    
}

int remover (Arvore *a, int v){
    if(a == NULL){
        return NULL;
    }
    else{
        if(a->info >v){
            a->esquerda = remover (a->esquerda,v);
            printf("\nElemento removido: %i \n", v);
        }
        else if (a->info <v){
            a->direita = remover (a->direita,v);
        }
        else{
            if((a->esquerda == NULL) && (a->direita == NULL)){
                free(a);
                a=NULL;
            }
            else if(a->direita == NULL){
                Arvore *tmp = a;
                a = a -> esquerda;
                free (tmp);
            }
            else if(a->esquerda == NULL){
                Arvore *tmp = a;
                a = a -> direita;
                free (tmp);
            }
            else{
                Arvore *tmp = a->esquerda;
                while(tmp->direita != NULL){
                    tmp=tmp->direita;
                }
                a->info = tmp->info;
                tmp->info = v;
                a->esquerda = remover(a->esquerda,v);
            }
        }
    }
    return a;
}

int main () 
{
int n, x, y;
int op, confirma;
Arvore *a = cria_vazio();

do
{
    printf("Escolha a opção desejada: 1-Adicionar; 2-Listar, 3-Buscar, 4-Remover:");
    scanf("%i", &op);
    switch (op)
    {
        case 1:
        printf("Digite o número:");
        scanf("%i", &n);
        adicionar (a, n); break;
        case 2:
        listar (a); break;
        case 3:
        printf("Qual elemento deseja buscar:");
        scanf("%i", &x);
        buscar(a,x); break;
        case 4:
        printf("Qual elemento deseja remover?");
        scanf("%i", &y);
        remover(a,y); break;
    }
	printf("Deseja fazer uma nova transação? 1-Sim 2-Não:");
	scanf("%i", &confirma);
}
	while(confirma == 1);
	return 0;
}
