#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    Pile *pile = creerPile();
    int choix, donnee;

    while (1)
    {
        printf("\n--- Menu ---\n");
        printf("1. Empiler un élément\n");
        printf("2. Dépiler un élément\n");
        printf("3. Consulter l'élément en haut de la pile\n");
        printf("4. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            printf("Entrez la valeur à empiler : ");
            scanf("%d", &donnee);
            empiler(pile, donnee);
            break;
        case 2:
            depiler(pile);
            break;
        case 3:
            printf("Élément en haut de la pile : %d\n", consulterSommet(pile));
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
