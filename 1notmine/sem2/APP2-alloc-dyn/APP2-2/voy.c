#include "voy.h"

void saisirVoyageur(Voyageur * ptv)
{
    printf("Donner l id: ");
    scanf("%s", ptv->id);
    printf("donner le nom: ");
    scanf("%s", ptv->nom);
    printf("donner addr: ");
    fflush(stdin);
    gets(voy->addr);
    printf("donner le nb des voyages: ");
    scanf("%d", &voy->nbVoy);
}

void saisirVoyageur (voyageur * ptv);
voyageur * charger_donnees (void sauvegarder_donnees (char nomFich[], Voyageur * tab, int n);
int trouver(voyageur * tab, char id[], int n);
voyageur * ajouter (Voyageur v, voyageur * tab, int * n);
void supprimer (voyageur * tab , char id[], int * n);
void liberer (voyageur * tab);
