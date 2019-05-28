#include "functions.h"


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
		printf("Arquivo não existente, tente novamente!\n" );
		/*printf("Digite o nome do Arquivo:\n");
		scanf(" %s", name_archive);
		FILE *archive = fopen(name_archive,"r");*/
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