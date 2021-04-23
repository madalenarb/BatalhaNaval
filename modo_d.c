#include "modo_d.h"

/* \Funçao: disparo1,
*
*  \brief implementação do disparo1
*
* \param tabuleiro3: tabuleiro onde vão ser registados os disparos
* \param disparosMin: indica o numero de disparos minimos para acertar em todas as peças
* \param disparosMax: indica o numero de disparos maximos para atinjir todas as posições possiveis do tabuleiro
* \param linhas: indica o numero de linhas definido pelo utilizador
* \param colunas: indica o numero de colunas definido pelo utilizador
*
* \return contador: contador de disparos do computador
*/
int disparo_1(int tabuleiro3[25][35], int disparosMin, int disparosMax, int linhas, int colunas){
    int randCol = 0;
    int randLin = 0;
    int n_disparos = 0;
    int contador = 0;
    char id_peca;
    char charRandCol;  
    apagar_tabuleiro(tabuleiro3, linhas, colunas);//limpar o tabuleiro


    while( disparosMin > 0 && n_disparos < disparosMax ){
        randCol = (rand()%colunas);//escolhe um ponto da coluna aleatoriamente
        randLin = (rand()%linhas);//escolhe um ponto da linha aleatoriamente
        charRandCol = randCol + 'A';

        if(tabuleiro3[randLin][randCol] == 0 ){
                contador++;
                id_peca = resposta(charRandCol, randLin);
                if(id_peca == 0){
                    tabuleiro3[randLin][randCol] = -2;
                }
                else if(id_peca > 0){
                    tabuleiro3[randLin][randCol] = id_peca;
                    disparosMin--;//sempre que acerta numa peça,ao disparosMin é subtraido 1, qnd todas foram atinjidas o jogo acaba
                }
                n_disparos--;
        }
    }
    return contador;
}
/* \Função: resposta
*
* \brief esta funçao serve para o utilizador dar o input de resposta aos disparos do computador;
o input tem que ser de um carater apenas: 1-8 caso o computador acerte numa peça e '-' caso atinja água.
a funçao tmb da print dos disparos do computador
*
* \param charCol: elemento da coluna que corresponde ao disparo do computador
* \param charLinha: elemento da linha que cooresponde ao disparo do computador
* \return id_peca_num: retorna o identificador da peça
*
*/
int resposta(char charCol, char linha)
{
    int id_peca = 0;
    printf("%c%d\n", charCol, linha);
    int id_peca_num = 0;
    id_peca = getchar();
    getchar();//este getchar adicional serve para podermos ignorar o "enter" no stdin, visto que este conta com um caracter
    id_peca_num = id_peca - '0';

    if(id_peca == '-'){
        id_peca_num = 0;
    } else if (id_peca_num > 0){
        id_peca_num = id_peca - '0';
    }
    return id_peca_num;
}

/* Função: verificar_matriz
*
* \brief:verifica se o tabuleiro ainda contém peças 
*
* \param tabuleiro: recebe o tabuleiro para poder verificá-lo
* \return: retorna 1 caso ainda esteja uma peça no tabuleiro
* \return: retorna 0 caso não seja encontrada nenhuma peça (ou seja, o tabuleiro tem todas as posições a 0)
*
*/
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
/*Função: verificar_mat
*
* \brief: verifica se ainda há peças numa célula3x3
*
* \param tabuleiro3: recebe o tabuleiro para poder ser analisado
* \param id_peca: recebe o id_peça (para que saiba quantos elementos de uma peça existem numa celula3x3; 
exemplo: se for encontrada uma peça 3, existem 3 elementos da peça nessa celula3x3)
* \param a: elemento de linha da celula3x3 pretendida
* \param b: elemento da coluna da celula3x3 pretendida
* \return: 0 caso todas as peças numa celula3x3 tenham sido encontradas
* \return: 1 caso ainda hajam peças numa celula3x3
*
*/
int verificar_mat(int tabuleiro3[25][35], int id_peca, int a, int b){
   int i, j;
   int numpecas = 0;
   for(i = 0; i < 3; i++){
       for(j = 0;j < 3; j++){
          if ( tabuleiro3[a + i][b + j]>0){
            numpecas++;
            if (numpecas == id_peca){ //se o numero de peças atinjidas for igual ao numero do tipo de peça, indica que todas as peças na matriz3x3 foram encontradas
            return 0;
            }
          }
       }
    }
    return 1;
}

/*funçao de disparo2: implementa o modo de disparo2
*
* \brief:o computador dispara de acordo com uma sequencia, ate atinjir todas as peças numa matriz3x3, e depois avança para a matriz seguinte
*
* \param tabuleiro3: tabuleiro onde vão ser registados os disparos
* \param disparosMin: numero de disparos mínimos para acertar todas as peças
* \param linhas: numero de linhas definidas pelo utilizador
* \param colunas: numero de colunas definidas pelo utilizador
* \return contador: retorna o numero de disparos do computador
*
*/

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
        for (b = 0; b < colunas;  b += 3){// disparar de matriz3x3 em matriz3x3
            for ( a = 0; a < linhas; a += 3){
                flag2 = 1;
                i = 0;
                while(flag2 == 1 && i < 9){
                    if (tabuleiro3[a + seqlin[i]][b + seqcol[i]] == 0 ){ //so dispara nas posiçoes que ainda n foram atinjidas, ou seja,nas que estão a 0
                        linha = (linhas - (a + seqlin[i]));
                        coluna = (b + seqcol[i]) + 'A';
                        id_peca = resposta(coluna, linha);//recebe o input do utilizador
                        contador++;
                        if(id_peca == 0){//disparo na agua
                            tabuleiro3[a + seqlin[i]][b + seqcol[i]] = -2;
                        }
                        else if(id_peca > 0){//disparo numa peça
                        tabuleiro3[a + seqlin[i]][b + seqcol[i]] = id_peca;
                        disparosMin--;
                        if(disparosMin == 0){//caso todas as peças tenham sido atinjidas, o jogo acaba
                            return contador;
                        }
                        flag2 = verificar_mat(tabuleiro3,id_peca,a,b);//verficar se a matriz3x3 ainda tem peças
                        }
                    }
                    i++;
                }
            }
        }
    }
    return contador;
}
/*funçao de disparo3: implementa o disparo 3
*
* \brief:semelhante ao disparo 2 mas inclui também a função de restricaodisparo3: o computador não dispara numa posição adjacente a uma posição já preenchida(ver função restricaodisparo3)
*
* \param tabuleiro3: tabuleiro onde vão ser registados os disparos
* \param disparosMin: numero de disparos mínimos para acertar todas as peças
* \param linhas: numero de linhas definidas pelo utilizador
* \param colunas: numero de colunas definidas pelo utilizador
* \return contador: retorna o número de disparos do computador
*
*/
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
                while(flag2 == 1 && i < 9){//coloca peças na matriz3x3 (até i=9) ou até acabarem as peças (flag2)
                    if (tabuleiro3[a + seqlin[i]][b + seqcol[i]] == 0 && tabuleiro_restricao[a + seqlin[i]][b + seqcol[i]] != 9 ){//respeita a restriçao das peças adjacentes (tabuleiro1 !=9)
                        linha = (linhas - (a + seqlin[i]));
                        coluna = (b + seqcol[i]) + 'A';
                        id_peca = resposta(coluna, linha);
                        contador ++;
                        if(id_peca == 0){
                            tabuleiro3[a + seqlin[i]][b + seqcol[i]] = -2;
                        }
                        else if( id_peca > 0 ){
                            tabuleiro3[a + seqlin[i]][b + seqcol[i]] = id_peca;
                            disparosMin --;
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
/* Função: restricaodisparo3
*
* \brief: esta funçao serve para aplicar a restriçao no disparo 3. As posiçoes restritas irão ser armazenadas no tabuleiro1 com o valor 9; 
no modo de disparo3 está definido que o computador não pode disparar nestas posições, aplicando assim a restrição de disparo3.  
* 
* \param tabuleiro3: recebe o tabuleiro3, onde sao registados os disparos
* \param tabuleiro: recebe outro tabuleiro vindo do modo de disparo3, neste vão ser armazenados as posições restritas pela restriçao de modo de disparo3
* \param a: elemento da linha correspondente a celula3x3 pretendida
* \param b: elemento da coluna correspondente a celula3x3 pretendida
* \return: void
*
*/
void restricaodisparo3(int tabuleiro3[25][35], int tabuleiro[25][35], int a, int b){
    int i, k, d;
    for(i = 0; i < 3; i++){ //vai analisar a matriz 3x3
        for(k = 0; k < 3; k++){
            if(tabuleiro3[a + i][b + k] > 0){ //caso encontre uma peça, coloca nas posiçoes adjacentes um 9 no tabuleiro1, indicando q n se pode disparar nestas
                for(d = -1; d < 2; d++){
                    tabuleiro[a + i + d][b + k + 1] = 9;
                }
                tabuleiro[a + i + 1][b + k] = 9;
                tabuleiro[a + i + 1][b + k-1] = 9;
            }
        }
    }
}
