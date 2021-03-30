#include "headers.h"

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
    printf("Modo de utilização: ./wargame[opções]\n");
    printf("opções:\n");
    printf("-h\t\t    ajuda para o utilizador\n");
    printf("-t\t\t    dimensão do tabuleiro (linha x coluna)\n");
    printf("-j\t\t    modo de jogo (0 a 2)\n");
    printf("-p\t\t    modo de posicionamento de peças pelo computador (1 a 2)\n");
    printf("-d\t\t    modo de disparo de peças pelo computador (1 a 3)\n");
    printf("-[1-8]\t\t    indica o número de peças de cada tipo (mínimo 1)\n\n");

}

int main(int argc, char *argv[])
{
    int i,
        linhas = DEFAULT_LINHAS,
        colunas = DEFAULT_COLUNAS,
        modoJogo = DEFAULT_MODO_JOGO,
        modoPosicionamento = DEFAULT_MODO_POSICIONAMENTO,
        modoDisparo = DEFAULT_MODO_DISPARO;
    int tabuleiro[9][9] = {0};
    char opt = 'h'; // opção para getopt()

    opterr = 0; // assim getopt() não gera erros por opções inválidas

    // opções da linha de comandos:
    while ((opt = getopt(argc,argv,"ht:j:p:d:1234568")) != -1)
    {
        //printf("%c",opt);
        switch(opt) {
            case 't':
                sscanf(optarg, "%dx%d", &linhas, &colunas);
                printf("%d %d\n", linhas, colunas);
                if ( linhas < 9 || colunas < 9 || linhas > 15 || colunas > 24 || linhas % 3 != 0 || colunas % 3 != 0)
                {
                    printf("-1\n");
                    return EXIT_FAILURE;
                }
                
                break;
            case 'j':
                sscanf(optarg,"%d", &modoJogo);
                if (modoJogo < 0 || modoJogo > 2){
                    printf("-1");
                    return EXIT_FAILURE;
                }
            
            case 'p':
                sscanf(optarg, "%d", &modoPosicionamento);
                if (modoPosicionamento < 1 || modoPosicionamento > 2){
                    printf ("-1");
                    return EXIT_FAILURE;
                }                
                break;
            
            case 'd':
                sscanf(optarg, "%d", &modoDisparo);
                if (modoDisparo < 1 || modoDisparo > 3)
                {
                    printf ("-1");
                    return EXIT_FAILURE;
                }
                
        }
    }
    //instrucoes();
}
