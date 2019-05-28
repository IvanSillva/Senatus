#include "tela.h"
#include "functions.h"
#define MAX 600


int main()
{
	
	pxl img[MAX][MAX];
	char cod[3];
	int lmt;
	int lrg, alt;
	int temp;
	temp = tela_inicio();

	if(temp == 1){
	read(img, cod, &lmt, &lrg, &alt);
		}else if(temp == 0)
			{
			printf("\33[H\33[2J");
			cbc();
			printf("Programa Encerrado!\n");
			exit(0);

			}

				return 0;
}