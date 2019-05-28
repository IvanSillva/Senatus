#include <stdio.h>
#include <stdlib.h>
#define DIM 600

//Structs para os pixels
typedef struct 
{
    int R, G, B; 
}pxl;

//Ler Imagem, e por na matriz.
void read(pxl img[DIM][DIM], char *cod, int *lmt, int *cl, int*ln);
void options(pxl img[DIM][DIM], char *cod, int *lmt, int *cl, int*ln);
void grey (pxl img[DIM][DIM], int *cl, int *ln);