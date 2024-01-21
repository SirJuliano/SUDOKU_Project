#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


#include "Grille.h"
#include "Resolution.h"
#include "Notes.h"

//fonction qui vérifie si la valeur val est déjà apparue dans la ligne/case/colonne
bool verifCase(bool *res, int val)
{
    if (res[val - 1])       // res est un tableau de booléens avec true pour la case(x-1) si la valeur x est déjà présente
    {
        return false;
    }
    else                        // si elle ne l'est pas, on la note comme présente
    {
        res[val - 1] = true;
    }
    return true;
}

//fonction qui vérifie si la colonne/case/ligne ne possède pas plusieurs chiffre identiques
bool gridVerif(T_grid grid, int X1, int X2, int Y1, int Y2, int lenght)
{
    bool res[(X2 - X1+1) * (Y2 - Y1)+1];
    for (int i = 0; i < lenght; i++)
                res[i] = false;
    //tableau de booléens initialisé a 0 avec autant de cases que de nombres à tester
    //pour les chiffres de 1 à 9, il y aura 9 cases
    for(int X = X1; X < X2 ; X++)
    {
        for(int Y = Y1; Y < Y2; Y++)
        {
            if(getVal(grid, X, Y)!=0)
            {
                if (!verifCase(res, getVal(grid, X, Y)))
                {
                    return false;
                }
            }
        }
    }
    return true;
}

//fonction vérifiant la validité d'une ligne
bool verifLine(T_grid grid, int y, int length)
{
    return gridVerif(grid, 0, length, y, y, length);
}

//fonction vérifiant la validité d'une colonne
bool verifColumn(T_grid grid, int x, int length)
{
    return gridVerif(grid, x, x, 0, length, length);
}

//fonction vérifiant la validité d'un carré
bool verifSquare(T_grid grid, int x, int y, int length)
{
    int sizeSquare = (int)sqrt(length);
    return gridVerif(grid, x, (x + sizeSquare-1), y, (y + sizeSquare-1), length);
}

//fonction vérifiant la validité de la grille complète
bool verifGrid(T_grid grid, int length)
{

    for(int i = 0; i < length; i++)
    {
        if(verifLine(grid, i, length) == false || verifColumn(grid, i, length) == false)
        {
            return false;
        }
    }

    int nbrSquarePerLine = sqrt(length);                //nombre de carré par ligne/colonne
    for (int j = 0; j < nbrSquarePerLine; j++)          //parcours des carrés de chaque lignes
    {
        for (int k = 0; k < nbrSquarePerLine; k++)      //parcours des carrés de chaque colonnes
        {
            if (verifSquare(grid, (j * nbrSquarePerLine), (k * nbrSquarePerLine), length) == false)     //on donne les coordonnées des cases situées en haut à gauche des carrés
            {
                return false;
            }
        }
    }
    printf("La grille est bonne \n");
    return true;
}

//Variable permettant de savoir si la fonction "rule_1and3" à remplit au moins 1 case

//Application des règles 1 et 3
bool rule_1and3 (T_grid grid, int sizet)
{
    printf("APPLICATION RULE_1_3\n");
    bool found = false;
    int i = 0;
    for (int x = 0; x < sizet; x++)
    {
        for (int y = 0; y < sizet; y++)
        {

            if (caseVide(&grid[x][y]))
            {
                i++;
                if (oneNoteLeft(grid[x][y].notes))
                {
                    grid = add_Value(grid, x, y, getvalNote(grid[x][y].notes));
                    found = true;
                }
            }
        }
    }
    return found;
}

//Application de la règle de résolution 2
bool rule_2 (T_grid grid, int sizet)
{
    printf("APPLICATION RULE_2\n");
    bool found = false;
    for (int x = 0; x < sizet; x++)
    {
        for (int y = 0; y < sizet; y++)
        {
            if (caseVide(&grid[x][y]))
            {
                int tmp = grid[x][y].notes;
                if (rule_2_line(grid, sizet, x, y, tmp))
                    found = true;
                else
                {
                    tmp = grid[x][y].notes;
                    if (rule_2_column(grid, sizet, x, y, tmp))
                        found = true;
                    else
                    {
                        tmp = grid[x][y].notes;
                        if (rule_2_square(grid, sizet, x, y, tmp))
                            found = true;

                    }
                }
            }
        }
    }
    return found;
}


//Application de règle 2 spécifiquement à une ligne
bool rule_2_line(T_grid grid, int sizet, int X, int Y, int tmp)
{
    for (int y = 0; y < sizet; y++)
    {
        if ((caseVide(&grid[X][y])) && (y != Y))
        {
            tmp = tmp & ~(grid[X][y].notes);
        }
    }
    bool found = false;
    if (oneNoteLeft(tmp))
    {
        grid = add_Value(grid, X, Y, getvalNote(tmp));
        found = true;
    }
    return found;
}


//Application de la règle 2 spécifiquement à une colonne
bool rule_2_column (T_grid grid, int sizet, int X, int Y, int tmp)
{
    for (int x = 0; x < sizet; x++)
    {
        if ((caseVide(&grid[x][Y])) && (x != X))
        {
            tmp = tmp & ~(grid[x][Y].notes);
        }
    }
    bool found = false;
    if (oneNoteLeft(tmp))
    {
        grid = add_Value(grid, X, Y, getvalNote(tmp));
        found = true;
    }
    return found;
}


//Application de règle 2 spécifiquement à un bloc
bool rule_2_square(T_grid grid, int sizet, int X, int Y, int tmp)
{
    int xs = (X / NBSQRT) * NBSQRT;
    int ys = (Y / NBSQRT) * NBSQRT;
    for (int x = xs; x < xs + NBSQRT; x++)
    {
        for (int y = ys; y < ys + NBSQRT; y++)
        {
            if ((caseVide(&grid[x][y])) && ((x != X) || (y != Y)))
            {
                tmp = tmp & ~(grid[x][y].notes);
            }
        }

    }
    bool found = false;
    if (oneNoteLeft(tmp))
    {
        grid = add_Value(grid, X, Y, getvalNote(tmp));
        found = true;
    }
    return found;
}


//Lance la résolution avec les règles 1 à 3
void run_rules (T_grid grid, int sizet)
 {
     if (rule_1and3(grid, sizet))
     {
         run_rules(grid, sizet);
         return;
     }
     else
     {
         if (rule_2(grid,sizet))
         {
             run_rules(grid, sizet);
             return;
         }
         else
         {
             if (rules_67(grid))
             {
                 run_rules(grid, sizet);
                 return;
             }
         }
     }

//     bool testGlobal = true;
//     bool testValid = true;

//     while (testGlobal){
//         while (!rule_1and3(grid, sizet)){
//             testValid = true;
//             while (!rule_2(grid, sizet) && testValid){
//                 while (!rules_67(grid) && testValid){
//                     testGlobal = false;
//                     break;
//                 }
//                 testValid = false;
//             }
//         }
//     }
 }

/*void run_rules (T_grid grid, int sizet)
{
    printf("RUN_RULES\n");
    bool theend = false;
    while(!theend)
    {
        while (!rule_1and3(grid, sizet)){
            if (rule_2(grid, sizet))
            {
                printf("APPLICATION RULE_2\n");
                break;
            }
            else theend = true;

            {
                if (rules_67(grid))
                {
                    printf("APPLICATION RULE_67\n");
                    break;
                }
                else theend = true;
            }
    }
}
}
*/

int* availableValues(T_grid grid, int X1, int Y1, int X2, int Y2, int* length)
{
    bool btab[LENGTH];
    for(int i = 0; i<LENGTH;i++)
    {
        btab[i]=true;
    }
    for(int X = X1; X <=X2; X++)
    {
        for(int Y = Y1; Y <= Y2; Y++)
        {
            if(grid[X][Y].value != 0)
            {
                btab[grid[X][Y].value - 1] = false;
            }
            else (*length)++;
        }
    }
    int* tab = (int*)malloc(*length * sizeof(int));
    int index = 0;
    for(int i = 0; i< LENGTH; i++)
    {
        if(btab[i])
        {
            tab[index] = i+1;
            index++;
        }
    }
    return tab;
}

bool rules_67_zone(T_grid grid, int X1, int Y1, int X2, int Y2, int K, int * tab)
{
    int tmp = setNote1_tab(tab, K);
    int x = X1;
    int y = Y1;
    int nbrCoord = 0;
    int note;
    int tCoord[K][2];
    for (int i = 0; i < K; i++)
    {
        printf("KUPLET EN TEST : %d\n", tab[i]);
    }
    while (x <= X2 && nbrCoord < K){
            y = Y1;
        while (y <= Y2 && nbrCoord < K){
            note = grid[x][y].notes;
            if (IsInTheTampon(tmp, note) && grid[x][y].value == 0){
                tCoord[nbrCoord][0] = x;
                tCoord[nbrCoord][1] = y;
                nbrCoord++;
            }
            y++;
        }
        x++;
    }
    bool found = false;
    if (/*tmp_test == 0 && */nbrCoord == K){
        printf("EUREKA\n");
        if (setNoteRule6(grid, X1, Y1, X2, Y2, tCoord, K, tmp))
        {
            found = true;
        }
    }

    return found;
}


bool generateKtuples(T_grid grid, int possibleValues[], int sizet, int k, int kuplet[], int index, int bfor, int X1, int Y1, int X2, int Y2) {
    bool found = false;
    if (index == k) {
        if (rules_89_zone (grid, X1, Y1, X2, Y2, k, kuplet))
        {
            found = true;
        }
        return found;
    }

    for (int i = bfor; i < sizet-k+1; i++) {
        kuplet[index] = possibleValues[i];
        generateKtuples(grid, possibleValues, sizet+1, k, kuplet, index + 1, i + 1, X1, Y1, X2, Y2);
    }
}

int max4(int a){
    if(a < 4) { return a; }
    else { return 4; }
}

bool rules_67(T_grid grid){
    int sizet;
    int * availVal;
    bool found = false;
    for (int l = 0; l < LENGTH; l++){
        sizet = 0;
        availVal = availableValues(grid, l, 0, l, LENGTH-1, &sizet);
        for (int k = 2; k <= max4(sizet); k++){
            int kuplet[k];
            if (generateKtuples(grid, availVal, sizet, k, kuplet, 0, 0, l, 0, l, LENGTH-1))
            {
                found = true;
            }
        }
    }
    for (int c = 0; c < LENGTH; c++){
        sizet = 0;
        availVal = availableValues(grid, 0, c, LENGTH-1, c, &sizet);
        for (int k = 2; k <= max4(sizet); k++){
            int kuplet[k];
            if (generateKtuples(grid, availVal, sizet, k, kuplet, 0, 0, 0, c, LENGTH-1, c))
            {
                found = true;
            }
        }
    }

    for (int i = 0; i < LENGTH; i += NBSQRT){
        for (int j = 0; j < LENGTH; j += NBSQRT){
            sizet = 0;
            availVal = availableValues(grid, i, j, i + NBSQRT - 1, j + NBSQRT - 1, &sizet);
            for (int k = 2; k <= max4(sizet); k++){
                int kuplet[k];
                if (generateKtuples(grid, availVal, sizet, k, kuplet, 0, 0, i, j, i + NBSQRT - 1, j + NBSQRT - 1))
                {
                    found = true;
                }
            }
        }
    }

    free(availVal);
    return found;
}
int varglob = 0;

bool rules_89_zone(T_grid grid, int X1, int Y1, int X2, int Y2, int K, int * tab)
{
    varglob++;
    //printf("RULES_89_ZONE NUMBER %d\n",varglob);
    //printf("X1 = %d, X2 = %d, Y1 = %d Y2 = %d \n",X1, X2, Y1, Y2);
    int tmp = setNote1_tab(tab, K);
    int x = X1;
    int y = Y1;
    int nbrCoord = 0;
    int notok = 0;
    int note;
    int tCoord[LENGTH - K][2];
    printf("X1 = %d, X2 = %d, Y1 = %d Y2 = %d \n",X1, X2, Y1, Y2);
    while (x <= X2){
            y = Y1;
        while (y <= Y2){
            note = grid[x][y].notes;
            /*if (((tmp & note) == 0)  && (grid[x][y].value == 0)){
                tCoord[notok][0] = x;
                tCoord[notok][1] = y;
                notok ++;
            }
            else {
                if (grid[x][y].value == 0)
                    nbrCoord++;
            }*/
            if (((tmp & note) == 0) && (LENGTH-K > notok)){
                tCoord[notok][0] = x;
                tCoord[notok][1] = y;
                notok ++;
                if ((tab[0] == 5) && (tab[1] == 6) && (tab[2] == 7) && (X1 == 6) && (X2 == 8) && (Y1 == 3) && (Y2 == 5))
                {
                    printf("JE GARDE LA CASE [%d][%d]\n", x,y);
                }
            }
            else nbrCoord++;
            y++;
        }
        x++;
    }
    //printf("ALORS PEUT ETRE ??\n");
    bool found = false;
    if (/*tmp_test == 0 && */nbrCoord == K){
        printf("EUREKA RULES 89\n");
        printf("X1 = %d, X2 = %d, Y1 = %d Y2 = %d \n",X1, X2, Y1, Y2);
        for (int i = 0; i < K; i++)
        {
            printf("KUPLET TROUVE : %d\n", tab[i]);
        }
        if (setNoteRule6(grid, X1, Y1, X2, Y2, tCoord, K, ~tmp))
        {
            found = true;
        }
    }

    return found;
}





