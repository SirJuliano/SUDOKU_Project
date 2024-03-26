//
// Created by nono on 28/02/24.
//

#ifndef SUDOKU_PROJECT_BOX_REDUCTION_MYSDL_H
#define SUDOKU_PROJECT_BOX_REDUCTION_MYSDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include "Resolution.h"

typedef struct {
    SDL_Rect rect;
    bool isPressed;
    SDL_Color color;
    SDL_Rect textfield;
} Button;

bool pointInsideRect(int x, int y, const SDL_Rect *rect);
void initialiserSDL();
void quitterSDL();
void dessinerGrille(SDL_Rect* grille, T_grid* grid, Button* tab, bool shownote, bool textimput, int coordX, int coordY);
void mysdl(T_grid grid);

#endif //SUDOKU_PROJECT_BOX_REDUCTION_MYSDL_H
