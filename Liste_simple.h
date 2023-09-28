#ifndef LISTE_SIMPLE_H_INCLUDED
#define LISTE_SIMPLE_H_INCLUDED

#include <stdbool.h>

typedef struct T_box_possibilities{
    struct T_box_possibilities *suiv;
    int *pdata;
} T_box_List;
typedef T_box_List *T_box;

void initListe(T_box *box);
bool isEmpty(T_box box);

T_box ajoutEnFin(T_box box, int mydata);
T_box fillList(T_box box, int length);

T_box deleteValue(T_box box, int value);  //Supprime une case en fonction du pdata contenu
T_box suppEnTete(T_box box);
void deleteList(T_box box, int size);

T_box getptrNextCell(T_box box);

int* getPtrData(T_box box);

int getNbreCell(T_box box);

void showList(T_box box);

bool foundData(T_box box, int value);







#endif // LISTEDOUBLE_H_INCLUDED
