#include "functions.h"

void read(pxl img[DIM][DIM], char *cod, int *lmt, int *cl, int*ln)
{
	cbc();
	int i, j;

	char name_archive[50];

	printf("Digite o nome do Arquivo:\n");

	scanf("%s", name_archive);

	FILE *archive = fopen(name_archive,"r");

	while( archive == NULL ) 
	{
		printf("Arquivo não existente, tente novamente!\n" );
		printf("Digite o nome do Arquivo:\n");
		scanf(" %s", name_archive);
		archive = fopen(name_archive,"r");
	}

	printf("Arquivo '%s' aberto com sucesso! \n", name_archive);

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
	cmd();
	options(img, cod, lmt, cl, ln);
}

void grey (pxl img[DIM][DIM], int *cl, int *ln)
{

	int j, i;

	for(i =0; i<ln; i++)
	{
		for(j =0; j<cl; j++)
		{
			img[i][j].B = (int) ((0.300 * img[i][j].R) + (0.599*img[i][j].G) + (0.145 * img[i][j].B));

			img[i][j].G = img[i][j].B;

			img[i][j].R = img[i][j].B;

			if(img[i][j].B > 255)
			{
				img[i][j].R = 255;
				img[i][j].G = 255;
				img[i][j].B = 255;

			}
			printf("%d\n", img[i][j].R);
			printf("%d\n", img[i][j].G);
			printf("%d\n", img[i][j].B);
			printf("\n");
		}
	}




}




void options(pxl img[DIM][DIM], char *cod, int *lmt, int *cl, int*ln)
{
	cmd();

	char acao[3];
	printf("\n");
	printf(" Informe o comando: ");
	scanf("%s", &acao);
	

	grey(img,*cl,*ln);
	/*switch(acao)
	{

		case 'gry':
		grey();
	}*/


}
	

