#ifndef LISTE_SIMPLE_H_INCLUDED
#define LISTE_SIMPLE_H_INCLUDED

#include <stdbool.h>

typedef struct T_box_possibilities{
    struct T_box_possibilities *suiv;
    int *pdata;              //attention à faire un malloc sur ce champ avant de s'en servir
} T_box_List;
typedef T_box_List *T_box;

void initListe(T_box *l);
void FillList(T_box l);




T_box ajoutEnTete(T_box l, int mydata);    //peut etre pas besoin des ajouts
T_box ajoutEn2ePosition (T_box l, int mydata);
T_box ajoutEnFin(T_box l, int mydata);

T_box Delete_Value(T_box box, int value);  //Supprime une case en fonction du pdata contenu 

T_box getptrNextCell(T_box l);


int* getPtrData(T_box l);     //surement necessaire
void swapPtrData( T_box source, T_box destination );  //probablement non necessaire

int getNbreCell(T_box l);     //ABSOLUMENT NECESSAIRE POUR DETERMINER SI UNE CASE EST VALIDE


void tri_selection_liste(T_box l, bool (*fcomp) (int a, int b));   //probablement pas nécessaire

/*
différentes fonctions qui pourraient s'avérer utiles
getptrNdata
ou getdata
getsyze
*/



#endif // LISTEDOUBLE_H_INCLUDED
