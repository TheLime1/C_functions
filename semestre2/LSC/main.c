#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    liste l = NULL;
    int choice, value, data;

    do
    {
        printf("Menu:\n");
        printf("1. Ajouter un element en tete\n");
        printf("2. Ajouter un element en fin\n");
        printf("3. Ajouter un element avant une donnee\n");
        printf("4. Supprimer l'element en tete\n");
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
            printf("Entrez la valeur a ajouter en fin: ");
            scanf("%d", &value);
            l = ajouter_fin(l, value);
            break;
        case 3:
            printf("Entrez la valeur a ajouter: ");
            scanf("%d", &value);
            printf("Entrez la donnee avant laquelle ajouter: ");
            scanf("%d", &data);
            l = ajouter_avant(l, value, data);
            break;
        case 4:
            l = supprimer_tete(l);
            break;
        case 5:
            afficher_liste(l);
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
