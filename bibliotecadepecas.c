#include "bibliotecadepecas.h"
//esta função identifica a posição das peças no tabuleiro em função com o identificador global
void bibliotecadepecas(int x, int y, int id_global, int tabuleiro[25][35])
{

    switch (id_global)
    {
    case 1: 
        tabuleiro[x][y] = 1;
        break;
    
    case 2: 
        tabuleiro[x][y + 1] = 1;
        break;

    case 3:
        tabuleiro[x][y + 2] = 1;
        break;

    case 4:
        tabuleiro[x + 1][y] = 1;
        break;

    case 5:
        tabuleiro[x + 1][y + 1] = 1;
        break;

    case 6:
        tabuleiro[x + 1][y + 2] = 1;
        break;

    case 7:
        tabuleiro[x + 2][y] = 1;
        break;

    case 8:
        tabuleiro[x + 2][y + 1] = 1;
        break;

    case 9:
        tabuleiro[x + 2][y + 2] = 1;
        break;

    case 10:
        tabuleiro[x][y] = 2;
        tabuleiro[x][y + 1] = 2;
        break;

    case 11:
        tabuleiro[x][y + 1] = 2;
        tabuleiro[x][y + 2] = 2;
        break;

    case 12:
        tabuleiro[x + 1][y] = 2;
        tabuleiro[x + 1][y + 1] = 2;
        break;
    
    case 13:
        tabuleiro[x + 1][y + 1] = 2;
        tabuleiro[x + 1][y + 2] = 2;
        break;

    case 14:
        tabuleiro[x + 2][y] = 2;
        tabuleiro[x + 2][y + 1] = 2;
        break;

    case 15:
        tabuleiro[x + 2][y + 1] = 2;
        tabuleiro[x + 2][y + 2] = 2;
        break;

    case 16:
        tabuleiro[x][y] = 2;
        tabuleiro[x + 1][y] = 2;
        break;

    case 17:
        tabuleiro[x + 1][y] = 2;
        tabuleiro[x + 2][y] = 2;
        break;

    case 18:
        tabuleiro[x][y + 1] = 2;
        tabuleiro[x + 1][y + 1] = 2;
        break;

    case 19:
        tabuleiro[x + 1][y + 1] = 2;
        tabuleiro[x + 2][y + 1] = 2;
        break;

    case 20:
        tabuleiro[x][y + 2] = 2;
        tabuleiro[x + 1][y + 2] = 2;
        break;

    case 21:
        tabuleiro[x + 1][y + 2] = 2;
        tabuleiro[x + 2][y + 2] = 2;
        break;
    
    case 22:
        tabuleiro[x][y] = 3;
        tabuleiro[x][y + 1] = 3;
        tabuleiro[x][y + 2] = 3;
        break;

    case 23:
        tabuleiro[x + 1][y] = 3;
        tabuleiro[x + 1][y + 1] = 3;
        tabuleiro[x + 1][y + 2] = 3;
        break;

    case 24:
        tabuleiro[x + 2][y] = 3;
        tabuleiro[x + 2][y + 1] = 3;
        tabuleiro[x + 2][y + 2] = 3;
        break;

    case 25:
        tabuleiro[x][y] = 3;
        tabuleiro[x + 1][y] = 3;
        tabuleiro[x + 2][y] = 3;
    break;

    case 26:
        tabuleiro[x][y + 1] = 3;
        tabuleiro[x + 1][y + 1] = 3;
        tabuleiro[x + 2][y + 1] = 3;
    break;

    case 27:
        tabuleiro[x][y + 2] = 3;
        tabuleiro[x + 1][y + 2] = 3;
        tabuleiro[x + 2][y + 2] = 3;
    break;

    case 28:
        tabuleiro[x][y] = 4;
        tabuleiro[x][y + 1] = 4;
        tabuleiro[x + 1][y] = 4;
        tabuleiro[x + 1][y + 1] = 4;
    break;

    case 29:
        tabuleiro[x][y + 1] = 4;
        tabuleiro[x][y + 2] = 4;
        tabuleiro[x + 1][y + 1] = 4;
        tabuleiro[x + 1][y + 2] = 4;
    break;

    case 30:
        tabuleiro[x + 1][y] = 4;
        tabuleiro[x + 1][y + 1] = 4;
        tabuleiro[x + 2][y] = 4;
        tabuleiro[x + 2][y + 1] = 4;
    break;

    case 31:
        tabuleiro[x + 1][y + 1] = 4;
        tabuleiro[x + 1][y + 2] = 4;
        tabuleiro[x + 2][y + 1] = 4;
        tabuleiro[x + 2][y + 2] = 4;
    break;

    case 32:
        tabuleiro[x][y] = 5;
        tabuleiro[x][y + 1] = 5;
        tabuleiro[x][y + 2] = 5;
        tabuleiro[x + 1][y + 1] = 5;
        tabuleiro[x + 2][y + 1] = 5;
    break;

    case 33:
        tabuleiro[x][y] = 5;
        tabuleiro[x + 1][y] = 5;
        tabuleiro[x + 2][y] = 5;
        tabuleiro[x + 1][y + 1] = 5;
        tabuleiro[x + 1][y + 2] = 5;
    break;

    case 34:
        tabuleiro[x][y + 1] = 5;
        tabuleiro[x + 1][y + 1] = 5;
        tabuleiro[x + 2][y] = 5;
        tabuleiro[x + 2][y + 1] = 5;
        tabuleiro[x + 2][y + 2] = 5;
    break;

    case 35:
        tabuleiro[x + 1][y] = 5;
        tabuleiro[x + 1][y + 1] = 5;
        tabuleiro[x][y + 2] = 5;
        tabuleiro[x + 1][y + 2] = 5;
        tabuleiro[x + 2][y + 2] = 5;
    break;

    case 36:
        tabuleiro[x][y + 1] = 6;
        tabuleiro[x + 1][y] = 6;
        tabuleiro[x + 1][y + 2] = 6;
        tabuleiro[x + 2][y] = 6;
        tabuleiro[x + 2][y + 1] = 6;
        tabuleiro[x + 2][y + 2] = 6;
    break;

    case 37:
        tabuleiro[x + 1][y] = 6;
        tabuleiro[x][y + 1] = 6;
        tabuleiro[x][y + 2] = 6;
        tabuleiro[x + 1][y + 2] = 6;
        tabuleiro[x + 2][y + 2] = 6;
        tabuleiro[x + 2][y + 1] = 6;
    break;

    case 38:
        tabuleiro[x + 2][y + 1] = 6;
        tabuleiro[x + 1][y] = 6;
        tabuleiro[x][y] = 6;
        tabuleiro[x][y + 1] = 6;
        tabuleiro[x][y + 2] = 6;
        tabuleiro[x + 1][y + 2] = 6;
    break;

    case 39:
        tabuleiro[x + 1][y + 2] = 6;
        tabuleiro[x + 2][y + 1] = 6;
        tabuleiro[x + 2][y] = 6;
        tabuleiro[x + 1][y] = 6;
        tabuleiro[x][y] = 6;
        tabuleiro[x][y + 1] = 6;
    break;

    case 40:
        tabuleiro[x][y] = 7;
        tabuleiro[x + 1][y] = 7;
        tabuleiro[x + 2][y] = 7;
        tabuleiro[x + 1][y + 1] = 7;
        tabuleiro[x][y + 2] = 7;
        tabuleiro[x + 1][y + 2] = 7;
        tabuleiro[x + 2][y + 2] = 7;
    break;   

    case 41:
       tabuleiro[x][y] = 7;
       tabuleiro[x][y + 1] = 7;
       tabuleiro[x][y + 2] = 7;
       tabuleiro[x + 1][y + 1] = 7;
       tabuleiro[x + 2][y] = 7;
       tabuleiro[x + 2][y + 1] = 7;
       tabuleiro[x + 2][y + 2] = 7;
    break;   

    case 42:
       tabuleiro[x][y] = 8;
       tabuleiro[x][y + 1] = 8;
       tabuleiro[x][y + 2] = 8;
       tabuleiro[x + 1][y] = 8;
       tabuleiro[x + 2][y] = 8;
       tabuleiro[x + 2][y + 1] = 8;
       tabuleiro[x + 2][y + 2] = 8;
       tabuleiro[x + 1][y + 2] = 8;
    break; 

    default:
        break;
    }
}