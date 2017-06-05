/*
 ============================================================================
 Name        : AAI.c
 Author      : Arthur Pires, Bruno Azevedo, Diego Garcia e Igor Picorelli
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AAI.h"

// UNICA VARIAVEL GLOBAL
int alfabeto[26] = {0}; // fazendo assim, inicializamos todas as posicoes como sendo 0, só funciona quando o valor é 0

int main(void) {
	setbuf(stdout, NULL);

	ListItem *lista = criaLista();
	int opcao = 0;
	do {
		menu();
		fflush(stdin);
		printf("Digite sua opção: ");

		scanf(" %d",&opcao);

		if (opcao > 0 && opcao < 6){
			printf("Opcao invalida!\n");
		}

		switch(opcao) {
			case 1:
				cadastrarAluno(lista, alfabeto);
				break;
			case 2:
				relatorioAlunosAprovados(lista);
				break;
			case 3:
				relatorioAlunosReprovados(lista);
				break;
			case 4:
				relatorioAlunos(lista);
				break;
			case 5:
				printf("\nSaindo...");
				exit(1);
		}
	}while(opcao > 0 && opcao < 6);

	return 0;
}
