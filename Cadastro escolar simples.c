#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

//criação de módulos e registros
typedef struct
{
	int matricula;
	char nome[10];
	int serie;
	int irmao;
	float mensalidade;
} tipo_cadastro;

//declaração de variáveis globais
tipo_cadastro aluno[20];
int i = 0, q = 0, cadastrar;

//módulo principal
int main (void)
{
	//estrutura do do/while para cadastros os alunos
	do
	{
		//limpa-tela
		system("cls");
		
		//acréscimo +1 da variável q que controla a quantidade de cadastros
		q++;
		
		//nome da escola
		printf("\tEscola Legal\n\nCadastro de alunos\n\n");
		
		//comandos para preencher o cadastro
		printf("Digite a matricula do aluno %d: ", i+1);
		scanf("%d", &aluno[i].matricula);
		
		printf("\nDigite o nome do aluno %d: ", i+1);
		fflush(stdin);
		gets(aluno[i].nome);
		
		printf("\nDigite a serie do aluno %d <1, 2, 3 ou 4>: ", i+1);
		scanf("%d", &aluno[i].serie);
		
		printf("\nO aluno %d possui irmao na escola <1-Sim,0-Nao>?: ", i+1);
		scanf("%d", &aluno[i].irmao);
		
		//comandos para calcular o valor da mensalidade
		switch(aluno[i].serie)
		{
			case 1:
					if(aluno[i].irmao == 1)
					{
						aluno[i].mensalidade = 110 - (110*0.20);
					} else
					  {
					  	aluno[i].mensalidade = 110;
					  } break;
			
			case 2:
					if(aluno[i].irmao == 1)
					{
						aluno[i].mensalidade = 130 - (130*0.20);
					} else
					  {
					  	aluno[i].mensalidade = 130;
					  } break;
		
		    case 3:
					if(aluno[i].irmao == 1)
					{
						aluno[i].mensalidade = 160 - (160*0.20);
					} else
					  {
					  	aluno[i].mensalidade = 160;
					  } break;
					  
			case 4:
					if(aluno[i].irmao == 1)
					{
						aluno[i].mensalidade = 170 - (170*0.20);
					} else
					  {
					  	aluno[i].mensalidade = 170;
					  } break;	
		}
		
		//acréscimo +1 da variável i que controla os elementos do vetor de registro
		i++;
		
		//comando que pergunta se o usuário deseja cadastrar mais um aluno
		printf("\n\nDeseja fazer novo cadastro <1-Sim,2-Nao>?: ");
		scanf("%d", &cadastrar);
	
	}while(cadastrar == 1 && i < 20);
	
//impressão dos resultados

//limpa-tela
system("cls");

//título
printf("\tEscola Legal\n\nCadastro de Aluno\n\n");

//colunas
printf("________________________________________________________\n");
printf("MATRICULA    NOME          SERIE    IRMAO    MENSALIDADE");
printf("\n________________________________________________________\n");
	
//estrutura for pra imrimir as linhas
for(i = 0; i < q; i++)
{
	printf("%9d    %-10s    %5d    %5d    %11.2f\n", aluno[i].matricula, aluno[i].nome, aluno[i].serie, aluno[i].irmao, aluno[i].mensalidade);
}

//última linha da tabela
 printf("\n________________________________________________________\n\n");
 
//comando para sair 
printf("Tecle enter para sair do programa...");

getche();           
}
