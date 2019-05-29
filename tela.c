#include "tela.h"
//Cabeçalho
void cbc()
{
	printf("\33[H\33[2J");
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
	printf("\t 1 - Abrir imagem PPM\n");
	printf("\t 0 - Encerrar Programa\n");
	printf("Opção: ");
	scanf("%d", &user);
	while(user!=1 && user!=0)
	{
		printf("Opção Invalida. Digite novamente \n");
		printf("Opção: ");
		scanf("%d", &user);
	}
	if(user == 0)
	{
		printf("\33[H\33[2J");
		cbc();
		printf("Programa Encerrado!\n");
		exit(0);
	}
	
	if(user == 1)
	{
		printf("\33[H\33[2J");
		return 1;
		
	}
	return 0;

	printf("\n");
}
//Tela Inicial
int tela_inicio()
{	
	printf("\33[H\33[2J");
	int op;
	cbc();
	printf("\t 1 - Iniciar\n");
	printf("\t 0 - Sair\n");
	printf("Opção: ");
	scanf("%d", &op);
	while(op!=1 && op!=0)
	{
		printf("Opção Invalida. Digite novamente \n");
		printf("Opção: ");
		scanf("%d", &op);
	}
	if(op == 0)
	{
		return 0;
	}
	
	if(op == 1)
	{
		printf("\33[H\33[2J");
		return opc();
		
	}
	return 0;
	
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

}