#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	int dados[100];
	
	for(int i = 0; i < 100; i++){
		printf("Insira o próximo número: ");
		scanf("%i", &dados[i]);
}
    int somatorio = 0;
    for(int j =0; j < 100; j++){
    	somatorio = somatorio + dados[j];
    }
    system("cls");
    printf("A soma dos valores inseridos é igual a %i", somatorio);
}
