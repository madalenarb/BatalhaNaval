#include "modo_p.h"
void p_1(int tabuleiro[25][35], int submat, int linhas, int colunas)
{
    //inicializa a variante e o tipo de peça
    //int id_global = return_id_global(tipoPeca, variante);
    int pos = 0;
    int contador, flag, id_global;
    int tabuleiro2[25][35] = {0}; // tabuleiro que será usado para comparar
    //Inicialização das coordenadas de posicionamento (poslinha, poscoluna)
    int poscoluna = 0;
    int poslinha = 0;
    int i = 0;
    int n_tipo_peca = 0;
    int contador_pecas[8] = {0};


    int numpecas = submat; //restrição nº2
    //printf("nº de peças %d\n", numpecas);
    for ( pos = 0; pos < submat; pos++)
    {
        //printf("pos%dx%d\n", poslinha, poscoluna);
        flag = 0; //quando flag = 0 pode-se colocar a peça na matriz, se flag = 1 não se pode colocar a peça na matriz
        id_global = id_global_aleatorio();
        contador = 0; //irá contar o número de tentativas a colocar uma peça na matriz

        if (id_global != 0)
        {
            numpecas--;
            n_tipo_peca = bibliotecadepecas(poslinha, poscoluna, id_global, tabuleiro);
            flag = verificar_pecas(tabuleiro, tabuleiro2, poslinha, poscoluna);
            //printf("flag = %d\n", flag);

            while( flag == 1 ){
                apagar_submat(tabuleiro, poslinha, poscoluna);
                id_global = id_global_aleatorio();
                if( id_global > 0){
                    n_tipo_peca = bibliotecadepecas(poslinha, poscoluna, id_global, tabuleiro);
                    flag = verificar_pecas(tabuleiro, tabuleiro2, poslinha, poscoluna);
                }

                //printf("flag = %d\n", flag);
                //printf("contador= %d\n", contador);
                //printf("id global = %d\n", id_global);
                contador++;
                if(contador >= 3){
                    apagar_submat(tabuleiro, poslinha, poscoluna);
                    id_global = 5;
                    n_tipo_peca = bibliotecadepecas(poslinha, poscoluna, id_global, tabuleiro);
                    flag = verificar_pecas(tabuleiro, tabuleiro2, poslinha, poscoluna);
                }
            }

            analisar_pecas(tabuleiro, tabuleiro2, linhas, colunas);
            contador_pecas[n_tipo_peca - 1]++;
            //imprimir_tabuleiro(tabuleiro, linhas, colunas);
            //imprimir_tabuleiro(tabuleiro2, linhas, colunas);
            
            /*
            for( i = 0; i < 8; i++ ){
                printf("peca %d: %d \n", i + 1, contador_pecas[i]);
            }
            */
            

            if (numpecas == 0){
                break;            
            }
        } else if ( id_global == 0 ){
            n_tipo_peca = bibliotecadepecas(poslinha, poscoluna, 0, tabuleiro);
        }

        poscoluna += 3;
        if(poscoluna >= colunas - 1){
            poscoluna = 0;
            poslinha += 3;
        }
    } 

    printf("%dx%d ", linhas, colunas);
    for(i = 0; i < 8; i++){
        printf("%d ", contador_pecas[i]);
    }
    printf("\n");
}

int p_2(int tabuleiro[25][35], int n_pecas[9], int flagvec[9], int submat, int linhas, int colunas)
{
    int i = 0,
        j = 0,
        n_pecas_aux[10] = {0},
        id_pecas_contador[10] = {0},
        numpecas = n_pecas[8];
        //printf("nº de pecas %d\n", numpecas);
        int tabuleiro2[25][35] = {0};
        n_pecas_aux[0] = submat - numpecas;

    int id_variante = 0,
        id_peca = 0,
        varianteMax = 0, //nº de variantes máximas de um tipo
        id_global = 0;

    int matrizVazia = 0;

    int contador = 0;

    int flag = 0; //flag que identifica quando uma peça está adjacente a outra peça

    for( i = 0; i < 9; i++){
        n_pecas_aux[i + 1] = n_pecas[i];
        //printf("peça aux%d: %d\n", i, n_pecas_aux[i]);
    }

    //inicialização da posição no canto superior esquerdo
    int pos = 0;
    int poscoluna = 0;
    int poslinha = 0;
    //printf("submat %d", submat);

    for( pos = 0; pos < submat; pos++ ){
        int flag1 = 90; // flag que indica quando é que se tem que returnar para P1
        // printf("pos %d x %d\n", poslinha, poscoluna);

        for( j = 0; j < 9; j++ ){
            if(n_pecas_aux[j] > 0){
                flagvec[j] = 1;
            }
        }
        /*        
        for( i = 0; i < 9; i++){
            printf("peça asha %d: %d\n", i, n_pecas_aux[i]);
        }
        */
                
        //printf("pos %d\n", pos);
            //printf("n_pecas_total %d", numpecas);
        //printf("id peca %d\n", id_peca);
        while( flag1 > 0 ){
            matrizVazia = rand()%2;
            if(matrizVazia == 0){
                id_peca = rand()%8 + 1;
            } else {
                id_peca = 0;
            }
            while( n_pecas_aux[id_peca] == 0 && flagvec[id_peca] == 0 ){
                matrizVazia = rand()%2;
                if(matrizVazia == 0){
                    id_peca = rand()%8 + 1;
                } else {
                    id_peca = 0;
                }
            }

            flagvec[id_peca] = 0;
            varianteMax = variante_max(id_peca);
            id_variante = variante_aleatoria(id_peca);
            //printf("variante: %d\n", id_variante);
            id_global = return_id_global(id_peca, id_variante);
            //printf("%d\n", id_global);
            bibliotecadepecas(poslinha, poscoluna, id_global, tabuleiro);
            //printf("tipo_peca= %d\n", id_peca);

            if(id_global > 0){
                flag = verificar_pecas(tabuleiro, tabuleiro2, poslinha, poscoluna);
            }

                //printf("flag = %d\n", flag);
                if(flag == 1){
                    id_variante = 1;
                    //printf("variante: %d\n", id_variante);
                }
                while( flag == 1 ){
                    apagar_submat(tabuleiro, poslinha, poscoluna);
                    if(id_global > 0){
                        id_global = return_id_global(id_peca, id_variante);
                    }
                    id_peca = bibliotecadepecas(poslinha, poscoluna, id_global, tabuleiro);
                    if(id_global > 0){
                        flag = verificar_pecas(tabuleiro, tabuleiro2, poslinha, poscoluna);
                    }
                    //printf("flagg = %d\n", flag);
                    //printf("id_tipo= %d\n", id_peca);
                    id_variante++;
                    if(id_variante > varianteMax){
                        for( contador = 0; contador < 9; contador++ ){
                            flag1 = 0;
                            flag1 += flagvec[contador];
                            //printf("flag1 asha %d: %d\n", contador, flagvec[contador]);
                        }
                        //printf("flag1 %d \n", flag1);
                        break;
                        //n_tipo_peca = bibliotecadepecas(poslinha, poscoluna, id_global, tabuleiro);
                        //flag = verificar_pecas(tabuleiro, tabuleiro2, poslinha, poscoluna);
                    }   
                        for( i = 0; i < 9; i++){
                            //printf("peça asha %d: %d\n", i, n_pecas_aux[i]);
                        }
                }
            if(flag == 0){
                flag1 = 0;
            }
            id_pecas_contador[id_peca]++;
        }
        if(flag1 == 0 && flag == 1){
            return -1;
        }


        analisar_pecas(tabuleiro, tabuleiro2, linhas, colunas);
        //imprimir_tabuleiro(tabuleiro, linhas, colunas);
        // imprimir_tabuleiro(tabuleiro2, linhas, colunas);
        n_pecas_aux[id_peca]--;
        numpecas--;

        poscoluna += 3;
        if( poscoluna >= colunas - 1 ){
            poscoluna = 0;
            poslinha += 3;
        }
    }
    printf("%dx%d ", linhas, colunas);
    for(i = 0; i < 8; i++){
        printf("%d ", n_pecas[i]);
    }
    printf("\n");
    return 0;
}
