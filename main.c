#include "pecas.h"
#include "tabuleiro.h"
#include "bibliotecadepecas.h"
#include "modo_d.h"
#include "modo_p.h"

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
    int i = 0, j = 0,
        linhas = DEFAULT_LINHAS,
        colunas = DEFAULT_COLUNAS,
        modoJogo = DEFAULT_MODO_JOGO,
        modoPosicionamento = DEFAULT_MODO_POSICIONAMENTO,
        modoDisparo = DEFAULT_MODO_DISPARO;
    int disparosMin = 0;  //nºs de disparos mínimos necessários para vencer
    int id_peca_2; // identifica o id peca da peca indicada pelo utilizador no modo de jogo 2
    int n_pecas[9] = {0};
    int flagvec[9] = {0}; // vetor de flag que indica que tipo de pecas já foram testadas (p_2)
    int tabuleiro[25][35] = {0};
    int tabuleiro2[25][35] = {0}; // tabuleiro onde se registão os disparos para confirmar que se chegou ao fim
    int tabuleiro3[25][35] = {0}; // tabuleiro no qual será registado as peças emncontradas pelo computador no modo de jogo 2
    char opt = 'h'; // opção para getopt()
    srand(time(NULL));

    // opções da linha de comandos:
    while ((opt = getopt(argc,argv,"ht:j:p:d:1:2:3:4:5:6:7:8:")) != -1)
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
                    exit(0);
                }
                break;

            case 'j':
                sscanf(optarg,"%d", &modoJogo);
                //printf("j = %d\n", modoJogo);
                if ( modoJogo < 0 || modoJogo > 2 ){
                    printf("O modo do jogo é de 0 a 2\n");
                    printf("-1\n");
                    exit(0);
                }
                break;
            
            case 'p':
                sscanf(optarg, "%d", &modoPosicionamento);
                //printf("p = %d\n", modoPosicionamento);
                if (modoPosicionamento < 1 || modoPosicionamento > 2){
                    printf ("O modo de posicionamento das peças é de 1 a 2\n");
                    printf("-1\n");
                    exit(0);   
                }           
                break;

            case 'd':
                sscanf(optarg, "%d", &modoDisparo);
                //printf("d = %d\n", modoDisparo);
                if (modoDisparo < 1 || modoDisparo > 3)
                {
                    printf("O modo de disparo das peças é de 1 a 3\n");
                    exit(0);
                }

                break;

            case '1':
                sscanf(optarg, "%d", &n_pecas[0]);// quando nº de peças de tipo 1 é menor do que o nº de peças de tipo 2 o que é que o programa tem de fazer?
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
    int sub_mat = 0;
    int flag = 0,
    flag2 = 0,
    flag3 = 1,
    flag4 = 1;
    int contador_r1 = 0;
    sub_mat = submat(linhas,colunas); //numero de matrizes 3x3 num tabuleiro
    int x;
    char y;
    

    if ( modoJogo == 0 ){
        if ( modoPosicionamento == 1 ){
            //printf("linhas: %d\n colunas: %d\n", linhas, colunas);
            p_1(tabuleiro, sub_mat, linhas, colunas);
            imprimir_tabuleiro(tabuleiro, linhas, colunas);
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
            imprimir_tabuleiro(tabuleiro, linhas, colunas);
        }
    }
   
    if ( modoJogo == 1 ){
        if(modoPosicionamento == 1){
            p_1(tabuleiro, sub_mat, linhas, colunas);
            imprimir_tabuleiro(tabuleiro, linhas, colunas);
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
            imprimir_tabuleiro(tabuleiro, linhas, colunas);

        }

        for ( i = 0; i < linhas; i++ ){
            for ( j = 0; j < colunas; j++ ){
                tabuleiro2[i][j] = tabuleiro[i][j];
                }
        }


        while( flag3 == 1 ){
            y = 0;
            x = 0;
            scanf(" %c %d", &y,&x); // x = nº de linhas total - linha
            y -= 65; // y = coluna
            //printf("%d %d\n", linhas - x + 1, y);

            if(tabuleiro[linhas - x][y] == 0){
                printf("-\n");
            } else if (tabuleiro[ linhas - x][y] != 0){
                printf("%d\n", tabuleiro[linhas - x][y]);
            }
            tabuleiro2[linhas - x][y] = 0;
            flag3 = verificar_tab(tabuleiro2, linhas, colunas);
            //imprimir_tabuleiro(tabuleiro2, linhas, colunas);
        }
    }
    
    if( modoJogo == 2 ){
        for(i = 0; i < 8; i++){
            disparosMin += (i + 1) * n_pecas[i];
        }
        if(modoDisparo == 1){
                disparo_1(tabuleiro, tabuleiro2, tabuleiro3, disparosMin, linhas, colunas);
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