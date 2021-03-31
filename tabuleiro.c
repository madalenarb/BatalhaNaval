#include "headers.h"
#include "tabuleiro.h"

void imprimir_tabuleiro(int tabuleiro[15][24], int linhas, int colunas)
{
    int i, j, v;
    for ( i = 0; i < linhas; i++ ){
        printf("%2d|| ", i + 1);
        for ( j = 0; j < colunas; j++ ){
            printf( "%d |", tabuleiro[j][i]);
        }
        printf("\n");
    }
    printf("     A");
    for (v = 0; v < colunas - 1; v++)
    {
        printf("  %c", (char)'B' + v);
    }
    
    printf("\n\n");
}