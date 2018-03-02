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

void alunos(tipo_aluno aluno[50], tipo_materia materia[50]);
void professores(tipo_professor professor[50]);

int  main()
{
	tipo_aluno aluno[50];
	tipo_materia materia[50];
	tipo_professor professor[50];

	int opcao;

	printf("\nBem Vindo ao PUC Sis!");
	printf("\nPara opcoes Aluno Digite 01");
	printf("\nPara opcoes Professores Digite 02\n");

	scanf("%i", &opcao);

	switch (opcao)
	{
	case 1: alunos(aluno, materia);
		break;
	case 2: professores(professor);
		break;
	default: printf("Opcao invalida");
	}

	system("pause");
}

void alunos(tipo_aluno aluno[50], tipo_materia materia[50])
{
	int i;
	int opcao;
	int qtd_aluno=0;
	int qtd_professor=0;
	int qtd_materia=0;

	char aux[50];

	printf("Digite 1 para cadastrar aluno");
	printf("Digite 2 para realizar matriculas");
	printf("Digite 4 para menu de impressao");

	scanf("%i", &opcao);

	switch (opcao)
	{

	case 1: 
	{
		printf("Digite o nome do aluno a ser cadastrado: ");
		scanf("%s \n", &aluno[qtd_aluno].nome_aluno);
		printf("Digite a materia que gostaria de cadastra-lo: ");
		scanf("%s \n", &aux);

		for (i = 0; i < 50; i++)
		{
			if (strcmp(aux, materia[i].nome) == 0)
			{
				aluno[qtd_aluno].materia_aluno[i] = 1;
				printf("Aluno cadastrado com sucesso!");
			}
			
			if(i==49)
			{
				printf("Materia nao encontrada!");
			}
		}


	}
	default:
		printf("Opcao invalida!");
		break;
	}

}

void professores(tipo_professor professor[50])
{

}