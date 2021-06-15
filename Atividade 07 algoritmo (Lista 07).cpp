#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	float precos[100];
	float precosAumentados[100];
	char desejaContinuar;
	float percentual;
	float preco;
	int quantidadeElementos = 0;
	
	printf("DIGITE UM NÚMERO MENOR QUE ZERO PARA FINALIZAR O CADASTRO DE CDs \n\n");
	for(int i = 0; i<100; i++){
		printf("Digite o preço do CD: ");
		scanf("%f", &preco);
		fflush(stdin);
		
		if(preco < 0) break;
		else {
			precos[i] = preco;
			quantidadeElementos++;
		}
	}
	
	int opcao;
	
	system("cls");
	printf("==================Menu Principal===============\n\n");
	printf("[1] - Aumento de 10%% no preço de todos os discos\n");
	printf("[2] - Aumento da porcentagem personalizada do preço de todos os discos\n");
	printf("[3] - Sair do programa.\n\n");
	printf("Digite a sua opção: ");
	scanf("%i", &opcao);
	printf("\n\n");
	
	if(opcao == 1)
		percentual = 10.00;
	else if(opcao == 2){
		printf("Digite o percentual que você quer aumentar no preço dos discos: ");
		scanf("%f", &percentual);
	} else if(opcao == 3) return 0;
	else printf("Opção não identificada.");
	
	printf("\n\n");
	for(int contador = 0; contador < quantidadeElementos; contador++){
		precosAumentados[contador] = ((precos[contador] * percentual)/100) + precos[contador]; 
	}
	
	printf("==================RESULTADO================\n");
	printf("Percentual de aumento: %.2f%%\n\n", percentual);
	printf("Tabela de aumento:\n\n");
	
	printf("========================================\n");
	printf("| Preço inicial | Preço após o aumento |\n");
	for(int j = 0; j<quantidadeElementos; j++){
		printf("| %13.2f | %20.2f |\n", precos[j], precosAumentados[j]);
	}
	printf("========================================\n");
}
    return 0;
