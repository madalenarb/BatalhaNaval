#include "headers.h"
#include "tabuleiro.h"

// retorna o número de matrizes 3x3
int submat(int colunas, int linhas)
{
    int comprimento = colunas/3;
    int largura = linhas/3;
    return (comprimento * largura);
}


void imprimir_tabuleiro(int tabuleiro[25][35], int linhas, int colunas)
{
    int i, j, v;
    for ( i = 0; i < linhas; i++ ){
        printf("%2d|| ", linhas - i );
        for ( j = 0; j < colunas; j++ ){
            if(tabuleiro[i][j] == 0){
                printf( "- " );
            } else if (tabuleiro[i][j] > 0 && tabuleiro[i][j] < 9) {
                printf("%d ", tabuleiro[i][j]);
            } else if ( tabuleiro[i][j] == 9 ){
                printf("x ");
            }
        }
        printf("\n");
    }
    //Imprime as letras
    printf("     A");
    for (v = 0; v < colunas - 1; v++)
    {
        printf(" %c", (char)'B' + v);
    }
    
    printf("\n\n");
    
}

void apagar_tabuleiro( int tabuleiro[25][35], int linhas, int colunas )
{
   int i, j;
    for ( i = 0; i < linhas; i++ ){
        for ( j = 0; j < colunas; j++ ){
            tabuleiro[i][j] = 0;
            }
    }
    printf("\n");
}

void apagar_submat(int tabuleiro[25][35], int poslinha, int poscoluna)
{
    int i, j;
    for ( i = 0; i < 3; i++ ){
        for ( j = 0; j < 3; j++ ){
            tabuleiro[i + poslinha][j+ poscoluna] = 0;
            }
        }
        printf("\n");   
}