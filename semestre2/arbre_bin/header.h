#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

// Définition de la structure d'un nœud de l'arbre binaire
typedef struct Noeud
{
    int donnee;
    struct Noeud *gauche;
    struct Noeud *droit;
} Noeud;

// Prototypes de fonctions
Noeud *creerNoeud(int donnee);
Noeud *insererNoeud(Noeud *racine, int donnee);
void parcoursPrefixe(Noeud *racine);
void parcoursInfixe(Noeud *racine);
void parcoursPostfixe(Noeud *racine);

#endif
