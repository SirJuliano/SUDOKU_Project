#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


#include "Grille.h"
#include "Resolution.h"
#include "Notes.h"

//fonction qui vérifie si la valeur val est déjà apparue dans la ligne/case/colonne
bool verifCase(bool *res, int val)
{
    if (res[val - 1] != 0)       // res est un tableau de booléens avec true pour la case(x-1) si la valeur x est déjà présente
    {
        return false;
    }
    else                        // si elle ne l'est pas, on la note comme présente
    {
        res[val - 1] = 1;
    }
    return true;
}

//fonction qui vérifie si la colonne/case/ligne ne posède pas plusieurs chiffre identiques
bool gridVerif(T_grid grid, int X1, int X2, int Y1, int Y2)
{
    bool res[(X2 - X1 + 1) * (Y2 - Y1 + 1)];        //tableau de booléens initialisé a 0 avec autant de cases que de nombres à tester
                                                    //pour les chiffres de 1 à 9, il y aura 9 cases
    for(int X = X1; X < X2 ; X++)
    {
        for(int Y = Y1; Y < Y2; Y++)
        {
            if(getVal(grid, X, Y)!=0)
            {
                if (verifCase(res, getVal(grid, X, Y)))
                {
                    return false;
                }
            }
        }
    }
    return true;
}

//fonction vérifiant la validité d'une ligne
bool verifLine(T_grid grid, int y, int length)
{
    return gridVerif(grid, 0, length, y, y);
}

//fonction vérifiant la validité d'une colonne
bool verifColumn(T_grid grid, int x, int length)
{
    return gridVerif(grid, x, x, 0, length);
}

//fonction vérifiant la validité d'un carré
bool verifSquare(T_grid grid, int x, int y, int length)
{
    int sizeSquare = sqrt(length);
    return gridVerif(grid, x, (x + sizeSquare), y, (y + sizeSquare));
}

//fonction vérifiant la validité de la grille complète
bool verifGrid(T_grid grid, int length)
{
    for(int i = 0; i < length; i++)
    {
        if(verifLine(grid, i, length) == false || verifColumn(grid, i, length) == false)
        {
            return false;
        }
    }
    int nbrSquarePerLine = sqrt(length);                //nombre de carré par ligne/colonne
    for (int j = 0; j < nbrSquarePerLine; j++)          //parcours des carrés de chaque lignes
    {
        for (int k = 0; k < nbrSquarePerLine; k++)      //parcours des carrés de chaque colonnes
        {
            if (verifSquare(grid, (j * nbrSquarePerLine), (k * nbrSquarePerLine), length) == false)     //on donne les coordonnées des cases situées en haut à gauche des carrés
            {
                return false;
            }
        }
    }
    return true;
}

/*
void completeArea(T_grid grid, int X1, int X2, int Y1, int Y2)  //regle 1
{
    int compteur = 0;
    int x = 0 ;
    int y = 0 ;
    int size = (X2 - X1 + 1) * (Y2 - Y1 + 1);
    bool tab[size];        //tableau de booléens initialisé a 0 avec autant de cases que de nombres à tester
    //pour les chiffres de 1 à 9, il y aura 9 cases
    for(int X = X1; X <= X2 ; X++)
    {
        for(int Y = Y1; Y <= Y2; Y++)
        {
            if(compteur > 1)
            {
                break;
            }
            if(getVal(grid, X, Y)!=0)
            {
                tab[getVal(grid, X, Y)-1] = 1;

            }
            else
            {

                compteur ++;
                x = X;
                y = Y;
            }

        }
    }
    if(compteur == 1){
        for(int i = 0; i<size; i++){
            if(tab[i] == 0){
                add_Value(grid,x, y, i+1);
            }
        }
    }
}
*/


void rule_1and3 (T_grid grid, int sizet)
{
    for (int i = 0; i < sizet; i++)
    {
        for (int j = 0; j < sizet; j++)
        {
            if (!caseVide(&grid[i][j]))
            {
                if (oneNoteLeft(&grid[i][j]))
                {
                    add_Value(grid, i, j, getvalNote(&grid[i][j]));
                }  
            }
        }
    }
}
for (int i = 0; i < sizet; i++)
    {
 
    int        for (int j = 0; j < sizet; j++)
        {
            if (!caseVide(&grid[i][j]))
            {
                if (oneNoteLeft(&grid[i][j]))
                {
                    add_Value(grid, i, j, getvalNote(&grid[i][j]));
                }  
            }
        }
    }