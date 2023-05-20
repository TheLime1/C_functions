#include <stdio.h>
#include <stdlib.h>
#include "wagons.h"

int main()
{
    int choix, numWagon, nbWagons = 0;
    Wagon wagon;
    Train train = NULL;
    char* fileName = "logFile.txt";

    do
    {
        do
        {
            printf("\n------------ Partie 1 ---------------------\n");
            printf("1. Ajouter une locomotive en tete du train.\n");
            printf("2. Ajouter un wagon a la queue du train.\n");
            printf("3. Rechercher un wagon.\n");
            printf("4. Afficher le train.\n");
            printf("------------ Partie 2 ---------------------\n");
            printf("5. Supprimer les wagons dont l'etat est en panne.\n");
            printf("6. Ajouter un wagon apres le numero du wagon donne en parametre.\n");
            printf("7. Libere la memoire occupe par tous les wagons.\n");
            printf("8. Afficer l historique des modifications (logFile.txt).\n");
            printf("0. Quitter.");
            printf("\n-------------------------------------------\n");
            scanf("%d", &choix);
        }while( choix<0 || choix>8 );

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

            // Partie 2 ------------------------------------
            // Supprimer les wagons en panne
            case 5:
                while( wagonPanneExiste(train) )
                    train = supprimerWagonPanne(train);

                afficherTrain(train, &nbWagons);
                journal(fileName, "Suppression des wagons en pannes");
                break;

            // ajouter un wagon aprés un autre
            case 6:
                afficherTrain(train, &nbWagons);
                printf("\nDonner les informations du wagon a inserer:\n");
                wagon = saisirWagon(wagon);
                printf("\nInserer apres le wagon avec le numero: ");
                scanf("%d", &numWagon);

                train = ajouterApres(train, wagon, numWagon);
                afficherTrain(train, &nbWagons);
                journal(fileName, "Ajout d'un wagon apres le numero du wagon donne en parametre.");
                break;

            // clear list from memory
            case 7:
                train = supprimerListe(train);
                afficherTrain(train, &nbWagons);
                journal(fileName, "Liberation de la memoire occupee par tous les wagons.");
                break;

            case 8:
                afficherJournal(fileName);
                break;

            case 0:
                break;

            default:
                break;
        }
    }while( choix!=0 );

    return 0;
}
