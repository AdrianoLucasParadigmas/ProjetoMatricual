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
int cancelar_matricula(tipo_aluno aluno[], tipo_materia materia[], tipo_qtd *qtd);
void vinculacao(tipo_professor professor[], tipo_materia materia[], tipo_qtd *qtd);
void remover_vinculacao(tipo_professor professor[], tipo_materia materia[], tipo_qtd *qtd);
void impressao(tipo_aluno aluno[], tipo_materia materia[], tipo_professor professor[], tipo_qtd *qtd);


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

		if (opc == 9)
			break;

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
		case 5:
			cancelar_matricula(aluno, materia, &qtd);
			break;
		case 6:
			vinculacao(professor, materia, &qtd);
			break;
		case 7:
			remover_vinculacao(professor, materia, &qtd);
			break;
		case 8:
			impressao(aluno, materia, professor, &qtd);
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
		gets_s(aluno[qtd->alunos].nome);
		qtd->alunos++;
		//printf("%i", qtd->alunos);
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
	int qtd_cadastros = 0, i, cont = 0;
	system("cls");

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

			if (j + 1 == qtd->alunos)
			{
				printf("Erro! Aluno nao cadastrado\n");
				i--;
			}
		}
	}
	strcpy(aluno_tmp[i + 1].nome, "\n");

	printf("Digite a quantidade de materias que os alunos serao matriculados:\n");
	scanf("%i", &qtd_cadastros);
	scanf("%c");


	for (int i = 0; i < qtd_cadastros; i++)
	{
		printf("Digite o nome da materia:\n");
		gets_s(materia_temp[i].nome);

		for (int j = 0; j < qtd->materias; j++)
		{

			if (strcmp(materia_temp[i].nome, materia[j].nome) == 0)
			{
				printf("Materia encontrada!\n");
				cont = 0;
				while (strcmp(aluno_tmp[cont].nome, "\n") != 0)
				{
					for (int ra = 0; ra < qtd->alunos; ra++)
					{
						if (strcmp(aluno_tmp[cont].nome, aluno[ra].nome) == 0)
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

int cancelar_matricula(tipo_aluno aluno[], tipo_materia materia[], tipo_qtd *qtd)
{
	tipo_aluno aluno_tmp[50];
	tipo_materia materia_temp[50];
	int qtd_cadastros = 0, i, cont = 0;
	system("cls");

	printf("Digite a quantidade de alnos que deseja desmatricular:\n");
	scanf("%i", &qtd_cadastros);
	if (qtd_cadastros == 0)return(0);

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

			if (j + 1 == qtd->alunos)
			{
				printf("Erro! Aluno nao cadastrado\n");
				i--;
			}
		}
	}
	strcpy(aluno_tmp[i + 1].nome, "\n");

	printf("Digite a quantidade de materias que os alunos serao desmatriculados:\n");
	scanf("%i", &qtd_cadastros);
	scanf("%c");


	for (int i = 0; i < qtd_cadastros; i++)
	{
		printf("Digite o nome da materia:\n");
		gets_s(materia_temp[i].nome);

		for (int j = 0; j < qtd->materias; j++)
		{

			if (strcmp(materia_temp[i].nome, materia[j].nome) == 0)
			{
				printf("Materia encontrada!\n");
				cont = 0;
				while (strcmp(aluno_tmp[cont].nome, "\n") != 0)
				{
					for (int ra = 0; ra < qtd->alunos; ra++)
					{
						if (strcmp(aluno_tmp[cont].nome, aluno[ra].nome) == 0)
							materia[j].aluno[ra] = 0;
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

void vinculacao(tipo_professor professor[], tipo_materia materia[], tipo_qtd *qtd)
{
	tipo_professor professor_tmp[50];
	tipo_materia materia_temp[50];
	int qtd_cadastros = 0, i, cont = 0;
	system("cls");

	printf("Digite a quantidade de professores que deseja vincular:\n");
	scanf("%i", &qtd_cadastros);
	scanf("%c");

	for (i = 0; i < qtd_cadastros; i++)
	{
		printf("Digite o nome do professor:\n");
		gets_s(professor_tmp[i].nome);

		for (int j = 0; j < qtd->professor; j++)
		{

			if (strcmp(professor_tmp[i].nome, professor[j].nome) == 0)
			{
				printf("Professor encontrado!\n");
				//Sleep(1000);
				//system("cls");
				break;
			}

			if (j + 1 == qtd->professor)
			{
				printf("Erro! Professor nao cadastrado\n");
				i--;
			}
		}
	}
	strcpy(professor_tmp[i + 1].nome, "\n");

	printf("Digite a quantidade de materias que os professores serao vinculados:\n");
	scanf("%i", &qtd_cadastros);
	scanf("%c");


	for (int i = 0; i < qtd_cadastros; i++)
	{
		printf("Digite o nome da materia:\n");
		gets_s(materia_temp[i].nome);

		for (int j = 0; j < qtd->materias; j++)
		{

			if (strcmp(materia_temp[i].nome, materia[j].nome) == 0)
			{
				printf("Materia encontrada!\n");
				cont = 0;
				while (strcmp(professor_tmp[cont].nome, "\n") != 0)
				{
					for (int rp = 0; rp < qtd->professor; rp++)
					{
						if (strcmp(professor_tmp[cont].nome, professor[rp].nome) == 0)
							materia[j].professor[rp] = 1;
					}
					cont++;
				}
				break;
			}

			if (j + 1 == qtd->materias)
			{
				printf("Erro! materia nao cadastrada\n");
				i--;
			}
		}
	}
}
void remover_vinculacao(tipo_professor professor[], tipo_materia materia[], tipo_qtd *qtd)
{
	tipo_professor professor_tmp[50];
	tipo_materia materia_temp[50];
	int qtd_cadastros = 0, i, cont = 0;
	system("cls");

	printf("Digite a quantidade de professores que deseja desvincular:\n");
	scanf("%i", &qtd_cadastros);
	scanf("%c");

	for (i = 0; i < qtd_cadastros; i++)
	{
		printf("Digite o nome do professor:\n");
		gets_s(professor_tmp[i].nome);

		for (int j = 0; j < qtd->professor; j++)
		{

			if (strcmp(professor_tmp[i].nome, professor[j].nome) == 0)
			{
				printf("Professor encontrado!\n");
				//Sleep(1000);
				//system("cls");
				break;
			}

			if (j + 1 == qtd->professor)
			{
				printf("Erro! Professor nao cadastrado\n");
				i--;
			}
		}
	}
	strcpy(professor_tmp[i + 1].nome, "\n");

	printf("Digite a quantidade de materias que os professores serao desvinculados:\n");
	scanf("%i", &qtd_cadastros);
	scanf("%c");


	for (int i = 0; i < qtd_cadastros; i++)
	{
		printf("Digite o nome da materia:\n");
		gets_s(materia_temp[i].nome);

		for (int j = 0; j < qtd->materias; j++)
		{

			if (strcmp(materia_temp[i].nome, materia[j].nome) == 0)
			{
				printf("Materia encontrada!\n");
				cont = 0;
				while (strcmp(professor_tmp[cont].nome, "\n") != 0)
				{
					for (int rp = 0; rp < qtd->professor; rp++)
					{
						if (strcmp(professor_tmp[cont].nome, professor[rp].nome) == 0)
							materia[j].professor[rp] = 0;
					}
					cont++;
				}
				break;
			}

			if (j + 1 == qtd->materias)
			{
				printf("Erro! materia nao cadastrada\n");
				i--;
			}
		}
	}
}

void impressao(tipo_aluno aluno[], tipo_materia materia[], tipo_professor professor[], tipo_qtd *qtd)
{
	int opcao, i, j;
	char	materia_aux[50], aluno_aux[50], professor_aux[50];

	system("cls");
	printf("\nDigite 1 para imprimir o nome de todos os aluno");
	printf("\nDigite 2 para imprimir todas as materias");
	printf("\nDigite 3 para imprimir o nome de todos os professores");
	printf("\nDigite 4 para imprimir a relacao professor-materia");
	printf("\nDigite 5 para imprimir a relacao aluno-materia");
	printf("\nDigite 6 para imprimir a relacao aluno-RA");
	printf("\nDigite 7 para imprimir as materias que o aluno esta matriculado");
	printf("\nDigite 8 para imprimir as materias que o professor esta lecionando\n");

	scanf("%i", &opcao);

	switch (opcao)
	{
	case 1:
	{
		system("cls");
		for (i = 0; i < qtd->alunos; i++)
		{
			if (aluno[i].nome != 0)
			{
				printf("%s\n", aluno[i].nome);
			}
		}

		system("pause");
	}
	break;
	case 2:
	{
		system("cls");
		for (i = 0; i < qtd->materias; i++)
		{
			if (materia[i].nome != 0)
			{
				printf("%s\n", materia[i].nome);
			}
		}

		system("pause");
	}
	break;
	case 3:
	{
		system("cls");
		for (i = 0; i < qtd->professor; i++)
		{
			if (professor[i].nome != 0)
			{
				printf("%s\n", professor[i].nome);
			}
		}

		system("pause");
	}
	break;
	case 4:
	{
		system("cls");
		printf("Digite a materia desejada: ");
		scanf("%s", &materia_aux);

		for (i = 0; i < 51; i++)
		{
			if (strcmp(materia_aux, materia[i].nome) == 0)
				break;
		}

		if (i == 50)
		{
			printf("Materia nao encontrada");
			system("pause");
		}
		else
		{
			printf("Os professores matriculados na materia sao: \n");

			for (j = 0; j < 50; j++)
			{
				if (materia[i].professor[j] == 1)
				{
					printf("%s \n", professor[j].nome);
				}
			}

			system("pause");
		}


	}
	break;
	case 5:
	{
		system("cls");
		printf("Digite a materia desejada: ");
		scanf("%s", &materia_aux);

		for (i = 0; i < 51; i++)
		{
			if (strcmp(materia_aux, materia[i].nome) == 0)
				break;
		}

		if (i == 50)
		{
			printf("Materia nao encontrada");
			system("pause");
		}
		else
		{
			printf("Os alunos matriculados na materia sao: \n");

			for (j = 0; j < 50; j++)
			{
				if (materia[i].aluno[j] == 1)
				{
					printf("%s \n", aluno[j].nome);
				}
			}

			system("pause");
		}


	}
	break;
	case 6:
	{
		system("cls");
		for (i = 0; i < qtd->alunos; i++)
		{
			if (aluno[i].nome != 0)
			{
				printf("%s    RA: %d\n", aluno[i].nome, i);
			}
		}

		system("pause");
	}
	break;
	case 7:
	{
		system("cls");
		printf("Digite o nome do aluno desejado: ");
		scanf("%s", &aluno_aux);

		for (i = 0; i < qtd->alunos; i++)
		{
			if (strcmp(aluno_aux, aluno[i].nome) == 0)
				break;
		}

		printf("\nMaterias que o aluno %s esta matriculado:\n", aluno[i].nome);

		for (j = 0; j < qtd->materias; j++)
		{
			if (materia[j].aluno[i] == 1)
			{
				printf("%s\n", materia[j].nome);
			}
		}
		system("pause");
	}
	break;
	case 8:
	{
		system("cls");
		printf("Digite o nome do professor desejado: ");
		scanf("%s", &professor_aux);

		for (i = 0; i < qtd->professor; i++)
		{
			if (strcmp(professor_aux, professor[i].nome) == 0)
				break;
		}

		printf("\nMaterias que o professor %s esta lecionando:\n", professor[i].nome);

		for (j = 0; j < qtd->materias; j++)
		{
			if (materia[j].professor[i] == 1)
			{
				printf("%s\n", materia[j].nome);
			}
		}
		system("pause");

	}
	break;
	default:
		printf("Opcao Invalida");
		break;
	}
}