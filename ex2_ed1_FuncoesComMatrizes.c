// 2-crie um programa em linguagem C que crie uma matriz de 10,3 armazene a nota P1, P2 e MEDIA 
//nas respectivas colunas, crie uma função passando a matriz como parametro para identificar 
//a maiorNotaP1, a maiorNotaP2 e a maiorMedia e mediaSala

#include <stdio.h>
#include <stdlib.h>


float notas(){
    int x,y; // variavel de controle do looping
    // primeiro bloco[10]=linha // segundo bloco[3]=coluna
     float notas[10][3]= { {5.5,6.9,8.5},
                            {9.7,9.7,8.7},
                            {5.7,9.8,6.8},
                            {6.7,6.8,7.9},
                            {3.6,5.4,6.3},
                            {2.1,5.4,3.4},
                            {7.5,8.5,6.3},
                            {6.4,7.5,8.4},
                            {7.5,4.6,8.1},
                            {9.1,8.6,7.4} };
    for(x=0; x<=9; x++){
        for (y=0; y<=2; y++){
           printf("notas[%d][%d]\n",x,y); 
        }
    }
}

int main() { 
    float p1, p2, media;
    float mp1, mp2, mmedia, mediasala;
    
    notas();
    
    //código com erro, fazer a correção
}


