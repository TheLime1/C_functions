#include <stdio.h>
#include <stdlib.h>
#include "Examen2016.h"

int main()
{
    int choix;
    int numTravASupp;
    int nbTravaux;

    pile P = NULL;
    liste L = NULL;
    travail T;

    do
    {
        do
        {
            printf("\n-------------------------------------------\n");
            printf("1. Ajouter un travail.\n");
            printf("2. Afficher la liste des travaux.\n");
            printf("3. Inserer un nouveau travail.\n");
            printf("4. Supprimer un travail.\n");
            printf("5. Empiler les travaux par temps operatoire.\n");
            printf("6. Consulter la pile.\n");
            printf("0. Quitter.");
            printf("\n-------------------------------------------\n");
            scanf("%d", &choix);
        }
        while( choix<0 || choix>6 );

        switch(choix)
        {
        case 1:
            T = saisir();
            L = ajouter_travail(L, T);
            break;

        case 2:
            nbTravaux = afficher_Liste(L);
            printf("\nnbTravaux: %d\n", nbTravaux);
            break;

        case 3:
            T = saisir();
            L = inserer_Travail(L, T);
            break;

        case 4:
            printf("\nDonner le numero du travail a supprimer: ");
            scanf("%d", &numTravASupp);
            L = supprimer_Travail(L, numTravASupp);
            break;

        case 5:
            P = empiler_Travaux(P, &L);
            break;

        case 6:
            consulter_pile(P);
            break;

        case 0:
            break;

        default:
            break;
        }
    }
    while( choix!=0 );

    libererLSC(&L);
    libererPile(&P);
    return 0;
}
