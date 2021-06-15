#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	float reais[50];
	int quantidadeAlunos;
	
	printf("Insira o número de alunos:\n");
	scanf("%i", &quantidadeAlunos);
	
	if(quantidadeAlunos > 50 || quantidadeAlunos <= 0){
		printf("Valor não encontrado!");
}
    for(int i = 0; i < quantidadeAlunos; i++){
    	printf("Insira a nota do aluno nº%i: ", i+1);
    	scanf("%d", &reais[i]);
    	fflush(stdin);
    }
    printf("\n\nNotas recebidas!");
}
