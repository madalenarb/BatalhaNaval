#include "headers.h"

void imprimir_tabuleiro(int tabuleiro[25][35], int linhas, int colunas);
int submat(int linhas, int colunas);
void apagar_tabuleiro( int tabuleiro[25][35], int linhas, int colunas );
void apagar_submat(int tabuleiro[25][35], int poslinha, int poscoluna);
int verificar_tab(int tabuleiro[25][35], int colunas, int linhas);