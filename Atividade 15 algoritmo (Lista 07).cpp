#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	char letras[30], letra;
	int quantidadeLetras = 0, i;
	
	printf("Insira '#' para parar a digita��o de caracteres\n\n");
	// Nesse trecho do c�digo a gente pede todos os caracteres usados para popular o vetor de caracteres.
	for(i=0; i<30;i++){
		printf("Insira a %i� letra: ", i+1);
		scanf("%c", &letra);
		fflush(stdin);
		
		if(letra == '#'|| quantidadeLetras > 30) break;
		else letras[i] = letra;
		
		quantidadeLetras++;
	}
	
	// Ordenar do maior para o menor
	// A < Z
	
	// Usando abaixo o algoritmo de ordena��o ensinado na aula:
	char letraNaPosicaoJ;
	for(int i = 0; i < quantidadeLetras; i++){
		for(int j = 0; j < quantidadeLetras; j++){
			//  Caso o letras na posi��o i seja maior que a letras na posi��o j, as posi��es s�o trocadas para que o maior sempre esteja no in�cio.
			if(letras[i] > letras[j]){
				letraNaPosicaoJ = letras[j];
				letras[j] = letras[i];
				letras[i] = letraNaPosicaoJ;
			}
		}
	}
	
	printf("Letras ordenadas: [");
	for(int k = 0; k<quantidadeLetras-1; k++){
		printf("%c, ", letras[k]);
	}
	printf("%c]", letras[quantidadeLetras-1]);
	
	system("Pause");
	system("cls");
	
	bool possuiOCaracterPesquisado;
	char caracterPesquisado;
	printf("Pesquise um caracter: ");
	scanf("%c", &caracterPesquisado);
	
	possuiOCaracterPesquisado = false;
	
	printf("O caracter pesquisado se encontra: \n");
	for(i = 0; i < quantidadeLetras; i++){
		if(letras[i] == caracterPesquisado) {
			printf("- Na posi��o %i", i);
			possuiOCaracterPesquisado = true;	
		}
	}
	
	if(!possuiOCaracterPesquisado) printf("O caracter pesquisado n�o se encontra na lista.");
}
    return 0;
