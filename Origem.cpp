#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tipo_aluno
{
	char nome_aluno[50];
	int materia_aluno[20];
};

struct tipo_professor
{
	char nome_professor[50];
	char materia_professor[20];
};

struct tipo_materia
{
	char nome[50];
	int alunos[20];
	int professores[20];
};

void alunos();
void professores();

void  main()
{
	tipo_aluno aluno[20];
	tipo_professor professor[20];
	tipo_materia materia[20];

	int opcao;

	printf("\nBem Vindo ao PUC Sis!");
	printf("\nPara opcoes Aluno Digite 01");
	printf("\nPara opcoes Professores Digite 02\n");

	scanf("%i", &opcao);

	switch (opcao)
	{
	case 1: alunos();
		break;
	case 2: professores();
		break;
	default: printf("Opcao invalida");
	}

	
	printf("dfghbj");

	system("pause");
}

void alunos()
{
	
}

void professores()
{

}