#include "headers.h"
#include "bibliotecadepecas.h"
#include "tabuleiro.h"

int return_id_global( int id_peca, int id_variante);
void coloca_peca(int tabuleiro[25][35], int submat, int linhas, int colunas);
void print_peca( int id_global, int tabuleiro[25][35], int poslinha, int poscoluna);
void analisar_pecas(int tabuleiro[25][35], int tabuleiro2[25][35], int colunas, int linhas);
int verificar_pecas(int tabuleiro[25][35], int tabuleiro2[25][35], int poslinha, int poscoluna);
int id_global_aleatorio(void);
int det_variante(int tipoPeca);