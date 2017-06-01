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


int alfabeto[26] = {0}; // fazendo assim, inicializamos todas as posicoes como sendo 0, só funciona quando o valor é 0

int main(void) {
	char matricula[9];
//	criarMatricula("arthur", matricula);
//	int i = 0;
//	for (i = 0; i < 9; i++){
//		printf("%c", matricula[i]);
//	}
	setbuf(stdout, NULL);
	aluno testeAluno;
    aluno teste2;
    aluno teste3;
	ListItem *lista = criaLista();


    strcpy(testeAluno.alunoDados.nome,"Arthur");
    criarMatricula(testeAluno.alunoDados.nome, matricula, alfabeto);
	strcpy(testeAluno.alunoDados.matricula,matricula);
    strcpy(testeAluno.alunoDados.email,"arthurclp@icloud.com");
	testeAluno.alunoDados.telefone	= 12312312321;

    strcpy(teste2.alunoDados.nome,"Amanda");
    criarMatricula(teste2.alunoDados.nome, matricula, alfabeto);
    strcpy(teste2.alunoDados.matricula,matricula);
    strcpy(teste2.alunoDados.email,"amanda2@icloud.com");
    teste2.alunoDados.telefone	= 12312312321;


    strcpy(teste3.alunoDados.nome,"Imanda");
    criarMatricula(teste3.alunoDados.nome, matricula, alfabeto);
    strcpy(teste3.alunoDados.matricula,matricula);
    strcpy(teste3.alunoDados.email,"amanda2@icloud.com");
    teste3.alunoDados.telefone	= 12312312321;

	inserir(lista,testeAluno);
    inserir(lista,teste2);
    inserir(lista,teste3);
	imprimirLista(lista);
	return 0;
}
