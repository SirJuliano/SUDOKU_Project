#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "Grille.h"



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

// void setNote1_v2(int *num, int numNote)
// {
//     int mask = 1 << (numNote-1);
//     *num = *num | mask;
// }

void setNote0(Box *cell, int numNote){
    int mask = 1 << (numNote-1);
    cell->notes = cell->notes & ~mask ;  //notetmp = notetmp &~casedeuxvide
}
// void setNote0_v2(int *cell, int numNote) {
//     int mask = 1 << (numNote - 1);
//     *cell = *cell & ~mask;
// }


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
    setNote0Column(grid, x, y, length, numNote);
    setNote0Square(grid, x, y, length, numNote);

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

// void printBinary(int num) {
//     printf("Jai fait mon atf \n");
//     for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
//         printf("%d", (num & (1 << i)) ? 1 : 0);
//     }
// }

int getvalNote(int note){
    switch (note) {
        case 1: return 1;
        case 2: return 2;
        case 4: return 3;
        case 8: return 4;
        case 16: return 5;
        case 32 : return 6;
        case 64 : return 7;
        case 128 : return 8;
        case 256 : return 9;
        case 512 : return 10;
        case 1024 : return 11;
        case 2048 : return 12;
        case 4096 : return 13;
        case 8192 : return 14;
        case 16384 : return 15;
        case 32768 : return 16;
        case 65536 : return 17;
        case 131072 : return 18;
        case 262144 : return 19;
        case 524288 : return 20;
        case 1048576 : return 21;
        case 2097152 : return 22;
        case 4194304 : return 23;
        case 8388608 : return 24;
        case 16777216 : return 25;
        default : return -1;
        // case 33554432 : return 26;
        // case 67108864 : return 27;
        // case 134217728 : return 28;
        // case 268435456 : return 29;
        // case 536870912 : return 30;
        // case 1073741824 : return 31;
        // case 2147483648 : return 32;
        
    }
}

bool oneNoteLeft (int note)
{
    if (getvalNote(note == -1))
        return false;
    else
        return true;
}


