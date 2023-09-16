#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Liste_simple.h"

//Nous avons choisis de reprendre nos fonctions de liste double travaillées en cours et de les modifier
//afin qu'elles fonctionnent comme des listes simples. C'est à dire que nous avons enlever le type T_cell *prec.

//initListe ne fait pas de malloc, juste une initialisation à NULL du pointeur de liste
void initListe(T_box *box)
{
    *box=NULL;
}

void FillList(T_box box, int length)
{
    for (int i = 1; i<length + 1; i++)
    {
        box = ajoutEnFin(box, i);
    }
    return box;
}


//Permet d'ajouter un nouvel élément au début d'une liste
T_box ajoutEnTete(T_box box, int mydata)
{
    T_box nouv = (T_box)malloc(sizeof(struct T_box_possibilities));
    nouv->pdata = (int*)malloc(sizeof(int));
    *(nouv->pdata)=mydata;

    if (box==NULL)
    {
        nouv->suiv=NULL;
    }
    else
    {

        nouv->suiv=box;
    }
    return nouv;
}

//Permet l'ajout d'un nouvel élément en 2eme position d'une liste
T_box ajoutEn2ePosition (T_box box, int mydata)
{

    T_box nouv = (T_box)malloc(sizeof(struct T_box_possibilities));
    nouv->pdata = (int*)malloc(sizeof(int));
    *(nouv->pdata)= mydata;
    if (box == NULL)
    {
        return ajoutEnTete(box, mydata);
    }

    T_box courant = box->suiv;
    box->suiv = nouv;
    nouv->suiv = courant;

    return box;
}

//Permet l'ajout d'un nouvel élément à la fin d'une liste
T_box ajoutEnFin(T_box l, int mydata)
{
    T_box nouv = (T_box)malloc(sizeof(struct T_box_possibilities));
    nouv->pdata = (int*)malloc(sizeof(int));
    *(nouv->pdata)= mydata;

    if (l==NULL)
    {
        nouv->suiv=NULL;
        return nouv;
    }
    else
    {
        T_box courant = l;
        while (courant->suiv != NULL)
        {
            courant = courant->suiv;
        }
        nouv->suiv=NULL;
        courant->suiv=nouv;
        return l;
    }
}

//Permet de supprimer le premier élément d'une liste (elle vérifie avant s'il y en a bien un)
T_box Delete_Value(T_box box, int value)
{
    if (box == NULL)
    {
        return box;
    }
    else{
        T_box current = box;
        while (current != NULL)
        {
            if (current->suiv->pdata == value)
            {
                T_box current2 = current->suiv->suiv;
                free(current->suiv->pdata);
                free(current->suiv);
                current->suiv=current2;
            }
        }
        return box;
    }
}


//Permet d'obtenir le pointeur de l'élément suivant d'une liste
T_box getptrNextCell(T_box l)
{
    if (l == NULL)
    {
        return l;
    }
    if (l->suiv == NULL)
    {
        return NULL;
    }
    return l->suiv;
}


//Permet d'obtenir le pointeur de la donnée enregistrée dans ce T_box (ici nous obtiendrons un int*
int* getPtrData(T_box l)
{
    if (l == NULL)
    {
        return NULL;
    }
    return l->pdata;
}

//Permet d'échanger de position deux données d'une liste en échangeant leurs pointeurs respectifs
void swapPtrData( T_box source, T_box destination )
{
    int* mem = source->pdata;
    source->pdata=destination->pdata;
    destination->pdata=mem;
}

//Permet d'obtenir le nombre de cellules dans une liste
int getNbreCell(T_box l)
{
    if (l == NULL)
    {
        return 0;
    }
    T_box courant = l;
    int i = 1;
    while (courant->suiv != NULL)
    {
        courant = courant->suiv;
        i += 1;
    }
    return i;
}


//Permet de trier une liste selon le résultat de la fonction fcomp choisie
void tri_selection_liste(T_box l, bool (*fcomp) (int a, int b))
{
    int i,k,sizel;
    sizel = getNbreCell(l);
    T_box courant =l;
    T_box plus_petit = NULL;
    T_box j = NULL;

    for (i=0;i<sizel;i++)
    {
        plus_petit = courant;
        j = courant;
        for (k=i;k<sizel;k++)
        {

            //if (*(getPtrData (j)) < *(getPtrData(plus_petit)))
            if (fcomp(*(j->pdata),*(plus_petit->pdata)))
            {
                //printf("%d",*(getPtrData(j)));
                plus_petit = j;
            }
            j = getptrNextCell(j);
        }
        swapPtrData (courant,plus_petit);
        courant = getptrNextCell(courant);
    }
}
