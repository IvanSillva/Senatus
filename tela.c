#include "tela.h"
#include "functions.h"
//Cabeçalho
void cbc()
{
	system("clear");
	printf("████████████████████████████████████████████████████████████\n");
	printf("███      █      █  ███  █       █        █  ███  █       ███\n");
	printf("███  █████  █████   ██  █  ███  ████  ████  ███  █  ████████\n");
	printf("███      █      █  █ █  █       ████  ████  ███  █       ███\n");
	printf("███████  █  █████  ██   █  ███  ████  ████  ███  ██████  ███\n");
	printf("███      █      █  ███  █  ███  ████  ████       █       ███\n");
	printf("████████████████████████████████████████████████████████████\n\n");
}

//Tela Inicial
void tela_inicio()
{
	system("clear");
	int op;
	cbc();
	printf("\t\t       ██ 1 - Iniciar ██\n");
	printf("\t\t       ██ 0 - Sair    ██\n");
	printf("\n\t\t\t   Opção: ");
	scanf("%d", &op);
	while(op!=1 && op!=0)
	{
		printf("\n\t    ██ Opção Invalida. Digite novamente ██\n");
		printf("\n\t\t\t   Opção: ");
		scanf("%d", &op);
	}
	if(op == 0)
	{

			cbc();
			printf("\t\t  ██ Programa Encerrado ██\n\n");
			exit(0);
	}
	
	if(op == 1)
	{	
		reading();
	}
}

void cmd()
{
	cbc();
	printf("██\t              OPÇÕES DE COMANDO:             \t  ██\n");
	printf("█ 1 - ‘gry’(Executa grey mode)\t\t\t           █\n");
	printf("█ 2 - ‘thr’(Binarização da imagem usando thresholding)     █\n");
	printf("█ 3 - ‘blu’(Executa blurring)\t\t\t           █\n");
	printf("█ 4 - ‘sha’(Executa sharpening)\t\t\t           █\n");
	printf("█ 5 - 'rot'(Rotação da imagem, dado o ângulo)\t           █\n");
	printf("█ 6 - 'amp’(Ampliar a imagem, dado o zoom)\t           █\n");
	printf("█ 7 - ‘red’(Reduzir a imagem, dado o zoom)\t           █\n");
	printf("█ 8 - ‘neg’(Negativo da imagem)\t\t\t           █\n");
	printf("█ 9 - ‘dtc’(Detecção de borda)\t\t\t           █\n");
	printf("█ 0 - ‘end’(Encerrar programa)\t\t\t           █\n");
	printf("██\t\t\t\t\t\t\t  ██\n");
}
void vsl(char name_archive[500])
{
	
		char comando[500];
		strcpy(comando, "eog ");
		strcat(comando, name_archive);
		system(comando);

}	

void load(char name_archive[500], char comand[500])
{

	cbc();
		printf("\n██ %s Arquivo '%s' ∘ \n",comand, name_archive);
		sleep(1);
	cbc();
		printf("\n██ %s Arquivo '%s' ∘∘ \n",comand, name_archive);
		sleep(1);
	cbc();
		printf("\n██ %s Arquivo '%s' ∘∘∘ \n",comand, name_archive);
		sleep(1);
}