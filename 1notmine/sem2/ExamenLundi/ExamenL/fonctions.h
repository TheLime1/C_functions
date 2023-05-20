#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <stdlib.h>

typedef struct date Date;
typedef struct scooter Scooter;
typedef struct cellule Cellule;
typedef struct cellule* Liste;
typedef struct file File;
typedef struct noeud* Arbre;

struct date
{
     int jour;
     int mois;
     int annee;
};

struct scooter
{
    char ID[20];    // unique
    int etat;       // 0 ou 1:disponible
    float kilometrage; // >= 0
    Date date;      // de la derniere maintenance
};

struct cellule
{
    Scooter scoot;
    struct cellule* suiv;
};

struct file
{
    struct cellule* tete;
    struct cellule* queu;
};

struct noeud
{
    Scooter scoot;
    struct noeud* pL;
    struct noeud* pR;
};



int FileEstVide(File f);
File initialiser();
void saisirScooter(Scooter* s);
Cellule* chercherScooter(Liste l, char id[]);
Liste ajouterScooter(Liste l, Scooter s);
void louerScooter(Liste l, char id[]);
void afficherScooter(Liste l, char nomFichier[]);
void afficherInfoScooter(Scooter s);
void ajouter_scooter_dans_fich(char* fileName, Scooter s);
File enfilerScooter(Liste l, File f, char id[]);
void entretenirScooter(File* f, Liste l);
void defilerScooter(File *f);
Arbre insererScooters(Arbre A, Scooter s);
Arbre initialiser_espace_Scooter(Scooter s);
Arbre construireArbre(Arbre a, Liste l);
Arbre maxScooter(Arbre a);

void afficher_ABR(Arbre a);

void liberer_ABR_Rec(Arbre a);
Liste liberer_LSC(Liste liste);
void libererFile(File* f);

#endif // FONCTIONS_H_INCLUDED
