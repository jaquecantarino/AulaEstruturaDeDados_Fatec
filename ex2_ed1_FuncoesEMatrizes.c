#include <stdio.h>
#include <stdlib.h>

/* crie um program em linguagem C que crie uma matriz de 10,3 armazene a nota P1, P2 
e MEDIA nas respectivas colunas, crime uma fun��o passando a matriz como parametro
 para identificar a maiorNotaP1, a maiorNotaP2 e a maiorMedia e mediaSala */

float notas[10][3];

float maiorNotaP1(){
	float maior; //armazena nota maior
	int x; //contador
	for(x=0;x<10;x++){
		if(x==0){
			maior = notas[0][0]; //armazena o valor do primeiro registro para comparar no resto	
		} else {
			if(notas[x][0] > maior)	maior = notas[x][0]; //compara se o proximo registro é maior que o armazenado como maior
		}
	}	
	return maior; // retorna a maior nota armazenada
}

float maiorNotaP2(){
	float maior;
	int x;
	for(x=0;x<10;x++){
		if(x==0){
			maior = notas[0][1];	
		} else {
			if(notas[x][1] > maior) maior = notas[x][1]; 
		}
	}	
	return maior;
}

float maiorMedia(){
	float maior;
	int x;
	for(x=0;x<10;x++){
		if(x==0){
			maior = notas[0][2];	
		} else {
			if(notas[x][2] > maior) maior = notas[x][2]; 
		}
	}	
	return maior;
}

float mediaSala(){
float media=0;
	int x; // contador
	for(x=0;x<10;x++){
		media += notas[x][2]; // soma media a media todos os dados da matriz
	}	
	media = media / 10; // pega todas as medias e divide por 10 que seria a maior nota possivel
	return media;
}


int main(int argc, char *argv[]) {
	int x;
	for(x=0; x<10; x++){
		printf("Informe nota p1 e nota p2:");
		scanf("%f %f", &notas[x][0], &notas[x][1]); //armazena em cada lugar da matriz conforme o laço rodar
		notas[x][2] = (notas[x][0]+notas[x][1])/2; // soma as duas notas recebidas e calcula a média
	}
	// chama as funções e as exibe. O %.2 indica que vamos usar só 2 numero pós virgula
	printf("Maior nota p1=%.2f \n", maiorNotaP1());
	printf("Maior nota p2=%.2f \n", maiorNotaP2());
	printf("Maior media=%.2f \n", maiorMedia());
	printf("Media da sala=%.2f \n", mediaSala());	
	return 0;
}
