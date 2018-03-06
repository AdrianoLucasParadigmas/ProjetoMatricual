#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>


struct tipo_qtd
{
	int alunos = 0;
	int professor = 0;
	int materias = 0;
};

struct tipo_aluno
{
	char nome[50];
	int RA;
};

struct tipo_professor
{
	char nome[50];
};

struct tipo_materia
{
	char nome[50];
	int aluno[50] = { 0 };
	int professor[50] = { 0 };
};

void cadastro_aluno(tipo_aluno aluno[], tipo_qtd *qtd);
void cadastro_materia(tipo_materia materia[], tipo_qtd *qtd);
void cadastro_professor(tipo_professor professor[], tipo_qtd *qtd);
void matricula(tipo_aluno aluno[], tipo_materia materia[], tipo_qtd *qtd);



void impressao();


void main()
{
	tipo_qtd qtd;
	tipo_aluno aluno[50];
	tipo_professor professor[50];
	tipo_materia materia[50];
	
	int opc = 9;

	while (opc != 0)
	{
		system("cls");
		printf("Digite o numero da opcao desejada:\n");
		printf("1-Cadastrar alunos\n");
		printf("2-Cadastrar disciplinas\n");
		printf("3-Cadastrar professores\n");
		printf("4-Realizar matricula\n");
		printf("5-Cancelar matricula\n");
		printf("6-Vincular professores a disciplinas\n");
		printf("7-Remover vinculo de professores a disciplinas\n");
		printf("8-Menu de impressao\n");
		printf("9-sair\n");
		scanf("%i", &opc);

		switch (opc)
		{
		case 1:
			cadastro_aluno(aluno, &qtd);
			break;

		case 2:
			cadastro_materia(materia, &qtd);
			break;

		case 3:
			cadastro_professor(professor, &qtd);
			break;
		case 4:
			matricula(aluno, materia, &qtd);
			break;
		default:
			printf("Opcao invalida!");
			break;
		}
	}

	/*{
	printf("Digite o nome de um aluno\n");
	gets_s(aluno[1].nome);
	qtd.alunos++;

	printf("Digite o nome de uma materia\n");
	gets_s(materia[1].nome);
	qtd.materias++;

	printf("Digite o nome de um professor\n");
	gets_s(professor[1].nome);
	qtd.professor++;

	strcpy(aluno[1].nome, "");
	strcpy(aluno[2].nome, "");
	strcpy(aluno[3].nome, "");
	strcpy(aluno[4].nome, "");

	strcpy(materia[1].nome, "Fisica");
	materia[1].aluno[1] = 0;
	materia[1].aluno[2] = 1;
	materia[1].aluno[3] = 0;
	materia[1].aluno[4] = 1;
	}*/
}



void cadastro_aluno(tipo_aluno aluno[], tipo_qtd *qtd)
{
	int qtd_cadastros = 0;
	system("cls");
	printf("Digite a quantida de alunos que deseja cadastrar\n");
	scanf("%i", &qtd_cadastros);
	scanf("%c");
	for (int i = 0; i < qtd_cadastros; i++)
	{
		printf("Digite o nome do aluno:\n");
		gets_s(aluno[i].nome);
		qtd->alunos++;
		printf("%i", qtd->alunos);
	}
	printf("Cadastro realizado com sucesso!\n");
	printf("Pressine qualquer tecla para voltar ao menu\n");
	scanf("%c");
}


void cadastro_materia(tipo_materia materia[], tipo_qtd *qtd)
{
	int qtd_cadastros = 0;
	system("cls");
	printf("Digite a quantida de materias que deseja cadastrar\n");
	scanf("%i", &qtd_cadastros);
	scanf("%c");
	for (int i = 0; i < qtd_cadastros; i++)
	{
		printf("Digite o nome da materia:\n");
		gets_s(materia[i].nome);
		qtd->materias++;
	}
	printf("Cadastro realizado com sucesso!\n");
	printf("Pressine qualquer tecla para voltar ao menu\n");
	scanf("%c");




}

void cadastro_professor(tipo_professor professor[], tipo_qtd *qtd)
{
	int qtd_cadastros = 0;
	system("cls");
	printf("Digite a quantida de professores que deseja cadastrar\n");
	scanf("%i", &qtd_cadastros);
	scanf("%c");
	for (int i = 0; i < qtd_cadastros; i++)
	{
		printf("Digite o nome do professor:\n");
		gets_s(professor[i].nome);
		qtd->professor++;
	}
	printf("Cadastro realizado com sucesso!\n");
	printf("Pressine qualquer tecla para voltar ao menu\n");
	scanf("%c");
}


void matricula(tipo_aluno aluno[], tipo_materia materia[], tipo_qtd *qtd)
{
	tipo_aluno aluno_tmp[50];
	tipo_materia materia_temp[50];
	int qtd_cadastros = 0, i,cont=0;

	printf("Digite a quantidade de alnos que deseja matricular:\n");
	scanf("%i", &qtd_cadastros);
	scanf("%c");

	for (i = 0; i < qtd_cadastros; i++)
	{
		printf("Digite o nome do aluno:\n");
		gets_s(aluno_tmp[i].nome);

		for (int j = 0; j < qtd->alunos; j++)
		{

		if (strcmp(aluno_tmp[i].nome, aluno[j].nome) == 0)
			{
				printf("Aluno encontrado!\n");
				//Sleep(1000);
				//system("cls");
				break;
			}

			if (j+1 == qtd->alunos)
			{
				printf("Erro! Aluno nao cadastrado\n");
				i--;
			}
		}
	}
	strcpy(aluno_tmp[i+1].nome, "\n");

	printf("Digite a quantidade de materias que os alunos serao matriculados:\n");
	scanf("%i", &qtd_cadastros);
	scanf("%c");


	for (int i = 0; i < qtd_cadastros; i++)
	{
		printf("Digite o nome da amteria:\n");
		gets_s(materia_temp[i].nome);

		for (int j = 0; j < qtd->materias; j++)
		{

			if (strcmp(materia_temp[i].nome, materia[j].nome)==0)
			{
				printf("Materia encontrada!\n");
				while (strcmp(aluno_tmp[cont].nome, "\n")!=0)
					{
					for (int ra = 0; ra < qtd->alunos; ra++)
						{
						if(strcmp(aluno_tmp[cont].nome,aluno[ra].nome)==0)
							materia[j].aluno[ra] = 1;
						}					
					cont++;
					}
				break;
			}

			if (j + 1 == qtd->materias)
			{
				printf("Erro! materia nao cadastrado\n");
				i--;
			}
		}
	}
}
void impressao()
{

}