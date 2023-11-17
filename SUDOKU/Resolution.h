#ifndef RESOLUTION_H_INCLUDED
#define RESOLUTION_H_INCLUDED

#include <stdbool.h>

#include "Grille.h"

bool verifCase(bool *res, int val);                             //fonction qui vérifie si la valeur val est déjà apparue dans la ligne/case/colonne
bool gridVerif(T_grid grid, int X1, int X2, int Y1, int Y2);   //fonction qui vérifie si la colonne/case/ligne ne posède pas plusieurs chiffre identiques

bool verifLine(T_grid grid, int x, int length);                 //fonction vérifiant la validité d'une ligne
bool verifColumn(T_grid grid, int y, int length);               //fonction vérifiant la validité d'une colonne
bool verifSquare(T_grid grid, int x, int y, int length);        //fonction vérifiant la validité d'un carré

bool verifGrid(T_grid grid, int length);                                   //fonction vérifiant la validité de la grille complète
void completeArea(T_grid grid, int X1, int X2, int Y1, int Y2);
// void setNote(int* cell, int numNote)


#endif // RESOLUTION_H_INCLUDED
