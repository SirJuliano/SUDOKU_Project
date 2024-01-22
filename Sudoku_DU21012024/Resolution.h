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
// void setNote(int* cell, int numNote)                                         //Variable vérifiant si la fonction "rule_1and3" à trouvé une solution
bool rule_1and3 (T_grid grid, int sizet);                       //fonction appliquant les règles de résolution 1 et 3                                            //Variable vérifiant si la fonction "rule_2" à trouvé une solution
bool rule_2 (T_grid grid, int sizet);
bool rule_2_line(T_grid grid, int sizet, int X, int Y, int tmp);//Focntion appliquant la règle de résolution 2
bool rule_2_column (T_grid grid, int sizet, int X, int Y, int tmp);//fonction appliquant rule_2 à une colonne
bool rule_2_square(T_grid grid, int sizet, int X, int Y, int tmp);//fonction appliquant rule_2 à un bloc
void run_rules (T_grid grid, int sizet);                        //fonction appliquant rule_2 à une ligne

int* availableValues(T_grid grid, int X1, int Y1, int X2, int Y2, int* length);
bool rules_67_zone (T_grid grid, int X1, int Y1, int X2, int Y2, int K, int * tab);
bool generateKtuples(T_grid grid, int possibleValues[], int sizet, int k, int kuplet[], int index, int bfor, int X1, int Y1, int X2, int Y2);
int max4(int a);
bool rules_67(T_grid grid);
bool rules_89_zone(T_grid grid, int X1, int Y1, int X2, int Y2, int K, int * tab);
#endif // RESOLUTION_H_INCLUDED
