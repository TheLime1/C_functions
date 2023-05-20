#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <stdlib.h>

typedef struct date Date;
typedef struct compte Compte;
typedef struct cellule Cellule;
typedef struct listeDC LDC;
typedef struct noeud Noeud;
typedef struct noeud* Arbre;

struct date
{
     int jour;
     int mois;
     int annee;
};

struct compte
{
    int numero;             // unique
    char nom[20];
    char typeDernOp;       // R ou V
    float solde;
    Date dateDerOp;      // de la derniere maintenance
};

struct file
{
    struct cellule* tete;
    struct cellule* queu;
};

struct noeud
{
    Compte compte;
    struct noeud* pL;
    struct noeud* pR;
};

struct cellule
{
    Compte compte;
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

void saisirCompte(Compte* c);
Cellule* chercherCompte(LDC l, int num);
LDC ajouterCompte(LDC L, Compte c);
LDC LDC_ajouter_Tete(LDC L, Compte compte);
LDC LDC_ajouter_Fin(LDC L, Compte compte);
LDC LDC_ajouter_avant(LDC L, Cellule *pIndex, Compte compte);

void Operation(LDC l, int num, float montant, char operation, Date d);
void afficherCompte(LDC L);

void sauvegarderCompte(LDC L, char nomfichier[]);
void enregistrer_compte_dans_fichier_binaire(Compte c, char* nomFichier);

Arbre inserer(Arbre a, Compte c);
Arbre initialiser_noeud_compte(Compte c);
Arbre remplirArbre(Arbre a, LDC l);

void afficher(Arbre a);
int calculerNbr(Arbre a, float montant);

void LDC_liberer_iter(LDC* L);
void liberer_ABR_Rec(Arbre a);

#endif // FONCTIONS_H_INCLUDED
