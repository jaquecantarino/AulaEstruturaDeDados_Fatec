// 1-crie um programa em linguagem C com 4 funções (somar, subatrair, multiplicar e dividir)
// recebendo os parametros do tipo float A e float B o retorno de cada função deve ser o valor da 
//operação matemática

#include <stdio.h>
#include <stdlib.h>

float somar (float a, float b){ // assinatura da função.
// float tipo de retorno / somar nome da função / () parametros
    float soma; // criação da variavel de resultado
    soma = a + b; // estrutura da conta
    return soma; // valor de saida, retorno da função
}

float subtrair (float a, float b){
    float subtracao;
    subtracao = a - b;
    return subtracao;
}

float multiplicar (float a, float b){
    float multiplicacao;
    multiplicacao = a * b;
    return multiplicacao;
}

float dividir (float a, float b){
    float divisao;
    divisao = a / b;
    return divisao;
}


int main() { // main = função principal ( inicio)
    printf("Testes:\n");
    printf("Função Soma:\n");
    float a;
    a=somar(2.53,2.53);
    printf("A soma dos números é: %f",a);
    
    printf("\nFunção Subtração:\n");
    float s;
    s=subtrair(5.50,2.00);
    printf("A subtracao dos números é: %f",s);
    
    printf("\nFunção Multiplicação:\n");
    float m;
    m=multiplicar(2,5);
    printf("A Multiplicação dos números é: %f",m);
    
    printf("\nFunção Divisão:\n");
    float d;
    d=dividir(10,5);
    printf("A divisão dos números é: %f",d);
}

