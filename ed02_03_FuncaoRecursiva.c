#include <stdio.h>

// 3. Fazer uma função recursiva que conta o número de ocorrências de um determinado caracter, caract(char c, char s[])

int caract(char c, char s[]){
    if(s[0] == '\0')
    return 0;
    if(s[0]==c){
        return (1+caract(c,++s));
    }
    return caract(c,++s);
}


int main()
{
    char s[30],c;
    int t;
    printf("Contagem de um caracter\n");
    printf("\nDigite: ");
    gets(s);
    printf("\nDigite qual caractere que deseja contar: ");
    c=getchar();
    t=caract(c,s);
    printf("\n\nFoi encontrado %d vezes", t);
    getch();


    return 0;
}