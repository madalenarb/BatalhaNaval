#include "modo_d.h"
//esta funçao verifica no modo de jogo 1 se todas as peças do tabuleiro ja foram encontradas
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

int disparo_1(int tabuleiro3[25][35], int disparosMin, int disparosMax, int linhas, int colunas){
    int randCol = 0;
    int randLin = 0;
    int n_disparos = 0;
    int contador = 0;
    char id_peca;
    char charRandCol;
    apagar_tabuleiro(tabuleiro3, linhas, colunas);
    //imprimir_tabuleiro(tabuleiro3, linhas, colunas);


    while( disparosMin > 0 && n_disparos < disparosMax ){
        randCol = (rand()%colunas);
        randLin = (rand()%linhas);
        charRandCol = randCol + 'A';

        if(tabuleiro3[randLin][randCol] == 0 ){
                contador++;
                id_peca = resposta(charRandCol, randLin);
                if(id_peca == 0){
                    tabuleiro3[randLin][randCol] = -2;
                }
                else if(id_peca > 0){
                    tabuleiro3[randLin][randCol] = id_peca;
                    disparosMin--;
                }
                n_disparos--;
        }
    }
    return contador;
}
//esta funçao serve para o utilizador dar o input de resposta aos disparos do computador
//o input tem que ser de um carater apenas: 1-8 caso o computador acerte numa peça e '-' caso atinja água
int resposta(char charCol, char linha)
{
    int id_peca = 0;
    printf("%c%d\n", charCol, linha);
    int id_peca_num = 0;
    id_peca = getchar();
    getchar();

    id_peca_num = id_peca - '0';

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
//esta matriz verifica se as peças numa matriz 3x3 ja foram todas encontradas pelo computador
//por exemplo: caso o computador dispare numa peça 3, quando disparar nas restantes duas peças 3, avança para a proxima matriz3x3
int verificar_mat(int tabuleiro3[25][35], int id_peca, int a, int b){
   int i, j;
   int numpecas = 0;
   for(i = 0; i < 3; i++){
       for(j = 0;j < 3; j++){
          if ( tabuleiro3[a + i][b + j]>0){
            numpecas++;
            if (numpecas == id_peca){
            return 0;
            }
          }
       }
    }
    return 1;
}

/*funçao de disparo2: o computador dispara de acordo com uma sequencia, ate atinjir todas as peças numa matriz3x3
, e depois avança para a matriz seguinte*/

int disparo_2(int tabuleiro3[25][35], int disparosMin, int linhas, int colunas){
    int i = 0;
    int id_peca;
    char coluna;
    int linha;
    int contador = 0;
    int a,b;
    //estes dois arrays servem para fazer a sequencia pretendida de disparo dentro da matriz 3x3
    int seqlin[] = { 1,0,2,1,1,0,2,0,2};
    int seqcol[] = { 1,1,1,0,2,0,2,2,0};
    int flag2 = 1;
    apagar_tabuleiro(tabuleiro3, linhas, colunas);
    while( disparosMin > 0){
        for (b = 0; b < colunas;  b += 3){
            for ( a = 0; a < linhas; a += 3){
                flag2 = 1;
                i = 0;
                while(flag2 == 1 && i < 9){
                    if (tabuleiro3[a + seqlin[i]][b + seqcol[i]] == 0 ){
                        linha = (linhas - (a + seqlin[i]));
                        coluna = (b + seqcol[i]) + 'A';
                        id_peca = resposta(coluna, linha);
                        contador++;
                        if(id_peca == 0){
                            tabuleiro3[a + seqlin[i]][b + seqcol[i]] = -2;
                        }
                        else if(id_peca > 0){
                        tabuleiro3[a + seqlin[i]][b + seqcol[i]] = id_peca;
                        disparosMin--;
                        if(disparosMin == 0){
                            return contador;
                        }
                        flag2 = verificar_mat(tabuleiro3,id_peca,a,b);
                        //printf("%d",id_pecanum);
                        }
                        //printf("a flag2 é =%d\n",flag2);
                    }
                    i++;

                    //imprimir_tabuleiro(tabuleiro3, linhas, colunas);
                }
            }
        }
    }
    return contador;
}
/*funçao de disparo3, semelhante ao disparo 2 mas inclui tmb a funcao de restricaodisparo3: o computador n dispara
numa posiçao adjacente a uma posiçao ja preenchida  */
int disparo_3(int tabuleiro3[25][35], int disparosMin, int linhas,int colunas){
    int i = 0;
    int id_peca;
    int contador = 0;
    char linha,coluna;
    int tabuleiro_restricao [25][35] = {{0}};
    int a,b;
    //estes dois arrays servem para fazer a sequencia pretendida de disparo dentro da matriz 3x3
    int seqlin[] = { 1,0,2,1,1,0,2,0,2};
    int seqcol[] = { 1,1,1,0,2,0,2,2,0};
    /*a flag2 devolve 0 caso as peças numa matriz3x3 ja tinham sido todas preenchidas (para verificar usamos a funçao
    verificar_mat)*/
    int flag2 = 1;
    apagar_tabuleiro(tabuleiro3, linhas, colunas);
    while(disparosMin > 0){
        for (b = 0; b < colunas;  b += 3){
            for ( a = 0; a < linhas; a += 3){
                flag2 = 1;
                i = 0;
                while(flag2 == 1 && i < 9){
                    if (tabuleiro3[a + seqlin[i]][b + seqcol[i]] == 0 && tabuleiro_restricao[a + seqlin[i]][b + seqcol[i]] != 9 ){
                        linha = (linhas - (a + seqlin[i]));
                        coluna = (b + seqcol[i]) + 'A';
                        id_peca = resposta(coluna, linha);
                        contador ++;
                        if(id_peca == 0){
                            tabuleiro3[a + seqlin[i]][b + seqcol[i]] = -2;
                        }
                        else if(id_peca > 0 ){
                            tabuleiro3[a + seqlin[i]][b + seqcol[i]] = id_peca;
                            disparosMin --;
                            //printf("%d disparosMin\n",disparosMin);
                            if(disparosMin == 0){
                                restricaodisparo3(tabuleiro3,tabuleiro_restricao,a,b);
                                return contador;
                            }
                        flag2 = verificar_mat(tabuleiro3, id_peca, a, b);
                        }
                    }
                    i++;
                }
                restricaodisparo3(tabuleiro3,tabuleiro_restricao,a,b);
            }
        }
    }
    return contador;
}
/*esta funçao serve para aplicar a restriçao no disparo 3 (o tabuleiro1 fica a 9 nas posiçoes adjacentes ao disparo,
 indicando ao computador que nao pode disparar nestas posiçoes)*/
void restricaodisparo3(int tabuleiro3[25][35], int tabuleiro[25][35], int a, int b){
    int i, k, d;
    for(i = 0; i < 3; i++){
        for(k = 0; k < 3; k++){
            if(tabuleiro3[a + i][b + k] > 0){
                for(d = -1; d < 2; d++){
                    tabuleiro[a + i + d][b + k + 1] = 9;
                }
                tabuleiro[a + i + 1][b + k] = 9;
                tabuleiro[a + i + 1][b + k-1] = 9;
            }
        }
    }
}
