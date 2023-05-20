#ifndef LDC_H_INCLUDED
#define LDC_H_INCLUDED
#include "general.h"

typedef struct cellule Cellule;
typedef struct listeDC LDC;

struct cellule
{
    Exemple_struct structure;
    struct cellule* suiv;
    struct cellule* prec;
};

struct listeDC
{
    Cellule* tete;
    Cellule* queu;
};


LDC LDC_init(LDC L);

int LDC_vide(LDC L);

Exemple_struct* LDC_chercher_int(LDC L, int num);
Cellule* chercher_structure(LDC L);

LDC LDC_ajouter_en_ordre_croissant(LDC L, Exemple_struct structure);

LDC LDC_ajouter_Tete(LDC L, Exemple_struct structure);

LDC LDC_ajouter_Fin(LDC L, Exemple_struct structure);

LDC LDC_ajouter_avant(LDC L, Cellule *pIndex, Exemple_struct structure);

LDC LDC_ajouter_apres(LDC L, Cellule *pC, Exemple_struct Exemple_struct);

LDC supp_queu_LDC(LDC L);

LDC supp_tete_LDC(LDC L);

LDC supp_1ereOcc_LDC(LDC L, Cellule* pC);

LDC supp_structure(LDC L);

LDC supp_element(LDC L);

Cellule* chercher_structure(LDC L);

void LDC_afficher(LDC L);

void LDC_liberer_iter(LDC* L);


#endif // LDC_H_INCLUDED
