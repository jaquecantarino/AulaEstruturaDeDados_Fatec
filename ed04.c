#include <stdio.h>

/* 1- Reescreva o programa do caixa eletrônico utilizando ponteiro de funções. */
int main(int argc, char *argv[]){
    
    int op;
    float saldo, saque, dep;
    
    printf("Informe o valor do saldo em conta: R$ ");
    scanf("%f", &saldo);
        
    float *p = &saldo;
    
	do{
	    printf("Escolha a operação que deseja realizar: ");
	    printf("\nDigite 1 para Saldo. ");
	    printf("\nDigite 2 para Saque. ");
	    printf("\nDigite 3 para Depósito. ");
	    printf("\nDigite a opção desejada: ");
	    scanf("%i", &op);
	    
	    switch(op){
	        case 1:{
	            printf("O valor do seu saldo é: R$ %2.2f\n", *p);
	            break;
	        }
	        case 2:{
	            printf("Informe o valor para saque: R$ ");
                scanf("%f", &saque);
                if(*p >=saque){
                    *p = *p - saque;
                    printf("Saque realizado com sucesso!\nSaldo Atualizado: R$ %2.2f\n", *  p);
                } else{
                    printf("Saldo Insuficiente!");
                }
	            break;
	        }
	        case 3:{
	            printf("Informe o valor para deposito: R$ ");
                scanf("%f", &dep);
                *p = *p + dep;
                printf("Deposito realizado com sucesso!\nSaldo Atualizado: R$ %2.2f\n", saldo);
	            break;
	        }
	        default: {
	            printf("Opção Inválida!");
	        }
	    }
	    printf("\nAperte 1 para continuar ou 0 para sair: ");
	    scanf("%i", &op);
	}while(op==1);

    return 0;
}

/* 2- Crie um programa em C que adicione dinamicamente uma nova posição e um vetor. */

int main(int argc, char *argv[]) {
    
	int d, c; 
	float *p, media; 
	
	printf("Informe a quantidade de dias: ");
	scanf("%i", &d);
	
	p = (float*) malloc (d * sizeof(float));
	for(c = 0; c < d; c++){
		printf("\nInforme a quantidade de clientes do %iº dia: ", c+1);
		scanf("%f", &p[c]);
		media += p[c];
	}
	media = media / d;
	printf("\nMédia de clientes = %2.2f, referente a quantidade de %i dias analisados", media, d);
	
	free(p);
	
	return 0;
}
