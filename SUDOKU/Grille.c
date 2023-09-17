#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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
int nbrOfSquare(int length, int height) //nombre de carrés (9 par default)
{
    int lSquare = length/sqrt(length);
    int hSquare = height/sqrt(height);
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
    gridF = (T_gridF)malloc(sizeof(int*) * lenght);
    for (int i=0; i<lenght; i++)
    {
        gridF[i] = (int*)malloc(sizeof(int) * height);
    }
    return gridF;  //tab2d representant la grille
}


void initGrid(T_gridF grid,int lenght, int height) //initialise toutes les cases de la grille à 0
{
    for (int i=0; i<lenght; i++)
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

void Show_grid_final (T_gridF gridF, int sizel) // affiche la grille
{
    int sizeSquare = sqrt(nbrOfSquare(sizel, sizel));
    int nbrCharPerLine = 4 * sizel + 2 + sizel / sizeSquare; //chaque case contient 2 espaces, un chiffre et un "|", il y a un "|" au debut et a la fin et un "|" entre chaque carré
    for (int lin = 0; lin < sizel; lin++)
    {
        if (lin % sizeSquare == 0)
        {
            for (int n = 0; n < nbrCharPerLine; n++)
            {
                printf("=");
            }
            printf("\n||");
            for (int col = 0; col < sizel; col++)
            {
                if (col % sizeSquare == sizeSquare - 1)
                {
                    if (gridF[lin][col] != 0)
                    {
                        printf(" %d ||",(gridF[lin][col]));
                    }
                    else
                    {
                        printf("   ||");
                    }
                }
                else
                {
                    if (gridF[lin][col] != 0)
                    {
                        printf(" %d |",(gridF[lin][col]));
                    }
                    else
                    {
                        printf("   |");
                    }
                }
            }
            printf("\n");
        }
        else
        {
            for (int n = 0; n < nbrCharPerLine; n++)
            {
                printf("-");
            }
            printf("\n||");
            for (int col = 0; col < sizel; col++)
            {
                if (col % sizeSquare == sizeSquare - 1)
                {
                    if (gridF[lin][col] != 0)
                    {
                        printf(" %d ||",(gridF[lin][col]));
                    }
                    else
                    {
                        printf("   ||");
                    }
                }
                else
                {
                    if (gridF[lin][col] != 0)
                    {
                        printf(" %d |",(gridF[lin][col]));
                    }
                    else
                    {
                        printf("   |");
                    }
                }
            }
            printf("\n");
        }
    }
    for (int n = 0; n < nbrCharPerLine; n++)
    {
        printf("=");
    }
    printf("\n");
}

void freeGrid(T_gridF grid, int sizel)
{
    for (int i=0; i<sizel; i++)
    {
        free(grid[i]);
    }
    free(grid);
}




