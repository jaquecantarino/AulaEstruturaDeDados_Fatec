#include <stdio.h>

//1- escreva uma função recursiva para calcular o valor de uma base x elevada a um expoente y.

int pot(int x, int y){
    if(y == 0)
        return 1;
    else
        return x * pot(x, y-1);
};

int main()
{
    int x, y;
    
    printf("Potenciação: x elevado a y\n");
    
    printf("Digite o valor da base (x): ");
    scanf("%d", &x);
    
    printf("Digite o valor do expoente (y): ");
    scanf("%d", &y);
    
    printf("O resultado de %d elevado a %d é: %d", x, y, pot(x, y));
    

    return 0;
}