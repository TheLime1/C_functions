#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef cellule
{
    int valeur;
    struct cellule *suivant;
};

typedef struct cellule *liste;
int liste_vide(liste l);
void afficher_liste(liste l);
liste ajouter_tete(liste l, int val);
liste ajouter_fin(liste l, int val);
liste ajouter_avant(liste l, int val, int donnee);
#endif
