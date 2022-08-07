#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct{ 
int mat;
char telefone[100];
char end[100];
char nome[100];
float med;
} TAluno;

FILE *paluno;
TAluno aluno_aux, aluno_nulo;

int linha() {
int i;
for (i = 1; i <= 90; i++)
printf("*");
printf("\n");
  return 0;
}
void cabec(){ 
printf("CADASTRO DE CLIENTES DA BIBLIOTECA\n");
linha();
}
void abre_arquivo()
{ paluno = fopen("cadastros.txt", "r+b");
if (paluno == NULL)
paluno = fopen("cadastros.txt", "w+b");
}
void inserir()
{ int resp;
do { cabec();
printf("\nCadastrar novo Cliente\n");
printf("\nCodigo: ");
scanf("%d", &aluno_aux.mat);
printf("\nNome.....: ");
fflush(stdin);
gets(aluno_aux.nome);
printf("\nEndereco.....: ");
fflush(stdin);
gets(aluno_aux.end);
printf("\ntelefone....: ");
scanf("%s", &aluno_aux.telefone);
printf("\nLivros....: ");
scanf("%f", &aluno_aux.med);
fseek(paluno, 0, SEEK_END);
fwrite(&aluno_aux, sizeof(TAluno), 1,

paluno);

printf("\nCliente cadastrado com sucesso!\n");

printf("\nDeseja cadastrar outro (1-sim/0-nao)? ");
scanf("%d", &resp);
} while (resp ==1);
system("cls");
}
int procura(int matp)
{ int p;
p = 0;
rewind(paluno);
fread(&aluno_aux, sizeof(TAluno), 1, paluno);
while (feof(paluno)==0)
{ if (aluno_aux.mat == matp)

return p;
else
{ fread(&aluno_aux, sizeof(TAluno), 1,

paluno);
p++;
}
}
return -1;
}

void mostre(int pos)
{ fseek(paluno, pos*sizeof(TAluno), SEEK_SET);
fread(&aluno_aux, sizeof(TAluno), 1, paluno);
printf("\n\n");
linha();
printf("CODIGO     NOME                 LIVROS           TELEFONE            ENDERECO\n");
linha();
printf("%9d %-20s %5.0f %20s %20s\n", aluno_aux.mat,aluno_aux.nome, aluno_aux.med,aluno_aux.telefone,aluno_aux.end);
linha();
}
void consultar()
{ int resp, matcon, posicao;
do{ cabec();
printf("\n\nConsultar Cliente\n\n");
printf("Codigo do Cliente: ");
scanf("%d", &matcon);
posicao = procura(matcon);
if (posicao == -1)
printf("\n\nCodigo nao encontrada!\n\n");
else
mostre(posicao);
printf("\n\nDeseja consultar outro(1-sim/0-nao)? ");

scanf("%d", &resp);
} while (resp == 1);
system("cls");
}
void remover()
{ int matrem, conf, resp, posicao;
aluno_nulo.mat = 0;
aluno_nulo.med = 0;
do{ cabec();
printf("\nRemover Cliente\n\n");
printf("Codigo: ");
scanf("%d", &matrem);
posicao = procura(matrem);
if (posicao == -1)
printf("\nCliente nao encontrado!!\a");
else
{ mostre(posicao);
printf("\n\nDeseja remover o Cliente (1-sim/0-nao)? ");

scanf("%d", &conf);
if (conf == 1)
{ 
fseek(paluno, posicao * sizeof(TAluno),SEEK_SET);

fwrite(&aluno_nulo,

sizeof(TAluno), 1, paluno);

printf("\n\nCliente removido com sucesso!");
}
else
printf("\nRemocao cancelada!");

}
printf("\n\n\nDeseja remover outro (1-sim/0-nao)? ");
scanf("%d", &resp);
} while (resp ==1);
system("cls");
}
void alterarNum()
{ int matalt, conf, resp, posicao;
do { cabec();
printf("\n\nAlterar Numero de telefone\n\n\n");

printf("codigo: ");
scanf("%d", &matalt);
posicao = procura(matalt);
if (posicao == -1)
printf("\nCliente nao encontrado!!\a");
else
{ mostre(posicao);
printf("\n\nAlterar numero de telefone(1-sim/0-nao)? ");

scanf("%d", &conf);
if (conf == 1)
{ printf("\nNovo Numero: ");
scanf("%s", &aluno_aux.telefone);
printf("\nNumero alterado com sucesso!\n\n");

fseek(paluno,posicao*sizeof(TAluno),

SEEK_SET);

fwrite(&aluno_aux,sizeof(TAluno), 1,

paluno);

mostre(posicao);
printf("\n Numero alterado com sucesso!\n");
}
else
printf("\nAlteracao cancelada!\n");
}
printf("\n\nDeseja alterar outro (1-sim/0-nao)? ");
scanf("%d", &resp);
}while (resp ==1);
system("cls");
}
void alterar()
{ int matalt, conf, resp, posicao;
do { cabec();
printf("\n\nAlterar quantidade de livros\n\n\n");

printf("codigo: ");
scanf("%d", &matalt);
posicao = procura(matalt);
if (posicao == -1)
printf("\nCliente nao encontrado!!\a");
else
{ mostre(posicao);
printf("\n\nAlterar quantidade de livros(1-sim/0-nao)? ");

scanf("%d", &conf);
if (conf == 1)
{ printf("\nNova quantia: ");
scanf("%f", &aluno_aux.med);
printf("\nLivros alterado com sucesso!\n\n");

fseek(paluno,posicao*sizeof(TAluno),

SEEK_SET);

fwrite(&aluno_aux,sizeof(TAluno), 1,

paluno);

mostre(posicao);
printf("\n Quantidade alterada com sucesso!\n");
}
else
printf("\nAlteracao cancelada!\n");
}
printf("\n\nDeseja alterar outro (1-sim/0-nao)? ");
scanf("%d", &resp);
}while (resp ==1);
system("cls");
}
void listagem()
{ cabec();
printf("\nListagem Geral\n\n");
linha();
printf("CODIGO     NOME                 LIVROS           TELEFONE            ENDERECO\n");
linha();
rewind(paluno);
fread(&aluno_aux, sizeof(TAluno), 1, paluno);
while (feof(paluno)==0)
{ if (aluno_aux.mat != 0)
printf("%9d %-20s %5.0f %20s %20s\n", aluno_aux.mat,aluno_aux.nome, aluno_aux.med,aluno_aux.telefone,aluno_aux.end);
fread(&aluno_aux, sizeof(TAluno), 1,paluno);
}
linha();
printf("tecle enter para voltar ao menu...");
getche();
system("cls");
}
main()
{ int op;
abre_arquivo();
do{ cabec();
printf("1 - Cadastrar Novo Cliente\n");
printf("2 - Excluir Cliente\n");
printf("3 - Pesquisar cliente por codigo\n");
printf("4 - Alterar quantidade de livros\n");
printf("5 - Alterar numero de telefone\n");
printf("6 - Listar todos os clientes\n");
printf("0 - Sair\n");
linha();
printf("Informe a opcao desejada: \n");
scanf("%d", &op);
system("cls");
switch(op)
{ case 1: inserir(); break;
case 2: remover(); break;
case 3: consultar(); break;
case 4: alterar(); break;
case 6: listagem(); break;
case 5: alterarNum(); break;
case 0: fclose(paluno); break;
default: printf("\n\n\aOpcao invalida!");
break;
}
} while (op != 0);
}
