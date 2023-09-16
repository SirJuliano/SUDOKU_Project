#ifndef LISTE_SIMPLE_H_INCLUDED
#define LISTE_SIMPLE_H_INCLUDED

#include <stdbool.h>

typedef struct T_box_possibilities{
    struct T_box_possibilities *suiv;
    int *pdata;              //attention à faire un malloc sur ce champ avant de s'en servir
} T_box_List;
typedef T_box_List *T_box;

void initListe(T_box *box);
bool isEmpty(T_box box);
T_box ajoutEnFin(T_box box, int mydata);
T_box fillList(T_box box, int length);

T_box deleteValue(T_box box, int value);  //Supprime une case en fonction du pdata contenu 
T_box getptrNextCell(T_box box);


int* getPtrData(T_box box);     //surement necessaire

int getNbreCell(T_box box);     //ABSOLUMENT NECESSAIRE POUR DETERMINER SI UNE CASE EST VALIDE

void showList(T_box box);




/*
différentes fonctions qui pourraient s'avérer utiles
getptrNdata
ou getdata
getsize
free liste pour fin run 
*/



#endif // LISTEDOUBLE_H_INCLUDED
