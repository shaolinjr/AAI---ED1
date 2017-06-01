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
//#include <string.h>
#include "AAI.h"
int main(void) {
//	char matricula[9];
//	criarMatricula("arthur", matricula);
//	int i = 0;
//	for (i = 0; i < 9; i++){
//		printf("%c", matricula[i]);
//	}
	setbuf(stdout, NULL);
	aluno testeAluno;
    aluno teste2;
	ListItem *lista = criaLista();


    strcpy(testeAluno.alunoDados.nome,"Arthur");
    strcpy(testeAluno.alunoDados.inicial,"A");
	strcpy(testeAluno.alunoDados.matricula,"A6501012");
    strcpy(testeAluno.alunoDados.email,"arthurclp@icloud.com");
	testeAluno.alunoDados.telefone	= 12312312321;


    strcpy(teste2.alunoDados.nome,"Arthur2");
    strcpy(teste2.alunoDados.inicial,"A");
    strcpy(teste2.alunoDados.matricula,"A6501012");
    strcpy(teste2.alunoDados.email,"arthurclp2@icloud.com");
    teste2.alunoDados.telefone	= 12312312321;

	inserir(lista,testeAluno);
    inserir(lista,teste2);
	imprimirLista(lista);
	return 0;
}
