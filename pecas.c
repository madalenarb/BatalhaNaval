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
                (id_global) = 41;
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
    int tipoPeca = -1;
    int poscoluna = 0;
    int poslinha = 0;
    int variante = 0;
    int numpecas = submat; //restrição nº2
    printf("nº de peças %d\n", numpecas);
    
    for ( pos = 0; pos < submat; pos++)
    {
        tipoPeca = rand()%8 + 1;
        
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

void print_peca( int id_peca, int id_variante, int tabuleiro[25][35], int poslinha, int poscoluna)
{
    int id_global = return_id_global( id_peca, id_variante);
    printf("id_global = %d\n\n\n", id_global);
    bibliotecadepecas(poslinha, poscoluna, id_global, tabuleiro);
}
