#include "headers.h"
#include "bibliotecadepecas.h"
#include "tabuleiro.h"

int verificar_tab(int tabuleiro[25][35], int colunas, int linhas);
void disparo_1(int tabuleiro[25][35],int tabuleiro3[25][35], int disparosMin,int colunas, int linhas);
int verificar_matriz(int tabuleiro[25][35]);
void disparo_2(int tabuleiro[25][35],  int tabuleiro3[25][35],int disparosMin,int linhas,int colunas);
void disparo_3(int tabuleiro[25][35],int tabuleiro3[25][35]);
int verficar_mat(int tabuleiro3[25][35], int id_pecanum, int a,int b);