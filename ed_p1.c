/******************************************************************************
• 1-O que é TAD e qual a sua aplicação? de um exemplo de uma implementação em linguagem C de um TAD (0,5)
R: TAD são dados abstratos, são instanciados fora do programa principal, pode representar alguma informação que o tipo primitivo
não conseguiria com eficácia.
Podemos citar como exemplo um cadastro de cliente, que tenha CPF, nome e idade, na TAD podemos usar varias de tipo diferentes,
como int para CPF, char para nome e int para idade.

----------------------------------------------------------------------------------------------------------
• 2-Defina os conceitos de FILAS e PILHAS, exemplifique possíveis implementações de cada uma. (0,5)
R: Filas: É uma estruta de dados dinâmica que possui mais de um elemento, onde sempre que houver uma remoção o dado removido é o mais antigo na estrutura.
Então, o primeiro objeto inserido na fila sempre será o primeiro a ser removido;
Pilhas: É uma estrutura 'oposta' da fila, isso é, os elementos inseridos na fila serão removidos na ordem oposta em que foram
inseridos. Isso porque todo acesso é feito através do topo, então, toda vez que um elemento é inserido ele passa a ser o topo;
A diferença entre os dois tipos está na ordem do item a ser removido;

----------------------------------------------------------------------------------------------------------

*******************************************************************************/

/* 3-Implemente uma fila dinâmica em um programa que simule o controle de uma pista de decolagem de aviões em um aeroporto. Neste programa, o usuário deve ser capaz de realizar as seguintes tarefas:
a) Listar o número de aviões aguardando na fila de decolagem;
b) Autorizar a decolagem do primeiro avião da fila;
c) Adicionar um avião à fila de espera;
d) Listar todos os aviões na fila de espera;
e) Listar as características do primeiro avião da fila.
Considere que os aviões possuem um nome e um número inteiro como identificador. Adicione outras características conforme achar necessário. (2,5)*/

#include<stdio.h>
#include<stdlib.h>

struct aviao{
    char nome[60];
    char tipo[60];
    char piloto[60];
    int codigo;
    int capacidade;
    struct aviao*proximo;
};


item*criarFila(){
    item*fila=(item*)malloc(sizeof(item));
    fila -> proximo = NULL;
    return fila;
}


int filaVazia(item*x){
    if(x->proximo==NULL){
        return 1;
    }else{
        return 0;
    }
}


void colocarNaFila(item*fila){
    item*novo=(item*)malloc(sizeof(item));
    printf("Tipo do avião:");
    scanf("%s",&novo->tipo);
    printf("Nome do avião:");
    scanf("%s",&novo->nome);
    printf("Codigo do Voo:");
    scanf("%i"&novo->Codigo);
    printf("Piloto do avião:")
    scanf("%s"&novo->piloto);
    printf("Capacidade de passageiros no voo:");
    scanf("%i"&novo->capacidade);
    novo->proximo=NULL;
    
    if(filaVazia(fila)==1){
        fila->proximo=novo;
    } else{
        item*temp=fila->proximo;
        while(temp->proximo!=NULL){
            temp=temp->proximo;
        }
        temp->proximo=novo;
    }
   
}


void tirarDaFila(item*fila){
    if(filaVazia(fila)==0){
        item*temp = fila->proximo;
        fila->proximo=temp->proximo;
        printf("Decolagem autorizada: %s, %s, %i, %s, %i \n",temp->tipo,temp->nome,temp->codigo,temp->piloto,temp->capacidade);
    }
}


void primeiroDaFila(item*fila){
    if(filaVazia(fila)==0){
        item*temp = fila->proximo;
        printf("Primeiro avião: %s, %s, %i, %s, %i \n",temp->tipo,temp->nome,temp->codigo,temp->piloto,temp->capacidade);
    }
}

void exibir(item*fila){
    item*temp=fila->proximo;
    while(temp!=NULL){
        printf("Avião: %s, %s, %i, %s, %i \n",temp->tipo,temp->nome,temp->codigo,temp->piloto,temp->capacidade);
        temp=temp->proximo;
    }
    
}

void total(item*fila){
    int comprimento = 0;
    item*temp=fila->proximo;
    while(temp!=NULL){
        comprimento++;
        temp=temp->proximo;
    }
    printf("Total de aviões: %i \n",comprimento);
}


int main(int iniciar, int confirmar){
    item*fila=criarFila();
    
    printf("Pista \n");
    do{
        printf("\n Escolha uma opção:");
        printf("\n 1-Aviões no aguardo \n 2-Autorizar voo \n 3- Adicionar avião \n 4-Lista de aviões \n 5-Primeiro voo");
        scanf("%i",&iniciar);
        switch(iniciar){
            case 1: exibir(fila); break;
            case 2: tirarDaFila(fila); break;
            case 3: colocarNaFila(fila); break;
            case 4: tota(fila); break;
            case 5: primeiroDaFila(fila); break;
        }
        printf("Nova transação? 1-Sim ou 2-Não");
        scanf("%i",&confirmar)
    } while(confirmar==1);
}

----------------------------------------------------------------------------------------------------------

/*4-Implemente uma pilha dinamica que simule o historico de navegação de um browser, onde a cada pagina acessada uma 
nova url e adicionada ao topo da pilha, implemente as seguintes funções:
a)adicionar nova url ao topo da pilha
b)mostrar url atual
c)voltar, removendo o topo da pilha 
d)quantidade de urls adicionadas a pilha (2,5)*/




