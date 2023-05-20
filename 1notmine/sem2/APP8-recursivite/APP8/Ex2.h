#ifndef EX2_H_INCLUDED
#define EX2_H_INCLUDED

// Ex2
typedef struct
{
    char nom[10];
    float moyenne;
} Etudiant;

struct cellule
{
    Etudiant et;
    struct cellule* suiv;
};

typedef struct cellule* liste;

void afficher_liste(liste l);
void afficher_liste_inverse(liste l);
liste ajouter_etudiant(liste l, Etudiant E);
liste supprimer_etudiant(liste l, char *nom);

struct cellule* newNode(Etudiant E);
void freeLC(liste l);

#endif // EX2_H_INCLUDED
