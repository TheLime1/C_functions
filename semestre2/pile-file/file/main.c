#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    File *file = creerFile();
    int choix, donnee;

    while (1)
    {
        printf("\n--- Menu ---\n");
        printf("1. Enfiler un élément\n");
        printf("2. Défiler un élément\n");
        printf("3. Consulter la tête de la file\n");
        printf("4. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            printf("Entrez la valeur à enfiler : ");
            scanf("%d", &donnee);
            enfiler(file, donnee);
            break;
        case 2:
            defiler(file);
            break;
        case 3:
            printf("Élément en tête de la file : %d\n", consulterTete(file));
            break;
        case 4:
            printf("Au revoir!\n");
            exit(0);
        default:
            printf("Choix invalide. Veuillez réessayer.\n");
            break;
        }
    }

    return 0;
}
