#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Liste_simple.h"
#include "Grille.h"

int main()
{


    // T_box box;
    // initListe(&box);
    // box = fillList(box, 9);
    // showList(box);

    T_gridF grille = finalGrid(9,9);
    grille = initGrid(grille, 9,9);
    grille = add_Value(grille, 0, 0, 2);
    grille = add_Value(grille, 3,1 ,4 );
    grille = add_Value(grille, 7, 2, 6);
    grille = add_Value(grille, 6, 8, 1);
    grille = add_Value(grille, 5, 3, 9);
    grille = add_Value(grille, 1, 4, 3);
    grille = add_Value(grille, 5, 7, 8);


    Show_grid_final(grille,9);

    grille = deleteAvalue(grille, 3, 1);
    grille = deleteAvalue(grille,5,3);

    Show_grid_final(grille, 9);



    
    return 0;
}