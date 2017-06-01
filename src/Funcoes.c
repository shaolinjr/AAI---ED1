/*
 * Funcoes.c
 *
 *  Created on: 23 de mai de 2017
 *      Author: n225733701
 */
#include <stdio.h>
#include <stdlib.h>
#include "AAI.h"


void criarMatricula (char *nomeAluno, char *matricula) // Receber como parametro um nome de aluno
{
//    char posicaoUm;
    char posicao2e3[3];
    char posicao4e5[3];
    char posicao6e7[3];
    char posicao8;
    char inicial = toupper((int) nomeAluno[0]);
    int contVerificador;
    int somasVerificador[6];

    // digito 1
    matricula[0] = inicial;
    matricula[1] = '\0';

    // 2 e 3 digitos
    int ascii = (int)inicial;
    snprintf(posicao2e3, 3, "%d", ascii);
    strcat(matricula, posicao2e3);

    // 4 e 5 digitos
    int posicaoAlfabeto = (int)inicial - (int)'A' + 1;
    if (posicaoAlfabeto < 10){
        posicao4e5[0] = '0';
        sprintf(&posicao4e5[1], "%d", posicaoAlfabeto);

    }else{
        snprintf(posicao4e5,3, "%d", posicaoAlfabeto); // temos que lembrar sempre do \0 quando se trata de string
    }
    matricula[5] = '\0';
    strcat(matricula, posicao4e5);
    //matricula[8] = '\0';


    // 6 e 7 digitos
    // temos que iterar sobre a lista de alunos
    // verificar o atributo inicial do aluno e ver se é igual o inicial dessa funçao
    // a cada igualdade, icrementamos o contador, que representará os 6 e 7 digitos

}

void adicionarDigitoVerificador (char *matricula){
    int i;
    int somasVerificador = 0;
    int verificador = somasVerificador % 11;
    for (i = 1; matricula[i] != '\0';i++){
       somasVerificador += ((int)matricula[i] - (int)'0')*(i * 5);
    }

    if (verificador == 10){
        matricula[i] = '0';
    }else{

        sprintf(&matricula[i],"%d",verificador);
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
	ListItem *tmp = lista;

	while(tmp->proxItem != NULL){
		printf("\n%s",tmp->proxItem->conteudo.alunoDados.nome);
		printf("\n%s",tmp->proxItem->conteudo.alunoDados.email);
		printf("\n-----------------\n");
		tmp = tmp->proxItem;
	}
}

//void cadastrarAluno(ListItem *lista){
//
//	dadosAluno novoAluno;
//	aluno aluno;
//
//	do{
//		printf("\nDigite o Nome do Aluno: ");
//		fflush(stdin);
//		gets(novoAluno.nome);
//
//		if (strlen(novoAluno.nome) == 0){
//			printf("\nPreencha o Nome.");
//		}
//	} while (strlen(novoAluno.nome) == 0);
//
//	do{
//		printf("\nDigite o E-mail do Aluno: ");
//		fflush(stdin);
//		gets(novoAluno.email);
//		if (strstr(novoAluno.email, "@") == NULL) {
//			printf("\nDigite um e-mail válido.");
//		}
//	} while (strstr(novoAluno.email, "@") == NULL);
//
//	printf("\nDigite o DDD+Telefone: ");
//	fflush(stdin);
//	scanf("&l",&novoAluno.telefone);
//
//	aluno.alunoDados = novoAluno;
//
//	inserir(lista, aluno);
//}

