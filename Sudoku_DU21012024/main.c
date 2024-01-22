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
    grille = add_Value(grille, 0, 0, 7);
    grille = add_Value(grille, 0, 2, 9);
    grille = add_Value(grille, 0, 5, 1);
    grille = add_Value(grille, 0, 8, 5);
    grille = add_Value(grille, 1, 7, 9);
    grille = add_Value(grille, 2, 4, 2);
    grille = add_Value(grille, 2, 5, 8);
    grille = add_Value(grille, 2, 8, 7);
    grille = add_Value(grille, 3, 2, 1);
    grille = add_Value(grille, 3, 6, 6);
    grille = add_Value(grille, 3, 8, 4);
    grille = add_Value(grille, 4, 5, 6);
    grille = add_Value(grille, 4, 7, 5);
    grille = add_Value(grille, 5, 0, 8);
    grille = add_Value(grille, 5, 5, 5);
    grille = add_Value(grille, 5, 6, 2);
    grille = add_Value(grille, 6, 0, 1);
    grille = add_Value(grille, 6, 2, 4);
    grille = add_Value(grille, 6, 3, 5);
    grille = add_Value(grille, 7, 2, 8);
    grille = add_Value(grille, 7, 3, 4);
    grille = add_Value(grille, 7, 8, 2);
    grille = add_Value(grille, 8, 0, 5);
    grille = add_Value(grille, 8, 1, 7);
    grille = add_Value(grille, 8, 4, 3);
*/


//TEST 2
/*
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
*/

//TEST 3    Test 2_uplet avec 2 et 3
/*
    grille = add_Value(grille, 0, 0, 1);
    grille = add_Value(grille, 0, 1, 4);
    grille = add_Value(grille, 1, 1, 8);
    grille = add_Value(grille, 2, 0, 7);
    grille = add_Value(grille, 4, 0, 5);
    grille = add_Value(grille, 5, 0, 6);
    grille = add_Value(grille, 8, 0, 9);
    grille = add_Value(grille, 1, 4, 5);
    grille = add_Value(grille, 1, 5, 6);
    grille = add_Value(grille, 1, 8, 9);
*/
//TEST 4 Test 3 uplet 1 5 8
/*
    grille = add_Value(grille, 0, 0, 3);
    grille = add_Value(grille, 0, 1, 7);
    grille = add_Value(grille, 0, 7, 9);
    grille = add_Value(grille, 1, 0, 9);
    grille = add_Value(grille, 1, 4, 7);
    grille = add_Value(grille, 2, 3, 4);
    grille = add_Value(grille, 2, 4, 2);
    grille = add_Value(grille, 2, 8, 6);
    grille = add_Value(grille, 3, 2, 1);
    grille = add_Value(grille, 3, 4, 8);
    grille = add_Value(grille, 3, 5, 4);
    grille = add_Value(grille, 3, 6, 2);
    grille = add_Value(grille, 5, 0, 8);
    grille = add_Value(grille, 5, 3, 6);
    grille = add_Value(grille, 5, 7, 5);
    grille = add_Value(grille, 6, 2, 6);
    grille = add_Value(grille, 6, 5, 2);
    grille = add_Value(grille, 6, 7, 1);
    grille = add_Value(grille, 7, 7, 3);
    grille = add_Value(grille, 7, 8, 9);
    grille = add_Value(grille, 8, 1, 5);
    grille = add_Value(grille, 8, 6, 4);
*/

/*    grille = add_Value(grille, 0, 2, 4);
    grille = add_Value(grille, 0, 8, 2);
    grille = add_Value(grille, 1, 1, 6);
    grille = add_Value(grille, 1, 2, 2);
    grille = add_Value(grille, 1, 7, 4);
    grille = add_Value(grille, 2, 5, 9);
    grille = add_Value(grille, 2, 6, 3);
    grille = add_Value(grille, 2, 7, 7);
    grille = add_Value(grille, 3, 7, 6);
    grille = add_Value(grille, 4, 0, 6);
    grille = add_Value(grille, 4, 1, 4);
    grille = add_Value(grille, 4, 3, 2);
    grille = add_Value(grille, 4, 7, 8);
    grille = add_Value(grille, 5, 1, 2);
    grille = add_Value(grille, 5, 8, 4);
    grille = add_Value(grille, 6, 0, 4);
    grille = add_Value(grille, 7, 0, 2);
    grille = add_Value(grille, 7, 4, 4);
    grille = add_Value(grille, 7, 6, 6);
    grille = add_Value(grille, 8, 7, 2);
*/

//TEST 5 RIIIEN
    //grille = add_Value(grille, 0, 0, 1);

//TEST 6 3UPLET 567 EXEMPLE PROF
/*
    grille = add_Value(grille, 0, 2, 8);
    grille = add_Value(grille, 0, 5, 7);
    grille = add_Value(grille, 1, 1, 4);
    grille = add_Value(grille, 1, 2, 2);
    grille = add_Value(grille, 1, 5, 5);
    grille = add_Value(grille, 3, 2, 3);
    grille = add_Value(grille, 3, 5, 6);
    grille = add_Value(grille, 3, 6, 8);
    grille = add_Value(grille, 3, 8, 1);
    grille = add_Value(grille, 4, 8, 6);
    grille = add_Value(grille, 5, 0, 9);
    grille = add_Value(grille, 6, 1, 8);
    grille = add_Value(grille, 6, 3, 1);
    grille = add_Value(grille, 6, 4, 3);
    grille = add_Value(grille, 6, 6, 4);
    grille = add_Value(grille, 6, 7, 7);
    grille = add_Value(grille, 7, 4, 9);
    grille = add_Value(grille, 8, 1, 1);
*/

//TEST 8 RANDOM
    grille = add_Value(grille, 0, 0, 8);
    grille = add_Value(grille, 0, 1, 4);
    grille = add_Value(grille, 0, 6, 5);
    grille = add_Value(grille, 0, 7, 9);
    grille = add_Value(grille, 0, 8, 7);
    grille = add_Value(grille, 1, 0, 5);
    grille = add_Value(grille, 1, 1, 6);
    grille = add_Value(grille, 1, 4, 3);
    grille = add_Value(grille, 2, 2, 7);
    grille = add_Value(grille, 2, 5, 5);
    grille = add_Value(grille, 3, 2, 2);
    grille = add_Value(grille, 3, 3, 6);
    grille = add_Value(grille, 3, 6, 8);
    grille = add_Value(grille, 3, 8, 9);
    grille = add_Value(grille, 4, 4, 8);
    grille = add_Value(grille, 5, 0, 9);
    grille = add_Value(grille, 5, 2, 1);
    grille = add_Value(grille, 5, 5, 2);
    grille = add_Value(grille, 5, 6, 4);
    grille = add_Value(grille, 6, 3, 9);
    grille = add_Value(grille, 6, 6, 6);
    grille = add_Value(grille, 7, 4, 2);
    grille = add_Value(grille, 7, 6, 1);
    grille = add_Value(grille, 7, 7, 7);
    grille = add_Value(grille, 8, 0, 1);
    grille = add_Value(grille, 8, 1, 7);
    grille = add_Value(grille, 8, 2, 4);
    grille = add_Value(grille, 8, 7, 2);
    grille = add_Value(grille, 8, 8, 8);

    Show_grid(grille, LENGTH);


    for (int i = 6; i < 9; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("\ncase [%d][%d]\n", i, j);
            printBinary2(grille[i][j]);
        }
    }
    run_rules(grille, LENGTH);
    //rules_67(grille);
    //int kuplet[] = {1,7,8};
    //rules_67_zone (grille, 6, 0, 8, 3, 3, kuplet);

    Show_grid(grille,LENGTH);

    verifGrid(grille, LENGTH);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("\ncase [%d][%d]\n", i, j);
            printBinary2(grille[i][j]);
        }
    }


    freeGrid(grille,LENGTH);




    return 0;
}
