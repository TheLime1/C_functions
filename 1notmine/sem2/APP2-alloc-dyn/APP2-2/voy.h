#ifndef VOY_H_INCLUDED
#define VOY_H_INCLUDED
#include <stdio.h>

typedef struct
{
    int nbVoy;
    char id[10];
    char nom[10];
    char addr[10];
} Voyageur;

int nbVoyageurs(char nomFich[]);
void saisirVoyageur (Voyageur * ptv);
Voyageur * charger_donnees (void sauvegarder_donnees (char nomFich[], Voyageur * tab, int n);
int trouver(Voyageur * tab, char id[], int n);
Voyageur * ajouter (Voyageur v, Voyageur * tab, int * n);
void supprimer (Voyageur * tab , char id[], int * n);
void liberer (Voyageur * tab);


#endif // VOY_H_INCLUDED
