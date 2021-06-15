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
		
		printf("Insira a matr�cula do funcion�rio: ");
		scanf("%i", &matricula);		
		fflush(stdin);
		
		if(matricula == 0) break;
		
		for(int j = 0; j < quantidadeFuncionarios; j++)
			if(matricula == codigoFuncional[j]) mesmaMatricula = true;
			
		printf("Agora, insira o sal�rio do funcion�rio: ");
		scanf("%d", &salario);		
		fflush(stdin);
		
		if(!mesmaMatricula){
			salarios[quantidadeFuncionarios] = salario;
			codigoFuncional[quantidadeFuncionarios] = matricula;
			quantidadeFuncionarios++;
			if(salario > maiorSalario) maiorSalario = salario;
			if(salario < menorSalario) menorSalario = salario;
			somaSalarios = somaSalarios + salario;
		} else printf("Erro... N�o conseguimos adicionar o funcion�rio, pois sua matr�cula j� est� cadastrada!\n\n");
	}
	
	double mediaSalarial = somaSalarios / quantidadeFuncionarios;
	
	printf("O maior sal�rio � %d\n", maiorSalario);
	printf("E o menor sal�rio � %d\n", menorSalario);
	printf("A media salarial da empresa � igual a %d", mediaSalarial);
}
   return 0;
