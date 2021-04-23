#include "headers.h"
#include "bibliotecadepecas.h"
#include "tabuleiro.h"

int return_id_global( int id_peca, int id_variante);
int variante_max(int id_peca);
int variante_aleatoria(int id_peca);
void print_peca( int id_global, int tabuleiro[25][35], int poslinha, int poscoluna);
void analisar_pecas(int tabuleiro[25][35], int tabuleiro2[25][35], int linhas, int colunas);
int verificar_pecas(int tabuleiro[25][35], int tabuleiro2[25][35], int poslinha, int poscoluna);
int id_global_aleatorio(void);