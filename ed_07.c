#include <stdio.h>

//Implemente uma pilha de um TAD que represente as cartas de um baralho Naipe+Carta exemplo: 9 de Ouros
struct carta {
    char baralho[52];
    struct carta *prox;
} typedef carta;

struct pilha {
    struct carta *prim;
} typedef pilha;


void push(pilha *p, char *n){
    printf("push %s \n", n);
    carta *novo = (carta*)malloc(sizeof(carta));
    strcpy(novo->baralho, n);
    novo->prox = NULL;
    //pilha vazia
    if(p->prim==NULL){
        p->prim = novo;
    } else {
        novo->prox = p->prim;
        p->prim = novo;
    }
}

void pop(pilha *p){
    printf("pop \n");
    if(p->prim==NULL){
        printf("Sem cartas \n");
    } else {
        carta *novoTopo = p->prim->prox;
        free(p->prim);
        p->prim = novoTopo;
    }
}

void mostrar(pilha *p){
    printf("Topo da pilha=%s %x \n", p->prim->baralho, p->prim);
}

// Utilizando os metodos POP e PUSH  distribua as cartas de cima para baixo LIFO (Last In, First Out)
int main(int argc, char *argv[]) {
    pilha p;
    
    printf("Cartas:\n");
    push(&p, "2 de Copas");
    push(&p, "5 de Espada");
    push(&p, "3 de Ouro");
    push(&p, "7 de Espada");
    push(&p, "1 de Copas");
    push(&p, "A de Ouro");
    push(&p, "10 de Paus");
    push(&p, "6 de Paus");
    
    mostrar(&p);
    pop(&p);
    mostrar(&p);
    pop(&p);
    mostrar(&p);
    pop(&p);
    mostrar(&p);
    pop(&p);
    mostrar(&p);
    pop(&p);
    mostrar(&p);
    pop(&p);
    mostrar(&p);
    pop(&p);
    mostrar(&p);
    pop(&p);
    
    return 0;
}


