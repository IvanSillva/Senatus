#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void cbc(); //Cabeçalho
int opc();	//Lista de opções
void tela_inicio(); //Tela Inicial
void cmd(); //Comandos do usuário
void vsl(char name_archive[500]);//Visualizar na tela
void load(char name_archive[500], char comand[500]);//Tela de carregamento