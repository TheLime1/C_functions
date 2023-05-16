#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

void liste_vide(liste l)
{
    if (l = NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void afficher_liste(liste l)
{
    if (liste_vide(l) == 1)
    {
        printf("liste vide");
    }
    else
    {
        while (l != NULL)
        {
            printf("%d", l->valeur);
            l = l->suivant;
        }
    }
}

liste ajouter_tete(liste l, int val)
{
    struct liste *nouv;
    nouv = (liste)malloc(sizeof(cellule));
    nouv->valeur = val;
    nouv->suivant = NULL;
    if (liste_vide(nouv) == 1)
    {
        l = nouv;
    }
    else
    {
        nouv->suivant = l;
        l = nouv;
    }
    return l;
}

liste ajouter_fin(liste l, int val)
{
    struct liste *nouv, *parcour;
    nouv = (liste)malloc(sizeof(cellule));
    nouv->valeur = val;
    nouv->suivant = NULL;
    if (liste_vide(l) == 1)
    {
        l = nouv;
    }
    else
    {
        parcour = l;
        while (parcour->suivant != NULL)
        {
            parcour = parcour->suivant;
        }
        parcour->suivant = nouv;
    }
    return l;
}

liste ajouter_avant(liste l, int val, int donnee)
{
    // add an element (val) before donnee in the list
    struct liste *nouv, *precedant, *courant;
    nouv = (liste)malloc(sizeof(cellule));
    nouv->valeur = val;
    nouv->suivant = NULL;
    if (liste_vide(l) == 1)
    {
        l = nouv;
    }
    else
    {
        courant = l;
        while (courant->valeur != donnee && courant != NULL)
        {
            precedant = courant;
            courant = courant->suivant;
        }
        if (courant == NULL)
        {
            printf("donnee non trouvee");
        }
        else
        {
            precedant->suivant = nouv;
            nouv->suivant = courant;
        }
    }
    return l;
}

liste supprimer_tete(liste l)
{
    struct liste *supp;
    if (liste_vide(l) == 1)
    {
        printf("liste vide");
    }
    else
    {
        supp = l;
        l = l->suivant;
        supp->suivant = NULL;
        free(supp);
    }
    return l;
}