#include "pecas.h"
#include "tabuleiro.h"
#include "bibliotecadepecas.h"

//definir valores default 
#define DEFAULT_LINHAS 9
#define DEFAULT_COLUNAS 9
#define DEFAULT_MODO_JOGO 0
#define DEFAULT_MODO_POSICIONAMENTO 1
#define DEFAULT_MODO_DISPARO 1

//função que será executada quando o utilizador escreve -h no terminal
void instrucoes(char *programa)
{
    printf("B A T A L H A   N A V A L\n\n");
    printf("Modo de utilização: %s[opções]\n", programa);
    printf("opções:\n");
    printf("-h\t\t    ajuda para o utilizador\n");
    printf("-t\t\t    dimensão do tabuleiro (linha x coluna)\n");
    printf("-j\t\t    modo de jogo (0 a 2)\n");
    printf("-p\t\t    modo de posicionamento de peças pelo computador (1 a 2)\n");
    printf("-d\t\t    modo de dispsaro de peças pelo computador (1 a 3)\n");
    printf("-[1-8]\t\t    indica o número de peças de cada tipo (mínimo 1)\n\n");

}

int main(int argc, char *argv[])
{
    int i = 0,
        linhas = DEFAULT_LINHAS,
        colunas = DEFAULT_COLUNAS,
        modoJogo = DEFAULT_MODO_JOGO,
        modoPosicionamento = DEFAULT_MODO_POSICIONAMENTO,
        modoDisparo = DEFAULT_MODO_DISPARO;
    int n_pecas[8] = {0};
    int tabuleiro[25][35] = {0};
    char opt = 'h'; // opção para getopt()

    // opções da linha de comandos:
    while ((opt = getopt(argc,argv,"ht:j:p:d:1:2:3:4:5:6:8:")) != -1)
    {
        //printf("%c",opt);
        switch(opt) {
            case 't':
                sscanf(optarg, "%dx%d", &linhas, &colunas);
                //printf("%dx%d\n", linhas, colunas);
                if ( linhas < 9 || colunas < 9 || linhas > 15 || colunas > 24 || linhas % 3 != 0 || colunas % 3 != 0 )
                {
                    printf("A dimensão do tabuleiro deve ser no mínimo 9x9 e no máximo 15x24\n\n");
                    printf("-1\n");
                    return EXIT_FAILURE;
                }
                break;

            case 'j':
                sscanf(optarg,"%d", &modoJogo);
                //printf("j = %d\n", modoJogo);
                if ( modoJogo < 0 || modoJogo > 2 ){
                    printf("O modo do jogo é de 0 a 2\n");
                    printf("-1\n");
                    return EXIT_FAILURE;
                }
                break;
            
            case 'p':
                sscanf(optarg, "%d", &modoPosicionamento);
                //printf("p = %d\n", modoPosicionamento);
                if (modoPosicionamento < 1 || modoPosicionamento > 2){
                    printf ("O modo de posicionamento das peças é de 1 a 2\n");
                    printf("-1\n");
                    return EXIT_FAILURE;   
                }           
                break;

            case 'd':
                sscanf(optarg, "%d", &modoDisparo);
                //printf("d = %d\n", modoDisparo);
                if (modoDisparo < 1 || modoDisparo > 3)
                {
                    printf("O modo de disparo das peças é de 1 a 3\n");
                    return EXIT_FAILURE;
                }
                if( modoJogo == 0 || modoJogo == 1 ){
                    instrucoes(argv[0]);
                    return EXIT_FAILURE;
                }
                break;

            case '1':
                sscanf(optarg, "%d", &n_pecas[0]);
                if( n_pecas[0] <= 0 ){
                    return EXIT_FAILURE;
                }

                if( modoPosicionamento == 1 && ( modoJogo == 0 || modoJogo == 1) ){
                    printf("-1\n");
                    return EXIT_FAILURE;
                }   
                break;

            case '2':
                sscanf(optarg, "%d", &n_pecas[1]);
                if( n_pecas[1] >= n_pecas[0] || n_pecas[1] < 0 ){   // se o nº de pecas não for fonecido 2 em p_2?   e se inserirem um nº de pecas de tipo 3 < nº de pecas de tipo 7
                    printf("Não se pode inserir um maior número de peças de um tipo de maior dimensão do que peças de um tipo de menor dimensão.\n");
                    instrucoes(argv[0]);
                    return EXIT_FAILURE;
                }

                if( modoPosicionamento == 1 && ( modoJogo == 0 || modoJogo == 1) ){
                    printf("-1\n");
                    return EXIT_FAILURE;
                }   
                break;

            case '3':
                sscanf(optarg, "%d", &n_pecas[2]);
                if( n_pecas[2] >= n_pecas[1] || n_pecas[2] < 0 ){
                    printf("Não se pode inserir um maior número de peças de um tipo de maior dimensão do que peças de um tipo de menor dimensão.\n");
                    instrucoes(argv[0]);
                    return EXIT_FAILURE;
                }

                if( modoPosicionamento == 1 && ( modoJogo == 0 || modoJogo == 1) ){
                    printf("-1\n");
                    return EXIT_FAILURE;
                }   
                break;

            case '4':
                sscanf(optarg, "%d", &n_pecas[3]);
                if( n_pecas[3] >= n_pecas[2] || n_pecas[3] < 0 ){
                    printf("Não se pode inserir um maior número de peças de um tipo de maior dimensão do que peças de um tipo de menor dimensão.\n");
                    instrucoes(argv[0]);
                    return EXIT_FAILURE;
                }

                if( modoPosicionamento == 1 && ( modoJogo == 0 || modoJogo == 1) ){
                    printf("-1\n");
                    return EXIT_FAILURE;
                }   
                break;

            case '5':
                sscanf(optarg, "%d", &n_pecas[4]);
                if( n_pecas[4] >= n_pecas[3] || n_pecas[4] < 0 ){
                    printf("Não se pode inserir um maior número de peças de um tipo de maior dimensão do que peças de um tipo de menor dimensão.\n");
                    instrucoes(argv[0]);
                    return EXIT_FAILURE;
                }

                if( modoPosicionamento == 1 && ( modoJogo == 0 || modoJogo == 1) ){
                    printf("-1\n");
                    return EXIT_FAILURE;
                }   
                break;

            case '6':
                sscanf(optarg, "%d", &n_pecas[5]);
                if( n_pecas[5] >= n_pecas[4]|| n_pecas[5] < 0  ){
                    printf("Não se pode inserir um maior número de peças de um tipo de maior dimensão do que peças de um tipo de menor dimensão.\n");
                    instrucoes(argv[0]);
                    return EXIT_FAILURE;
                }

                if( modoPosicionamento == 1 && ( modoJogo == 0 || modoJogo == 1) ){
                    printf("-1\n");
                    return EXIT_FAILURE;
                }   
                break;

            case '7':
                sscanf(optarg, "%d", &n_pecas[6]);
                if( n_pecas[6] >= n_pecas[5] || n_pecas[6] < 0 ){
                    printf("Não se pode inserir um maior número de peças de um tipo de maior dimensão do que peças de um tipo de menor dimensão.\n");
                    instrucoes(argv[0]);
                    return EXIT_FAILURE;
                }

                if( modoPosicionamento == 1 && ( modoJogo == 0 || modoJogo == 1) ){
                    printf("-1\n");
                    return EXIT_FAILURE;
                }   
                break;

            case '8':
                sscanf(optarg, "%d", &n_pecas[7]);
                if( n_pecas[7] >= n_pecas[6] || n_pecas[7] < 0 ){
                    printf("Não se pode inserir um maior número de peças de um tipo de maior dimensão do que peças de um tipo de menor dimensão.\n");
                    instrucoes(argv[0]);
                    return EXIT_FAILURE;
                }

                if( modoPosicionamento == 1 && ( modoJogo == 0 || modoJogo == 1) ){
                    printf("-1\n");
                    return EXIT_FAILURE;
                }   
                break;

            default: //opções inválidas
                printf("Erro: opção '%c' desconhecida \n\n", optopt);
            case 'h':
                instrucoes(argv[0]);
                return EXIT_FAILURE;
                break;
        }
    }

    //instrucoes();
    //imprimir_tabuleiro(tabuleiro, linhas, colunas);
    /*for ( i = 0; i < 2; i++ )
    {
        colocar_peca(tabuleiro,0,0,1,i);
        imprimir_tabuleiro(tabuleiro, linhas, colunas);
        tabuleiro[15][24] = {0};
    }*/
    /*
    testar a impressão de peças aleatorias:
    */
    
    if ( modoJogo == 0 ){
        if( modoPosicionamento == 1 ){
            int numdemat = submat(linhas,colunas); //numero de matrizes 3x3 num tabuleiro
            p_1(tabuleiro, numdemat, linhas, colunas);
            imprimir_tabuleiro(tabuleiro, linhas, colunas);
            //printf("\n submat = %d\n\n", numdemat);
        }
    }
    
    
    
    //Testa todas as peças
    /*
   for( i = 1; i <= 42; i++ ){
    bibliotecadepecas(0,0,i,tabuleiro);
    printf("%d\n\n", i);
    analisar_pecas(tabuleiro, colunas, linhas);
    imprimir_tabuleiro(tabuleiro, linhas, colunas);
    apagar_tabuleiro(tabuleiro, linhas, colunas);
    }
   */
}