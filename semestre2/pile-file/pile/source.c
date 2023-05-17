#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Pile *creerPile()
{
    Pile *pile = (Pile *)malloc(sizeof(Pile));
    pile->sommet = NULL;
    return pile;
}

int estVide(Pile *pile)
{
    return (pile->sommet == NULL);
}

void empiler(Pile *pile, int donnee)
{
    NoeudPile *nouveauNoeud = (NoeudPile *)malloc(sizeof(NoeudPile));
    nouveauNoeud->donnee = donnee;
    nouveauNoeud->suivant = pile->sommet;
    pile->sommet = nouveauNoeud;
    printf("Élément %d empilé dans la pile.\n", donnee);
}

void depiler(Pile *pile)
{
    if (estVide(pile))
    {
        printf("La pile est vide. Impossible de dépiler un élément.\n");
        return;
    }
    NoeudPile *temp = pile->sommet;
    pile->sommet = pile->sommet->suivant;
    int elementDepile = temp->donnee;
    free(temp);
    printf("Élément %d dépilé de la pile.\n", elementDepile);
}

int consulterSommet(Pile *pile)
{
    if (estVide(pile))
    {
        printf("La pile est vide. Impossible de consulter un élément.\n");
        return -1;
    }
    return pile->sommet->donnee;
}

int main()
{
    Pile *pile = creerPile();

    empiler(pile, 10);
    empiler(pile, 20);
    empiler(pile, 30);

    printf("Élément en haut de la pile : %d\n", consulterSommet(pile));

    depiler(pile);
    depiler(pile);
    depiler(pile);

    return 0;
}
