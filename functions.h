#include <stdio.h>
#include <stdlib.h>
#define MAX 600
//Structs para os pixels
typedef struct 
{
    int R, G, B; 
}pxl;

//Ler Imagem, e por na matriz.
void read(pxl img[MAX][MAX], char *cod, int *lmt, int *cl, int*ln);