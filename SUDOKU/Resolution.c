#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Liste_simple.h"
#include "Grille.h"
#include "Resolution.h"

//verifie que la colonne est valide
bool validColumn(T_gridF grid, int posLength)
{
    for(int i=0; i<LENGTH; i++)
    {
        if(grid[i][posLength]!=0)
        {
            for (int j=i+1; j<LENGTH; j++)
            {
                if(grid[i][posLength]==grid[j][posLength])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

//verifie que la ligne est valide
bool validLine(T_gridF grid, int posHeight)
{
    for (int i = 0; i<HEIGHT;i++)
    {
        if (grid[posHeight][i]!=0)
        {
            for (int j = i+1; j<HEIGHT; j++)
            {
                if (grid[posHeight][i] == grid[posHeight][j])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

//verifie que le carre de 3*3 est valide
bool validSquare(T_gridF grid, int square)
{
    int Lstart = square / 3 * 3;
    int Hstart = square % 3 * 3;
    for (int len = Lstart; len < Lstart + 3; len++)
    {
        for (int hei = Hstart; hei < Hstart + 3; hei++)
        {
            if (grid[len][hei] != 0)
            {
                for (int lCur = len ; lCur < Lstart + 3; lCur++)
                {
                    for (int hCur = hei; hCur < Hstart + 3; hCur++)
                    {
                        if 
                    }
                }
            }
            
        }
    }
}


// bool validGrid(T_gridF grid)
// {
//     for(int i=0; i)
// }