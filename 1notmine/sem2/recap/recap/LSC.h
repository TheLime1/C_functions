#ifndef LSC_H_INCLUDED
#define LSC_H_INCLUDED
#include "general.h"

typedef struct Cellule* LSC;

struct Cellule
{
    Exemple_struct structure;
    struct Cellule* suivant;
};

int LSC_vide(LSC liste);

// Parcourir et afficher
void LSC_parcours(LSC pListe, int* nbCellules);

LSC LSC_ajouter_debut(LSC pListe, Exemple_struct structure);

LSC LSC_ajouter_Fin(LSC pListe, Exemple_struct structure);

int LSC_rechercher_int(LSC pListe, int num);

LSC LSC_ajouter_Apres(LSC pListe, Exemple_struct structure, int num);

LSC LSC_ajouter_Avant(LSC pListe, Exemple_struct structure, int num);

// supprimer au debut ou au mileu ou à la fin
// cette fonction ne fait pas appel à aucune autre fonction
void LSC_supprimer_int(LSC pListe, int key);

LSC LSC_supprimer_Debut(LSC pListe);

LSC LSC_supprimer_Fin(LSC pListe);

LSC LSC_supprimer_Milieu(LSC pListe, int num);

LSC LSC_liberer(LSC liste);


#endif // LSC_H_INCLUDED
