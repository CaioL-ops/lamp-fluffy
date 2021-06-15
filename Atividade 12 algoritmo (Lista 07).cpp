#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int matriculaFuncional[50];
	int mesesTrabalho[50];
	int matricula, meses, quantidadeFuncionarios = 0, i, j, troca;
	bool contratadosNoMesmoMes, mesmaMatricula;
	
	printf("Insere 0 na matr�cula para encerrar o cadastro de funcion�rios:\n\n");
	for(i = 0; i<50; i++){
		
		contratadosNoMesmoMes = false;
		mesmaMatricula = false;
		
		printf("Insere a matr�cula do funcion�rio:");
		scanf("%i", &matricula);
		if(matricula == 0) break;
		
		for(int j = 0; j < quantidadeFuncionarios; j++)
			if(matricula == matriculaFuncional[j]) mesmaMatricula = true;
			
		printf("Agora, insere quantos meses de trabalho ele tem: ");
		scanf("%i", &meses);		

		for(int j = 0; j < quantidadeFuncionarios; j++)
			if(meses == mesesTrabalho[j]) contratadosNoMesmoMes = true;
			
			// Se n�o foram contratados no mesmo m�s nem tem a mesma matr�cula, o sistema permite o cadastro do funcion�rio.
		if(!mesmaMatricula && !contratadosNoMesmoMes){
			mesesTrabalho[quantidadeFuncionarios] = meses;
			matriculaFuncional[quantidadeFuncionarios] = matricula;
			quantidadeFuncionarios++;
		} else {
			printf("Erro... N�o conseguimos adicionar o funcion�rio, pois sua matr�cula j� est� cadastrada ou foi admitido no mesmo m�s que outro funcion�rio.\n\n");
		}
	}
	
	//	Nesse c�digo aqui eu estou ordenando os inteiros em ordem crescente, para que os 3 menores valores ocupem as 3 primeiras posi��es.
	for(i = 0; i< quantidadeFuncionarios; i++){
		for(j = 0; j< quantidadeFuncionarios; j++){
			if(mesesTrabalho[i] < mesesTrabalho[j]){
				//trocar n�o s� os meses de trabalho como tamb�m a matr�cula para que a matr�cula continue na mesma posi��o que os meses de trabalho.
				troca = mesesTrabalho[i];
				mesesTrabalho[i] = mesesTrabalho[j];
				mesesTrabalho[j] = troca;
				
				troca = matriculaFuncional[i];
				matriculaFuncional[i] = matriculaFuncional[j];
				matriculaFuncional[j] = troca;
			}
		}
	}
	
	// Nessa parte eu limpo a tela e imprimo as 3 primeiras posi��es dos vetores matricula funcional e meses de trabalho associando elas.	
	system("cls");
	printf("=====Funcion�rios admitidos mais cedo:=====\n\n");
	for(i = 0; i< 3; i++)
		printf("Funcion�rio %i, com %i mes(es) de trabalho\n", matriculaFuncional[i], mesesTrabalho[i]);	
	
}
     return 0;
