#include <stdio.h>
#include <stdlib.h>
#include "even.h"

int main()
{
    int nbEmployes;
    char* nomFichier = "nombre_enfants.txt";
    char* binNomFichier = "nbEnfants.bin";
    employe* employes;

    printf("Donner le nombres des employes: ");
    scanf("%d", &nbEmployes);

    employes = malloc(nbEmployes * sizeof(employe));

    for(int i=0; i<nbEmployes; i++)
        *(employes+i) = saisirEmp();

    binEnregsitrer(binNomFichier, employes, nbEmployes);
    binChercher(binNomFichier, "test");

//    enregisrter(nomFichier, employes, nbEmployes);
//    chercher(nomFichier, "test");

//    afficherNPlus(nomFichier, 3);
//
//    supprimer(nomFichier);

    free(employes);
    return 0;
}
