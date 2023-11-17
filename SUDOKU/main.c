#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "Grille.h"
#include "Resolution.h"
#include "Notes.h"

#define LENGTH 9
#define NBSQRT sqrt(LENGTH)

int main()
{


    T_grid grille = createGrid(LENGTH);
    initGrid(grille, LENGTH);

    grille = add_Value(grille, 0, 0, 1);
    grille = add_Value(grille, 0, 1, 2);
    grille = add_Value(grille, 0, 2, 3);
    grille = add_Value(grille, 1, 0, 4);
    grille = add_Value(grille, 1, 1, 5);
    grille = add_Value(grille, 1, 2, 6);
    grille = add_Value(grille, 2, 0, 7);
    grille = add_Value(grille, 2, 1, 8);

    grille = add_Value(grille, 3, 1 ,4);
    grille = add_Value(grille, 7, 2, 6);
    grille = add_Value(grille, 6, 8, 1);
    grille = add_Value(grille, 5, 3, 9);
    grille = add_Value(grille, 1, 4, 3);
    grille = add_Value(grille, 5, 7, 8);




    Show_grid(grille,LENGTH);

    printBinary2(grille[2][2]);
    /*int a = 0;
    setNote1_v2(&a, 4);
    setNote1_v2(&a, 6);
    printBinary(a);
    setNote0_v2(&a, 4);
    printBinary(a);
    setNote0_v2(&a, 4);
    printBinary(a);
*/
//    printBinary(a);
    //grille = deleteAvalue(grille, 3, 1);
    //grille = deleteAvalue(grille,5,3);

    printf("\n\n\n\n");

    completeArea(grille, 0, 2, 0, 2);

    Show_grid(grille,LENGTH);



    freeGrid(grille,LENGTH);




    return 0;
}
