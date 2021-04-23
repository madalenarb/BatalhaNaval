#include "modo_p.h"


/*
* Função: p_1
* 
* \brief: função que implementa o modo de posicionamento 1
*
* \param tabuleiro int: tabuleiro que é usado para colocar as peças
* \param submat int: número de matrizes 3x3
* \param linhas int: número de linhas
* \param colunas int: número de colunas
*
*/
void p_1(int tabuleiro[25][35], int submat, int linhas, int colunas)
{
    int pos = 0;
    int contador, flag;
    /* id_global: identificador global */
    int id_global;
    /* tabuleiro2: tabuleiro onde são colocadas as flags -1 nas posições onde não se
    podem colocar peças (restrição 1)*/
    int tabuleiro2[25][35] = {0};

    int poscoluna = 0;
    int poslinha = 0;
    int i = 0;
    /* n_tipo_peca: identificador da peça */
    int n_tipo_peca = 0;
    /* contador_pecas: as posicoes de 1 a 8, respetivamente correspondem aos identificadores da peca
    e a posição 0 corresponde aos espaços vazios */
    int contador_pecas[9] = {0};


    int numpecas = submat; //restrição nº2

    for ( pos = 0; pos < submat; pos++)
    {
        /* quando flag = 0 pode-se colocar a peça na matriz, se flag = 1 não se pode colocar a peça na matriz */
        flag = 0; 
        id_global = id_global_aleatorio();
        /* contador: irá contar o número de tentativas a colocar uma peça na matriz*/
        contador = 0;

        if (id_global != 0)
        {
            /* decrementa o número de peças que ainda podemos posicionar */
            numpecas--;

            /* posiciona a peca que se pretende e guarda na variável n_tipo_peca o identificador da peca */
            n_tipo_peca = bibliotecadepecas(poslinha, poscoluna, id_global, tabuleiro);
            flag = verificar_pecas(tabuleiro, tabuleiro2, poslinha, poscoluna);

            /* fica dentro deste ciclo até a flag ficar a 0, o que significará
            que a peça pode ser colocada */
            while( flag == 1 ){
                /* apaga a submatriz */
                apagar_submat(tabuleiro, poslinha, poscoluna);
                /* id_global: um id_global aleatória será gerado */
                id_global = id_global_aleatorio();
                /* se o id_global gerado for maior que 0, ou seja correspondente a uma peça */
                if( id_global > 0){
                    /* coloca a peca */
                    n_tipo_peca = bibliotecadepecas(poslinha, poscoluna, id_global, tabuleiro);
                    /* verifica se a peca pode ser colocada */
                    flag = verificar_pecas(tabuleiro, tabuleiro2, poslinha, poscoluna);
                }

                /* incrementa o número de tentativas de colocar a peca */
                contador++;
                /* se o programa passar das 3 tentativas, é forçado a colocar
                uma peca de tipo 1, de identificador de variante igual a 5 */
                if(contador >= 3){
                    apagar_submat(tabuleiro, poslinha, poscoluna);
                    id_global = 5;
                    n_tipo_peca = bibliotecadepecas(poslinha, poscoluna, id_global, tabuleiro);
                    flag = verificar_pecas(tabuleiro, tabuleiro2, poslinha, poscoluna);
                }
            }

            analisar_pecas(tabuleiro, tabuleiro2, linhas, colunas);
            contador_pecas[n_tipo_peca]++;
  
            /* se não houver mais peças a colocar, sai do loop */
            if (numpecas == 0){
                break;            
            }

        /* se o id_global for igual a 0, corresponde a um espaço em branco */
        } else if ( id_global == 0 ){
            n_tipo_peca = bibliotecadepecas(poslinha, poscoluna, 0, tabuleiro);
        }

        /* desce 3 colunas */
        poscoluna += 3;
        /* se chegou à ultima coluna, tem que ir para a 1ª coluna da linha de baixo*/
        if(poscoluna >= colunas - 1){
            poscoluna = 0;
            poslinha += 3;
        }
    } 
    /* imprime o tamanho do tabuleiro e o número de cada id_peca */
    printf("%dx%d ", linhas, colunas);
    for(i = 1; i < 9; i++){
        printf("%d ", contador_pecas[i] );
    }
}


/*
* Função: p_2
*
* \brief: implementa o modo de posição 2
*
* \param tabuleiro int: tabuleiro que será usado para colocar as peças
* \param n_pecas int: vetor com o número de peças nas posições correspondentes ao seu id_peca - 1
* \param flagvec int: vetor de flags que indica os tipos de peça que ainda não foram usados
* \param submat int: representa o número total de matrizes 3x3
* \param linhas int: número de linhas do tabuleiro
* \param colunas int: número de colunas do tabuleiro
* \return: -1 se ainda não foi possível colocar a peça, 0 se foi possível colocar a peça
*
*/
int p_2(int tabuleiro[25][35], int n_pecas[9], int flagvec[9], int submat, int linhas, int colunas)
{
    int i = 0,
        j = 0,
        /* n_pecas_aux: vetor que tem o número de peças nas posições correspondentes ao seu id_peca,
        sendo que a posição 0 corresponde ao número de matrizes 3x3 vazias */
        n_pecas_aux[10] = {0},
        /* numpecas: corresponde ao número total de peças */
        numpecas = n_pecas[8];
        /* tabuleiro onde são colocadas as flags -1 nas posições onde não se
        podem colocar peças (restrição 1)*/
        int tabuleiro2[25][35] = {0};
        /* o número de espaços vazios serão as restantes matrizes 3x3 */
        n_pecas_aux[0] = submat - numpecas;

    int id_variante = 0,
        id_peca = 0,
        /*varinateMax: número de variante máximas*/
        varianteMax = 0,
        id_global = 0;

    /* matrizVazia: é uma flag que indica se a matriz será ou não vazia,
    se matrizVazia == 1, será vazia,
    se matrizVazia == 0, terá uma peça
    */
    int matrizVazia = 0;

    int flag = 0; //flag que identifica quando uma peça está adjacente a outra peça
    /* flag1: verifica se foram testados todos os tipos de peça */
    int flag1 = 0;

    /* copia o vetor n_pecas para o n_pecas_aux, mas avançando as posições por 1 */
    for( i = 0; i < 9; i++){
        n_pecas_aux[i + 1] = n_pecas[i];
    }

    //inicialização da posição no canto superior esquerdo
    int pos = 0;
    int poscoluna = 0;
    int poslinha = 0;

    for( pos = 0; pos < submat; pos++ ){
        flag1 = 90;

        /* se o nº de peças de um certo tipo for maior que 0, coloca-se um 1 na respetiva posição no flagvec */
        for( j = 0; j < 9; j++ ){
            if(n_pecas_aux[j] > 0){
                flagvec[j] = 1;
            }
        }

        /* enquanto há peças a testar: */
        while( flag1 > 0 ){
            /* Há 50% de probabilidades de ser uma matrizVazia */
            matrizVazia = rand()%2;
            if(matrizVazia == 0){
                id_peca = rand()%8 + 1;
            } else {
                id_peca = 0;
            }
            /* enquanto o id_peca não corresponder a uma peça selecionada, 
            ou se corresponder a um tipo de peça já testado: */
            while( n_pecas_aux[id_peca] == 0 && flagvec[id_peca] == 0 ){
                matrizVazia = rand()%2;
                if(matrizVazia == 0){
                    id_peca = rand()%8 + 1;
                } else {
                    id_peca = 0;
                }
                /*sai deste loop se o id_peca for um valor selecionado ou um tipo de peça ainda não 
                testado */
            }

            flagvec[id_peca] = 0;
            varianteMax = variante_max(id_peca);
            id_variante = variante_aleatoria(id_peca);
            id_global = return_id_global(id_peca, id_variante);
            bibliotecadepecas(poslinha, poscoluna, id_global, tabuleiro);

            if(id_global > 0){
                flag = verificar_pecas(tabuleiro, tabuleiro2, poslinha, poscoluna);
            }

                if( flag == 1 ){
                    id_variante = 1;
                }

                while( flag == 1 ){
                    apagar_submat(tabuleiro, poslinha, poscoluna);
                    if(id_global > 0){
                        /* vai buscar o id_global em função ao id_peca, id_variante */
                        id_global = return_id_global(id_peca, id_variante);
                    }

                    id_peca = bibliotecadepecas(poslinha, poscoluna, id_global, tabuleiro);

                    if(id_global > 0){
                        flag = verificar_pecas(tabuleiro, tabuleiro2, poslinha, poscoluna);
                    }

                    id_variante++;

                    /* quando excede o número de variantes máximos e ainda não foi possível colocar a peça, 
                    analiza-se a flag1, de modo a confirmar se já testámos todos os tipos de peças escolhidos
                    */
                    if(id_variante > varianteMax){
                        for( i = 0; i < 9; i++ ){
                            flag1 = 0;
                            flag1 += flagvec[i];
                        }
                        break;
                    }   
                }

            if(flag == 0){
                flag1 = 0;
            }
        }

        /* se a flag1 continuar igual a 0 e a flag for igual a 1, 
        significa que não foi possível posicionar a peça e por isso irá 
        returnar -1 */
        if(flag1 == 0 && flag == 1){
            return -1;
        }


        analisar_pecas(tabuleiro, tabuleiro2, linhas, colunas);
        n_pecas_aux[id_peca]--;
        numpecas--;

        /* atualização da posição atual */
        poscoluna += 3;
        if( poscoluna >= colunas - 1 ){
            poscoluna = 0;
            poslinha += 3;
        }
    }
    printf("%dx%d ", linhas, colunas);
    for(i = 0; i < 8; i++){
        printf("%d ", n_pecas[i] );
    }
    return 0;
}
