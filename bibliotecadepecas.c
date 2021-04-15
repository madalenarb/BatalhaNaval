#include "bibliotecadepecas.h"
//esta função identifica a posição das peças no tabuleiro em função com o identificador global
int bibliotecadepecas(int x, int y, int id_global, int tabuleiro[25][35])
{

    switch (id_global)
    {
    case 0:
        break;

    case 1: 
        tabuleiro[x][y] = 1;
        return 1;
    
    case 2: 
        tabuleiro[x][y + 1] = 1;

        return 1;

    case 3:
        tabuleiro[x][y + 2] = 1;
        return 1;

    case 4:
        tabuleiro[x + 1][y] = 1;
        return 1;

    case 5:
        tabuleiro[x + 1][y + 1] = 1;
        return 1;

    case 6:
        tabuleiro[x + 1][y + 2] = 1;
        return 1;

    case 7:
        tabuleiro[x + 2][y] = 1;
        return 1;

    case 8:
        tabuleiro[x + 2][y + 1] = 1;
        return 1;

    case 9:
        tabuleiro[x + 2][y + 2] = 1;
        return 1;

    case 10:
        tabuleiro[x][y] = 2;
        tabuleiro[x][y + 1] = 2;
        return 2;

    case 11:
        tabuleiro[x][y + 1] = 2;
        tabuleiro[x][y + 2] = 2;
        return 2;

    case 12:
        tabuleiro[x + 1][y] = 2;
        tabuleiro[x + 1][y + 1] = 2;
        return 2;
    
    case 13:
        tabuleiro[x + 1][y + 1] = 2;
        tabuleiro[x + 1][y + 2] = 2;
        return 2;

    case 14:
        tabuleiro[x + 2][y] = 2;
        tabuleiro[x + 2][y + 1] = 2;
        return 2;

    case 15:
        tabuleiro[x + 2][y + 1] = 2;
        tabuleiro[x + 2][y + 2] = 2;
        return 2;

    case 16:
        tabuleiro[x][y] = 2;
        tabuleiro[x + 1][y] = 2;
        return 2;

    case 17:
        tabuleiro[x + 1][y] = 2;
        tabuleiro[x + 2][y] = 2;
        return 2;

    case 18:
        tabuleiro[x][y + 1] = 2;
        tabuleiro[x + 1][y + 1] = 2;
        return 2;

    case 19:
        tabuleiro[x + 1][y + 1] = 2;
        tabuleiro[x + 2][y + 1] = 2;
        return 2;

    case 20:
        tabuleiro[x][y + 2] = 2;
        tabuleiro[x + 1][y + 2] = 2;
        return 2;

    case 21:
        tabuleiro[x + 1][y + 2] = 2;
        tabuleiro[x + 2][y + 2] = 2;
        return 2;
    
    case 22:
        tabuleiro[x][y] = 3;
        tabuleiro[x][y + 1] = 3;
        tabuleiro[x][y + 2] = 3;
        return 3;

    case 23:
        tabuleiro[x + 1][y] = 3;
        tabuleiro[x + 1][y + 1] = 3;
        tabuleiro[x + 1][y + 2] = 3;
        return 3;

    case 24:
        tabuleiro[x + 2][y] = 3;
        tabuleiro[x + 2][y + 1] = 3;
        tabuleiro[x + 2][y + 2] = 3;
        return 3;

    case 25:
        tabuleiro[x][y] = 3;
        tabuleiro[x + 1][y] = 3;
        tabuleiro[x + 2][y] = 3;
        return 3;

    case 26:
        tabuleiro[x][y + 1] = 3;
        tabuleiro[x + 1][y + 1] = 3;
        tabuleiro[x + 2][y + 1] = 3;
        return 3;

    case 27:
        tabuleiro[x][y + 2] = 3;
        tabuleiro[x + 1][y + 2] = 3;
        tabuleiro[x + 2][y + 2] = 3;
        return 3;

    case 28:
        tabuleiro[x][y] = 4;
        tabuleiro[x][y + 1] = 4;
        tabuleiro[x + 1][y] = 4;
        tabuleiro[x + 1][y + 1] = 4;
        return 4;

    case 29:
        tabuleiro[x][y + 1] = 4;
        tabuleiro[x][y + 2] = 4;
        tabuleiro[x + 1][y + 1] = 4;
        tabuleiro[x + 1][y + 2] = 4;
        return 4;

    case 30:
        tabuleiro[x + 1][y] = 4;
        tabuleiro[x + 1][y + 1] = 4;
        tabuleiro[x + 2][y] = 4;
        tabuleiro[x + 2][y + 1] = 4;
        return 4;

    case 31:
        tabuleiro[x + 1][y + 1] = 4;
        tabuleiro[x + 1][y + 2] = 4;
        tabuleiro[x + 2][y + 1] = 4;
        tabuleiro[x + 2][y + 2] = 4;
        return 4;

    case 32:
        tabuleiro[x][y] = 5;
        tabuleiro[x][y + 1] = 5;
        tabuleiro[x][y + 2] = 5;
        tabuleiro[x + 1][y + 1] = 5;
        tabuleiro[x + 2][y + 1] = 5;
        return 5;

    case 33:
        tabuleiro[x][y] = 5;
        tabuleiro[x + 1][y] = 5;
        tabuleiro[x + 2][y] = 5;
        tabuleiro[x + 1][y + 1] = 5;
        tabuleiro[x + 1][y + 2] = 5;
        return 5;

    case 34:
        tabuleiro[x][y + 1] = 5;
        tabuleiro[x + 1][y + 1] = 5;
        tabuleiro[x + 2][y] = 5;
        tabuleiro[x + 2][y + 1] = 5;
        tabuleiro[x + 2][y + 2] = 5;
        return 5;

    case 35:
        tabuleiro[x + 1][y] = 5;
        tabuleiro[x + 1][y + 1] = 5;
        tabuleiro[x][y + 2] = 5;
        tabuleiro[x + 1][y + 2] = 5;
        tabuleiro[x + 2][y + 2] = 5;
        return 5;

    case 36:
        tabuleiro[x][y + 1] = 6;
        tabuleiro[x + 1][y] = 6;
        tabuleiro[x + 1][y + 2] = 6;
        tabuleiro[x + 2][y] = 6;
        tabuleiro[x + 2][y + 1] = 6;
        tabuleiro[x + 2][y + 2] = 6;
        return 6;

    case 37:
        tabuleiro[x + 1][y] = 6;
        tabuleiro[x][y + 1] = 6;
        tabuleiro[x][y + 2] = 6;
        tabuleiro[x + 1][y + 2] = 6;
        tabuleiro[x + 2][y + 2] = 6;
        tabuleiro[x + 2][y + 1] = 6;
        return  6;

    case 38:
        tabuleiro[x + 2][y + 1] = 6;
        tabuleiro[x + 1][y] = 6;
        tabuleiro[x][y] = 6;
        tabuleiro[x][y + 1] = 6;
        tabuleiro[x][y + 2] = 6;
        tabuleiro[x + 1][y + 2] = 6;
        return 6;

    case 39:
        tabuleiro[x + 1][y + 2] = 6;
        tabuleiro[x + 2][y + 1] = 6;
        tabuleiro[x + 2][y] = 6;
        tabuleiro[x + 1][y] = 6;
        tabuleiro[x][y] = 6;
        tabuleiro[x][y + 1] = 6;
        return 6;

    case 40:
        tabuleiro[x][y] = 7;
        tabuleiro[x + 1][y] = 7;
        tabuleiro[x + 2][y] = 7;
        tabuleiro[x + 1][y + 1] = 7;
        tabuleiro[x][y + 2] = 7;
        tabuleiro[x + 1][y + 2] = 7;
        tabuleiro[x + 2][y + 2] = 7;
        return 7;   

    case 41:
       tabuleiro[x][y] = 7;
       tabuleiro[x][y + 1] = 7;
       tabuleiro[x][y + 2] = 7;
       tabuleiro[x + 1][y + 1] = 7;
       tabuleiro[x + 2][y] = 7;
       tabuleiro[x + 2][y + 1] = 7;
       tabuleiro[x + 2][y + 2] = 7;
        return 7;   

    case 42:
       tabuleiro[x][y] = 8;
       tabuleiro[x][y + 1] = 8;
       tabuleiro[x][y + 2] = 8;
       tabuleiro[x + 1][y] = 8;
       tabuleiro[x + 2][y] = 8;
       tabuleiro[x + 2][y + 1] = 8;
       tabuleiro[x + 2][y + 2] = 8;
       tabuleiro[x + 1][y + 2] = 8;
        return 8; 

    default:
        return 0;
    }
}