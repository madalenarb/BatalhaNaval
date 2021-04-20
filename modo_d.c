#include "modo_d.h"

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

void disparo_1(int tabuleiro[25][35], int tabuleiro3[25][35], int disparosMin,int linhas, int colunas){
    int randcol = 0;
    int randlin = 0;
    int flag = 0;
    char id_peca; 
        
    apagar_tabuleiro(tabuleiro3, linhas, colunas);
    
    while( disparosMin > 0 || flag == 1 ){
        randcol = (rand()%colunas);
        randlin = (rand()%linhas);
        
        printf("\n%d", tabuleiro3[randlin][randcol]);
        if(tabuleiro3[randlin][randcol] == 0){
                tabuleiro3[randlin][randcol] = -2;
                scanf("%c", id_peca);
                int id_pecanum = id_peca - '0';
                if(id_peca == '-'){
                    tabuleiro3[randlin][randcol] = -2;
                 }
                else if(id_pecanum > 0){
                    tabuleiro3[randlin][randcol] = id_pecanum;
                }
                printf("%c\n",id_peca);
        }       
    
    flag = verificar_tab(tabuleiro, linhas, colunas);   
    }   

}

//verifica se a matriz 3x3 ainda tem peças. caso encontre uma peça retorna 1, se nao houverem peças retorna 0
int verificar_matriz(int tabuleiro[25][35]){
    int i,j = 0;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(tabuleiro[i][j] != 0){
              return 1;
            }
        }
    }
 return 0;
}




void disparo_2(int tabuleiro[25][35], int tabuleiro3[25][35]){
    int flag;
    int i = 0;
    //estes dois arrays servem para fazer a sequencia pretendida de disparo dentro da matriz 3x3
    int seqlin[] = { 1,0,2,1,1,0,2,0,2};
    int seqcol[] = { 1,1,1,0,2,0,2,2,0};
    int poscoluna = 0;
    int poslinha = 0;
    flag = 1;

    while(flag == 1 && i < 9){
        if (tabuleiro[poslinha+seqlin[i]][poscoluna+seqcol[i]] == 0 ){
            tabuleiro3[poslinha+seqlin[i]][poscoluna+seqcol[i]] = 9;
        }
        if(tabuleiro[poslinha+seqlin[i]][poscoluna+seqcol[i]] !=0 ){
            tabuleiro3[poslinha+seqlin[i]][poscoluna+seqcol[i]] = tabuleiro[poslinha+seqlin[i]][poscoluna+seqcol[i]];
            tabuleiro[poslinha+seqlin[i]][poscoluna+seqcol[i]] = 0;
            
            flag = verificar_matriz( tabuleiro); 
        }
        i++;
             
    }
}

void disparo_3(int tabuleiro[25][35], int tabuleiro3[25][35]){
    int flag,j,k;
    int i = 0;
    //estes dois arrays servem para fazer a sequencia pretendida de disparo dentro da matriz 3x3
    int seqlin[] = { 1,0,2,1,1,0,2,0,2};
    int seqcol[] = { 1,1,1,0,2,0,2,2,0};
    int poscoluna = 0;
    int poslinha = 0;
    flag = 1;

    while(flag == 1 && i < 9 ){
        if (tabuleiro[poslinha+seqlin[i]][poscoluna+seqcol[i]] == 0 ){
            tabuleiro3[poslinha+seqlin[i]][poscoluna+seqcol[i]] = 9;
        }
        if(tabuleiro[poslinha+seqlin[i]][poscoluna+seqcol[i]] != 0 && tabuleiro[poslinha+seqlin[i]][poscoluna+seqcol[i]] != 9 ){
            tabuleiro3[poslinha+seqlin[i]][poscoluna+seqcol[i]] = tabuleiro[poslinha+seqlin[i]][poscoluna+seqcol[i]];
            tabuleiro[poslinha+seqlin[i]][poscoluna+seqcol[i]] = 0;
            for(j = -1; j < 2; j++){
                if(tabuleiro[poslinha+seqlin[i]+j][poscoluna+seqcol[i]+1] == 0){
                tabuleiro3[poslinha+seqlin[i]+j][poscoluna+seqcol[i]+1] = 9;
                }
            }
            if(tabuleiro[poslinha+seqlin[i]+1][poscoluna+seqcol[i]] == 0){
                tabuleiro[poslinha+seqlin[i]+1][poscoluna+seqcol[i]] = 9;
            }
            if(tabuleiro[poslinha+seqlin[i]+1][poscoluna+seqcol[i]-1] == 0){
                tabuleiro3[poslinha+seqlin[i]+1][poscoluna+seqcol[i]-1] = 9;
            }
            
            flag = verificar_matriz(tabuleiro);
        }
        i++;
    }
}