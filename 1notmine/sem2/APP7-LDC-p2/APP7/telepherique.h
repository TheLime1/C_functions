#ifndef TELEPHERIQUE_H_INCLUDED
#define TELEPHERIQUE_H_INCLUDED

typedef struct cabine Cabine;
typedef struct cellule Cellule;
typedef struct listeDC LDC;
typedef struct date Date;

struct date
{
    int jour;
    int mois;
    int annee;
};

struct cabine
{
    int num;    // not unique
    int capacite;
    Date date;
    int etat; // 1 out 0
};

struct cellule
{
    Cabine cabine;
    struct cellule* suiv;
    struct cellule* prec;
};

struct listeDC
{
    Cellule* tete;
    Cellule* queu;
};

LDC init_telepherique(LDC L);
Cabine saisir_cabine();
Cellule* chercher_cabine(LDC L);
LDC ajouter_cabine(LDC L, Cabine cabine);
int afficher_telepherique(LDC L);
LDC supp_cabine(LDC L);
void MAJ_telepherique(LDC L);
LDC vider_telepherique(LDC L);

// helper function
int listeDC_vide(LDC L);
LDC ajouter_tete(LDC L, Cabine cabine);
LDC ajouter_queue(LDC L, Cabine cabine);
LDC ajouter_apres(LDC L, Cellule *pC, Cabine cabine);
LDC supp_tete_LDC(LDC L);
LDC supp_queu_LDC(LDC L);
LDC supp_1ereOcc_LDC(LDC L, Cellule* pC);

#endif // TELEPHERIQUE_H_INCLUDED
