#include "tela.h"
#include "functions.h"
//Cabeçalho
void cbc()
{
	system("clear");
	printf("======================================= \n");
	printf("\t\tSENATUS\n");
	printf("\t     (Image Editor)\n");
	printf("======================================= \n");
	printf("\n");
}
//Opções
int opc()
{
	cbc();
	int user;
	printf(" 1 - Abrir imagem PPM\n");
	printf(" 0 - Encerrar Programa\n");
	printf("Opção: ");
	scanf("%d", &user);
	while(user!=1 && user!=0)
	{
		printf("\n !Opção Invalida. Digite novamente! \n");
		printf("\n Opção: ");
		scanf("%d", &user);
	}
	if(user == 0)
	{
		system("clear");
		cbc();
		printf("Programa Encerrado!\n");
		exit(0);
	}
	
	if(user == 1)
	{
		system("clear");
		return 1;
		
	}
	return 0;

	printf("\n");
}
//Tela Inicial
void tela_inicio()
{
	system("clear");
	int op;
	cbc();
	printf(" 1 - Iniciar\n");
	printf(" 0 - Sair\n");
	printf("\n Opção: ");
	scanf("%d", &op);
	while(op!=1 && op!=0)
	{
		printf("\n !Opção Invalida. Digite novamente! \n");
		printf("\n Opção: ");
		scanf("%d", &op);
	}
	if(op == 0)
	{
			system("clear");
			cbc();
			printf(" Programa Encerrado!\n");
			exit(0);
	}
	
	if(op == 1)
	{	
		read();
	}
}

void cmd()
{
	cbc();
	printf("\t   OPÇÕES DE COMANDO:\n\n");
	printf(" 1 - ‘gry’(Executa grey mode)\n");
	printf(" 2 - ‘thr’(Binarização da imagem usando thresholding)\n");
	printf(" 3 - ‘blu’(Executa blurring)\n");
	printf(" 4 - ‘sha’(Executa sharpening)\n");
	printf(" 5 - 'rot'(Rotação da imagem, dado o ângulo)\n");
	printf(" 6 - 'amp’(Ampliar a imagem, dado o zoom)\n");
	printf(" 7 - ‘red’(Reduzir a imagem, dado o zoom)\n");
	printf(" 8 - ‘neg’(Negativo da imagem)\n");
}

void vsl(char name_archive[500])
{
	
		char comando[500];
		strcpy(comando, "eog ");
		strcat(comando, name_archive);
		system(comando);

}	