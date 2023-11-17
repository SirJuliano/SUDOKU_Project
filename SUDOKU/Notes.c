#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "Grille.h"
/*
Le set note 0 ne fonctionne pas
Maintenant il fonctionne mais mal, il faudra voir ou ça foire, montrer aux autres avec exemple
*/


/*void initNote(T_grid grid, int length)
{
    for(int x = 0; x<length; x++)
    {
        for(int y = 0; y<length; y++)
        {
            grid[x][y].notes=511;
        }
    }
}
*/
void setNote1(Box *cell, int numNote)
{
    int mask = 1 << (numNote-1);
    cell->notes = cell->notes | mask;
}

void setNote1_v2(int *num, int numNote)
{
    int mask = 1 << (numNote-1);
    *num = *num | mask;
}

void setNote0(Box *cell, int numNote)
{
    int mask = 1 << (numNote-1);
    cell->notes = cell->notes & ~mask ;
}
void setNote0_v2(int *cell, int numNote) {
    int mask = 1 << (numNote - 1);
    *cell = *cell & ~mask;
}


void setNote0Line(T_grid grid, int x, int y, int length, int numNote)
{
    for(int i = 0; i<length; i++)
    {
        if(i != x)
        {
            setNote0(&grid[i][y], numNote);
        }
    }
}

void setNote0Column(T_grid grid, int x, int y, int length, int numNote)
{
    for(int i = 0; i<length; i++)
    {
        if(i != y)
        {
            setNote0(&grid[x][i], numNote);
        }
    }
}

void setNote0Square(T_grid grid, int x, int y, int length, int numNote)
{
    int nbr = sqrt(length);                //nombre de carré par ligne/colonne
    int xs = (x / nbr) * nbr;
    int ys = (y / nbr) * nbr;
    for(int X = xs; X < xs + 3; X++)
    {
        for(int Y = ys; Y < ys + 3; Y++)
        {
            if(x != X || y != Y)
            {
                setNote0(&grid[X][Y], numNote);
                printf("je modifie la case %d,%d en enlevant la valeur : %d \n", X,Y,numNote);
            }
        }
    }
}

void setVal(T_grid grid, int x, int y,int length, int numNote)
{
    setNote0Line(grid, x, y, length, numNote);
    setNote0Column(grid, x,y, length, numNote);
    setNote0Square(grid, x,y, length, numNote);

}

int getNote(Box *cell, int numNote) {
    int mask = 1 << (numNote - 1);
    return (cell->notes & mask) != 0;
}

void printBinary2(Box cell) {
    printf("Jai fait mon atf \n");
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        printf("%d", (cell.notes & (1 << i)) ? 1 : 0);
    }
}

void printBinary(int num) {
    printf("Jai fait mon atf \n");
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        printf("%d", (num & (1 << i)) ? 1 : 0);
    }
}

int getvalNote(Box *cell){
    switch (cell->notes) {
        case 0x1: return 1;
        case 0x2: return 2;
        case 0x4: return 3;
        case 0x8: return 4;
        case 0x10: return 5;
        case 0x20 : return 6;
        case 0x40 : return 7;
        case 0x80 : return 8;
        case 0x100 : return 9;/*
        case 0x : return 10;
        case 0x : return 11;
        case 0x : return 12;
        case 0x : return 13;
        case 0x : return 14;
        case 0x : return 15;
        case 0x : return 16;
        case 0x : return 17;
        case 0x : return 18;
        case 0x : return 19;
        case 0x : return 20;
        case 0x : return 21;
        case 0x : return 22;
        case 0x : return 23;
        case 0x : return 24;
        case 0x : return 25;
        case 0x : return 26;
        case 0x : return 27;
        case 0x : return 28;
        case 0x : return 29;
        case 0x : return 30;
        case 0x : return 31;
        case 0x : return 32;*/
        
    }
}