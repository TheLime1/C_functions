#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

LDC initialiser_LDC(LDC l)
{
    l.tete = NULL;
    l.queue = NULL;
    return l;
}

int liste_vide(LDC l)
{
    return (l.tete == NULL && l.queue == NULL);
}

void afficher_queue(LDC l)
{
    struct cellule *p;
    if (liste_vide(l))
    {
        printf("La liste est vide");
    }
    else
    {
        p = l.queue;
        while (p != NULL)
        {
            printf("%d ", p->valeur);
            p = p->suiv;
        }
    }
}

LDC ajouter_tete(LDC l, int val)
{
    struct cellule *p;
    p = (struct cellule *)malloc(sizeof(struct cellule));
    p->valeur = val;
    p->suiv = NULL;
    p->prec = NULL;
    if (liste_vide(l))
    {
        l.queue = p;
    }
    else
    {
        p->suiv = l.tete;
        l.tete->prec = p;
    }
    l.tete = p;
    return l;
}

LDC ajouter_queue(LDC l, int val)
{
    struct cellule *p;
    p = (struct cellule *)malloc(sizeof(struct cellule));
    p->valeur = val;
    p->suiv = NULL;
    p->prec = NULL;
    if (liste_vide(l))
    {
        l.tete = p;
    }
    else
    {
        p->prec = l.queue;
        l.queue->suiv = p;
    }
    l.queue = p;
    return l;
}

LDC ajouter_milieu(LDC L, int x, int y)
{
    cellule *parc; // parcour
    cellule *nouv; // nouveau
    parc = L.tete;
    // rechercher de laddrese de y
    while (parc != NULL && parc->valeur != y)
    {
        parc = parc->suiv;
        if (parc)
        {
            if (parc == L.tete)
            {
                L = ajouter_tete;
            }
            else
            {
                nouv = (cellule *)malloc(sizeof(cellule));
                nouv->val = x;
                nouv->suiv = parc;
                nouv->prec = parc->prec;
                (parc->prec)->suiv = nouv;
                (parc->prec) = nouv;
            }
        }
    }
}

LDC supp_val(LDC L, int a)
{
    cellule *supp, *parc;
    parc L.queue;
    while (parc != NULL && parc->val != a)
    {
        parc = parc->prec if (parc)
        {
            if (parc == L.queue)
            {
                L = supp_queue(L, a) // add supp_qu
            }
            else
            {
                (parc->suiv)->prec = parc->prec;
                (parc->prec)->suiv = parc->suiv;
                free(supp);
            }
        }
    }
}