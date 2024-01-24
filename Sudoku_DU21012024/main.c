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
// TEST 2-uplet CACHES OU NUS
/*2 uplet nus (5,7) 1er bloc
  2 uplet caché (2,8) 2eme bloc*/
/*
    grille = add_Value(grille, 0, 0, 1);
    grille = add_Value(grille, 0, 3, 2);
    grille = add_Value(grille, 0, 4, 4);
    grille = add_Value(grille, 0, 5, 9);
    grille = add_Value(grille, 1, 1, 6);
    grille = add_Value(grille, 2, 1, 3);
    grille = add_Value(grille, 2, 2, 8);

    
    grille = add_Value(grille, 3, 8, 2);
    grille = add_Value(grille, 4, 8, 8);
    grille = add_Value(grille, 6, 7, 5);
    grille = add_Value(grille, 6, 8, 7);
    grille = add_Value(grille, 7, 7, 3);
    grille = add_Value(grille, 8, 4, 2);
    grille = add_Value(grille, 8, 5, 8);
    grille = add_Value(grille, 8, 6, 1);

    Show_grid(grille, LENGTH);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("\ncase [%d][%d]\n", i, j);
            printBinary2(grille[i][j]);
        }
    }
    for (int i = 6; i < 9; i++)
    {
        for (int j = 6; j < 9; j++)
        {
            printf("\ncase [%d][%d]\n", i, j);
            printBinary2(grille[i][j]);
        }
    }

    rules_610(grille);  //A MODIFIER

    Show_grid(grille,LENGTH);

    verifGrid(grille, LENGTH);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("\ncase [%d][%d]\n", i, j);
            printBinary2(grille[i][j]);
        }
    }
    for (int i = 6; i < 9; i++)
    {
        for (int j = 6; j < 9; j++)
        {
            printf("\ncase [%d][%d]\n", i, j);
            printBinary2(grille[i][j]);
        }
    }

    */
    



//TEST 3-uplets CACHES OU NUS
/* 3-uplet nus (5,7,9) premier bloc 
   3-uplet caché (2,8,9) dernier bloc
*/

/*
    grille = add_Value(grille, 0, 0, 1);
    grille = add_Value(grille, 0, 3, 2);
    grille = add_Value(grille, 0, 4, 4);
    grille = add_Value(grille, 1, 1, 6);
    grille = add_Value(grille, 1, 5, 5);
    grille = add_Value(grille, 2, 1, 3);
    grille = add_Value(grille, 2, 2, 8);
    grille = add_Value(grille, 3, 2, 2);
    grille = add_Value(grille, 4, 1, 7);
    grille = add_Value(grille, 4, 2, 4);


    grille = add_Value(grille, 3, 6, 9);
    grille = add_Value(grille, 4, 6, 8);
    grille = add_Value(grille, 5, 6, 2);
    grille = add_Value(grille, 6, 7, 5);
    grille = add_Value(grille, 6, 8, 7);
    grille = add_Value(grille, 7, 5, 2);
    grille = add_Value(grille, 7, 7, 3);
    grille = add_Value(grille, 8, 4, 8);
    grille = add_Value(grille, 8, 6, 1);

    Show_grid(grille, LENGTH);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("\ncase [%d][%d]\n", i, j);
            printBinary2(grille[i][j]);
        }
    }
    for (int i = 6; i < 9; i++)
    {
        for (int j = 6; j < 9; j++)
        {
            printf("\ncase [%d][%d]\n", i, j);
            printBinary2(grille[i][j]);
        }
    }

    rules_610(grille);//A MODIFIER

    Show_grid(grille,LENGTH);

    verifGrid(grille, LENGTH);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("\ncase [%d][%d]\n", i, j);
            printBinary2(grille[i][j]);
        }
    }
    for (int i = 6; i < 9; i++)
    {
        for (int j = 6; j < 9; j++)
        {
            printf("\ncase [%d][%d]\n", i, j);
            printBinary2(grille[i][j]);
        }
    }

*/

//TEST POUR FAIRE TOURNER CHAQUE REGLE INDIVIDUELLEMENT EN BOUCLE
/*

    grille = add_Value(grille, 0, 0, 8);
    grille = add_Value(grille, 0, 1, 4);
    grille = add_Value(grille, 0, 3, 2);
    grille = add_Value(grille, 0, 6, 5);
    grille = add_Value(grille, 0, 7, 9);
    grille = add_Value(grille, 0, 8, 7);
    grille = add_Value(grille, 1, 0, 5);
    grille = add_Value(grille, 1, 1, 6);
    grille = add_Value(grille, 1, 2, 9);
    grille = add_Value(grille, 1, 4, 3);
    grille = add_Value(grille, 1, 8, 1);
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
    grille = add_Value(grille, 7, 0, 6);
    grille = add_Value(grille, 7, 4, 2);
    grille = add_Value(grille, 7, 6, 1);
    grille = add_Value(grille, 7, 7, 7);
    grille = add_Value(grille, 7, 8, 3);
    grille = add_Value(grille, 8, 0, 1);
    grille = add_Value(grille, 8, 1, 7);
    grille = add_Value(grille, 8, 2, 4);
    grille = add_Value(grille, 8, 5, 6);
    grille = add_Value(grille, 8, 7, 2);
    grille = add_Value(grille, 8, 8, 8);


    Show_grid(grille, LENGTH);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("\ncase [%d][%d]\n", i, j);
            printBinary2(grille[i][j]);
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("\ncase [%d][%d]\n", i, j);
            printBinary2(grille[i][j]);
        }
    }
    bool theend = true;
    while (theend)
    {
        if (!rules_610(grille)) ;//A MODIFIER POUR CHAQUE REGLE A FAIRE TOURNER EN BOUCLE
        {
            theend = false;
        }
    }
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
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("\ncase [%d][%d]\n", i, j);
            printBinary2(grille[i][j]);
        }
    }

*/

//TEST LES 6 REGLES TOURNENT EN BOUCLE
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


    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("\ncase [%d][%d]\n", i, j);
            printBinary2(grille[i][j]);
        }
    }

    run_rules(grille, LENGTH);   //VERIFIER QU'ON A BIEN REMIS LES FONCTIONS EN ETAT

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
