#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "Grille.h"

int main()
{


    // T_box box;
    // initListe(&box);
    // box = fillList(box, 9);
    // showList(box);

    T_gridF grille = finalGrid(25,25);
    initGrid(grille, 25, 25);
    grille = add_Value(grille, 0, 0, 2);
    grille = add_Value(grille, 3, 1 ,4);
    grille = add_Value(grille, 7, 2, 6);
    grille = add_Value(grille, 6, 8, 1);
    grille = add_Value(grille, 5, 3, 9);
    grille = add_Value(grille, 1, 4, 3);
    grille = add_Value(grille, 5, 7, 8);


    /*for (int i = 0;i <9;i++)
    {
        for (int j = 0;j<9;j++)
        {
            printf("tab[%d][%d]= %d \n",i,j,grille[i][j]);
        }
    }*/


    Show_grid_final(grille,25);
/*
    grille = deleteAvalue(grille, 3, 1);
    grille = deleteAvalue(grille,5,3);

    printf("\n\n\n\n");

    Show_grid_final(grille,15);
*/


    freeGrid(grille,25);




    return 0;
}
