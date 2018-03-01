#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tipo_materia					//Armazena o nome de uma materia
	{
	char nome[50];
	};
struct tipo_aluno					//Necessario para guardar os nomes de entrada para matricula (Conjuntos de alunos)
	{	
	char nome[50];
	};				
struct tipo_professor				// ||	||...
	{
	char nome[50];
	};


/*
|
|
|
*/

struct tipo_cadastro_aluno			//Armazena o nome de um aluno e todas as materia que está matriculado
	{
	char nome[50];					//Um nome de aluno  		
	tipo_materia materias[50];		//Até 50 materias podem ser incluidas
	};
struct tipo_cadastro_materia_a		//Armazena o nome de uma materia e todos os alunos matriculados 
	{
	char nome[50];					//Uma nome de materia
	tipo_aluno alunos[50];			//Até 50 alunos podem ser matriculados
	};


	
struct tipo_cadastro_professor		//Armazena o nome de um professor e todas as materia que está ministrando
	{
	char nome[50];					//Um nome de professor
	tipo_materia materias[50];		//Até 50  materias podem ser ministradas
	};
struct tipo_cadastro_materia_p		//Armazena o nome de uma materias e todas os professores que a ministram 
	{
	char nome[50];					//Um nome de materia
	tipo_professor professores[50];	//Até 50  preofessores podem ministradar
	};

struct tipo_cadastro				//Une todas as opções acima em uma só struct
	{
	tipo_cadastro_aluno  	aluno;     
	tipo_cadastro_materia_a materia_a;
	tipo_cadastro_professor	professor;
	tipo_cadastro_materia_p	materia_p;
	};


//Prototipos das funções
int cadastro_geral(int opcao, tipo_cadastro cadastro[], int qtd_alunos, int qtd_materia, int qtd_professor);
void menu(tipo_cadastro cadastro[], int qtd_alunos);

void main()
{
	tipo_cadastro cadastro [100];

	int qtd_alunos = 0, qtd_materia = 0, qtd_professor = 0;

	menu(cadastro, qtd_alunos);
	system("pause");

/*********Exemplo de cadastro****************

	Alunos	
	strcpy (cadastro[1].aluno.nome,"Lucas");
	strcpy (cadastro[1].aluno.materias[1].nome,"Fisica");	
	strcpy (cadastro[1].aluno.materias[2].nome,"Calculo");
    strcpy (cadastro[1].aluno.materias[3].nome,"Paradigmas");

	strcpy (cadastro[1].materia_a.nome,"Fisica");
	strcpy (cadastro[1].materia_a.alunos[1].nome,"Adriano");
	strcpy (cadastro[1].materia_a.alunos[2].nome,"Fabio");
	strcpy (cadastro[1].materia_a.alunos[3].nome,"Lucas");


	professores
	strcpy (cadastro[1].professor.nome,"Pannain");
	strcpy (cadastro[1].professor.materias[1].nome,"Circuitos");	
	strcpy (cadastro[1].professor.materias[2].nome,"OS");
    strcpy (cadastro[1].professor.materias[3].nome,"AI");

	strcpy (cadastro[1].materia_p.nome,"Fisica");
	strcpy (cadastro[1].materia_p.professores[1].nome,"Magela");
	strcpy (cadastro[1].materia_p.professores[2].nome,"Elaine");
	strcpy (cadastro[1].materia_p.professores[3].nome,"Leandro");

*/
	
}

void menu(tipo_cadastro cadastro[], int qtd_alunos)
{
	int opc;
	int qtd_alunos = 0, qtd_materia = 0, qtd_professor = 0;
	printf("Digite o numero da opcao desejada:\n");
	printf("1-Cadastrar alunos\n");
	printf("2-Cadastrar disciplinas\n");
	printf("3-Cadastrar professores\n");
	printf("4-Realizar matricula\n");
	printf("5-Cancelar matricula\n");
	printf("6-Vincular professores a disciplinas\n");
	printf("7-Remover vinculo de professores a disciplinas\n");
	printf("8-Menu de impressao\n");
	scanf("%i", &opc);
	cadastro_geral(opc, cadastro, qtd_alunos, qtd_materia, qtd_professor);
}


int cadastro_geral(int opcao, tipo_cadastro cadastro[], int qtd_alunos, int qtd_materia, int qtd_professor)//*********Depois atualizar para ponteiros********** 
{
	int i = 0, qtd_cadastros;
	tipo_aluno	   aluno[50];		//|
	tipo_materia   materia[50];		//|Conjuntos de até 50 nomes 
	tipo_professor professor[50];	//|

	switch (opcao)
	{
	case 1:	//Cadastro de alunos
		system("cls");
		printf("Digite a quantidade de alunos que deseja cadastrar\n");
		scanf("%i", &qtd_cadastros);
		scanf("%c");//Limpa lixo (fflush não funciona)
		
		for (i = 0; i < qtd_cadastros; i++)//Grava os nomes dos alunos na struct de cadastro
			{			
			printf("Digite o nome do aluno\n");
			gets_s(cadastro[qtd_alunos].aluno.nome);
			qtd_alunos++;
			}
		break;

	case 2: //Cadastro de disciplina
		system("cls");	
		printf("Digite a quantidade de disciplinas que deseja cadastrar\n");
		scanf("%i", &qtd_cadastros);
		scanf("%c");//Limpa lixo (fflush não funciona)
		
		for (i = 0; i < qtd_cadastros; i++)//Grava os nomes das materias na struct de cadastro
			{
			printf("Digite o nome da disciplina\n");
			gets_s(cadastro[qtd_materia].materia_a.nome);
			qtd_materia++;
			}
		break;

	case 3: //Cadastro de professor
		system("cls");	
		printf("Digite a quantidade de disciplinas que deseja cadastrar\n");
		scanf("%i", &qtd_cadastros);
		scanf("%c");//Limpa lixo (fflush não funciona)
		
		for (i = 0; i < qtd_cadastros; i++)//Grava os nomes dos professores na struct de cadastro
			{
			printf("Digite o nome da disciplina\n");
			gets_s(cadastro[qtd_professor].professor.nome);
			qtd_professor++;
			}
		break;




	
	case 4:	//Matricula de alunos
		system("cls");
		printf("Digite a quantidade alunos que deseja matricular\n");
		scanf("%i", &qtd_cadastros);
		scanf("%c");//Limpa lixo (fflush não funciona)
		
		for (i = 0; i < qtd_cadastros; i++)//Guarda temporariamente os nomes a serem matriculados
			{
			printf("Digite o nome do aluno\n");
			gets_s(aluno[i].nome);
			}

		printf("Digite a quantidade de materias que os alunos serao matriculados\n");
		scanf("%i", &qtd_cadastros);
		scanf("%c");//Limpa lixo (fflush não funciona)
		
		for (i = 0; i < qtd_cadastros; i++)//Guarda temporariamente as materias
			{
			printf("Digite o nome da materia\n");
			gets_s(materia[i].nome);
			}	
		break;

		//**********Falta fazer a união dos alunos com as materias********** 
		 

		


		/*for (i = 0; i <= qtd_alunos; i++)//Busca e verifica se o aluno está cadastrado
		{
			if (strcmp(nomeAluno, aluno[i].nome) == 0)
			{
				i_aluno_cadastrado = i;
				printf("Aluno encontrado\n");
			}
		}

		printf("Digite o nome da materia\n");
		scanf("%i");
		gets_s(materia[]);
		while ((aluno[i_aluno_cadastrado].materias[i].materia) != NULL)//Busca materia na grade do aluno, caso não encotre cadastra como nova
		{
			if (strcmp(materia, aluno[i_aluno_cadastrado].materias[i].materia) == 0)
			{
				printf("Materia ja cadastrada na grade\n");
				menu(aluno, qtd_alunos);
				return(0);
			}
			i++;
		}
		printf("Materia cadastrada com sucesso\n");
		menu(aluno, qtd_alunos);
		break;*/


	default:
		break;		
	}
	system("cls");
	menu(cadastro, qtd_alunos);
	return (0);	
	


	/*do 	{
	scanf("%c", &aluno[0].nome[i]);
	i++;
	}while (aluno[0].nome[i-1]!=';');

	while(j<i-1)
	{
	printf("%c",aluno[0].nome[j]);
	j++;
	}
	*/


}