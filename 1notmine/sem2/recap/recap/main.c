#include "fichiersBinaires.h"
#include "fichiersTexte.h"
#include "LSC.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choix = -1;
    char* nomFich = "fichier.bin";

    Pile P = NULL;
    File file = initialiser();
    LSC L = NULL;
    abr ABR_Abonne = NULL;

    // declarer les tableau
    // remplir les tableaux/fichiers,
    // si l'énoncer le demande
//    int n = nbVgr = 0;
//    voyageur* TabVgr;
//    do
//    {
//        printf("\nDonner le nombre des voyageurs: ");
//        scanf("%d", &nbVgr);
//    }
//    while(nbVgr<=0);
//    TabVgr = charger_donnees(nomFichier, &nbVgr);

    do
    {
        do
        {
            printf("\n-------------------------------------------\n");
            printf("1. .\n");
            printf("2. .\n");
            printf("3. .\n");
            printf("4. .\n");
            printf("5. .\n");
            printf("6. .\n");
            printf("0. Quitter.");
            printf("\n-------------------------------------------\n");
            scanf("%d", &choix);
        }
        while( choix<0 || choix>6 );

        switch(choix)
        {
        case 1:

            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

            break;

        case 6:

            break;

        case 0:
            break;

        default:
            break;
        }
    }
    while( choix!=0 );


    freeABR_Rec(ABR_Abonne);
    libererLSC(&L);
    libererPile(&P);
    // liberer
    // verifier les modes d'ouverture des fichiers
    return 0;
}
