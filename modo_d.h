#include "headers.h"
#include "bibliotecadepecas.h"
#include "tabuleiro.h"

int verificar_tab(int tabuleiro[25][35], int colunas, int linhas);
int resposta(char charCol, char charLin);
void disparo_1(int tabuleiro[25][35], int tabuleiro3[25][35], int disparosMin, int disparosMax, int linhas, int colunas);
int verificar_matriz(int tabuleiro[25][35]);
void disparo_2(int tabuleiro[25][35], int tabuleiro3[25][35], int linhas, int colunas, int submat);
void disparo_3(int tabuleiro[25][35],int tabuleiro3[25][35]);