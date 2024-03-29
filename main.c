/*
Projeto Intermédio Programação
Maria Madalena Barros, 100026
José Montez, 99996
Regente: Professor Nuno Horta MEEC
*/

#include "pecas.h"
#include "tabuleiro.h"
#include "bibliotecadepecas.h"
#include "modo_d.h"
#include "modo_p.h"

/* definir valores default */
#define DEFAULT_LINHAS 9 /* valor por omissão para o número de linhas do tabuleiro */
#define DEFAULT_COLUNAS 9 /* valor por omissão para o número de colunas do tabuleiro */
#define DEFAULT_MODO_JOGO 0 /* valor por omissão do modo de jogo */
#define DEFAULT_MODO_POSICIONAMENTO 1 /* valor por omissão do modo de posicionamento */
#define DEFAULT_MODO_DISPARO 1 /* valor por omissão do modo de disparo */

/*
* \Função: instrucoes
*
* \brief função que será chamada quando escreverem a opção -h no terminal
ou quando houver um erro
*
* \param programa char*: nome do programa
* \return void
*
*/

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

/*
* \Função main
*
* \Verifica a linha de comando e cria os modos de jogo, chamando as funções 
do modo de posição e do modo de disparo
*
* \param argc int- (argument count) é um valor inteiro que possui o número
de argumentos com os quais a função main() foi chamada na linha de comandos
* \param argv char- (argument vector) é um valor char, em que cada string é
um dos parâmetros da linha de comando.
* /return 0- O programa acabou
*
*/

int main(int argc, char *argv[])
{
    /*
    * i, j: contadores utilizados em ciclos for;
    */
    int i = 0, j = 0,

        /*
        * definição dos valores default
        */
        linhas = DEFAULT_LINHAS,
        colunas = DEFAULT_COLUNAS,
        modoJogo = DEFAULT_MODO_JOGO,
        modoPosicionamento = DEFAULT_MODO_POSICIONAMENTO,
        modoDisparo = DEFAULT_MODO_DISPARO;
    
    /*
    * disparosMin: número mínimo de disparos necessários para
    acertar em todos os navios do tabuleiro, este indicará 
    quando se atingirem todos os barcos;
    *
    * disparosMax: número máximo de disparos que se pode realizar, utilizado
    no modo de jogo 2, modo de disparo 1, para indicar os disparos máximos
    possíveis (linhas * colunas);
    */
    int disparosMin = 0,
        disparosMax = 0;

    /*
    * n_pecas: vetor que indica a quantidade de cada peca,
    sendo que as posições 0 a 7 do vetor correspondem a
    um tipo de peça do tabuleiro, de 1 a 8, e a posição
    8 corresponde ao número total de peças no tabuleiro
    */
    int n_pecas[9] = {0};

    /*
    * flagvec: vetor de flag que indica que tipo de peças
    já foram testadas, de 0, que corresponde a uma matriz
    3x3 vazia, a 8 (aplica-se ao modo de jogo 2)
    */
    int flagvec[9] = {0};

    /*
    * tabuleiro: tabuleiro onde são geradas as peças no
    modo de jogo 0 e no modo de jogo 1
    */
    int tabuleiro[25][35] = {{0}};

    /*
    * tabuleiro3: tabuleiro onde são registadas as peças já atingidas,
    * no modo 1, retirando o número correspondente ao id_peça do tabuleiro, 
    trocando por '-'
    * no modo 2, colocando o número correspondente ao id_peca no tabuleiro;
    */
    int tabuleiro3[25][35] = {{0}};

    /* opt: opção para getopt() */
    char opt = 'h';
    srand(time(NULL));

    /* verifica a linha de comandos: */
    while ((opt = getopt(argc,argv,"ht:j:p:d:1:2:3:4:5:6:7:8:")) != -1)
    {
        switch(opt) {
            /* case 't': identifica quando se usa o -t, que definirá o tamanho do tabuleiro  */
            case 't':
                sscanf(optarg, "%dx%d", &linhas, &colunas);
                /* O número de linhas tem de ser entre o 9 e o 15 e o número de colunas 
                tem de ser entre 9 e 24, sendo que ambas têm de ser dívisiveis por 3 */
                if ( linhas < 9 || colunas < 9 || linhas > 15 || colunas > 24 || linhas % 3 != 0 || colunas % 3 != 0 )
                {
                    printf("A dimensão do tabuleiro deve ser no mínimo 9x9 e no máximo 15x24\n\n");
                    printf("-1\n");
                    instrucoes(argv[0]);
                    exit(0);
                }
                break;

            /* case 'j': identifica quando se usa o -j, que definirá o modo de jogo. */
            case 'j':
                sscanf(optarg,"%d", &modoJogo);
                
                /* O modo de Jogo é entre o 0 e o 2 */
                if ( modoJogo < 0 || modoJogo > 2 ){
                    printf("O modo do jogo é de 0 a 2\n");
                    printf("-1\n");
                    instrucoes(argv[0]);
                    exit(0);
                }
                break;
                
            /* case 'p': identifica quando se usa o -p, que definirá o modo de posicionamento; */
            case 'p':
                sscanf(optarg, "%d", &modoPosicionamento);
                /* O modo de posicionamento é entre o 1 e o 2 */
                if (modoPosicionamento < 1 || modoPosicionamento > 2){
                    printf ("O modo de posicionamento das peças é de 1 a 2\n");
                    printf("-1\n");
                    instrucoes(argv[0]);
                    exit(0);
                }
                break;
                
            /* case 'd': identifica quando se usa o -d, que definirá o modo do disparo */
            case 'd':
                sscanf(optarg, "%d", &modoDisparo);
                /*
                O modo de Disparo é entre o 1 e o 3;
                */
                if (modoDisparo < 1 || modoDisparo > 3)
                {
                    printf("O modo de disparo das peças é de 1 a 3\n");
                    instrucoes(argv[0]);
                    exit(0);
                }
                break;

            /*
            * case '[1-8]': identifica qual é o tipo de peça pretendida (do 1 ao 8) e,
            respetivamente o número de peças;
            */
            case '1':
                sscanf(optarg, "%d", &n_pecas[0]);
                n_pecas[8] += n_pecas[0];
                flagvec[1] = 1;
                break;

            case '2':
                sscanf(optarg, "%d", &n_pecas[1]);
                if( n_pecas[1] > n_pecas[0] ){
                    printf("-1\n");
                    instrucoes(argv[0]);
                    exit(0);
                }

                n_pecas[8] += n_pecas[1];
                flagvec[2] = 1;
                break;

            case '3':
                sscanf(optarg, "%d", &n_pecas[2]);
                if( n_pecas[2] > n_pecas[1] ){
                    printf("-1\n");
                    instrucoes(argv[0]);
                    exit(0);
                }

                n_pecas[8] += n_pecas[2];
                flagvec[3] = 1;
                break;

            case '4':
                sscanf(optarg, "%d", &n_pecas[3]);
                if( n_pecas[3] > n_pecas[2] ){
                    printf("-1\n");
                    instrucoes(argv[0]);
                    exit(0);
                }

                n_pecas[8] += n_pecas[3];
                flagvec[3] = 1;
                break;

            case '5':
                sscanf(optarg, "%d", &n_pecas[4]);
                if( n_pecas[4] > n_pecas[3] ){
                    printf("-1\n");
                    instrucoes(argv[0]);
                    exit(0);
                }

                n_pecas[8] += n_pecas[4];
                flagvec[5] = 1;
                break;

            case '6':
                sscanf(optarg, "%d", &n_pecas[5]);
                if( n_pecas[5] > n_pecas[4] ){
                    printf("-1\n");
                    instrucoes(argv[0]);
                    exit(0);
                }
                n_pecas[8] += n_pecas[5];
                flagvec[6] = 1;
                break;

            case '7':
                sscanf(optarg, "%d", &n_pecas[6]);
                if( n_pecas[6] > n_pecas[5] ){
                    printf("-1\n");
                    instrucoes(argv[0]);
                    exit(0);
                }

                n_pecas[8] += n_pecas[6];
                flagvec[7] = 1;
                break;

            case '8':
                sscanf(optarg, "%d", &n_pecas[7]);
                if( n_pecas[7] > n_pecas[6] ){
                    printf("-1\n");
                    instrucoes(argv[0]);
                    exit(0);
                }

                n_pecas[8] += n_pecas[7];
                flagvec[8] = 1;
                break;

            default:
                /* se as opções forem inválidas: */
                printf("Erro: opção '%c' desconhecida \n\n", optopt);
            case 'h':
                instrucoes(argv[0]);
                exit(0);
                break;
        }
    }

    /* contador: irá contar o número de jogadas, que no final do jogo serão impressas */
    int contador = 0;
    /* time_t start, end: indica o início e o fim da contagem do tempo */
    time_t start, end;

    /* total de tempo durante uma jogada (aparecerá no final do programa) */
    int total = 0;

    /* sub_mat: número de matrizes 3x3 dentro do tabuleiro */
    int sub_mat = 0;

    /*
    * flag: no modo de posicionamento 2, esta flag verifica se 
    foi possível colocar a peça depois de experimentar todas as variantes:
    * Se foi, a flag passa a 0, colocando a peça,
    * Se não foi, a flag passa a 1 e volta a repetir a função p_2;
    *
    * flag 2: verifica se todas as peças já foram colocadas
    */
    int flag = 0,
        flag2 = 1;

    sub_mat = submat(linhas,colunas);

    /*
    * x: linha
    * y: coluna
    * y_char: coluna em char
    */
    int x = 0;
    char y_char;
    int y = 0;

    /* modo de jogo 0 */
    if ( modoJogo == 0 ){
        if ( modoPosicionamento == 1 ){
            p_1(tabuleiro, sub_mat, linhas, colunas);
        }

        if(modoPosicionamento == 2){
            /* salvaguarda a restrição 4 */
            if( n_pecas[8] > sub_mat / 2 ){
                printf("\nO nº total de peças tem de ser menor ou igual à metade do número de metrizes 3x3.\n\n");
                exit(0);
            }

            flag = p_2(tabuleiro, n_pecas, flagvec, sub_mat, linhas, colunas);

            while(flag == -1){
                apagar_tabuleiro(tabuleiro, linhas, colunas);
                flag = p_2(tabuleiro, n_pecas, flagvec, sub_mat, linhas, colunas);
            }
        }
        printf("\n");
        imprimir_tabuleiro(tabuleiro, linhas, colunas);
    }

      /* Modo de jogo 1 */
    if ( modoJogo == 1 ){
        /* inicializa a contagem do tempo */
        time (&start);
        printf("* =================================\n");
        printf("* Modo de Jogo 1\n");
        printf("* Insira as coordenadas de Disparo\n");
        printf("* =================================\n");
        if(modoPosicionamento == 1){
            p_1(tabuleiro, sub_mat, linhas, colunas);
            printf("\n");
        }
        if( modoPosicionamento == 2 ){
            /* salvaguarda a restrição 4 */
            if( n_pecas[8] > sub_mat / 2 ){
                printf("\nO nº total de peças tem de ser menor ou igual à metade do número de metrizes 3x3.\n\n");
                exit(0);
            }

            flag = p_2(tabuleiro, n_pecas, flagvec, sub_mat, linhas, colunas);

            /* enquanto a flag == -1 a função p_2 irá repetir */
            while(flag == -1){
                apagar_tabuleiro(tabuleiro, linhas, colunas);
                flag = p_2(tabuleiro, n_pecas, flagvec, sub_mat, linhas, colunas);
            }
            printf("\n");
        }

        /* cópia do tabuleiro para o tabuleiro3 */
        for ( i = 0; i < linhas; i++ ){
            for ( j = 0; j < colunas; j++ ){
                tabuleiro3[i][j] = tabuleiro[i][j];
                }
        }

        /*
        *salvaguarda que, no caso de não especificarem um número,
        o tabuleiro impresso é vazio e acaba o programa;
        */
        if(n_pecas[8] <= 0 && modoPosicionamento == 2 ){
            imprimir_tabuleiro(tabuleiro, linhas, colunas);
            return(0);
        }

        while( flag2 == 1 ){
            y = 0;
            x = 0;

            scanf(" %c %d", &y_char, &x);

            contador++;

            /* O y indicará em que coluna está, em integer*/
            y = y_char - 'A';

            if(tabuleiro[linhas - x][y] == 0){
                printf("-\n");
            } else if (tabuleiro[ linhas - x][y] != 0){
                printf("%d\n", tabuleiro[linhas - x][y]);
            }

            /*
            * altera as posiçoes do disparo no tabuleiro para 0, "eliminando" assim as peças
            do tabuleiro3;
            */
            tabuleiro3[linhas - x][y] = 0;
            flag2 = verificar_tab(tabuleiro3, linhas, colunas);
        }
        /* fim da contagem de tempo */
        time(&end);
        imprimir_tabuleiro(tabuleiro, linhas, colunas);
        /* calculo do tempo (final - inicial) */
        total = difftime (end,start);

        /* print do tempo e do número de jogadas */
        printf("Fim de jogo: %d jogadas em %d segundos\n",contador,total);

    }


    /* modo de jogo 2 */
    if( modoJogo == 2 ){
        printf("* =================================\n");
        printf("* Modo de Jogo 2\n");
        printf("* Crie um tabuleiro com as características indicadas\n");
        printf("* Responda aos disparos do programa\n");
        printf("* =================================\n");
        printf("%dx%d ", linhas, colunas);

        /* Imprime o número de peças organizado por identificador da peça */
        for(i = 0; i < 8; i++){
            printf("%d ", n_pecas[i]);
        }
        printf("\n");

        for(i = 0; i < 8; i++){
            disparosMin += (i + 1) * n_pecas[i];
        }

        printf("\n");

        disparosMax = linhas * colunas;

        if(modoDisparo == 1){
            time(&start);
            if(disparosMin > 0){

                /* disparo1, e retorna o numero de jogadas */
                contador = disparo_1(tabuleiro3, disparosMin, disparosMax, linhas, colunas);
                time(&end);
                total = difftime (end,start);
            }
        }
        if(modoDisparo == 2){
            if(disparosMin > 0){
                time(&start);
                /* disparo2, e retorna o numero de jogadas */
                contador = disparo_2(tabuleiro3, disparosMin, linhas, colunas);
                time(&end);
                total = difftime (end, start);

            }
        }
        if(modoDisparo == 3){
            if(disparosMin > 0){
                time(&start);
                /* disparo3, e retorna o numero de jogadas */
                contador = disparo_3(tabuleiro3, disparosMin, linhas, colunas);
                time(&end);
                total = difftime (end,start);

            }
        }
        printf("\n");
        imprimir_tabuleiro(tabuleiro3, linhas, colunas);
        printf("Fim de jogo: %d jogadas em %d segundos\n", contador, total);
    }
    return 0;
}
