#include <stdio.h>
#include <stdlib.h>
void cbc()
{
	printf("======================================= \n");
	printf("\t\tSENATUS\n");
	printf("\t     (Image Editor)\n");
	printf("======================================= \n");
	printf("\n");
}

void opc()
{
	cbc();
	printf("\t 1 - Abrir imagem PPM\n");
	printf("\t 2 - Criar imagem PPM\n");
	printf("\n");

}

void tela_inicio( )
{
	int op;
	cbc();
	printf("1 - Iniciar\n");
	printf("0 - Sair\n");
	printf("\n");
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
		printf("\33[H\33[2J");
		printf("Programa Encerrado!\n");
		exit(0);
	}
	

	if(op == 1)
	{
		printf("\33[H\33[2J");
		opc();
		

	}
	
}

int main()
{

	tela_inicio();

	

	return 0;
}