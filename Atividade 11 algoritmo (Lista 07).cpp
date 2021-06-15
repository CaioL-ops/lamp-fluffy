#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	int codigoFuncional[100];
	double salarios[100];
	int quantidadeFuncionarios = 0, matricula, i;
	bool mesmaMatricula;
	double salario;
	double menorSalario = 900000000;
	double maiorSalario = 0;
	double somaSalarios = 0;
	
	for(i = 0; i<100; i++){
		mesmaMatricula = false;
		
		printf("Insira a matrícula do funcionário: ");
		scanf("%i", &matricula);		
		fflush(stdin);
		
		if(matricula == 0) break;
		
		for(int j = 0; j < quantidadeFuncionarios; j++)
			if(matricula == codigoFuncional[j]) mesmaMatricula = true;
			
		printf("Agora, insira o salário do funcionário: ");
		scanf("%d", &salario);		
		fflush(stdin);
		
		if(!mesmaMatricula){
			salarios[quantidadeFuncionarios] = salario;
			codigoFuncional[quantidadeFuncionarios] = matricula;
			quantidadeFuncionarios++;
			if(salario > maiorSalario) maiorSalario = salario;
			if(salario < menorSalario) menorSalario = salario;
			somaSalarios = somaSalarios + salario;
		} else printf("Erro... Não conseguimos adicionar o funcionário, pois sua matrícula já está cadastrada!\n\n");
	}
	
	double mediaSalarial = somaSalarios / quantidadeFuncionarios;
	
	printf("O maior salário é %d\n", maiorSalario);
	printf("E o menor salário é %d\n", menorSalario);
	printf("A media salarial da empresa é igual a %d", mediaSalarial);
}
   return 0;
