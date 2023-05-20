#include <stdio.h>
#include <stdlib.h>
#include "EvenEnfant.h"

int main()
{
    char* nomFichier = "nombre_enfants.txt";
    char* BINnomFichier = "nombre_enfants.bin";
    char prenomEmploye[20];

//    enregistrerInfo(NomFichier);
//    printf("Donner le prenom de l employe a rechercher: ");
//    scanf("%s", prenomEmploye);
//    chercherEmploye(NomFichier, prenomEmploye);
//    afficherEmployeNPlus(NomFichier, 3);
//    supprimerEmploye0enfants(NomFichier);

    enregistrerInfoBIN(BINnomFichier);
    printf("Donner le prenom de l employe a rechercher: ");
    scanf("%s", prenomEmploye);
    chercherEmployeBIN(BINnomFichier, prenomEmploye);
    afficherEmployeNPlusBIN(BINnomFichier, 3);
    supprimerEmploye0enfantsBIN(BINnomFichier);

    return 0;
}
