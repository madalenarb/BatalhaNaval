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

void coloca_peca(int tabuleiro[25][35], int submat, int linhas, int colunas)
{
    //inicializa a variante e o tipo de peça
    //int id_global = return_id_global(tipoPeca, variante);
    int i = 0;
    int pos = 0;
    int contador, flag, id_global;
    int tabuleiro2[25][35] = {0}; // tabuleiro que será usado para comparar
    srand(time(NULL));
    //Inicialização das coordenadas de posicionamento (poslinha, poscoluna)
    int poscoluna = 0;
    int poslinha = 0;
    int n_tipo_peca = 0;
    int contador_pecas[8] = {0};

    int numpecas = submat; //restrição nº2
    printf("nº de peças %d\n", numpecas);

    for ( pos = 0; pos < submat; pos++)
    {
        flag = 0; //quando flag = 0 pode-se c8olocar a peça na matriz, se flag = 1 não se pode colocar a peça na matriz
        id_global = id_global_aleatorio();
        contador = 0; //irá contar o número de tentativas a colocar uma peça na matriz

        //printf("id peça %d\n", tipoPeca);
        //printf( "variante: %d\n", variante);
        if (id_global != 0)
        {
            numpecas--;
            n_tipo_peca = bibliotecadepecas(poslinha, poscoluna, id_global, tabuleiro);
            flag = verificar_pecas(tabuleiro, tabuleiro2, poslinha, poscoluna);
            //printf("flag = %d\n", flag);

            while( flag == 1 ){
                apagar_submat(tabuleiro, poslinha, poscoluna);
                id_global = id_global_aleatorio();
                n_tipo_peca = bibliotecadepecas(poslinha, poscoluna, id_global, tabuleiro);
                flag = verificar_pecas(tabuleiro, tabuleiro2, poslinha, poscoluna);
                //printf("flag = %d\n", flag);
                //printf("contador= %d\n", contador);
                contador++;
                if(contador >= 3){
                    apagar_submat(tabuleiro, poslinha, poscoluna);
                    id_global = 5;
                    n_tipo_peca = bibliotecadepecas(poslinha, poscoluna, id_global, tabuleiro);
                    flag = verificar_pecas(tabuleiro, tabuleiro2, poslinha, poscoluna);
                }
            }

            analisar_pecas(tabuleiro, tabuleiro2, linhas, colunas);
            contador_pecas[n_tipo_peca - 1]++;
            /*
            for( i = 0; i < 8; i++ ){
                printf("peca %d: %d \n", i + 1, contador_pecas[i]);
            }
            */

            if (numpecas == 0){
                break;            
            }
        } else if ( id_global == 0 ){
            pos++;
        }

        poscoluna += 3;
        if(poscoluna >= colunas - 1){
            poscoluna = 0;
            poslinha += 3;

        }
    }
}

int id_global_aleatorio(void){
    int id_global = 0;
    id_global = rand()%43;
    return id_global;
}



//retrição 1

void analisar_pecas(int tabuleiro[25][35], int tabuleiro2[25][35], int colunas, int linhas)
{
    int i,j,n;
    for ( i = 0; i < linhas; i++ ){
        for ( j = 0; j < colunas; j++ )
        {

            if ( tabuleiro[i][j] > 0 ){
                if( i > 0 && j < colunas ){
                    if( tabuleiro[i - 1][j + 1] == 0 ){
                        tabuleiro2[i - 1][j + 1 ] = -1;
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
}