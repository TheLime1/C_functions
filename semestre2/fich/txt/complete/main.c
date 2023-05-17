#include <stdio.h>
#include <stdlib.h>
#include "gateau.h"

int main()
{
    int choice = 1;
    gateau g;
    char nom_fich[] = "gateaux.txt";

    while (choice != 0)
    {
        printf("\nMenu:\n");
        printf("1. Ajouter un gâteau\n");
        printf("2. Afficher le nombre de gâteaux\n");
        printf("3. Afficher les caractéristiques du gâteau de la ligne 1\n");
        printf("0. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            saisir_gateau(&g);
            ajouter_gateau_ft(g, nom_fich);
            break;
        case 2:
            printf("Le nombre de gâteaux est: %d\n", nbre_gateaux_ft(nom_fich));
            break;
        case 3:
            afficher_gateau(nom_fich, 1);
            break;
        case 0:
            printf("Au revoir!\n");
            break;
        default:
            printf("Choix non valide!\n");
            break;
        }
    }
    return 0;
}