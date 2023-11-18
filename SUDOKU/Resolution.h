#ifndef RESOLUTION_H_INCLUDED
#define RESOLUTION_H_INCLUDED

#include <stdbool.h>

#include "Grille.h"

bool verifCase(bool *res, int val);                             //fonction qui vérifie si la valeur val est déjà apparue dans la ligne/case/colonne
bool gridVerif(T_grid grid, int X1, int X2, int Y1, int Y2, int lenght);   //fonction qui vérifie si la colonne/case/ligne ne posède pas plusieurs chiffre identiques

bool verifLine(T_grid grid, int x, int length);                 //fonction vérifiant la validité d'une ligne
bool verifColumn(T_grid grid, int y, int length);               //fonction vérifiant la validité d'une colonne
bool verifSquare(T_grid grid, int x, int y, int length);        //fonction vérifiant la validité d'un carré

bool verifGrid(T_grid grid, int length);                        //fonction vérifiant la validité de la grille complète
// void setNote(int* cell, int numNote)
bool found_rule_1and3;
void rule_1and3 (T_grid grid, int sizet);
bool found_rule_2 ;
void rule_2 (T_grid grid, int sizet);
bool rule_2_line(T_grid grid, int sizet, int X, int Y, int tmp);
bool rule_2_column (T_grid grid, int sizet, int X, int Y, int tmp);
bool rule_2_square(T_grid grid, int sizet, int X, int Y, int tmp);
void run_rules (T_grid grid, int sizet);
#endif // RESOLUTION_H_INCLUDED
