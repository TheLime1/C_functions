#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Ex2.h"

void afficher_liste(liste l)
{
    if( !l )
        return;

    printf("\nnom: %s", l->et.nom);
    printf("\nmoyenne: %.2f\n", l->et.moyenne);
    afficher_liste(l->suiv);
}


void afficher_liste_inverse(liste l)
{
    if( !l )
        return;

    afficher_liste_inverse(l->suiv);
    printf("\nnom: %s", l->et.nom);
    printf("\nmoyenne: %.2f\n", l->et.moyenne);
}

liste ajouter_etudiant(liste l, Etudiant E)
{
    if( !l )
        l = newNode(E);
    else
        l->suiv = ajouter_etudiant(l->suiv, E);

    return l;
}

struct cellule* newNode(Etudiant E)
{
    struct cellule* nouv;
    nouv = (struct cellule*)malloc(sizeof(struct cellule));
    nouv->et = E;
    nouv->suiv = NULL;

    return nouv;
}

liste supprimer_etudiant(liste l, char *nom)
{
    if( !l )
    {
        printf("\nAucun Etudiant avec le nom \"%s\"", nom);
        return l;
    }

    if( strcmp( l->et.nom, nom) == 0 )
    {
        struct cellule* temp = l->suiv;
        free(l);
        printf("\nSuppression de l'etudiant/e \"%s\"...\n", nom);
        return temp;
    }

    l->suiv = supprimer_etudiant(l->suiv, nom);

    return l;
}

void freeLC(liste l)
{
    if ( l == NULL )
        return;

    freeLC(l->suiv);
    free(l);
}
