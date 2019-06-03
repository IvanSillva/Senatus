#include "tela.h"
#include "functions.h"


int main()
{
	
	pxl img[DIM][DIM];
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