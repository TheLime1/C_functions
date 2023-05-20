#include "Examen2018.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choix;
    int nbOuvrages = 0;
    int code_ouvrage = 0;
    int numAbonne = 0;
    char* nomFich = "biblio.bin";
    Abr ABR_Abonne = NULL;
    Abonne abonne;

    // où dans case 1 avec "wa"
    do
    {
        printf("\nDonner le nombre des ouvrages: ");
        scanf("%d", &nbOuvrages);
    }
    while(nbOuvrages<=0);
    Remplir_bibio(nomFich, nbOuvrages);

    do
    {
        do
        {
            printf("\n-------------------------------------------\n");
            printf("1. Inserer un abonne dans L'ABR des abonnes\n");
            printf("2. Emprunter un ouvrage.\n");
            printf("3. Afficher ABR.\n");
            printf("0. Quitter.");
            printf("\n-------------------------------------------\n");
            scanf("%d", &choix);
        }
        while( choix<0 || choix>4 );

        switch(choix)
        {
        case 1:
            Saisir_Abonne(&abonne);
            ABR_Abonne = Inserer_abonne(ABR_Abonne, abonne);
            break;

        case 2:
            printf("\nDonner le code de l'ouvrage: ");
            scanf("%d", &code_ouvrage);
            printf("\nDonner le numero d'inscription de l'abonne: ");
            scanf("%d", &numAbonne);
            Emprunter_ouvrage(ABR_Abonne, code_ouvrage, numAbonne);
            break;

        case 3:
            Afficher_ABR(ABR_Abonne);
            break;

        case 0:
            break;

        default:
            break;
        }
    }
    while( choix!=0 );

    Liberer_ABR_et_LSC(ABR_Abonne);
    return 0;
}
