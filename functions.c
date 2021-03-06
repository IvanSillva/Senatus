#include "functions.h"


void reading()
{

	char cod[3];
	int lmt;
	int ln, cl;
	int i, j;
	cbc();
	
	char name_archive[60];

	printf("\n██ Digite o nome do Arquivo: ");

	scanf("%s", name_archive);

	FILE *archive = fopen(name_archive,"r");

	while( archive == NULL ) 
	{
		printf("\n██ !Arquivo não existente, tente novamente! ██\n" );
		printf("\n██ Digite o nome do Arquivo: ");
		scanf(" %s", name_archive);
		archive = fopen(name_archive,"r");
	}
	
	load(name_archive, "Abrindo");

	printf("██ Arquivo '%s' aberto com sucesso! \n", name_archive);
	sleep(0.5);

	fscanf(archive, "%s", cod);
	fscanf(archive, "%d", &cl);
	fscanf(archive, "%d", &ln);
	fscanf(archive, "%d", &lmt);

	pxl **img;

	img = (pxl**)calloc(ln,sizeof(pxl*));

	for(i=0;i<ln;i++)
	{ 
   	 	img[i] = (pxl*)calloc(cl,sizeof(pxl));
	}

	for(i = 0; i < ln; i++)
	{
		for(j = 0; j < cl; j++)
		{
			fscanf(archive,"%d", &img[i][j].R);
			fscanf(archive,"%d", &img[i][j].G);
			fscanf(archive,"%d", &img[i][j].B);
		}
	}

	fclose(archive);

	cmd();

	options(img, cod, &lmt, &cl, &ln);
}

void freememory(pxl **img, int cl, int ln, int i)
{
	
    if(i<ln)
    {
      
      free(img[i]);

      return freememory(img, cl, ln, i+1);
    }
    else
    {
  		return free(img);		
    }	
}

void save(pxl **img, int lmt, int cl, int ln)
{
	int i, j;

	char name_archive[60];
	printf("\n");
	printf("██ Digite o nome do novo Arquivo: ");
	scanf("%s", name_archive);

	FILE *test = fopen(name_archive,"r+");

	while(test != NULL)
	{
		printf("\n██ !Arquivo '%s' já existe! ██\n\n", name_archive);
		printf("██ Digite o nome do novo Arquivo: ");
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

	load(name_archive, "Salvando");

	printf("\n");
	printf("██ Arquivo salvo com sucesso!\n");
	vsl(name_archive);
}

void grey (pxl **img, int cl, int ln)
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

		}
	}
}

void thr(pxl **img, int cl, int ln)
{
	

	int j, i, media =0, limit;

	printf("\n██ Valor Limite: ");


	scanf("%d", &limit);


	for(i =0; i<ln; i++)
	{
		for(j =0; j<cl; j++)
		{
			
			media = (img[i][j].R + img[i][j].G + img[i][j].B) / 3;


			if(media > limit)
			{
				img[i][j].R = 255;
				img[i][j].G = 255;
				img[i][j].B = 255;

			}
			else
			{
				img[i][j].G = 0;
				img[i][j].R = 0;
				img[i][j].B = 0;


			}
		}

	}
}

void ngtv(pxl **img, int cl, int ln)
{
	

	int j, i, media =0, limit;

	printf("\n██ Valor Limite: ");


	scanf("%d", &limit);


	for(i =0; i<ln; i++)
	{
		for(j =0; j<cl; j++)
		{
			
			media = (img[i][j].R + img[i][j].G + img[i][j].B) / 3;


			if(media > limit)
			{
				img[i][j].R = 0;
				img[i][j].G = 0;
				img[i][j].B = 0;

			}
			else
			{
				img[i][j].G = 255;
				img[i][j].R = 255;
				img[i][j].B = 255;


			}
		}

	}
}

void rot(pxl **img, int lmt, int cl, int ln)
{
	int i, j, a,b;

	pxl **imgrot;

	int ang;
	printf("\n");
	printf("██ 1 - Direita | 2 - Esquerda | 3 - Inverter ██\n");
	printf("\n");
	printf("██ Informe a orientação: ");
	scanf("%d", &ang);

	while (ang > 3 || ang <1)
	{
		printf("██ Opção Invalida! ██\n");
		printf("██ Informe a orientação: ");
		scanf("%d", &ang);
	}

	if(ang == 3 )
	{	
		imgrot = (pxl**)calloc(ln,sizeof(pxl*));

		for(i=0;i<ln;i++)
		{ 
   	 		imgrot[i] = (pxl*)calloc(cl,sizeof(pxl));
		}


		for(i = ln-1, a =0; i >=0; i--)
		{
			for(j = cl-1, b=0; j >= 0; j--)
			{
				imgrot[a][b].R = img[i][j].R;
				imgrot[a][b].G	= img[i][j].G;
				imgrot[a][b].B	= img[i][j].B;
				b++;
			}
			a++;
		}	

		save(imgrot,lmt,cl,ln);
	}

	if(ang == 2 )
	{	
		imgrot = (pxl**)calloc(cl,sizeof(pxl*));

		for(i=0;i<cl;i++)
		{ 
   	 		imgrot[i] = (pxl*)calloc(ln,sizeof(pxl));
		}

		for(i = cl-1, a=0; i >= 0; i--)
		{
			for(j = 0, b=0; j <= ln-1; j++)
			{
				imgrot[a][b].R = img[j][i].R;
				imgrot[a][b].G = img[j][i].G;
				imgrot[a][b].B = img[j][i].B;
				b++;
			}
			a++;
		}	

		save(imgrot,lmt,ln,cl);	
	}

	if(ang == 1 )
	{	
		imgrot = (pxl**)calloc(cl,sizeof(pxl*));

		for(i=0;i<cl;i++)
		{ 
   	 		imgrot[i] = (pxl*)calloc(ln,sizeof(pxl));
		}
		
		for(i = 0, a=0; i <= cl - 1; i++)
		{
			for(j = ln - 1, b=0; j >= 0; j--)
			{
				imgrot[a][b].R = img[j][i].R;
				imgrot[a][b].G = img[j][i].G;
				imgrot[a][b].B = img[j][i].B;
				b++;
			}
			a++;
		}	
		save(imgrot,lmt,ln,cl);
	}	
}

void rdz(pxl **img, int lmt, int cl, int ln)
{
	int i, j, n;
	int a = 0, b = 0;

	printf("\n██ Nivel de Redução: ");
	scanf("%d", &n);

	pxl **imgred;

	imgred = (pxl**)calloc(ln/n,sizeof(pxl*));

	for(i=0;i<ln/n;i++)
	{ 
   			imgred[i] = (pxl*)calloc(cl/n,sizeof(pxl));
	}

	for(i = 0; i < (ln/n)-1; i++)
	{	

		for(j = 0; j < (cl/n)-1; j++)
		{	

			imgred[i][j].R = img[a][b].R;
			imgred[i][j].G = img[a][b].G;
			imgred[i][j].B = img[a][b].B;
			b+=n;
		}
		b = 0;
		a+=n;
	}

	cl/=n;
	ln/=n;

	save(imgred,lmt,cl,ln);

	freememory(imgred,cl,ln,0);
}

void amp(pxl **img, int lmt, int cl, int ln)
{
	int i, j, n;

	int a = 0, b = 0;

	printf("\n██ Nivel de Ampliação: ");
	scanf("%d", &n);

	pxl **imgamp;

	imgamp = (pxl**)calloc(ln*n,sizeof(pxl*));

	for(i=0;i<ln*n;i++)
	{ 
   			imgamp[i] = (pxl*)calloc(cl*n,sizeof(pxl));
	}
	
	for(i = 0; i <= ln-1; i++)
	{	
		for(int k = 0; k<n; k++)
		{

			for(j = 0; j <= cl-1; j++)
			{	
				for(int w = 0; w<n; w++)
				{
					imgamp[a][b].R =	img[i][j].R;
					imgamp[a][b].G =	img[i][j].G;
					imgamp[a][b].B =	img[i][j].B;
					b++;
				}
			}
			b=0;
			a++;
		}
		
	}

	cl*=n;
	ln*=n;

	save(imgamp,lmt,cl,ln);

	freememory(imgamp,cl,ln,0);
}

void blur(pxl **img, int cl, int ln)
{
	int i, j, n;

	printf("\n██ Nível de Blurring: ");
	scanf("%d", &n);

 	for(int k = 0; k < n; k++)
 	{
		for(i = 1; i < ln-1; i++)
		{
			for(j = 1; j < cl-1; j++)
			{
				img[i][j].R = (img[i-1][j-1].R + img[i-1][j].R + img[i-1][j+1].R + 
						       img[i][j-1].R + img[i][j].R + img[i][j+1].R +
						       img[i+1][j-1].R + img[i+1][j].R + img[i+1][j+1].R)/9;

				img[i][j].G = (img[i-1][j-1].G + img[i-1][j].G + img[i-1][j+1].G + 
						       img[i][j-1].G + img[i][j].G + img[i][j+1].G +
						       img[i+1][j-1].G + img[i+1][j].G + img[i+1][j+1].G)/9;

				img[i][j].B = (img[i-1][j-1].B + img[i-1][j].B + img[i-1][j+1].B + 
						       img[i][j-1].B + img[i][j].B + img[i][j+1].B +
						       img[i+1][j-1].B + img[i+1][j].B + img[i+1][j+1].B)/9;
			}
		}
	}
}

void sharp(pxl **img, int cl, int ln)
{
	int i, j;

	pxl **imgb;
	imgb = (pxl**)calloc(ln,sizeof(pxl*));

	for(i=0;i<ln;i++)
	{ 
   	 imgb[i] = (pxl*)calloc(cl,sizeof(pxl));
	}


	for(i =0; i<ln;i++)
	{
		for(j =0; j<cl; j++)
		{
			imgb[i][j] = img[i][j];
		}
	}


	for(i = 1; i < ln - 1; i++)
	{
			for(j = 1; j < cl - 1; j++)
			{
				
				img[i][j].R =  5*imgb[i][j].R - imgb[i-1][j].R - imgb[i][j-1].R - imgb[i][j+1].R - imgb[i+1][j].R;

				if(img[i][j].R < 0){
					img[i][j].R = 0;
				}else if(img[i][j].R > 255){
					img[i][j].R = 255;
				}

				img[i][j].G =  5*imgb[i][j].G -imgb[i-1][j].G - imgb[i][j-1].G - imgb[i][j+1].G - imgb[i+1][j].G;

				if(img[i][j].G < 0){
					img[i][j].G = 0;
				}else if(img[i][j].G > 255){
					img[i][j].G = 255;
				}


				img[i][j].B =  5*imgb[i][j].B -imgb[i-1][j].B - imgb[i][j-1].B - imgb[i][j+1].B - imgb[i+1][j].B;

				if(img[i][j].B < 0){
					img[i][j].B = 0;
				}else if(img[i][j].B > 255){
					img[i][j].B = 255;
				}

			}
		}
		freememory(imgb,cl,ln, 0);
	//}
}

void dtcb(pxl **img,int lmt, int cl, int ln)
{
	int i, j;

	pxl **imgb;
	imgb = (pxl**)calloc(ln,sizeof(pxl*));

	for(i=0;i<ln;i++)
	{ 
   	 imgb[i] = (pxl*)calloc(cl,sizeof(pxl));
	}


	for(i =0; i<ln;i++)
	{
		for(j =0; j<cl; j++)
		{
			imgb[i][j] = img[i][j];
		}
	}


	for(i = 1; i < ln - 1; i++)
	{
			for(j = 1; j < cl - 1; j++)
			{
				
				img[i][j].R =  8*imgb[i][j].R - imgb[i-1][j-1].R - imgb[i-1][j].R - imgb[i-1][j+1].R - 
						   	   imgb[i][j-1].R - imgb[i][j+1].R - imgb[i+1][j-1].R - imgb[i+1][j].R - imgb[i+1][j+1].R;

				if(img[i][j].R < 0){
					img[i][j].R = 0;
				}else if(img[i][j].R > 255){
					img[i][j].R = 255;
				}

				img[i][j].G =  8*imgb[i][j].G - imgb[i-1][j-1].G - imgb[i-1][j].G - imgb[i-1][j+1].G - 
						   	     imgb[i][j-1].G - imgb[i][j+1].G - imgb[i+1][j-1].G - imgb[i+1][j].G - imgb[i+1][j+1].G;

				if(img[i][j].G < 0){
					img[i][j].G = 0;
				}else if(img[i][j].G > 255){
					img[i][j].G = 255;
				}


				img[i][j].B =  8*imgb[i][j].B - imgb[i-1][j-1].B - imgb[i-1][j].B - imgb[i-1][j+1].B - 
						   	   imgb[i][j-1].B - imgb[i][j+1].B - imgb[i+1][j-1].B - imgb[i+1][j].B - imgb[i+1][j+1].B;

				if(img[i][j].B < 0){
					img[i][j].B = 0;
				}else if(img[i][j].B > 255){
					img[i][j].B = 255;
				}

			}
		}

		freememory(imgb,cl,ln, 0);
}

void options(pxl **img, char *cod, int *lmt, int *cl, int*ln)
{
	cmd();
	int i, j;
	int acao;
	printf("\n");
	printf("██ Informe o número do comando: ");
	scanf("%d", &acao);

	while(acao<0 || acao>9)
	{	
		printf ("\n██ Número do comando inválido!\n");
		printf("\n██ Informe o número do comando: ");
		scanf("%d", &acao);
	}

	switch(acao)
	{

		case 1:
		grey(img,*cl,*ln);
		save(img,*lmt,*cl,*ln);
		freememory(img,*cl,*ln, 0);
		break;

		case 2:
		thr(img,*cl,*ln);
		save(img,*lmt,*cl,*ln);
		freememory(img,*cl,*ln, 0);
		break;

		case 3:
		blur(img,*cl,*ln);
		save(img,*lmt,*cl,*ln);
		freememory(img,*cl,*ln, 0);
		break;

		case 4:
		sharp(img,*cl,*ln);
		save(img,*lmt,*cl,*ln);
		freememory(img,*cl,*ln, 0);
		break;

		case 5:
		rot(img,*lmt,*cl,*ln);	
		freememory(img,*cl,*ln, 0);
		break;

		case 6:
		amp(img,*lmt,*cl,*ln);
		freememory(img,*cl,*ln, 0);
		break;

		case 7:
		rdz(img,*lmt,*cl,*ln);
		freememory(img,*cl,*ln, 0);
		break;

		case 8:
		ngtv(img,*cl,*ln);
		save(img,*lmt,*cl,*ln);
		freememory(img,*cl,*ln, 0);
		break;

		case 9:
		dtcb(img,*lmt,*cl,*ln);
		save(img,*lmt,*cl,*ln);
		freememory(img,*cl,*ln, 0);
		break;

		case 0:
		system("clear");
		cbc();
		printf("\t\t  ██ Programa Encerrado ██\n\n");
		break;


	    default :
    	printf ("██Valor inválido!██\n");

	}
}


