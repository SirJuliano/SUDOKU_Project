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
    if (res[val - 1])       // res est un tableau de booléens avec true pour la case(x-1) si la valeur x est déjà présente
    {
        return false;
    }
    else                        // si elle ne l'est pas, on la note comme présente
    {
        res[val - 1] = true;
    }
    return true;
}

//fonction qui vérifie si la colonne/case/ligne ne posède pas plusieurs chiffre identiques
bool gridVerif(T_grid grid, int X1, int X2, int Y1, int Y2, int lenght)
{
    bool res[(X2 - X1+1) * (Y2 - Y1)+1];
    for (int i = 0; i < lenght; i++)
                res[i] = false;
    //tableau de booléens initialisé a 0 avec autant de cases que de nombres à tester
    //pour les chiffres de 1 à 9, il y aura 9 cases
    for(int X = X1; X < X2 ; X++)
    {
        for(int Y = Y1; Y < Y2; Y++)
        {
            if(getVal(grid, X, Y)!=0)
            {
                if (!verifCase(res, getVal(grid, X, Y)))
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
    return gridVerif(grid, 0, length, y, y, length);
}

//fonction vérifiant la validité d'une colonne
bool verifColumn(T_grid grid, int x, int length)
{
    return gridVerif(grid, x, x, 0, length, length);
}

//fonction vérifiant la validité d'un carré
bool verifSquare(T_grid grid, int x, int y, int length)
{
    int sizeSquare = sqrt(length);
    return gridVerif(grid, x, (x + sizeSquare-1), y, (y + sizeSquare-1), length);
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
    printf("La grille est bonne \n");
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

bool found_rule_1and3 = true;

void rule_1and3 (T_grid grid, int sizet)
{
    bool found = false;
    int i = 0;
    for (int x = 0; x < sizet; x++)
    {
        for (int y = 0; y < sizet; y++)
        {

            if (caseVide(&grid[x][y]))
            {
                i++;
                if (oneNoteLeft(grid[x][y].notes))
                {
                    grid = add_Value(grid, x, y, getvalNote(grid[x][y].notes));
                    found = true;
                }
            }
        }
    }
    found_rule_1and3 = found;
}

bool found_rule_2 = true;

void rule_2 (T_grid grid, int sizet)
{
    bool found = false;
    for (int x = 0; x < sizet; x++)
    {
        for (int y = 0; y < sizet; y++)
        {
            if (caseVide(&grid[x][y]))
            {
                int tmp = grid[x][y].notes;
                if (rule_2_line(grid, sizet, x, y, tmp))
                    found = true;
                else
                {
                    tmp = grid[x][y].notes;
                    if (rule_2_column(grid, sizet, x, y, tmp))
                        found = true;
                    else
                    {
                        tmp = grid[x][y].notes;
                        if (rule_2_square(grid, sizet, x, y, tmp))
                            found = true;

                    }
                }
            }
        }
    }
    found_rule_2 = found;
    if (found)
        found_rule_1and3 = found;
}

bool rule_2_line(T_grid grid, int sizet, int X, int Y, int tmp)
{
    for (int y = 0; y < sizet; y++)
    {
        if ((caseVide(&grid[X][y])) && (y != Y))
        {
            tmp = tmp & ~(grid[X][y].notes);
        }
    }
    bool found = false;
    if (oneNoteLeft(tmp))
    {
        grid = add_Value(grid, X, Y, getvalNote(tmp));
        found = true;
    }
    return found;
}

bool rule_2_column (T_grid grid, int sizet, int X, int Y, int tmp)
{
    for (int x = 0; x < sizet; x++)
    {
        if ((caseVide(&grid[x][Y])) && (x != X))
        {
            tmp = tmp & ~(grid[x][Y].notes);
        }
    }
    bool found = false;
    if (oneNoteLeft(tmp))
    {
        grid = add_Value(grid, X, Y, getvalNote(tmp));
        found = true;
    }
    return found;
}

bool rule_2_square(T_grid grid, int sizet, int X, int Y, int tmp)
{
    int nbr = sqrt(sizet);                //nombre de carré par ligne/colonne
    int xs = (X / nbr) * nbr;
    int ys = (Y / nbr) * nbr;
    for (int x = xs; x < xs + nbr; x++)
    {
        for (int y = ys; y < ys + nbr; y++)
        {
            if ((caseVide(&grid[x][Y])) && (x != X) && (y != Y))
            {
                tmp = tmp & ~(grid[X][y].notes);
            }
        }

    }
    bool found = false;
    if (oneNoteLeft(tmp))
    {
        grid = add_Value(grid, X, Y, getvalNote(tmp));
        found = true;
    }
    return found;
}

void run_rules (T_grid grid, int sizet)
{
    while (!(!found_rule_1and3 && !found_rule_2))
    {
        found_rule_1and3 = true;
        found_rule_2 = true;
        while (found_rule_1and3)
        {
            rule_1and3(grid, sizet);
        }
        while (found_rule_2)
        {
            rule_2(grid, sizet);
        }
    }
}

