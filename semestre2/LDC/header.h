#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct cellule
{
    int valeur;
    struct cellule *suiv;
    struct cellule *prec;
} cellule;

typedef struct ldc
{
    struct cellule *tete;
    struct cellule *queue;
} ldc;

typedef struct ldc LDC;

LDC initialiser_LDC(LDC l);
int liste_vide(LDC l);
void afficher_queue(LDC l);
LDC ajouter_tete(LDC l, int val);
LDC ajouter_queue(LDC l, int val);

#endif
