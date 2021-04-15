#include "pecas.h"

int return_id_global( int id_peca, int id_variante)
{
    int id_global = 0;
    if (id_peca > 0 && id_peca < 43)
    {
    
        switch (id_peca)
        {
            case 1:
                (id_global) = id_variante;
                break;

            case 2:
                (id_global) = id_variante + 9;   
                break;

            case 3:
                (id_global) = id_variante + 21;
                break;

            case 4:
                (id_global) = id_variante + 27;
                break;   

            case 5:
                (id_global) = id_variante + 31;
                break;   

            case 6:
                (id_global) = id_variante + 35;
                break;

            case 7:
                (id_global) = id_variante + 39;
                break;

            case 8:
                (id_global) = 42;
                break;
            default:
                break;
        }
    }
    return id_global;
}


int variante_max(int id_tipo){
    int varianteMax = 0;
    switch (id_tipo)
    {
    case 1:
        varianteMax = 9;
        break;

    case 2:
        varianteMax = 12;
        break;

    case 3:
        varianteMax = 6;
        break;

    case 4:
    case 5:
    case 6:
        varianteMax = 4;
        break;

    case 7:
        varianteMax = 2;
        break;

    case 8:
        varianteMax = 1;
        break;
    
    default:
        break;
    }
    return varianteMax;
}

int variante_aleatoria(int id_tipo){
    int variante = 0;
    switch (id_tipo)
    {
    case 1:
        variante = (rand()%9) + 1;
        break;

    case 2:
        variante = (rand()%12) + 1;
        break;

    case 3:
        variante = (rand()%6) + 1;
        break;

    case 4:
    case 5:
    case 6:
        variante = (rand()%4) + 1;
        break;

    case 7:
        variante = (rand()%2) + 1;
        break;

    case 8:
        variante = 1;
        break;
    
    default:
        break;
    }
    return variante;
}

int id_global_aleatorio(void){
int id_global = 0;
id_global = rand()%43;
return id_global;
}


//retrição 1

void analisar_pecas(int tabuleiro[25][35], int tabuleiro2[25][35], int linhas, int colunas)
{
    int i,j,n;
    for ( i = 0; i < linhas + 1 ; i++ ){
        for ( j = 0; j < colunas + 1; j++ )
        {

            if ( tabuleiro[i][j] > 0 ){
                if( i > 0 && j < colunas ){
                    if( tabuleiro[i - 1][j + 1] == 0 ){
                        tabuleiro2[i - 1][j + 1] = -1;
                    }
                }

                if( i < linhas && j < colunas ){
                    if ( tabuleiro[i + 1][j + 1] == 0 ){
                        tabuleiro2[i + 1][j + 1] = -1;
                    }
                }

                if( i < linhas && j > 0 ){
                    if(tabuleiro[ i + 1 ][j - 1] == 0){
                        tabuleiro2[ i + 1 ][j - 1] = -1;
                    }
                }

                if( i < linhas ){
                    if (tabuleiro[ i + 1 ][j] == 0){
                        tabuleiro2[i + 1][j] = -1;
                    }
                }

                if( j < colunas ){
                    if ( tabuleiro[i][j + 1] == 0 ){
                        tabuleiro2[i][j + 1] = -1;
                    }
                }
            }
        }
    }
}

int verificar_pecas(int tabuleiro[25][35], int tabuleiro2[25][35], int poslinha, int poscoluna)
{
    int i = 0, j = 0;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (tabuleiro[i + poslinha][j + poscoluna] > 0){
                if ( tabuleiro2[i + poslinha][j + poscoluna] == -1){
                    return 1;
                }
            }
        }
    }
    return 0;
}