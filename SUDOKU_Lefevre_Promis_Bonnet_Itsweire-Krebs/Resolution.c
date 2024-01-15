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

//fonction qui vérifie si la colonne/case/ligne ne possède pas plusieurs chiffre identiques
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

//Variable permettant de savoir si la fonction "rule_1and3" à remplit au moins 1 case
bool found_rule_1and3 = true;


//Application des règles 1 et 3
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

//Variable indiquant si "rule_2" a remplit au moins une case
bool found_rule_2 = true;

//Application de la règle de résolution 2 
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


//Application de règle 2 spécifiquement à une ligne
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


//Application de la règle 2 spécifiquement à une colonne 
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


//Application de règle 2 spécifiquement à un bloc
bool rule_2_square(T_grid grid, int sizet, int X, int Y, int tmp)
{
    int xs = (X / NBSQRT) * NBSQRT;
    int ys = (Y / NBSQRT) * NBSQRT;
    for (int x = xs; x < xs + NBSQRT; x++)
    {
        for (int y = ys; y < ys + NBSQRT; y++)
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


//Lance la résolution avec les règles 1 à 3
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

bool* availableValues(T_grid grid, int X1, int Y1, int X2, int Y2)
{
    bool* tab[LENGTH];
    for(int i = 0; i<LENGTH;i++)
    {
        tab[i]=1;
    }
    for(int X = X1; X<X2; X++)
    {
        for(int Y = Y1; Y < Y2; Y++)
        {
            if(grid[X][Y].value != 0)
            {
                tab[grid[X][Y].value] = 0;
            }
        }
    }
    return tab;
}


void rules_67_zone (T_grid grid, int X1, int Y1, int X2, int Y2, int K, int * tab)
{
    int tmp = setNote1_tab(tab, K);
    int tmp_test = tmp;
    int x = X1;
    int y = Y1;
    int nbrCoord = 0;
    int note;
    int ** tCoord[K];
    while (x <= X2 && nbrCoord < K){
        while (y <= Y2 && nbrCoord < K){
            note = grid[x][y].notes;
            if (IsInTheTampon(tmp, note)){
                tmp_test = tmp_test ^ (tmp_test & note);
                tCoord[nbrCoord][0] = x;
                tCoord[nbrCoord][1] = y;
                nbrCoord++;
            }
            x++;
            y++;
        }
    }
    if (tmp_test == 0 && nbrCoord == K){
        setNoteRule6(grid, X1, Y1, X2, Y2, &tCoord, K, tmp);
    }
}


























// tab [possibilités restantes]
// tabk [k];
// while (k->3)
//     for i = 0 to lenght tab [possibilités restantes]
//         tabk[0] = tab[i]
//         tabk[1] = tab[i+1]
//         tabk[2] = tab[i+2]

//         echec je veux mtn tabk[i+2] = tab[i+3]

// index de mon uplet, k?, i la position  dans mon tableau 
// for oui de 2 à k 
//     tabk[k] = i1





// int kuplet[k];
// for (int i = 0; i < k; i++)
// {
//     kuplet[i] = i + 1;
// }
int* generateKtuples (int* array,int n, int k, int *current, int index, int bfor)
{
    if (index == k)
    {
        //Fonctiondeteo(current,k);
        printf("[%d,%d,%d]\n",current[0],current[1],current[2]);
        return;
    }

    for (int i = bfor ; i < n - index; i ++)
    {
        current[index] = array[i];
        generateKtuples(array[i],n,k,current,index+1, i+1);
    }
}













