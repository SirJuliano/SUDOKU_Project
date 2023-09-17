#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Liste_simple.h"
#include "Grille.h"
/*
T_grid createGrid(int largeur, int hauteur)
{
    T_grid grid;
    grid = (T_box***)malloc(sizeof(T_box**)*largeur);
    for (int i=0; i<largeur; i++)
    {
        grid[i] = (T_box**)malloc(sizeof(T_box*)*hauteur);
    }
    return grid;  //tab2D contenant des pointeurs
}
*/
int areaOfSquare(int largeur, int hauteur)
{
    int lSquare = largeur/3;
    int hSquare = hauteur/3;
    return (lSquare * hSquare);
}

int inSquare(int posLargeur, int posHauteur)
{
    int L = posLargeur / 3;
    int H = posHauteur / 3;
    return (L * H);
}
/*
void fillGrid(T_grid grid, int largeur, int hauteur)
{
    int area = areaOfSquare(largeur, hauteur);
    for (int l = 0; l < largeur; l++)
    {
        for (int h = 0; h < hauteur; h++)
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
T_gridF finalGrid(int largeur, int hauteur)
{
    T_gridF gridF;
    gridF = (int**)malloc(sizeof(int*) * largeur);
    for (int i=0; i<largeur; i++)
    {
        gridF[i] = (int*)malloc(sizeof(int) * hauteur);
    }
    return gridF;  //tab2d representant la grille
}

T_gridF add_Value(T_gridF gridF, int pos_line, int pos_column, int value)
{
    gridF[pos_line][pos_column] = value;
    return gridF;
}

T_gridF deleteAvalue (T_gridF gridF, int pos_line, int pos_column)
{
    gridF[pos_line][pos_column] = NULL;
    return gridF;
}

void Show_grid_final (T_gridF gridF, int size)
{
    for (int col = 0; col < size; col++)
    {
        for (int n = 0; n < (2 * size + 1); n++)
            printf("-");
        printf("\n|");
        for (int lin = 0; lin < size; lin++)
        {
            if (gridF[lin][col] != NULL)
                printf("%d|",(gridF[col][lin]));
            else
                printf(" |");
        }
        printf("\n");
    }
    for (int n = 0; n < (2 * size + 1); n++)
            printf("-");
}

