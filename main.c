#include "tela.h"

#define MAX 600

typedef struct 
{
    int R, G, B; 
}pxl;


	



void read(pxl img[MAX][MAX], char *cod, int *lmt, int *cl, int*ln)
{
	cbc();
	int i, j;

	char name_archive[50];

	printf("Digite o nome do Arquivo:\n");

	scanf("%s", name_archive);

	FILE *archive = fopen(name_archive,"r");

	if( archive == NULL ) 
	{
		printf( "Erro na abertura do arquivo!\n" );
		exit(1);
	}

	fscanf(archive, "%s", cod);
	fscanf(archive, "%d", cl);
	fscanf(archive, "%d", ln);
	fscanf(archive, "%d", lmt);

	for(i = 0; i < *ln; i++)
	{
		for(j = 0; j < *cl; j++)
		{
			fscanf(archive,"%d", &img[i][j].R);
			fscanf(archive,"%d", &img[i][j].G);
			fscanf(archive,"%d", &img[i][j].B);
		}
	}
	fclose(archive);
}


int main()
{
	//tela_inicio();
	pxl img[MAX][MAX];
	char cod[3];
	int lmt;
	int lrg, alt;
	int temp;
	temp = tela_inicio();

	if(temp == 1){
	read(img, cod, &lmt, &lrg, &alt);
	}else if(temp == 0){
		printf("\33[H\33[2J");
		cbc();
		printf("Programa Encerrado!\n");
		exit(0);

	}
	return 0;
}