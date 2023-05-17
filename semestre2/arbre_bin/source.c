#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Créer un nouveau nœud de l'arbre binaire
Noeud *creerNoeud(int donnee)
{
    Noeud *nouveauNoeud = (Noeud *)malloc(sizeof(Noeud));
    nouveauNoeud->donnee = donnee;
    nouveauNoeud->gauche = NULL;
    nouveauNoeud->droit = NULL;
    return nouveauNoeud;
}

// Insérer un nœud dans l'arbre binaire
Noeud *insererNoeud(Noeud *racine, int donnee)
{
    if (racine == NULL)
    {
        racine = creerNoeud(donnee);
    }
    else if (donnee <= racine->donnee)
    {
        racine->gauche = insererNoeud(racine->gauche, donnee);
    }
    else
    {
        racine->droit = insererNoeud(racine->droit, donnee);
    }
    return racine;
}

// Parcours préfixe de l'arbre binaire
void parcoursPrefixe(Noeud *racine)
{
    if (racine == NULL)
    {
        return;
    }
    printf("%d ", racine->donnee);
    parcoursPrefixe(racine->gauche);
    parcoursPrefixe(racine->droit);
}

// Parcours infixe de l'arbre binaire
void parcoursInfixe(Noeud *racine)
{
    if (racine == NULL)
    {
        return;
    }
    parcoursInfixe(racine->gauche);
    printf("%d ", racine->donnee);
    parcoursInfixe(racine->droit);
}

// Parcours postfixe de l'arbre binaire
void parcoursPostfixe(Noeud *racine)
{
    if (racine == NULL)
    {
        return;
    }
    parcoursPostfixe(racine->gauche);
    parcoursPostfixe(racine->droit);
    printf("%d ", racine->donnee);
}

int main()
{
    Noeud *racine = NULL;

    // Insertion des nœuds dans l'arbre binaire
    racine = insererNoeud(racine, 4);
    racine = insererNoeud(racine, 2);
    racine = insererNoeud(racine, 6);
    racine = insererNoeud(racine, 1);
    racine = insererNoeud(racine, 3);

    // Parcours préfixe de l'arbre binaire
    printf("Parcours préfixe: ");
    parcoursPrefixe(racine);
    printf("\n");

    // Parcours infixe de l'arbre binaire
    printf("Parcours infixe: ");
    parcoursInfixe(racine);
    printf("\n");

    // Parcours postfixe de l'arbre binaire
    printf("Parcours postfixe: ");
    parcoursPostfixe(racine);
    printf("\n");

    return 0;
}
