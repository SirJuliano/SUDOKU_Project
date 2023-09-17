#ifndef RESOLUTION_H_INCLUDED
#define RESOLUTION_H_INCLUDED

#include "Grille.h"
#include <stdbool.h>

bool validColumn(T_gridF grid, int posLargeur);
bool validLine (T_gridF grid, int posHeight);
bool validSquare(int posLine, int posColumn);

#define LENGTH 9
#define HEIGHT 9


#endif // RESOLUTION_H_INCLUDED
