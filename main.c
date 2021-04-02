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
    int tabuleiro[25][35] = {0};
    char opt = 'h'; // opção para getopt()

    // opções da linha de comandos:
    while ((opt = getopt(argc,argv,"ht:j:p:d:1234568")) != -1)
    {
        //printf("%c",opt);
        switch(opt) {
            case 't':
                sscanf(optarg, "%dx%d", &linhas, &colunas);
                //printf("%dx%d\n", linhas, colunas);
                if ( linhas < 9 || colunas < 9 || linhas > 15 || colunas > 24 || linhas % 3 != 0 || colunas % 3 != 0)
                {
                    printf("-1\n");
                    return EXIT_FAILURE;
                }

                break;
            case 'j':
                sscanf(optarg,"%d", &modoJogo);
                //printf("j = %d\n", modoJogo);
                if (modoJogo < 0 || modoJogo > 2){
                    printf("-1");
                    return EXIT_FAILURE;
                }
                break;
            
            case 'p':
                sscanf(optarg, "%d", &modoPosicionamento);
                //printf("p = %d\n", modoPosicionamento);
                if (modoPosicionamento < 1 || modoPosicionamento > 2){
                    printf ("-1");
                    return EXIT_FAILURE;
                }                
                break;
            
            case 'd':
                sscanf(optarg, "%d", &modoDisparo);
                //printf("d = %d\n", modoDisparo);
                if (modoDisparo < 1 || modoDisparo > 3)
                {
                    printf ("-1");
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
   
    int numdemat = submat(linhas,colunas); //numero de matrizes 3x3 num tabuleiro
    coloca_peca(tabuleiro, numdemat, colunas);
    imprimir_tabuleiro(tabuleiro, linhas, colunas);
    printf("\n submat = %d\n\n", numdemat);
    
    
    
        //Testa todas as peças
    /*
   for( i = 1; i <= 42; i++ ){
    bibliotecadepecas(0,0,i,tabuleiro);
    printf("%d\n\n", i);
    imprimir_tabuleiro(tabuleiro, linhas, colunas);
    apagar_tabuleiro(tabuleiro, linhas, colunas);
   }
   */
   
}



/*void colocar_peca(int tabuleiro[15][24], int x, int y, int identificadorPeca, int identificadorVariante)
{
    if(identificadorPeca == 1){
        tabuleiro[(x + identificadorVariante)%3][y] = 1;
    }
}

void apagar_tabuleiro(int tabuleiro, int linhas, int colunas)
{
    int i;
    for ( i = 0; i < linhas; i++)
    {
        printf("0")
    }
    
}*/