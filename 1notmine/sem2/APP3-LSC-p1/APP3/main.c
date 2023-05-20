#include <stdio.h>
#include <stdlib.h>
#include "wagons.h"

int main()
{
    int choix, numWagon, nbWagons = 0;
    Wagon wagon;

    Train train = NULL;

    do
    {
        do
        {
            printf("\n------------------------------\n");
            printf("1. Ajouter une locomotive en tete du train.\n");
            printf("2. Ajouter un wagon a la queue dutrain.\n");
            printf("3. Rechercher un wagon.\n");
            printf("4. Afficher le train.\n");
            printf("0. Quitter.");
            printf("\n------------------------------\n");
            scanf("%d", &choix);
        }while( choix<0 || choix>4 );

        switch(choix)
        {
            // Ajouter locomotive
            case 1:
                wagon = saisirWagon(wagon);
                train = ajouterLocomotive(train, wagon);
                afficherTrain(train, &nbWagons);
                printf("\nnbWagons: %d", nbWagons);
                break;

            // Ajouter wagon
            case 2:
                wagon = saisirWagon(wagon);
                train = ajouterFin(train, wagon);
                afficherTrain(train, &nbWagons);
                printf("\nnbWagons: %d", nbWagons);
                break;

            // Rechercher
            case 3:
                printf("Donner le numero du wagon a rechercher: ");
                scanf("%d", &numWagon);
                rechercherWagon(train, numWagon);
                break;

            // Afficher train
            case 4:
                afficherTrain(train, &nbWagons);
                printf("\nnbWagons: %d", nbWagons);
                break;

            case 0:
                break;

            default:
                break;
        }
    }while( choix!=0 );

    return 0;
}
