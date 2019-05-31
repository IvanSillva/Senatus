#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//Iniciar GCC mais facilmente.s
int main(){
	system("gcc main.c tela.c tela.h functions.c functions.h");
	system("./a.out");
}