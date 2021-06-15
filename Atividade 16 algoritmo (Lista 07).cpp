#include<stdio.h>
#include<locale.h>


int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int contador;
	int a[10], b[10], c[10][10];
	
	printf("==== Preenchendo o vetor A =====\n\n");
	for(contador = 0; contador < 10; contador++){
		printf("Digite a posição %i do vetor a: ", contador);
		scanf("%i", &a[contador]);
	}
	printf("\n\n");
	
	printf("==== Preenchendo o vetor B =====\n\n");
	for(contador = 0; contador < 10; contador++){
		printf("Digite a posição %i do vetor b: ", contador);
		scanf("%i", &b[contador]);
	}
	printf("\n\n");		
	
	for(int i = 0; i<10; i++){
		for(int j = 0; j<10; j++){
			c[i][j] = a[i] + b[j];
		}
	}
	
	int linha, coluna;
	
	printf("==== Apresentando o vetor c ====\n\n");
	for(linha = 0; linha < 10; linha++){
		printf("[");
		for(coluna = 0; coluna<9; coluna++){
			printf("%3i, ", c[linha][coluna]);
		}
		printf("%3i]\n", c[linha][9]);
	}
	
	int valor, posicaoLinha, posicaoColuna;
	printf("\n\n");
	printf("Pesquise um valor: ");
	scanf("%i", &valor);
	
	for(linha = 0; linha < 10; linha++){
		for(coluna = 0; coluna<10; coluna++){
			if(c[linha][coluna] == valor){
				printf("O valor digitado aparece na linha %i e na coluna %i\n", linha, coluna);
			}
		}
	}
	
}
    return 0;
