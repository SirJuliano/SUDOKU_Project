#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "Grille.h"
#include "Resolution.h"

#define LENGTH 9
#define NBSQRT sqrt(LENGTH)

int main()
{


    T_grid grille = createGrid(LENGTH);
    initGrid(grille, LENGTH);

    grille = add_Value(grille, 0, 0, 2);
    grille = add_Value(grille, 3, 1 ,4);
    //grille = add_Value(grille, 7, 1 ,4);
    grille = add_Value(grille, 7, 2, 6);
    grille = add_Value(grille, 6, 8, 1);
    grille = add_Value(grille, 5, 3, 9);
    grille = add_Value(grille, 1, 4, 3);
    grille = add_Value(grille, 5, 7, 8);


    /*Show_grid(grille,LENGTH);

    grille = deleteAvalue(grille, 3, 1);
    grille = deleteAvalue(grille,5,3);

    printf("\n\n\n\n");*/

    Show_grid(grille,LENGTH);

    if (verifGrid(grille, LENGTH))
    {
        printf("Tout est bon\n");
    }
    else
    {
        printf("Rien ne va\n");
    }


    freeGrid(grille,LENGTH);




    return 0;
}
