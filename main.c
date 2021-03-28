#include "headers.h"

//definir valores default 
#define DEFAULT_LINHA 9
#define DEFAULT_COLUNA 9
#define DEFAULT_MODO_JOGO 0
#define DEFAULT_MODO_POSICIONAMENTO 1
#define DEFAULT_MODO_DISPARO 1

void instrucoes()
{
    printf("B A T A L H A   N A V A L\n\n");
    printf("Modo de utilização: ./wargame[opções]\n");
    printf("Opções:\n");
    printf("-h\t\t    ajuda para o utilizador\n");
    printf("-t\t\t    dimensão do tabuleiro (linha x coluna)\n");
    printf("-j\t\t    modo de jogo\n");
    printf("-p\t\t    modo de posicionamento de peças pelo computador (1 a 2)\n");
    printf("-d\t\t    modo de disparo de peças pelo computador (1 a 3)\n");
    printf("-[1-8]\t\t    indica o número de peças de cada tipo (mínimo 1)\n\n");
}

int main()
{
instrucoes();
}