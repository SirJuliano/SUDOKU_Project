#ifndef SUDOKU_PROJECT_ERREUR_ANTOINE_NOTES_H
#define SUDOKU_PROJECT_ERREUR_ANTOINE_NOTES_H
#include "Grille.h"

// void initNote(T_grid grid, int length);
void setNote1(Box *cell, int numNote);                                  //Met à 1 le bit "numNote" de la note contenue dans "*cell"
void setNote0(Box *cell, int numNote);                                  //Met à 0 le bit "numNote" de la note contenue dans "*cell"
void setNote0Line(T_grid grid, int x, int y, int length, int numNote);  //Met à 0 le bit "numNote" des notes de toutes les cases de la ligne
void setNote0Column(T_grid grid, int x, int y, int length, int numNote);//Met à 0 le bit "numNote" des notes de toutes les cases de la colonne
void setNote0Square(T_grid grid, int x, int y, int length, int numNote);//Met à 0 le bit "numNote" des notes de toutes les cases du bloc
void setNote0Zone(T_grid grid, int x, int y,int length, int numNote);   //Applique ensembles les 3 précédentes fonctions

// int getNote(Box *cell, int numNote);
// void printBinary2(Box cell);
// void printBinary(int num);

int getvalNote(int note);                                               //renvois la version décimal de la note
bool oneNoteLeft (int note);     

int getNbrNote(int note);
bool EqualvalsNote(int* n1, int* n2);

bool IsInTheTampon(int tmp, int note);
void setNoteRule6(T_grid grid, int x1_zone, int y1_zone, int x2_zone, int y2_zone, int **tab, int tablength, int tmp);
    //verifie qu'il n'y ai plus qu'une valeur possible sur une case#endif //SUDOKU_PROJECT_ERREUR_ANTOINE_NOTES_H
#endif