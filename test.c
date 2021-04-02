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

void coloca_peca(int tabuleiro[25][35], int submat, int colunas)
{
    int pos = 0;
    srand(time(NULL));
    int status = 0; //quando status = 0 pode-se colocar a peça na matriz, se status = 1 não se pode colocar a peça na matriz
    int contador = 0; //irá contar o número de tentativas a colocar uma peça na matriz
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
        while (contador < 3)
        {        

                //escolhe o tipo de peça aleatoriamente
                tipoPeca = rand()%8 + 1;
                
                //Escolhe a variante aleatoriamente
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
                status = analisar_pecas(tabuleiro, poslinha, poscoluna);
                contador++;
                printf("contador: %d\n", contador);
                printf("id peça a: %d\n", tipoPeca);
                printf( "variante a: %d\n", variante);
                if (status == 0){
                break;
                if(contador == 3){
                    variante = 5;
                    tipoPeca = 1;
                }
            }

        } 
        
        
        printf("id peça %d\n", tipoPeca);
        printf( "variante: %d\n", variante);
        if (tipoPeca != 0)
        {
            numpecas--;
            
            print_peca(tipoPeca,variante,tabuleiro,poslinha,poscoluna);
            
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

void print_peca( int id_peca, int id_variante, int tabuleiro[25][35], int poslinha, int poscoluna)
{
    int id_global = return_id_global( id_peca, id_variante);
    printf("id_global = %d\n\n\n", id_global);
    bibliotecadepecas(poslinha, poscoluna, id_global, tabuleiro);
}

//retrição 1

int analisar_pecas(int tabuleiro[25][35],int poslinha,int poscoluna)
{
    int i,j;
    for (i = 0; i < 3; i++){
        for ( j = -1; j < 2; j++)
        {
            /*
            return 1:indica que é uma posição inválida
            posição inválida: se houver uma peça adjacente ou na diagonal relativamente a outra, 

            analisa a fronteira da direita da matrix 3x3 e faz return 1 se a posição for inválida
            */
            if( tabuleiro[poslinha + 2][poscoluna + i] != 0  && tabuleiro[poslinha + 3][poscoluna + j] != 0 ){
                return 1;
            }
            // analisa a fronteira inferior da matrix 3x3 e faz return
            if( tabuleiro[poslinha + i][poscoluna + 2] != 0  && tabuleiro[poslinha + j][poscoluna + 3] != 0 ){
                return 1;
            }
            // analisa a fronteira da esquerda da matrix 3x3 e faz return
            if ( tabuleiro[poslinha][poscoluna + i] != 0 && tabuleiro[poslinha - 1][poscoluna + j] != 0 )
            {
                return 1;
            }
            // analisa a fronteira superior da matrix 3x3 e faz return
            if (tabuleiro[poslinha + i][poscoluna] != 0 && tabuleiro[poslinha + j][poscoluna - 1]){
                return 1;
            }
        }
    }
    return 0;
}










void coloca_peca(int tabuleiro[25][35], int submat, int colunas)
{
    int pos = 0;
    srand(time(NULL));
    int flag = 0; //quando flag = 0 pode-se colocar a peça na matriz, se flag = 1 não se pode colocar a peça na matriz
    int contador = 0; //irá contar o número de tentativas a colocar uma peça na matriz
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
        //escolhe o tipo de peça aleatoriamente
        tipoPeca = rand()%8 + 1;
        
        //Escolhe a variante aleatoriamente
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

        
        
        printf("id peça %d\n", tipoPeca);
        printf( "variante: %d\n", variante);
        if (tipoPeca != 0)
        {
            numpecas--;
            print_peca(tipoPeca,variante,tabuleiro,poslinha,poscoluna);
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