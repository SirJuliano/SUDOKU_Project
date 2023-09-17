#ifndef GRILLE_H_INCLUDED
#define GRILLE_H_INCLUDED

#include "Liste_simple.h"
//typedef T_box ** T_grid;
typedef int ** T_gridF;

// T_grid createGrid(int largeur, int hauteur);
int areaOfSquare(int largeur, int hauteur);
int inSquare(int poslenght, int posheight);
// void fillGrid(T_grid grid, int largeur, int hauteur);

// void show_grid(T_grid grid, int size);
T_gridF finalGrid(int largeur, int hauteur);
T_gridF initGrid(T_gridF grid,int lenght, int height);
T_gridF add_Value(T_gridF gridF, int pos_line, int pos_column, int value);
T_gridF deleteAvalue (T_gridF gridF, int pos_line, int pos_column);
void Show_grid_final (T_gridF gridF, int size);

#endif // GRILLE_H_INCLUDED
