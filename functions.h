#include <stdio.h>
#include <stdlib.h>
#define MAX 600

typedef struct 
{
    int R, G, B; 
}pxl;


void read(pxl img[MAX][MAX], char *cod, int *lmt, int *cl, int*ln);