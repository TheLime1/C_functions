#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct NoeudPile
{
    int donnee;
    struct NoeudPile *suivant;
} NoeudPile;

typedef struct Pile
{
    NoeudPile *sommet;
} Pile;

Pile *creerPile();
int estVide(Pile *pile);
void empiler(Pile *pile, int donnee);
void depiler(Pile *pile);
int consulterSommet(Pile *pile);

#endif
