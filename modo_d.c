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

void disparo_1(int tabuleiro[25][35], int tabuleiro3[25][35], int disparosMin,int linhas, int colunas){
    int randcol = 0;
    int randlin = 0;
    int flag = 0;
    char id_peca; 
    char charndlin ;
    char charndcol;   
    apagar_tabuleiro(tabuleiro3, linhas, colunas);
    imprimir_tabuleiro(tabuleiro3, linhas, colunas);
    
    
    while( disparosMin > 0 || flag == 1 ){
        randcol = (rand()%colunas);
        randlin = (rand()%linhas);
        charndlin = (linhas-randlin)+ '0';
        charndcol = randcol + 'A';
        
        if(tabuleiro3[randlin][randcol] == 0 ){
                printf("\n%c%c\n",charndlin, charndcol);
                
                id_peca = getchar();
                getchar();
                
                int id_pecanum = id_peca - '0';
                
                //printf("%d\n",id_pecanum);
                //printf("%d\n",id_peca);
                if(id_peca == '-'){
                    tabuleiro3[randlin][randcol] = -2;
                    //printf("%c",'-');
                }
                else if(id_pecanum > 0){
                    tabuleiro3[randlin][randcol] = id_pecanum;
                    disparosMin --;
                    //printf("%d",id_pecanum);
                } 
        }    
                     
    }       
        flag = verificar_tab(tabuleiro, linhas, colunas);   
      

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




void disparo_2(int tabuleiro[25][35], int tabuleiro3[25][35],int disparosMin,int linhas,int colunas){
    int flag;
    int id_pecanum;
    int i = 0;
    char id_peca;
    char linha,coluna;
    int a,b,c;
    //estes dois arrays servem para fazer a sequencia pretendida de disparo dentro da matriz 3x3
    int seqlin[] = { 1,0,2,1,1,0,2,0,2};
    int seqcol[] = { 1,1,1,0,2,0,2,2,0};
    int poscoluna = 0;
    int poslinha = 0;
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