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
//	char inicial[2];
	char matricula[9];
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

void menu ();

ListItem* criaLista ();

void inserir(ListItem *lista, aluno novoAluno);

void cadastrarAluno(ListItem *lista, int *alfabeto);
int posicaoAlfabeto (char letra);

void relatorioAlunosReprovados(ListItem *lista); // alterar
void imprimirReprovados(aluno *Aluno, int notaFinal); //adicionar

void relatorioAlunosAprovados(ListItem *lista);
void imprimirAprovados(aluno *Aluno, int notaFinal);

void imprimirRelatorioAlunos(aluno *Aluno, int notaFinal);
void relatorioAlunos(ListItem *Lista);


void criarMatricula (char *nomeAluno, char *matricula, int *alfabeto);

#endif /* AAI_H_ */
