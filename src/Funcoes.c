/*
 * Funcoes.c
 *
 *  Created on: 23 de mai de 2017
 *      Author: n225733701
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "AAI.h"

//int alfabeto[26] = {0}; // fazendo assim, inicializamos todas as posicoes como sendo 0, só funciona quando o valor é 0

int posicaoAlfabeto (char letra){
	return (int)letra - (int) 'A' + 1;
}

void criarMatricula (char *nomeAluno, char *matricula, int *alfabeto) // Receber como parametro um nome de aluno
{
    char posicao2e3[3];
    char posicao4e5[3];
    char posicao6e7[3];
    char posicao8[2];
    char inicial = toupper((int) nomeAluno[0]);
    int contVerificador;
	int i;

    // digito 1
    matricula[0] = inicial;
    matricula[1] = '\0';

    // 2 e 3 digitos
    int ascii = (int)inicial;
    snprintf(posicao2e3, 3, "%d", ascii);
    strcat(matricula, posicao2e3);

    // 4 e 5 digitos
    int posAlfabeto = posicaoAlfabeto(inicial);
    if (posAlfabeto < 10){
        posicao4e5[0] = '0';
        sprintf(&posicao4e5[1], "%d", posAlfabeto);

    }else{
        snprintf(posicao4e5,3, "%d", posAlfabeto); // temos que lembrar sempre do \0 quando se trata de string
    }
    matricula[5] = '\0';
    strcat(matricula, posicao4e5);
    //matricula[8] = '\0';


    // 6 e 7 digitos
	alfabeto[posAlfabeto -1]++; // incrementando array -> colocamos aqui, pois começamos o array com 0
	int contagemAlunos = alfabeto[posAlfabeto - 1];
	if (contagemAlunos < 10){
		matricula[5] = '0';
		sprintf(&matricula[6],"%d",contagemAlunos);
		matricula[7] = '\0';

	}else{
		snprintf(posicao6e7,3,"%d",contagemAlunos);
		strcat(matricula, posicao6e7);
	}


	int somasVerificador = 0;
	int  verificador;
	for (i = 1; matricula[i] != '\0';i++){
		somasVerificador += ((int)matricula[i] - (int)'0')*(i * 5);
	}
	verificador = somasVerificador % 11;

	if (verificador == 10){
		matricula[7] = '0';
		matricula[8] = '\0';
	}else{

		sprintf(posicao8,"%d",verificador);
		strcat(matricula, posicao8);
	}


}


ListItem* criaLista (){
	ListItem *lista = (ListItem*) malloc (sizeof(ListItem));
	lista->proxItem = NULL;

	return lista;
}

void inserir(ListItem *lista, aluno novoAluno){
	if(!lista){
		printf("Erro de memoria");
		exit(1);
	}
	ListItem *novo = (ListItem*) malloc(sizeof(ListItem));

	if(!novo){
		printf("Erro de memoria");
		exit(1);
	}

	novo->conteudo = novoAluno;
	novo->proxItem = NULL;


	if(lista->proxItem == NULL){
		lista->proxItem = novo;
	}else{
		ListItem *tmp = lista->proxItem;

		while(tmp->proxItem != NULL){
			tmp = tmp->proxItem;
		}

		tmp->proxItem = novo;
	}

}

void imprimirLista (ListItem *lista){

	if(!lista){
		printf("Erro de memoria");
		exit(1);
	}


	ListItem *tmp = lista;

	while(tmp->proxItem != NULL){
		printf("\n%s",tmp->proxItem->conteudo.alunoDados.nome);
		printf("\n%s",tmp->proxItem->conteudo.alunoDados.email);
		printf("\n%s",tmp->proxItem->conteudo.alunoDados.matricula);
		printf("\n-----------------\n");
		tmp = tmp->proxItem;
	}
}

void cadastrarAluno(ListItem *lista,  int *alfabeto){

	dadosAluno novoAluno;
	aluno aluno;
    char matricula[9];
	//Inserção de Dados Cadastrais
	do{
		printf("\nDigite o Nome do Aluno: ");
		fflush(stdin);
		gets(novoAluno.nome);

		if (strlen(novoAluno.nome) == 0){
			printf("\nPreencha o Nome.");
		}
	} while (strlen(novoAluno.nome) == 0);

	do{
		printf("\nDigite o E-mail do Aluno: ");
		fflush(stdin);
		gets(novoAluno.email);
		if ((strstr(novoAluno.email, "@") == NULL) || (strstr(novoAluno.email, ".") == NULL)) {
			printf("\nDigite um e-mail valido.");
		}
	} while ((strstr(novoAluno.email, "@") == NULL) || (strstr(novoAluno.email, ".") == NULL));

    do {
        printf("\nDigite o DDD+Telefone: ");
        fflush(stdin);
        scanf("%li", &novoAluno.telefone);

        if(novoAluno.telefone <= 0){
            printf("Telefone invalido.");
        }
    }while(novoAluno.telefone <= 0);
	//Inserção de Notas
	do {
		printf("\nDigite a nota da prova 1: ");
		fflush(stdin);
		scanf("%f", &aluno.prova1);
		if (aluno.prova1 < 0 || aluno.prova1 > 35) {
			printf("\nNota Invalida. ");
		}
	} while (aluno.prova1 < 0 || aluno.prova1 > 35);

	do {
		printf("\nDigite a nota da prova 2: ");
		fflush(stdin);
		scanf("%f", &aluno.prova2);
		if (aluno.prova2 < 0 || aluno.prova2 > 35) {
			printf("\nNota Invalida. ");
		}
	} while (aluno.prova2 < 0 || aluno.prova2 > 35);

	do {
		printf("\nDigite a nota total dos trabalhos: ");
		fflush(stdin);
		scanf("%f", &aluno.trabalhos);
		if (aluno.trabalhos < 0 || aluno.trabalhos > 30) {
			printf("\nNota Invalida. ");
		}
	} while (aluno.trabalhos < 0 || aluno.trabalhos > 30);

    criarMatricula(novoAluno.nome, matricula,alfabeto);
    strcpy(novoAluno.matricula,matricula);
	aluno.alunoDados = novoAluno;

	inserir(lista, aluno);
}

void imprimirReprovados(aluno *Aluno, int notaFinal){


        printf("\n-> A Nota Final do Aluno: %s || Matricula: %s ", Aluno->alunoDados.nome, Aluno->alunoDados.matricula);
        printf("\n   foi: %d, infelizmente abaixo da Media de 60%%", notaFinal);
        printf("\n-----------------\n");
}

void relatorioAlunosReprovados(ListItem *lista){
	ListItem *tmp = lista;
	float somatorio;

	if(!lista){
		printf("Erro de memoria");
		exit(1);
	}

	while(tmp->proxItem != NULL){
		somatorio = tmp->proxItem->conteudo.prova1 + tmp->proxItem->conteudo.prova2 + tmp->proxItem->conteudo.trabalhos;
		if(somatorio < 60){
			imprimirReprovados(&tmp->conteudo, somatorio);
		}
		tmp = tmp->proxItem;

	}
}


