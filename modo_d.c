#include "modo_d.h"

int verificar_tab(int tabuleiro[25][35],int colunas,int linhas){
    int i,j;
    for (i=0; i<colunas; i++){
        for (j=0; j<linhas; j++){
             if (tabuleiro[i][j] != 0){
                return 1;
            }

        }
    }
    return 0;  
}
void disparo1(int tabuleiro3[25][35],int tabuleiro[25][35],int colunas,int linhas){
    int randcol, randlin,flag, contador;
        
    randcol = (rand()%colunas) ;
    randlin = (rand()%linhas) ;
    
    if(tabuleiro3[randcol][randlin] == 0){
            
        if (tabuleiro[randcol][randlin] == 0){
                tabuleiro3[randcol][randlin] = 9;
        }
        if (tabuleiro[randcol][randlin] > 0){
                tabuleiro3[randcol][randlin] = tabuleiro[randcol][randlin];
                tabuleiro[randcol][randlin] = 0;
        }
           
        }                   
}

