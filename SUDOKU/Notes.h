#ifndef SUDOKU_PROJECT_ERREUR_ANTOINE_NOTES_H
#define SUDOKU_PROJECT_ERREUR_ANTOINE_NOTES_H
#include "Grille.h"

void initNote(T_grid grid, int length);
void setNote1(Box cell, int numNote);
void setNote1_v2(int *num, int numNote);

void setNote0(Box cell, int numNote);
void setNote0_v2(int *cell, int numNote);

void setNote0Line(T_grid grid, int x, int y, int length, int numNote);
void setNote0Column(T_grid grid, int x, int y, int length, int numNote);
void setNote0Square(T_grid grid, int x, int y, int length, int numNote);
void setVal(T_grid grid, int x, int y,int length, int numNote);
int getNote(Box *cell, int numNote);
void printBinary2(Box cell);
void printBinary(int num);

int getvalNote(Box *cell);
bool oneNoteLeft (Box *cell);

#endif //SUDOKU_PROJECT_ERREUR_ANTOINE_NOTES_H
