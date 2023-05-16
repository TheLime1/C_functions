#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    LDC l;
    l = initialiser_LDC(l);
    int choice, value, x, y;

    do
    {
        printf("Menu:\n");
        printf("1. Ajouter un element en tete\n");
        printf("2. Ajouter un element en queue\n");
        printf("3. Ajouter un element apres une valeur\n");
        printf("4. Supprimer une valeur\n");
        printf("5. Afficher la liste\n");
        printf("0. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Entrez la valeur a ajouter en tete: ");
            scanf("%d", &value);
            l = ajouter_tete(l, value);
            break;
        case 2:
            printf("Entrez la valeur a ajouter en queue: ");
            scanf("%d", &value);
            l = ajouter_queue(l, value);
            break;
        case 3:
            printf("Entrez la valeur a ajouter: ");
            scanf("%d", &x);
            printf("Entrez la valeur apres laquelle ajouter: ");
            scanf("%d", &y);
            l = ajouter_milieu(l, x, y);
            break;
        case 4:
            printf("Entrez la valeur a supprimer: ");
            scanf("%d", &value);
            l = supp_val(l, value);
            break;
        case 5:
            afficher_queue(l);
            break;
        case 0:
            printf("Au revoir!\n");
            break;
        default:
            printf("Choix invalide!\n");
        }

        printf("\n");

    } while (choice != 0);

    return 0;
}
