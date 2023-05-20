#ifndef VOYAGEURS_H_INCLUDED
#define VOYAGEURS_H_INCLUDED

typedef struct
{
    char ID[10];
    char nom[10];
    char adresse[20];
    int nbVoyages;
} voyageur;


int nbVoyageurs(char nomFich[]);
void saisirVoyageur(voyageur* ptv);
voyageur* charger_donnees(char nomFich[], int * n);
void sauvegarder_donnees(char nomFich[], voyageur* tab, int n);
int trouver(voyageur* tab, char id[], int n);
voyageur* ajouter(voyageur v, voyageur* tab, int* n);
void supprimer(voyageur* tab ,char id[], int* n);
void liberer(voyageur* tab);

void afficherFichier(char nomFich[]);
void afficherTab(voyageur* tab, int n);

#endif // VOYAGEURS_H_INCLUDED
