#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    Noeud *racine = NULL;
    int choix, donnee;

    while (1)
    {
        printf("\n--- Menu ---\n");
        printf("1. Insérer un nœud\n");
        printf("2. Parcours préfixe\n");
        printf("3. Parcours infixe\n");
        printf("4. Parcours postfixe\n");
        printf("5. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            printf("Entrez la valeur du nœud à insérer : ");
            scanf("%d", &donnee);
            racine = insererNoeud(racine, donnee);
            printf("Nœud inséré avec succès.\n");
            break;
        case 2:
            printf("Parcours préfixe: ");
            parcoursPrefixe(racine);
            printf("\n");
            break;
        case 3:
            printf("Parcours infixe: ");
            parcoursInfixe(racine);
            printf("\n");
            break;
        case 4:
            printf("Parcours postfixe: ");
            parcoursPostfixe(racine);
            printf("\n");
            break;
        case 5:
            printf("Au revoir!\n");
            exit(0);
        default:
            printf("Choix invalide. Veuillez réessayer.\n");
            break;
        }
    }

    return 0;
}
