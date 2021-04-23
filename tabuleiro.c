#include "tabuleiro.h"

/* 
* Função: submat
*
* \brief função que retorna o número de matrizes 3x3 existentes no
tabuleiro 
* 
* \param colunas int: número de colunas do tabuleiro
* 
* \param linhas int: número de linhas do tabuleiro
*
* \return int: linhas * colunas, corresponde ao número total de 
matrizes 3x3 existentes no tabuleiro.
*/
int submat(int colunas, int linhas)
{
    /* comprimento: número de matrizes 3x3 que existem na horizontal  */
    int comprimento = colunas / 3;
    /* largura: número de matrizes 3x3 que existem na vertical  */
    int largura = linhas / 3;
    return (comprimento * largura);
}

/*
* Função: imprimir_tabuleiro
*
* /brief função que imprime o tabuleiro
*
* \param tabuleiro int: 
*/

void imprimir_tabuleiro(int tabuleiro[25][35], int linhas, int colunas)
{
    int i, j, v;
    for ( i = 0; i < linhas; i++ ){
        printf("%2d|| ", linhas - i );
        for ( j = 0; j < colunas; j++ ){
            if(tabuleiro[i][j] == 0 || tabuleiro[i][j] == -2){
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
}

void apagar_submat(int tabuleiro[25][35], int poslinha, int poscoluna)
{
    int i, j;
    for ( i = 0; i < 3; i++ ){
        for ( j = 0; j < 3; j++ ){
            tabuleiro[i + poslinha][j+ poscoluna] = 0;
            }
        }
}

/* 
* Função: verificar_tab
*
* \brief funçao que verifica se todas as peças do tabuleiro já foram encontradas, no modo de jogo 1,
ou seja rastreia o tabuleiro, verificando se todas as posições do tabuleiro
estão a 0
*
* \param tabuleiro int: tabuleiro que será verificado
*
* \param linhas int: número de linhas do tabuleiro
*
* \param colunas int: número de colunas do tabuleiro
*
* \return int: 1 se atingiu todas as peças, 0 se ainda houverem peças
por atingir
*  
*/
int verificar_tab(int tabuleiro[25][35], int linhas, int colunas){
    int i,j;
    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
             if (tabuleiro[i][j] != 0){
                return 1;
            }

        }
    }
    return 0;
}