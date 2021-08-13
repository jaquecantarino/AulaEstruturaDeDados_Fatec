#include <stdio.h>

//Exemplo ponteiro em aula. 
//Aula 3 - Norton.

int main (){
    
    //EXEMPLO 1:
    
    int*ptr; //ponteiro que armazena endereços de variaveis do tipo inteiro;
    int valor=10; //variavel do tipo inteiro que recebe o valor 10;
    ptr = &valor; //estou atribuindo ao ponteiro o endereço da variavel valor;
    
    printf("Endereço da Variavel Valor: %x \n",&valor); //peço para que a aplicação mostre qual endereço em memoria da variavel valor.
    printf("Endereço no Ponteiro: %x \n" ,ptr); //mostrando o valor do ponteiro, que recebeu o endereço da variavel atraves do &;
    printf("Valor = %i \n" ,valor); //mostro o valor da variavel valor declarado acima;
    printf("Valor via ponteiro = %i \n" ,*ptr);//peço que o valor seja informado atraves da utilização de ponteiro
    
    //quando usamos o o * em frente ao ponteiro, exemplo *ptr, acessamos o valor da variavel armazenada nesse endereço
    
}
