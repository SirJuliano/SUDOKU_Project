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

bool isEmpty(T_box box)
{
    if (box == NULL)
    {
        return true;
    }
    else return false;
}




//Permet l'ajout d'un nouvel élément à la fin d'une liste
T_box ajoutEnFin(T_box box, int mydata)
{
    T_box nouv = (T_box)malloc(sizeof(struct T_box_possibilities));
    nouv->pdata = (int*)malloc(sizeof(int));
    *(nouv->pdata)= mydata;

    if (box==NULL)
    {
        nouv->suiv=NULL;
        return nouv;
    }
    else
    {
        T_box courant = box;
        while (courant->suiv != NULL)
        {
            courant = courant->suiv;
        }
        nouv->suiv=NULL;
        courant->suiv=nouv;
        return box;
    }
}

T_box fillList(T_box box, int length)
{
    for (int i = 1; i<length + 1; i++)
    {
        box = ajoutEnFin(box, i);
    }
    return box;
}

//Permet de supprimer le premier élément d'une liste (elle vérifie avant s'il y en a bien un)
T_box deleteValue(T_box box, int value)
{
    if ((box) == NULL)
    {
        return box;
    }
    else{
        T_box current = box;
        while (current != NULL)
        {
            if (*current->suiv->pdata == value)
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

T_box suppEnTete(T_box box)
{
    if (box == NULL)
    {
        return box;
    }

    T_box current = box->suiv;
    free(box->pdata);
    free(box);
    return current;

}

void deleteList(T_box box, int size)
{
    for (int i = 0; i < size; i++)
        box = suppEnTete(box);
}

//Permet d'obtenir le pointeur de l'élément suivant d'une liste
T_box getptrNextCell(T_box box)
{
    if (box == NULL)
    {
        return box;
    }
    if (box->suiv == NULL)
    {
        return NULL;
    }
    return box->suiv;
}


//Permet d'obtenir le pointeur de la donnée enregistrée dans ce T_box (ici nous obtiendrons un int*
int* getPtrData(T_box box)
{
    if (box == NULL)
    {
        return NULL;
    }
    return box->pdata;
}

//Permet d'obtenir le nombre de cellules dans une liste
int getNbreCell(T_box box)
{
    if (box == NULL)
    {
        return 0;
    }
    T_box courant = box;
    int i = 1;
    while (courant->suiv != NULL)
    {
        courant = courant->suiv;
        i += 1;
    }
    return i;
}

void showList(T_box box)
{
    T_box current = box;

    if (!isEmpty(current))
    {
        int i = 0;
        while (current != NULL)
        {
            printf("L[%d] = %d\n", i, *current->pdata);
            current = current->suiv;
            i ++;
        }
    }
}

bool foundData(T_box box, int value)     //Peut etre return le pointeur du data found(sinon NULL)
{
    if (box == NULL)
    {
        return false;
    }
    T_box current = box;
    while (current != NULL)
    {
        
        if (current->pdata == value)
        {
            return true;
        }
        current  = getptrNextCell(current);
        }
        return false;
}