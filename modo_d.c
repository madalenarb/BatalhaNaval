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
int verificar_mat(int tabuleiro3[25][35],int id_pecanum,int a,int b){
   int i,j;
   int numpecas = 0;
   for(i = 0; i<3; i++){
       for(j = 0;j<3; j++){
          if ( tabuleiro3[a+i][b+j]>0){
            numpecas++;
            if (numpecas == id_pecanum){
            return 0;
            }
          }
       }
    }
    return 1;
}

void disparo_1(int tabuleiro[25][35], int tabuleiro3[25][35], int disparosMin, int disparosMax, int linhas, int colunas){
    int randCol = 0;
    int randLin = 0;
    int flag = 0;
    int n_disparos = 0;
    char id_peca; 
    char charRandLin;
    char charRandCol;   
    apagar_tabuleiro(tabuleiro3, linhas, colunas);
    //imprimir_tabuleiro(tabuleiro3, linhas, colunas);
    
    
    while( disparosMin > 0 && n_disparos < disparosMax ){
        randCol = (rand()%colunas);
        randLin = (rand()%linhas);
        charRandLin = (linhas-randLin)+ '0';
        charRandCol = randCol + 'A';
        
        if(tabuleiro3[randLin][randCol] == 0 ){

                id_peca = resposta(charRandCol, charRandLin);
                //printf("%d\n",id_pecanum);
                //printf("%d\n",id_peca);
<<<<<<< HEAD
                if(id_peca == '-'){
                    tabuleiro3[randlin][randcol] = -2;
                    //printf("%c",'-');
                }
                else if(id_pecanum > 0){
                    tabuleiro3[randlin][randcol] = id_pecanum;
                    disparosMin --;
=======
                if(id_peca == 0){
                    tabuleiro3[randLin][randCol] = -2;
                    //printf("%c",'-');
                }
                else if(id_peca > 0){
                    tabuleiro3[randLin][randCol] = id_peca;
                    disparosMin--;
>>>>>>> 5da33d96c24071a1cabdc2e8366374477ee16425
                    //printf("%d",id_pecanum);
                } 
                n_disparos--;
        }         
    }       
}

int resposta(char charCol, char charLin)
{
    int id_peca = 0;
    printf("%c%c\n", charCol, charLin);
    int tipo_peca_num = 0;
    id_peca = getchar();
    getchar();
    
    int id_peca_num = id_peca - '0';
    
    if(id_peca == '-'){
        id_peca_num = 0;
    } else if (id_peca_num > 0){
        id_peca_num = id_peca - '0';
    }
    return id_peca_num;
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




<<<<<<< HEAD
void disparo_2(int tabuleiro[25][35], int tabuleiro3[25][35],int disparosMin,int linhas,int colunas){
    int flag;
    int id_pecanum;
=======
void disparo_2(int tabuleiro[25][35], int tabuleiro3[25][35], int linhas, int colunas, int submat){
    int flag;
    char charLin;
    char charCol;  
>>>>>>> 5da33d96c24071a1cabdc2e8366374477ee16425
    int i = 0;
    char id_peca;
    char linha,coluna;
    int a,b,c;
    //estes dois arrays servem para fazer a sequencia pretendida de disparo dentro da matriz 3x3
    int seqlin[] = { 1,0,2,1,1,0,2,0,2 };
    int seqcol[] = { 1,1,1,0,2,0,2,2,0 };
    int poscoluna = 0;
    int poslinha = 0;
<<<<<<< HEAD
    flag = 1;
    int flag2 = 1;
    apagar_tabuleiro(tabuleiro3, linhas, colunas);
    while(flag == 1 && disparosMin > 0){
        for (a = 0; a<linhas;  a+=3){
            for ( b = 0; b<colunas; b+=3){
                flag2 =1;
                i = 0;
                while(flag2 == 1 && i<9){
                        if (tabuleiro3[a+seqlin[i]][b+seqcol[i]] == 0 ){
                            printf("linha é:%d\n",a);
                            printf("coluna é:%d\n",b);
                            linha = (linhas - (a+seqlin[i]))+ '0';
                            coluna = (b+seqcol[i])+'A';
                            printf("%c%c\n",coluna,linha); 
                            id_peca = getchar();
                            getchar();
                            int id_pecanum = id_peca - '0';

                            if(id_peca == '-'){
                            tabuleiro3[a+seqlin[i]][b+seqcol[i]] = -2;
                            }
                            else if(id_pecanum > 0){
                            tabuleiro3[a+seqlin[i]][b+seqcol[i]] = id_pecanum;
                            disparosMin --;
                            printf("disparosminimos:%d\n",disparosMin);
                            flag2 =verificar_mat(tabuleiro3,id_pecanum,a,b);
                            //printf("%d",id_pecanum);
                            }          
                            printf("a flag2 é =%d\n",flag2);           
                        }
                        i++;
                        
                        imprimir_tabuleiro(tabuleiro3, linhas, colunas);
                }
            }
        }      
=======
    int pos = 0;

    for( pos = 0; pos < submat; pos++ ){
        for( i = 0; i < 9; i++ ){
            if (tabuleiro[poslinha + seqlin[i]][poscoluna + seqcol[i]] == 0 ){
                tabuleiro3[poslinha + seqlin[i]][poscoluna + seqcol[i]] = -2;
            }
            if(tabuleiro[poslinha + seqlin[i]][poscoluna + seqcol[i]] != 0 ){
                tabuleiro3[poslinha + seqlin[i]][poscoluna + seqcol[i]] = tabuleiro[poslinha+seqlin[i]][poscoluna+seqcol[i]];
                tabuleiro[poslinha + seqlin[i]][poscoluna + seqcol[i]] = 0;
            }
            charLin = (linhas - (poslinha + seqlin[i])) + '0';
            charCol = (poscoluna + seqcol[i]) + 'A';
        }
        poscoluna += 3;
        if( poscoluna >= colunas - 1 ){
            poscoluna = 0;
            poslinha += 3;
        }
>>>>>>> 5da33d96c24071a1cabdc2e8366374477ee16425
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