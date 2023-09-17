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
    int Lstart = square % 3 * 3;     //square représente le numéro du carré
    int Hstart = square / 3 * 3;    //coordonnée de la case en haut à gauche du carré
    for (int len = Lstart; len < Lstart + 3; len++)
    {
        for (int hei = Hstart; hei < Hstart + 3; hei++)     //parcours du carré
        {
            if (grid[len][hei] != 0)        //s'il y a une valeur dans la case
            {
                for (int lCur = Lstart ; lCur < Lstart + 3; lCur++)
                {
                    for (int hCur = Hstart; hCur < Hstart + 3; hCur++)     //parcours du carré
                    {
                        if (len != lCur && hei != hCur && grid[len][hei] == grid[lCur][hCur])       //si les cases ont la même valeur, le carré n'est pas valide
                            return false;
                    }
                }
            }
            
        }
    }
    return true;    //sinon, le carré est valide
}

bool validGrid(T_gridF grid)
{
    for(int i = 0; i < LENGTH; i++)
    {
        if(validColumn(grid, i)==false)
        {
            return false;
        }
    }
    for(int j=0; j < HEIGHT; j++)
    {
        if(validLine(grid, j) == false)
        {
            return false;
        }
    }
    int nbrSquare = nbrOfSquare(LENGTH, HEIGHT);
    for(int k=0; k < nbrSquare; k++)
    {
        if(validSquare(grid, k)==false)
        {
            return false;
        }
    }
    return true;    
}


// bool validGrid(T_gridF grid)
// {
//     for(int i=0; i)
// }