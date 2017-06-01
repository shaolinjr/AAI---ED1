/*
 * AAI.h
 *
 *  Created on: 23 de mai de 2017
 *      Author: n225733701
 */

#ifndef AAI_H_
#define AAI_H_

typedef struct {
	char nome[50];
	char inicial[2];
	char matricula[8];
	char email[50];
	long telefone;
}dadosAluno;

typedef struct {
	dadosAluno alunoDados;
	float prova1;
	float prova2;
	float trabalhos;
}aluno;

struct item{
    aluno conteudo;
    struct item *proxItem;
};
typedef struct item ListItem;


ListItem* criaLista ();

void inserir(ListItem *lista, aluno novoAluno);
void imprimirLista (ListItem *lista);
void cadastrarAluno();

void relatorioAlunosAprovados(); // talvez passar a lista como parametro

void relatorioAlunosReprovados(); // talvez passar a lista como parametro

void relatorioGeral(); // talvez passar a lista como parametro

void criarMatricula (char *nomeAluno, char *matricula);

void adicionarDigitoVerificador (char *matricula);

#endif /* AAI_H_ */