#include "functions.h"

void read(pxl img[DIM][DIM], char *cod, int *lmt, int *cl, int*ln)
{
	cbc();
	int i, j;

	char name_archive[60];

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

void save(pxl img[DIM][DIM], int lmt, int cl, int ln)
{
	int i, j;

	char name_archive[60];
	printf("\n");
	printf(" Digite o nome do novo Arquivo: ");
	scanf("%s", name_archive);
	FILE *test = fopen(name_archive,"r+");
	while(test != NULL){
		printf("\n !!Arquivo '%s' já existe!!\n\n", name_archive);
		printf(" Digite o nome do novo Arquivo: ");
		scanf("%s", name_archive);
		test = fopen(name_archive,"r+");
	}

	FILE *archive = fopen(name_archive,"w");

	fprintf(archive, "P3\n");
	fprintf(archive, "%d ", cl);
	fprintf(archive, "%d\n", ln);
	fprintf(archive, "%d\n", lmt);

	for(i = 0; i < ln; i++)
	{
		for(j = 0; j < cl; j++)
		{
			fprintf(archive,"%d ", img[i][j].R);
			fprintf(archive,"%d ", img[i][j].G);
			fprintf(archive,"%d \n", img[i][j].B);
		}
	}

	fclose(archive);

	printf("\n");
	printf(" Arquivo salvo com sucesso!\n");
	vsl(name_archive);
}

void grey (pxl img[DIM][DIM], int cl, int ln)
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

			/*printf("%d\n", img[i][j].R);
			printf("%d\n", img[i][j].G);
			printf("%d\n", img[i][j].B);
			printf("\n");*/
		}
	}


}

void rot(pxl img[DIM][DIM], int lmt, int cl, int ln)
{
	int i, j;

	int ang;
	printf("\n");
	printf(" 1 - Direita | 2 - Esquerda | 3 - Inverter\n");
	printf("\n");
	printf(" Informe a orientação: ");

	scanf("%d", &ang);

	while (ang > 3 || ang <1)
	{
		printf(" Opção Invalida! \n");
		printf(" Informe a orientação: ");
		scanf("%d", &ang);
	}

	char name_archive[60];

	printf("\n");
	printf(" Digite o nome do novo Arquivo: ");
	scanf("%s", name_archive);
	FILE *test = fopen(name_archive,"r+");
	
	while(test != NULL)
	{
		printf("\n !!Arquivo '%s' já existe!!\n\n", name_archive);
		printf(" Digite o nome do novo Arquivo: ");
		scanf("%s", name_archive);
		test = fopen(name_archive,"r+");
	}


	FILE *archive = fopen(name_archive,"w");

	fprintf(archive, "P3\n");
	fprintf(archive, "%d ", ln);
	fprintf(archive, "%d\n", cl);
	fprintf(archive, "%d\n", lmt);

	if(ang == 3 )
	{	
		for(i = ln; i >0; i--)
		{
			for(j = cl; j > 0; j--)
			{
				fprintf(archive,"%d ", img[i][j].R);
				fprintf(archive,"%d ", img[i][j].G);
				fprintf(archive,"%d \n", img[i][j].B);
			}
		}	
	}

	fclose(archive);

	printf("\n");
	printf(" Arquivo salvo com sucesso!\n");
	vsl(name_archive);
}


void rdz(pxl img[DIM][DIM], int lmt, int cl, int ln)
{
	int i, j;

	char name_archive[60];
	printf("\n");
	printf(" Digite o nome do novo Arquivo: ");
	scanf("%s", name_archive);
	FILE *test = fopen(name_archive,"r+");
	while(test != NULL){
		printf("\n !!Arquivo '%s' já existe!!\n\n", name_archive);
		printf(" Digite o nome do novo Arquivo: ");
		scanf("%s", name_archive);
		test = fopen(name_archive,"r+");
	}

	FILE *archive = fopen(name_archive,"w");

	fprintf(archive, "P3\n");
	fprintf(archive, "%d ", cl/2);
	fprintf(archive, "%d\n", ln/2);
	fprintf(archive, "%d\n", lmt);

	for(i = 0; i < ln; i++)
	{	
		i++;
		for(j = 0; j < cl; j++)
		{	
			j++;
			fprintf(archive,"%d ", img[i][j].R);
			fprintf(archive,"%d ", img[i][j].G);
			fprintf(archive,"%d \n", img[i][j].B);
		}
	}
}
void amp(pxl img[DIM][DIM], int lmt, int cl, int ln)
{
	int i, j;
	int a = 0, b = 0;

	char name_archive[60];
	printf("\n");
	printf(" Digite o nome do novo Arquivo: ");
	scanf("%s", name_archive);
	FILE *test = fopen(name_archive,"r+");
	while(test != NULL){
		printf("\n !!Arquivo '%s' já existe!!\n\n", name_archive);
		printf(" Digite o nome do novo Arquivo: ");
		scanf("%s", name_archive);
		test = fopen(name_archive,"r+");
	}

	FILE *archive = fopen(name_archive,"w");

	fprintf(archive, "P3\n");
	fprintf(archive, "%d ", cl*2);
	fprintf(archive, "%d\n", ln*2);
	fprintf(archive, "%d\n", lmt);
	cl *= 2;
	ln *= 2;
	for(i = 0; i < ln; i++)
	{	
		for(int k = 0; k<2; k++)
		{
		for(j = 0; j < cl/2; j++)
		{	

			fprintf(archive,"%d ", img[i][j].R);
			fprintf(archive,"%d ", img[i][j].G);
			fprintf(archive,"%d ", img[i][j].B);
			fprintf(archive,"%d ", img[i][j].R);
			fprintf(archive,"%d ", img[i][j].G);
			fprintf(archive,"%d ", img[i][j].B);	
		}
		}
	}
	fclose(archive);

	printf("\n");
	printf(" Arquivo salvo com sucesso!\n");
	vsl(name_archive);
}








void options(pxl img[DIM][DIM], char *cod, int *lmt, int *cl, int*ln)
{
	cmd();

	int acao;
	printf("\n");
	printf(" Informe o comando: ");
	scanf("%d", &acao);
	while(acao<1 || acao>7){
		printf(" Informe o comando: ");
		scanf("%d", &acao);
	}
	//grey(img,*cl,*ln);
	//save(img,*lmt,*cl,*ln);
	switch(acao)
	{

		case 1:
		grey(img,*cl,*ln);
		save(img,*lmt,*cl,*ln);
		break;

		case 2:
		break;

		case 3:
		break;

		case 4:
		break;

		case 5:
		rot(img,*lmt,*cl,*ln);
		break;

		case 6:
		amp(img,*lmt,*cl,*ln);
		break;

		case 7:
		rdz(img,*lmt,*cl,*ln);
		break;


	    default :
    	printf ("Valor invalido!\n");

	}


}
	
