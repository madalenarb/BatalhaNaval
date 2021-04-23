#include "pecas.h"

/* 
* Função: return_id_global
*
* \brief função que, através do identificador da peça e do identificador da
variante, obtem o identificador global
* 
* \param id_peca int: identificador da peca
* \param id_variante int: identificador da variante
* \return int: id_global
*
*/
int return_id_global( int id_peca, int id_variante)
{
    int id_global = 0;
    /* salvaguarda que o identificador da peça se encontra entre 1 e 42,
    caso contrário o id_global fica a 0
    */
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

/*
* Função: variante_max
*
* \brief função que retorna o máximo de variantes que existem para cada
identificador da peça
*
* \param id_peca: identificador da peça
* \return int: varianteMax
*
*/
int variante_max(int id_peca){
    int varianteMax = 0;
    /* o número de variantes varia conforme o id_peca */
    switch (id_peca)
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

/*
* Função variante_aleatoria
*
* \brief gera identificadores da variante aleatórios
*
* \param id_peca: identificador da peca
* \return id_global
*
*/
int variante_aleatoria(int id_peca){
    int variante = 0;
    switch (id_peca)
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

/*
* Função: id_global_aleatorio
*
* \brief gera um id_global aleatório
*
* \param void
* \return id_global
*
*/
int id_global_aleatorio(void){
    int id_global = 0;
    /* número aleatório entre o 0 e o 42 */
    id_global = rand()%43;

    return id_global;
}


/* 
* Função: analisar_pecas
*
* \brief função que implementa a restrição 1, colocando as posições adjecentes a uma peça a -1,
de modo a assinalar que não se poderá colocar nenhuma peça nessas posições
*
* \param tabuleiro int: tabuleiro onde as peças são posicionadas
* \param tabuleiro2 int: tabuleiro onde são colocadas as flags -1 nas posições onde não se
podem colocar peças (restrição 1)
* \return void
*
*/
void analisar_pecas(int tabuleiro[25][35], int tabuleiro2[25][35], int linhas, int colunas)
{
    /* i, j: variáveis usadas em ciclos for */
    int i,j;
    /*
    Visto que as peças são colocadas numa ordem especifica: seguindo as matrizes 3x3
    da esquerda para a direita, sendo que quando se chega à ultima coluna da linha deve-se
    descer 1 matriz 3x3, colocando na 1ª matriz 3x3 dessa linha, torna-se, assim,
    evidente que só deveremos analisar à direita e abaixo de cada peça posicionada.
    Deste modo, este ciclo "for" irá colocar as flags -1 em posições adjecentes a cada posição das peças:
    do lado direito, do lado esquerdo e nas diagonais (excepto quando a posição adjecante pertence à peça ou está 
    fora do tabuleiro).
    */
    for ( i = 0; i < linhas + 1 ; i++ ){
        for ( j = 0; j < colunas + 1; j++ )
        {

            /* se houver uma peça */
            if ( tabuleiro[i][j] > 0 ){
                /* analisa a diagonal superior direita, ignorando, deste modo,
                as posições da 1ª linha e da última coluna, para não colocar 
                uma flag fora do tabuleiro */
                if( i > 0 && j < colunas ){
                    if( tabuleiro[i - 1][j + 1] == 0 ){
                        tabuleiro2[i - 1][j + 1] = -1;
                    }
                }

                /* analisa a diagonal inferior direita, ignorando, deste modo,
                as posições da última linha e da última coluna, para não colocar 
                uma flag fora do tabuleiro */
                if( i < linhas && j < colunas ){
                    if ( tabuleiro[i + 1][j + 1] == 0 ){
                        tabuleiro2[i + 1][j + 1] = -1;
                    }
                }

                /* analisa a diagonal inferior esquerda, ignorando, deste modo,
                as posições da última linha e da 1ª coluna, para não colocar 
                uma flag fora do tabuleiro */
                if( i < linhas && j > 0 ){
                    if(tabuleiro[ i + 1 ][j - 1] == 0){
                        tabuleiro2[ i + 1 ][j - 1] = -1;
                    }
                }

                /* analisa a posição à direita, ignorando, deste modo,
                as posições da última linha, para não colocar 
                uma flag fora do tabuleiro */
                if( i < linhas ){
                    if (tabuleiro[ i + 1 ][j] == 0){
                        tabuleiro2[i + 1][j] = -1;
                    }
                }

                /* analisa a posição abaixo, ignorando, deste modo,
                as posições da última coluna, para não colocar 
                uma flag fora do tabuleiro */
                if( j < colunas ){
                    if ( tabuleiro[i][j + 1] == 0 ){
                        tabuleiro2[i][j + 1] = -1;
                    }
                }
            }
        }
    }
}


/*
* Função: verificar_pecas
* 
* \brief função que averigua se podemos colocar a peca, através de uma comparação
entre o tabuleiro e o tabuleiro2, retornando uma flag
*
* \param tabuleiro int: tabuleiro onde se colocaram as pecas
* \param tabuleiro int: tabuleiro onde se coloca as flags para indicar onde não
se podem colocar as peças
* \param poslinha int: número da linha em que a primeira posição 
(do canto superior esquerdo) da matriz 3x3 se encontra
* \param poscoluna int: número da coluna em que a primeira posição 
(do canto superior esquerdo) da matriz 3x3 se encontra
* \return: 1 se não se pode colocar a peça na matriz 3x3 indicada, 
0 se se pode colocar a peça na matriz 3x3 indicada
*
*/
int verificar_pecas(int tabuleiro[25][35], int tabuleiro2[25][35], int poslinha, int poscoluna)
{
    int i = 0, j = 0;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            /* se o tabuleiro tiver uma peca na posição [i + poslinha][j + poscoluna]
            e nessa mesma posição o tabuleiro2 tiver um -1, não se pode colocar a peça
            nessa posição, logo retorna 1 */
            if (tabuleiro[i + poslinha][j + poscoluna] > 0){
                if ( tabuleiro2[i + poslinha][j + poscoluna] == -1){
                    return 1;
                }
            }
        }
    }
    return 0;
}