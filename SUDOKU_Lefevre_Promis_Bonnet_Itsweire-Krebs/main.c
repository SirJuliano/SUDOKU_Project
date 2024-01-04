#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "Grille.h"
#include "Resolution.h"
#include "Notes.h"

int main()
{
    T_grid grille = createGrid(LENGTH);
    initGrid(grille, LENGTH);
//TEST 1
/*
    grille = add_Value(grille, 0, 2, 5);
    grille = add_Value(grille, 0, 5, 4);
    grille = add_Value(grille, 1, 4, 2);
    grille = add_Value(grille, 1, 8, 4);
    grille = add_Value(grille, 2, 1, 7);
    grille = add_Value(grille, 2, 8, 8);
    grille = add_Value(grille, 3, 3, 6);
    grille = add_Value(grille, 3, 6, 3);
    grille = add_Value(grille, 4, 3, 2);
    grille = add_Value(grille, 4, 7, 4);
    grille = add_Value(grille, 5, 0, 7);
    grille = add_Value(grille, 5, 2, 4);
    grille = add_Value(grille, 6, 1, 8);
    grille = add_Value(grille, 6, 6, 1);
    grille = add_Value(grille, 7, 4, 5);
    grille = add_Value(grille, 7, 5, 3);
    grille = add_Value(grille, 8, 0, 9);
    grille = add_Value(grille, 8, 7, 2);
*/


//TEST 2

    grille = add_Value(grille, 0, 0, 7);
    grille = add_Value(grille, 0, 4, 5);
    grille = add_Value(grille, 0, 5, 1);
    grille = add_Value(grille, 1, 2, 2);
    grille = add_Value(grille, 1, 5, 9);
    grille = add_Value(grille, 1, 8, 8);
    grille = add_Value(grille, 2, 2, 4);
    grille = add_Value(grille, 2, 6, 1);
    grille = add_Value(grille, 2, 8, 6);
    grille = add_Value(grille, 3, 0, 1);
    grille = add_Value(grille, 3, 1, 8);
    grille = add_Value(grille, 3, 3, 3);
    grille = add_Value(grille, 3, 6, 6);
    grille = add_Value(grille, 3, 7, 2);
    grille = add_Value(grille, 4, 2, 3);
    grille = add_Value(grille, 4, 5, 5);
    grille = add_Value(grille, 4, 6, 9);
    grille = add_Value(grille, 4, 7, 4);
    grille = add_Value(grille, 4, 8, 7);
    grille = add_Value(grille, 5, 2, 5);
    grille = add_Value(grille, 5, 6, 3);
    grille = add_Value(grille, 6, 2, 7);
    grille = add_Value(grille, 6, 4, 1);
    grille = add_Value(grille, 6, 6, 8);
    grille = add_Value(grille, 6, 8, 4);
    grille = add_Value(grille, 7, 3, 9);
    grille = add_Value(grille, 7, 6, 7);
    grille = add_Value(grille, 8, 3, 6);
    grille = add_Value(grille, 8, 4, 7);
    grille = add_Value(grille, 8, 7, 3);
    grille = add_Value(grille, 8, 8, 9);



    Show_grid(grille, LENGTH);

    run_rules(grille, LENGTH);

    Show_grid(grille,LENGTH);

    verifGrid(grille, LENGTH);

    freeGrid(grille,LENGTH);




    return 0;
}
