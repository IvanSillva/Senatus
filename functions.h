#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tela.h"
#define DIM 600

//Structs para os pixels
typedef struct 
{
    int R, G, B; 
}pxl;

//Ler Imagem, e por na matriz.
void read(pxl img[DIM][DIM], char *cod, int *lmt, int *cl, int*ln);
void options(pxl img[DIM][DIM], char *cod, int *lmt, int *cl, int*ln);
void grey (pxl img[DIM][DIM], int cl, int ln);
void save(pxl img[DIM][DIM], int lmt, int cl, int ln);
void rot(pxl img[DIM][DIM], int lmt, int cl, int ln);
void rdz(pxl img[DIM][DIM], int lmt, int cl, int ln);
void thr(pxl img[DIM][DIM], int cl, int ln);
void blur(pxl img[DIM][DIM], int cl, int ln);
void sharp(pxl img[DIM][DIM], int cl, int ln);
void ngtv(pxl img[DIM][DIM], int cl, int ln);