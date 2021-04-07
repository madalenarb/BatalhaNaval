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
    int pos = 0;
    int tabuleiro2[25][35] = {0}; // tabuleiro que será usado para comparar 
    srand(time(NULL));
    int flag = 0; //quando flag = 0 pode-se colocar a peça na matriz, se flag = 1 não se pode colocar a peça na matriz
    int contador = 1; //irá contar o número de tentativas a colocar uma peça na matriz
    //Inicialização das coordenadas de posicionamento (poslinha, poscoluna)
    int poscoluna = 0;
    int poslinha = 0;

    //inicializa a variante e o tipo de peça
    int variante = -1;
    int tipoPeca = -1;

    int numpecas = submat; //restrição nº2
    printf("nº de peças %d\n", numpecas);

    for ( pos = 0; pos < submat; pos++)
    {
        tipoPeca = tipo_peca();
        variante = det_variante(tipoPeca);
            printf("id peça %d\n", tipoPeca);
            printf( "variante: %d\n", variante);

        //printf("id peça %d\n", tipoPeca);
        //printf( "variante: %d\n", variante);
        if (tipoPeca != 0)
        {
            numpecas--;
            analisar_pecas(tabuleiro, tabuleiro2, linhas, colunas);
            print_peca(tipoPeca,variante,tabuleiro,poslinha,poscoluna);
            flag = verificar_pecas(tabuleiro, tabuleiro2, poslinha, poscoluna);
            printf("flag = %d\n", flag);

            if( flag != 0 ){
                for( contador = 0; contador < 3; contador++ ){
                    apagar_submat(tabuleiro, tabuleiro2, poslinha, poscoluna);
                    tipoPeca = tipo_peca();
                    variante = det_variante(tipoPeca);
                    print_peca(tipoPeca,variante,tabuleiro,poslinha,poscoluna);
                    flag = verificar_pecas(tabuleiro, tabuleiro, poslinha, poscoluna);
                    printf("variante : %d \n", variante);
                    printf("id_globalaa : %d \n", tipoPeca);
                    printf("flag = %d\n", flag);
                    if( flag == 0 ){
                        break;
                    }
                }
            }
                if (flag == 1){
                    apagar_submat(tabuleiro, tabuleiro, poslinha, poscoluna);
                    tipoPeca = 1;
                    variante = 5;
                    print_peca(tipoPeca,variante,tabuleiro,poslinha,poscoluna);
                    flag = verificar_pecas(tabuleiro, tabuleiro2, poslinha, poscoluna);
                }
            imprimir_tabuleiro(tabuleiro, linhas, colunas); //TESTE
            //verificapeca();
            if (numpecas == 0){
                break;            
            }
        }
        poscoluna += 3;
        if(poscoluna >= colunas - 1){
            poscoluna = 0;
            poslinha += 3;

        }
    }
}

int tipo_peca(void){
    int tipoPeca = 0;
    int variante = 0;
    return rand()%8 + 1;
    }

int det_variante(int tipoPeca){ 
    int variante = 0;
    switch (tipoPeca)
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

void print_peca( int id_peca, int id_variante, int tabuleiro[25][35], int poslinha, int poscoluna)
{
    int id_global = return_id_global( id_peca, id_variante);
    printf("id_global = %d\n\n\n", id_global);
    bibliotecadepecas(poslinha, poscoluna, id_global, tabuleiro);
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
    imprimir_tabuleiro(tabuleiro2, linhas, colunas);
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