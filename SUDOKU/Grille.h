#ifndef GRILLE_H_INCLUDED
#define GRILLE_H_INCLUDED

typedef int ** T_grid;


T_grid createGrid(int length);                                                 //allocation de la memoire nécéssaire pour un tableau à deux dimensions
void initGrid(T_grid grid, int length);                                        //initialise toutes les cases de la grille à 0

T_grid add_Value(T_grid grid, int pos_line, int pos_column, int value);      //ajoute une valeur dans la case souhaitee
T_grid deleteAvalue(T_grid grid, int pos_line, int pos_column);              //supprime la valeur de la case
int getVal(T_grid grid, int x, int y);                                          //renvoie la chiffre de la case x, y
void Show_grid(T_grid grid, int length);                                      //affiche la grille

void freeGrid(T_grid grid, int length);                                        //libère la mémoire allouée pour la grille

#endif // GRILLE_H_INCLUDED
