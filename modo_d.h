#include "headers.h"
#include "bibliotecadepecas.h"
#include "tabuleiro.h"

int verificar_tab(int tabuleiro[25][35], int colunas, int linhas);
int resposta(char charCol, char charLin);
void disparo_1(int tabuleiro[25][35], int tabuleiro3[25][35], int disparosMin, int disparosMax, int linhas, int colunas);
int verificar_matriz(int tabuleiro[25][35]);
int verificar_mat(int tabuleiro3[25][35], int id_peca, int a, int b);
void disparo_2(int tabuleiro[25][35], int tabuleiro3[25][35], int disparosMin, int linhas,int colunas);
void disparo_3(int tabuleiro[25][35],int tabuleiro3[25][35]);