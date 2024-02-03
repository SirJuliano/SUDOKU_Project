#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


#include "Grille.h"
#include "Resolution.h"
#include "Notes.h"

//Fonction qui v�rifie si la valeur val est d�j� apparue dans la ligne/case/colonne
bool verifCase(bool *res, int val)
{
    if (res[val - 1])       // res est un tableau de bool�ens avec true pour la case(x-1) si la valeur x est d�j� pr�sente
    {
        return false;
    }
    else                        // si elle ne l'est pas, on la note comme pr�sente
    {
        res[val - 1] = true;
    }
    return true;
}

//fonction qui v�rifie si la colonne/case/ligne ne poss�de pas plusieurs chiffres identiques
bool gridVerif(T_grid grid, int X1, int X2, int Y1, int Y2, int lenght)
{
    bool res[(X2 - X1+1) * (Y2 - Y1+1)];
    for (int i = 0; i < lenght; i++)
                res[i] = false;
    //tableau de bool�ens initialis� a 0 avec autant de cases que de nombres � tester
    //pour les chiffres de 1 � 9, il y aura 9 cases
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

//fonction v�rifiant la validit� d'une ligne
bool verifLine(T_grid grid, int y, int length)
{
    return gridVerif(grid, 0, length, y, y+1, length);
}

//fonction v�rifiant la validit� d'une colonne
bool verifColumn(T_grid grid, int x, int length)
{
    return gridVerif(grid, x, x+1, 0, length, length);
}

//fonction v�rifiant la validit� d'un carr�
bool verifSquare(T_grid grid, int x, int y, int length)
{
    int sizeSquare = (int)sqrt(length);
    return gridVerif(grid, x, (x + sizeSquare), y, (y + sizeSquare), length);
}

//fonction v�rifiant la validit� de la grille compl�te
bool verifGrid(T_grid grid, int length)
{

    for(int i = 0; i < length; i++)
    {
        if(verifLine(grid, i, length) == false || verifColumn(grid, i, length) == false)
        {
            printf("La grille est fausse\n");
            return false;
        }
    }

    int nbrSquarePerLine = NBSQRT;                //nombre de carr� par ligne/colonne
    for (int j = 0; j < nbrSquarePerLine; j++)          //parcours des carr�s de chaque lignes
    {
        for (int k = 0; k < nbrSquarePerLine; k++)      //parcours des carr�s de chaque colonnes
        {
            if (verifSquare(grid, (j * nbrSquarePerLine), (k * nbrSquarePerLine), length) == false)     //on donne les coordonn�es des cases situ�es en haut � gauche des carr�s
            {
                printf("La grille est fausse\n");
                return false;
            }
        }
    }
    printf("La grille est bonne \n");
    return true;
}




//Application des r�gles 1 et 3
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

//Application de la r�gle de r�solution 2
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


//Application de r�gle 2 sp�cifiquement � une ligne
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


//Application de la r�gle 2 sp�cifiquement � une colonne
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


//Application de r�gle 2 sp�cifiquement � un bloc
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

bool verifbetweenrules(T_grid grid)
{
    bool problem = true;
    for (int x = 0; x < LENGTH; x++)
    {
        for (int y = 0; y < LENGTH;y++)
        {
            if ((caseVide(&grid[x][y])) && (grid[x][y].notes == 0))
            {
                printf("La case [%d][%d] � un probl�me : elle est vide et aucune valeur ne peut y etre plac�e. La grille est donc fausse.\n",x,y);
                problem = false;
            }
        }
    }
    return problem;
}


//Lance la r�solution avec les r�gles 1 � 3
void run_rules (T_grid grid, int sizet)
{
    if (!verifbetweenrules(grid))
        return;
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
            if (rules_610(grid))
            {
                run_rules(grid, sizet);
                return;
            }

            else
            {
                if (rules_1112_launch(grid))
                {
                    run_rules(grid,sizet);
                    return;
                }
            }
        }

    }
/*
     bool testGlobal = true;
     bool testValid = true;

     while (testGlobal){
         while (!rule_1and3(grid, sizet)){
             testValid = true;
             while (!rule_2(grid, sizet) && testValid){
                 while (!rules_67(grid) && testValid){
                     testGlobal = false;
                     break;
                 }
                 testValid = false;
             }
         }
     }
 }
*/
}
/*void run_rules (T_grid grid, int sizet)
{
    bool theend = false;
    while (!theend)
    {
        while (!rule_1and3(grid, sizet))
        {
            if (rule_2(grid, sizet))
            {
                continue;
            }
            // Si rules_67 est vraie, recommencer la boucle interne
            else if (rules_67(grid))
            {
                continue;
            }
            else theend = true;
        }

        // Si on arrive ici, c'est que ni rule_1and3, ni rule_2, ni rules_67 n'�taient vraies
    }
}*/

/*void run_rules(T_grid grid, int sizet) {
    printf("RUN_RULES\n");
    bool theend = false;

    while (!theend) {
        // Tant que rule_1and3 est vraie, ou que rule_2 est vraie, ou que rules_67 est vraie
        while (rule_1and3(grid, sizet) || rule_2(grid, sizet) || rules_67(grid)) {
            // Si rule_1and3 est vraie, recommencer la boucle interne
            if (rule_1and3(grid, sizet)) {
                continue;
            }
            // Si rule_2 est vraie, recommencer la boucle interne
            else if (rule_2(grid, sizet)) {
                continue;
            }
            // Si rules_67 est vraie, recommencer la boucle interne
            else if (rules_67(grid)) {
                continue;
            }
        }

        // Si on arrive ici, c'est que ni rule_1and3, ni rule_2, ni rules_67 n'�taient vraies
        theend = true;
    }
}*/


//fonction renvoyant un tableau remplie des valeurs non pr�sentes dans une zone et sa taille
int* availableValues(T_grid grid, int X1, int Y1, int X2, int Y2, int* length)
{
    bool btab[LENGTH];
    for(int i = 0; i<LENGTH;i++)
    {
        btab[i]=true;
    }
    for(int X = X1; X <=X2; X++)    //parcours de la zone donn�e
    {
        for(int Y = Y1; Y <= Y2; Y++)
        {
            if(grid[X][Y].value != 0 && btab[grid[X][Y].value - 1] != false)   //si une case est remplie
            {
                btab[grid[X][Y].value - 1] = false; //est est supprim�e du tableau de possibilit�s
            }
            else (*length)++;   //sinon, le tableau de possibilit� grandit
        }
    }
    int* tab = (int*)malloc(*length * sizeof(int));
    int index = 0;
    for(int i = 0; i< LENGTH; i++)
    {
        if(btab[i])
        {
            tab[index] = i+1;   //cr�ation du tableau remplie des valeurs possibles
            index++;
        }
    }
    return tab;
}

//fonction envoyant les coordonn�es des cases correspondantes au kuplet donn�e (si elles existent) � setNoteRule610
bool rules_67_zone(T_grid grid, int X1, int Y1, int X2, int Y2, int K, int * kuplet)
{
    int tmp = setNote1_tab(kuplet, K);  //cr�ation de tampon correspondant au kuplet donn�e
    int x = X1;
    int y = Y1;
    int nbrCoord = 0;
    int note;
    int tCoord[K][2];
    while (x <= X2 && nbrCoord < K){    //parcours de la zone
            y = Y1;
        while (y <= Y2 && nbrCoord < K){
            note = grid[x][y].notes;
            if (IsInTheTampon(tmp, note) && grid[x][y].value == 0){     //Si la note de d'une case est comprise dans le kuplet (et si elle est vide),
                tCoord[nbrCoord][0] = x;                                //on garde ses coordonn�es en m�moires afin de ne pas mofifier sa note.
                tCoord[nbrCoord][1] = y;                                //On ne modifie que les cases ne comprenant pas le kuplet
                nbrCoord++;
            }
            y++;
        }
        x++;
    }
    bool found = false;
    if (nbrCoord == K){                                                         //si le tableau est remplie
        bool result = setNoteRule610(grid, X1, Y1, X2, Y2, tCoord, K, tmp);     //on applique les r�gles sur la zone donn�e
        if (result)
        {
            found = true;
        }
    }
    return found;       //on revoie true si la grille a �t� modifi�, false sinon
}

//fonction envoyant les coordonn�es des cases correspondantes au kuplet donn�e (si elles existent) � setNoteRule610
bool rules_89_zone(T_grid grid, int X1, int Y1, int X2, int Y2, int K, int * tab)
{
    int tmp = setNote1_tab(tab, K);  //cr�ation de tampon correspondant au kuplet donn�e
    int x = X1;
    int y = Y1;
    int nbrCoord = 0;
    int notOk = 0;
    int note;
    int tCoord[LENGTH - K][2];
    while (x <= X2){            //parcours de la zone
        y = Y1;
        while (y <= Y2){
            note = grid[x][y].notes;
            if (((tmp & note) == 0) && (LENGTH - K >= notOk)){      //si la note de la case n'a rien en commun avec le kuplet et que le tableau n'est pas plein
                tCoord[notOk][0] = x;                               //on garde ses coordonn�es en m�moires afin de ne pas mofifier sa note.
                tCoord[notOk][1] = y;                               //On ne modifie que les cases comprenant le kuplet
                notOk ++;
            }
            else
            {
                nbrCoord++;
            }
            y++;
        }
        x++;
    }
    bool found = false;
    if (nbrCoord == K){                                                                 //si le tableau est remplie
        bool result = setNoteRule610(grid, X1, Y1, X2, Y2, tCoord, LENGTH - K, ~tmp);   //on applique les r�gles sur la zone donn�e
        if (result)
        {
            found = true;
        }
    }
    return found;       //on revoie true si la grille a �t� modifi�, false sinon
}


bool generateKtuples(T_grid grid, int possibleValues[], int sizet, int k, int kuplet[], int index, int bfor, int X1, int Y1, int X2, int Y2) {
    //Le premier appel � cette fonction veut savoir si des notes ont pu �tre modifi�es
    //La cr�tion des K-uples se fait dans la boucle "for"
    bool found = false;
    bool result1 = false;
    bool result2 = false;
    bool founded = false;
    if (index == k) {//Condition d'arr�t, on a cr�� un kuplet complet, on lance les r�gles 5 � 10
        result1 = rules_89_zone (grid, X1, Y1, X2, Y2, k, kuplet);     //Ici, pour chaque K-uplet, result1 renvoie "true" si
        if (result1)                                                   //Une note a �t� modifi�e (ie on pourra relancer run_rules depuis le d�but)
        {
            found = true;
        }
        result2 = rules_67_zone (grid, X1, Y1, X2, Y2, k, kuplet);      //Pareil que pour result1 mais avec "rules_67_zone"
        if (result2)
        {
            found = true;
        }
        return found;        //Ce bool�en est renvoy� � la fonction qui a g�n�r� cet appel de "generateKtuples", � savoir
    }                        //Un autre generateKtuples (car c'est une fonction r�cursive)

    for (int i = bfor; i < sizet-k+1; i++) {
        kuplet[index] = possibleValues[i];      //Chaque appel de generateKtuples permet de remplir une case du tableau kuplet
        founded = generateKtuples(grid, possibleValues, sizet+1, k, kuplet, index + 1, i + 1, X1, Y1, X2, Y2) || founded;
        //Ainsi, au premier appel, on cr�� [1, , ], puis on lance generateKtuples pour l'indice suivant du tableau
        //A ce nouvel appel on aura [1,2, ] qui recommencera jusqu'� remplir compl�tement le tableau kuplet
        //La boucle "for" permet de g�n�rer tout les K-uplets possibles
        //Enfin, comme chaque "found" est renvoy� aux "generateKtuples" qui l'a appel�, la derni�re ligne de cette boucle
        //Permet de retenir si une note a �t� modifi�e dans la variable "founded" (true si c'est le cas)
    }
    return founded;

}

int max4(int a){
    if(a < 4) { return a; }
    else { return 4; }
}


//cette fonction lance les r�gles 6 � 10 sur toutes les lignes, colonnes et carr�s de la grille
bool rules_610(T_grid grid){
    printf("APPLICATION RULES_610\n");
    int sizet;
    bool found = false;
    bool ktuple = false;
    for (int l = 0; l < LENGTH; l++){       //Boucles pour les lignes
        sizet = 0;
        int * availVal;
        availVal = availableValues(grid, l, 0, l, LENGTH-1, &sizet);   //Renvoie les possibilit�s restantes sur la ligne
        for (int k = 2; k <= max4(sizet); k++){
            int kuplet[k];
            ktuple = generateKtuples(grid, availVal, sizet, k, kuplet, 0, 0, l, 0, l, LENGTH-1);  //On lance les r�gles avec "generateKtuples" car c'est cette derni�re qui appelle les r�gles 5 � 10
            if (ktuple == true)
            {
                found = true;
            }
        }
        free(availVal);
    }

    for (int c = 0; c < LENGTH; c++){      //Boucles pour les colonnes
        sizet = 0;
        int * availVal;
        availVal = availableValues(grid, 0, c, LENGTH-1, c, &sizet);    //Renvoie les possibilit�s restantes sur la colonne
        for (int k = 2; k <= max4(sizet); k++){
            int kuplet[k];
            ktuple = generateKtuples(grid, availVal, sizet, k, kuplet, 0, 0, 0, c, LENGTH-1, c);  //On lance les r�gles avec "generateKtuples" car c'est cette derni�re qui appelle les r�gles 5 � 10
            if (ktuple == true)
            {
                found = true;
            }
        }
        free(availVal);
    }

    for (int i = 0; i < LENGTH; i += NBSQRT){   //Boucles pour les blocs
        for (int j = 0; j < LENGTH; j += NBSQRT){
            sizet = 0;
            int * availVal;
            availVal = availableValues(grid, i, j, i + NBSQRT - 1, j + NBSQRT - 1, &sizet);  //Renvoie les possibilit�s restantes dans le bloc
            for (int k = 2; k <= max4(sizet); k++){
                int kuplet[k];
                ktuple = generateKtuples(grid, availVal, sizet, k, kuplet, 0, 0, i, j, i + NBSQRT - 1, j + NBSQRT - 1);  //On lance les r�gles avec "generateKtuples" car c'est cette derni�re qui appelle les r�gles 5 � 10
                if (ktuple == true)
                {
                    found = true;
                }
            }
            free(availVal);
        }
    }
    return found;  //Ce bool�en est � vrai si au moins un appel de "generateKtuples" � renvoy� "true"
                   //Cela indique qu'une note au moins a �t� modifi�e (ie on pourra alors relancer run_rules)
}





bool rules_1112_launch(T_grid grid)
{
    printf("APPLICATION RULES_1112\n");
    bool found = false;
    int * availval;
    int sizetAvailVal;
    for (int i = 0; i < LENGTH; i += NBSQRT){   //Boucles pour les blocs
        for (int j = 0; j < LENGTH; j += NBSQRT){
            sizetAvailVal = 0;
            availval = availableValues(grid, i, j, i + NBSQRT - 1, j + NBSQRT - 1, &sizetAvailVal); //Renvoie les possibilit�s restantes dans le bloc
            for (int k = 0; k < sizetAvailVal; k++){
                found = rules_1112(grid,i, j, i + NBSQRT - 1, j + NBSQRT - 1, availval[k]) || found;
            }
            free(availval);
        }
    }

    return found;

}

bool rules_1112(T_grid grid, int X1, int Y1, int X2, int Y2, int testValue)
{

    bool firstMatchFound = false;
    int tmp = setNote1_int(testValue);
    int x;
    int y;
    bool rowPossible = true;
    bool columnPossible = true;
    int note;
    int MatchCases [LENGTH][2];
    int nbrMatchCases = 0;
    bool found = false;
    int i = X1;
    //for (int i = X1; i <= X2; i++)
    while (i <= X2 && (rowPossible || columnPossible))
    {
        //for (int j = Y1; j <= Y2; j++)
        int j = Y1;
        while (j <= Y2 && (rowPossible || columnPossible))
        {
            if (caseVide(&grid[i][j]))
            {
                note = grid[i][j].notes;
                if (IsInTheTampon(note,tmp))
                {
                    if (!firstMatchFound)
                    {
                        x = i;
                        y = j;
                        firstMatchFound = true;
                    }
                    else
                    {
                        if (x != i)
                            rowPossible = false;
                        if (y != j)
                            columnPossible = false;
                    }
                    MatchCases[nbrMatchCases][0] = i;
                    MatchCases[nbrMatchCases][1] = j;
                    nbrMatchCases ++;
                }
            }
            j++;
        }
        i++;
    }

    if (rowPossible && (!columnPossible))
    {
        found = setNoteRule610(grid, MatchCases[0][0], 0, MatchCases[0][0], LENGTH-1, MatchCases, nbrMatchCases, tmp) || found;
    }

    if ((!rowPossible) && columnPossible)
    {
        found = setNoteRule610(grid, 0, MatchCases[0][1], LENGTH-1, MatchCases[0][1], MatchCases, nbrMatchCases, tmp) || found ;
    }

    return found;
}
