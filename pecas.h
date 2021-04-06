#include "headers.h"
#include "bibliotecadepecas.h"

int return_id_global( int id_peca, int id_variante);
void coloca_peca(int tabuleiro[25][35], int submat, int linhas, int colunas);
void print_peca( int id_peca, int id_variante, int tabuleiro[25][35], int poslinha, int poscoluna);
void analisar_pecas(int tabuleiro[25][35], int tabuleiro2[25][35], int colunas, int linhas);
int rand_variante(int tipoPeca);
int verificar_pecas(int tabuleiro[25][35], int tabuleiro2[25][35], int poslinha, int poscoluna);
int tipo_peca();
int det_variante(int tipoPeca);