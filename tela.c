#include "tela.h"
//Cabeçalho
void cbc()
{
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