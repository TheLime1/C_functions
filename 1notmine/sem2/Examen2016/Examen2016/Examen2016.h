#ifndef EXAMEN2016_H_INCLUDED
#define EXAMEN2016_H_INCLUDED

typedef struct travail travail;
typedef struct cellule* liste;
typedef struct cellule* pile;

struct travail
{
    int num;
    int tempsOp;
    char code[10];
};

struct cellule
{
    travail trav;
    struct cellule* suiv;
};

travail saisir();
liste ajouter_travail(liste L, travail T);

int afficher_Liste(liste L);

liste inserer_Travail(liste L, travail T);

liste supprimer_Travail(liste L, int numero);

travail max_temps_op(liste L);

pile empiler_Travaux(pile P, liste *L);

void consulter_pile(pile P);
int pile_vide(pile P);

void libererLSC(liste *L);
void libererPile(pile *pile);
pile depiler(pile p);

#endif // EXAMEN2018_H_INCLUDED
