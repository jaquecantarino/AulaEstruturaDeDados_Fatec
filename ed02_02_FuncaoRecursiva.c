#include <stdio.h>

// 2. Escrever uma função recursiva que retorna o tamanho de um string, tamstring(char s[])

int tamString(char s[]){
    int tm = 0;
    
    while(s[tm] != '\0'){
        tm++;
    }
    return tm;
}

int main()
{
    char vet[30] = ("Jaqueline Teste");
    
    printf("O tamanho da palavra é: %d",tamString(vet));

    return 0;
}