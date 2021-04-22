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

//definir valores default 
#define DEFAULT_LINHAS 9 /* valor por omissão para o número de linhas do tabuleiro */
#define DEFAULT_COLUNAS 9 /* valor por omissão para o número de colunas do tabuleiro */
#define DEFAULT_MODO_JOGO 0 /* valor por omissão do modo de jogo */
#define DEFAULT_MODO_POSICIONAMENTO 1 /* valor por omissão do modo de posicionamento */
#define DEFAULT_MODO_DISPARO 1 /* valor por omissão do modo de disparo */

/*
Função: instrucoes

Argumento: programa



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
Função main

Argumentos: argc, argv

return: 0- O programa acabou

Descrição: Verifica a linha de comando;
Inicializa variáveis;
Cria os modos de jogo, chamando as funções do modo de posição e do modo de disparo;
*/

int main(int argc, char *argv[])
{
    int i = 0, j = 0,
        /*
        definição dos valores default
        */
        linhas = DEFAULT_LINHAS,
        colunas = DEFAULT_COLUNAS,
        modoJogo = DEFAULT_MODO_JOGO,
        modoPosicionamento = DEFAULT_MODO_POSICIONAMENTO,
        modoDisparo = DEFAULT_MODO_DISPARO;
    /*
    disparosMin: número mínimo de disparos necessários para 
    acertar em todos os navios do tabuleiro.
    disparosMax: número máximo de disparos que se pode realizar.
    */
    int disparosMin = 0, 
        disparosMax = 0; 
     /*
    n_pecas: vetor que indica a quantidade de cada peca,
    sendo que as posições 0 a 7 do vetor correspondem a 
    um tipo de peça do tabuleiro, de 1 a 8, e a posição 
    8 corresponde ao número total de peças no tabuleiro
    */
    int n_pecas[9] = {0};
    /*
    flagvec: vetor de flag que indica que tipo de peças
    já foram testadas, de 0, que corresponde a uma matriz 
    3x3 vazia, a 8 (aplica-se ao modo de jogo 2)
    */
    int flagvec[9] = {0};
    /*
    tabuleiro: tabuleiro onde são geradas as peças no
    modo de jogo 0 e no modo de jogo 1
    */
    int tabuleiro[25][35] = {0};
    /*
    tabuleiro3: tabuleiro onde são registadas as peças
    encontradas pelo PC após um disparo, no modo de jogo 2
    */
    int tabuleiro3[25][35] = {0};
    int n_pecas_contador[9] = {0};
    char opt = 'h'; // opção para getopt()
    srand(time(NULL));

    /*
    verifica a linha de comandos:
    */
    while ((opt = getopt(argc,argv,"ht:j:p:d:1:2:3:4:5:6:7:8:")) != -1)
    {
        //printf("%c",opt);
        switch(opt) {
            /*
            case 't': identifica quando se usa o -t, e de seguida aponta (através do ) para o ínicio da inserção de 2 números 
            */
            case 't':
                sscanf(optarg, "%dx%d", &linhas, &colunas);
                //printf("%dx%d\n", linhas, colunas);
                /*
                O número de linhas tem de ser entre o 9 e o 15 e o número de colunas tem de ser entre 9 e 24, sendo que
                ambas têm de ser dívisiveis por 3
                */
                if ( linhas < 9 || colunas < 9 || linhas > 15 || colunas > 24 || linhas % 3 != 0 || colunas % 3 != 0 )
                {
                    printf("A dimensão do tabuleiro deve ser no mínimo 9x9 e no máximo 15x24\n\n");
                    printf("-1\n");
                    exit(0);
                }
                break;

            case 'j':
                sscanf(optarg,"%d", &modoJogo);
                //printf("j = %d\n", modoJogo);
                /*
                O modo de Jogo é entre o 0 e o 2
                */
                if ( modoJogo < 0 || modoJogo > 2 ){
                    printf("O modo do jogo é de 0 a 2\n");
                    printf("-1\n");
                    exit(0);
                }
                break;
            
            case 'p':
                sscanf(optarg, "%d", &modoPosicionamento);
                //printf("p = %d\n", modoPosicionamento);
                /*
                O modo de posicionamento é entre o 1 e o 2
                */
                if (modoPosicionamento < 1 || modoPosicionamento > 2){
                    printf ("O modo de posicionamento das peças é de 1 a 2\n");
                    printf("-1\n");
                    exit(0);   
                }           
                break;

            case 'd':
                sscanf(optarg, "%d", &modoDisparo);
                //printf("d = %d\n", modoDisparo);
                /*
                O modo de Disparo é entre o 1 e o 3
                */
                if (modoDisparo < 1 || modoDisparo > 3)
                {
                    printf("O modo de disparo das peças é de 1 a 3\n");
                    exit(0);
                }
                break;

            case '1':
                sscanf(optarg, "%d", &n_pecas[0]);
                n_pecas[8] += n_pecas[0];
                flagvec[1] = 1;
                break;

            case '2':
                sscanf(optarg, "%d", &n_pecas[1]);
                if( n_pecas[1] > n_pecas[0] ){
                    printf("-1\n");
                    exit(0);
                }

                n_pecas[8] += n_pecas[1];
                flagvec[2] = 1;
                break;

            case '3':
                sscanf(optarg, "%d", &n_pecas[2]);
                if( n_pecas[2] > n_pecas[1] ){
                    printf("-1\n");
                    exit(0);
                }

                n_pecas[8] += n_pecas[2];
                flagvec[3] = 1;
                break;

            case '4':
                sscanf(optarg, "%d", &n_pecas[3]);
                if( n_pecas[3] > n_pecas[2] ){
                    printf("-1\n");
                    exit(0);
                }

                n_pecas[8] += n_pecas[3];
                flagvec[3] = 1;
                break;

            case '5':
                sscanf(optarg, "%d", &n_pecas[4]);
                if( n_pecas[4] > n_pecas[3] ){
                    printf("-1\n");
                    exit(0);
                }

                n_pecas[8] += n_pecas[4];
                flagvec[5] = 1;
                break;

            case '6':
                sscanf(optarg, "%d", &n_pecas[5]);
                if( n_pecas[5] > n_pecas[4] ){
                    printf("-1\n");
                    exit(0);
                }
                n_pecas[8] += n_pecas[5];
                flagvec[6] = 1;
                break;

            case '7':
                sscanf(optarg, "%d", &n_pecas[6]);
                if( n_pecas[6] > n_pecas[5] ){
                    printf("-1\n");
                    exit(0);
                }

                n_pecas[8] += n_pecas[6];
                flagvec[7] = 1;
                break;

            case '8':
                sscanf(optarg, "%d", &n_pecas[7]);
                if( n_pecas[7] > n_pecas[6] ){
                    printf("-1\n");
                    exit(0);
                }

                n_pecas[8] += n_pecas[7];
                flagvec[8] = 1;
                break;

            default: //opções inválidas
                printf("Erro: opção '%c' desconhecida \n\n", optopt);
            case 'h':
                instrucoes(argv[0]);
                exit(0);
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
    int contador = 0;
    time_t start, end;
    double total;
    int sub_mat = 0;
    int flag = 0,
    flag2 = 0,
    flag3 = 1;
    int contador_r1 = 0;
    sub_mat = submat(linhas,colunas); //numero de matrizes 3x3 num tabuleiro
    int x = 0;
    char y_char;
    int y = 0;

    for( i = 0; i < 9; i++){
        n_pecas_contador[i + 1] = n_pecas[i];
    }

    if ( modoJogo == 0 ){
        if ( modoPosicionamento == 1 ){
            //printf("linhas: %d\n colunas: %d\n", linhas, colunas);
            p_1(tabuleiro, sub_mat, linhas, colunas);
            //printf("\n submat = %d\n\n", sub_mat);
            
            //printf("%dx%d", linhas, colunas);
        }

        if(modoPosicionamento == 2){
            //restrição 4

            if( n_pecas[8] > sub_mat / 2 ){
                printf("\nO nº total de peças tem de ser menor ou igual à metade do número de metrizes 3x3.\n\n");
                exit(0);
            }
            /*for( i = 0; i < 9; i++){
                printf("peça antes %d: %d\n", i + 1, n_pecas[i]);
            }*/
            flag = p_2(tabuleiro, n_pecas, flagvec, sub_mat, linhas, colunas);

            while(flag == -1){
                apagar_tabuleiro(tabuleiro, linhas, colunas);
                flag = p_2(tabuleiro, n_pecas, flagvec, sub_mat, linhas, colunas);
                contador_r1++;
                //printf("contador: %d\n", contador_r1);
               /* if(contador_r1 == 1000){
                    printf("-1\n"); 
                    exit(0);
                }*/
            }
        }
        printf("\n");
        imprimir_tabuleiro(tabuleiro, linhas, colunas);
    }
   
    if ( modoJogo == 1 ){
        time (&start);
        printf("*=================================\n");
        printf("* Modo de Jogo 1\n");
        printf("* Insira as coordenadas de Disparo\n");
        printf("*=================================\n");
        int contador_jogadas = 0;
        if(modoPosicionamento == 1){
            p_1(tabuleiro, sub_mat, linhas, colunas);
            printf("\n");
        }
        if(modoPosicionamento == 2){
            if( n_pecas[8] > sub_mat / 2 ){
                printf("\nO nº total de peças tem de ser menor ou igual à metade do número de metrizes 3x3.\n\n");
                exit(0);
            }

            flag2 = p_2(tabuleiro, n_pecas, flagvec, sub_mat, linhas, colunas);

            while(flag2 == -1){
                apagar_tabuleiro(tabuleiro, linhas, colunas);
                flag2 = p_2(tabuleiro, n_pecas, flagvec, sub_mat, linhas, colunas);
                contador_r1++;
            }
            printf("\n");
        }

        for ( i = 0; i < linhas; i++ ){
            for ( j = 0; j < colunas; j++ ){
                tabuleiro3[i][j] = tabuleiro[i][j];
                }
        }


        while( flag3 == 1 ){
            y = 0;
            x = 0;
            scanf(" %c %d", &y_char,&x); // x = nº de linhas total - linha
            contador++;
            y = y_char - 'A'; // y = coluna
            //printf("%d %d\n", linhas - x + 1, y);

            if(tabuleiro[linhas - x][y] == 0){
                printf("-\n");
            } else if (tabuleiro[ linhas - x][y] != 0){
                printf("%d\n", tabuleiro[linhas - x][y]);
            }
            tabuleiro3[linhas - x][y] = 0;
            flag3 = verificar_tab(tabuleiro3, linhas, colunas);
            //imprimir_tabuleiro(tabuleiro2, linhas, colunas);
            //imprimir_tabuleiro(tabuleiro, linhas, colunas);
            contador_jogadas++;
        }
        time(&end);
        imprimir_tabuleiro(tabuleiro, linhas, colunas);
        total = difftime (end,start);
        printf("Fim de jogo:%djogadas em %fsegundos\n",contador,total);
        
    }
    
    if( modoJogo == 2 ){
        printf("*=================================\n");
        printf("* Modo de Jogo 2\n");
        printf("* Crie um tabuleiro com as características indicadas\n");
        printf("* Responda aos disparos do programa\n");
        printf("*=================================\n");
        printf("%dx%d ", linhas, colunas);
        for(i = 0; i < 8; i++){
            disparosMin += (i + 1) * n_pecas[i];
        }
        n_pecas_contador[0] = sub_mat - (n_pecas[8]);
        //printf("%dx%d ", linhas, colunas);
        for(i = 8; i >= 0; i--){
            while(n_pecas_contador[i] > 0){
                printf("%d ", i );
                n_pecas_contador[i]--;
            }

        }
        printf("\n");

        disparosMax = linhas * colunas;

        if(modoDisparo == 1){
            time (&start);
            if(disparosMin > 0){
                
                contador = disparo_1(tabuleiro3, disparosMin, disparosMax, linhas, colunas);
                time(&end);
                total = difftime (end,start);
                
            }
        }
        if(modoDisparo == 2){
            if(disparosMin > 0){
                time (&start);
                
                contador = disparo_2(tabuleiro3, disparosMin, linhas, colunas);
                time(&end);
                total = difftime (end,start);
                
            }
        }
        if(modoDisparo == 3){
            if(disparosMin > 0){
                time (&start);
                
                contador = disparo_3(tabuleiro, tabuleiro3, disparosMin, linhas, colunas);
                time(&end);
                total = difftime (end,start);
                
            }
        }
        printf("\n");
        imprimir_tabuleiro(tabuleiro3, linhas, colunas);
        printf("\nFim de jogo:%djogadas em %fsegundos\n",contador,total);
    }
    return 0;
}
