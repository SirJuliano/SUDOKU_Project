#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Liste_simple.h"
#include "Grille.h"
/*
T_grid createGrid(int lenght, int height)
{
    T_grid grid;
    grid = (T_box***)malloc(sizeof(T_box**)*lenght);
    for (int i=0; i<lenght; i++)
    {
        grid[i] = (T_box**)malloc(sizeof(T_box*)*height);
    }
    return grid;  //tab2D contenant des pointeurs
}
*/
int nbrOfSquare(int lenght, int height) //nombre de carrés (9 par default)
{
    int lSquare = lenght/3;
    int hSquare = height/3;
    return (lSquare * hSquare);
}

int inSquare(int poslenght, int posheight) //savoir a quel carré la case appartient
{
    int L = poslenght / 3;
    int H = posheight / 3 * 3;
    return (L + H);
}
/*
void fillGrid(T_grid grid, int lenght, int height)
{
    int area = areaOfSquare(lenght, height);
    for (int l = 0; l < lenght; l++)
    {
        for (int h = 0; h < height; h++)
        {
            T_box box;
            initListe(box);
            box = fillList(box, area);
            grid[l][h] = box;
        }
    }
}

void show_grid(T_grid grid, int size)
{
    for (int col = 0; col < size; col++)
    {
        for (int n = 0; n < (2 * size + 1); n++)
            printf("-");
        printf("\n|");
        for (int lin = 0; lin < size; lin++)
        {
            if (get_size(grid[col][lin]) == 1)
                printf("%d|",(grid[col][lin])->pdata);
            else
                printf(" |");
        }
        printf("\n");
    }
    for (int n = 0; n < (2 * size + 1); n++)
            printf("-");
}
*/
T_gridF finalGrid(int lenght, int height) //allocation de la memoire pour un tableau en deux dimensions
{
    T_gridF gridF;
    gridF = (int**)malloc(sizeof(int*) * lenght); 
    for (int i=0; i<lenght; i++)
    {
        gridF[i] = (int*)malloc(sizeof(int) * height); 
    }
    return gridF;  //tab2d representant la grille
}


T_gridF initGrid(T_gridF grid,int lenght, int height) //initialise toutes les cases de la grille à 0
{
    for (int i=0; i<lenght;i++)
    {
        for (int j=0; j<height; j++)
        {
            grid[i][j] = 0;
        }
    }
}


T_gridF add_Value(T_gridF gridF, int pos_line, int pos_column, int value) //ajoute une valeur dans la case souhaitee
{
    gridF[pos_line][pos_column] = value;
    return gridF;
}

T_gridF deleteAvalue (T_gridF gridF, int pos_line, int pos_column) //supprime la valeur de la case
{
    gridF[pos_line][pos_column] = 0;
    return gridF;
}

void Show_grid_final (T_gridF gridF, int size) // affiche la grille 
{
    for (int col = 0; col < size; col++)
    {
        for (int n = 0; n < (2 * size + 1); n++)
            printf("-");
        printf("\n|");
        for (int lin = 0; lin < size; lin++)
        {
            if (gridF[lin][col] != 0L)
                printf("%d|",(gridF[col][lin]));
            else
                printf(" |");
        }
        printf("\n");
    }
    for (int n = 0; n < (2 * size + 1); n++)
            printf("-");
}

