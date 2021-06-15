#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int matriculaFuncional[50];
	int mesesTrabalho[50];
	int matricula, meses, quantidadeFuncionarios = 0, i, j, troca;
	bool contratadosNoMesmoMes, mesmaMatricula;
	
	printf("Insere 0 na matrícula para encerrar o cadastro de funcionários:\n\n");
	for(i = 0; i<50; i++){
		
		contratadosNoMesmoMes = false;
		mesmaMatricula = false;
		
		printf("Insere a matrícula do funcionário:");
		scanf("%i", &matricula);
		if(matricula == 0) break;
		
		for(int j = 0; j < quantidadeFuncionarios; j++)
			if(matricula == matriculaFuncional[j]) mesmaMatricula = true;
			
		printf("Agora, insere quantos meses de trabalho ele tem: ");
		scanf("%i", &meses);		

		for(int j = 0; j < quantidadeFuncionarios; j++)
			if(meses == mesesTrabalho[j]) contratadosNoMesmoMes = true;
			
			// Se não foram contratados no mesmo mês nem tem a mesma matrícula, o sistema permite o cadastro do funcionário.
		if(!mesmaMatricula && !contratadosNoMesmoMes){
			mesesTrabalho[quantidadeFuncionarios] = meses;
			matriculaFuncional[quantidadeFuncionarios] = matricula;
			quantidadeFuncionarios++;
		} else {
			printf("Erro... Não conseguimos adicionar o funcionário, pois sua matrícula já está cadastrada ou foi admitido no mesmo mês que outro funcionário.\n\n");
		}
	}
	
	//	Nesse código aqui eu estou ordenando os inteiros em ordem crescente, para que os 3 menores valores ocupem as 3 primeiras posições.
	for(i = 0; i< quantidadeFuncionarios; i++){
		for(j = 0; j< quantidadeFuncionarios; j++){
			if(mesesTrabalho[i] < mesesTrabalho[j]){
				//trocar não só os meses de trabalho como também a matrícula para que a matrícula continue na mesma posição que os meses de trabalho.
				troca = mesesTrabalho[i];
				mesesTrabalho[i] = mesesTrabalho[j];
				mesesTrabalho[j] = troca;
				
				troca = matriculaFuncional[i];
				matriculaFuncional[i] = matriculaFuncional[j];
				matriculaFuncional[j] = troca;
			}
		}
	}
	
	// Nessa parte eu limpo a tela e imprimo as 3 primeiras posições dos vetores matricula funcional e meses de trabalho associando elas.	
	system("cls");
	printf("=====Funcionários admitidos mais cedo:=====\n\n");
	for(i = 0; i< 3; i++)
		printf("Funcionário %i, com %i mes(es) de trabalho\n", matriculaFuncional[i], mesesTrabalho[i]);	
	
}
     return 0;
