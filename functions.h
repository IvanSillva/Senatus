#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tela.h"


//Structs para os pixels
typedef struct 
{
    int R, G, B; 
}pxl;

//Ler Imagem, e por na matriz.
void read();
void options(pxl **img, char *cod, int *lmt, int *cl, int*ln);
void save(pxl **img, int lmt, int cl, int ln);
void grey (pxl **img, int cl, int ln);
void rot(pxl **img, int lmt, int cl, int ln);
void rdz(pxl **img, int lmt, int cl, int ln);
void thr(pxl **img, int cl, int ln);
void blur(pxl **img, int cl, int ln);
void sharp(pxl **img, int cl, int ln);
void ngtv(pxl **img, int cl, int ln);
void freememory(pxl **img, int cl, int ln, int i);
void dtcb(pxl **img,int lmt, int cl, int ln);