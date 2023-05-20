#include <stdio.h>
#include <stdlib.h>
#include "telepherique.h"

int main()
{
    int choix, capTot;
    Cabine cabine;
    LDC L = init_telepherique(L);

    do
    {
        do
        {
            printf("\n-------------------------------------------\n");
            printf("1. Ajouter une cabine.\n");
            printf("2. Supprimer la premiere cabine en panne.\n");
            printf("3. MAJ telepherique.\n");
            printf("4. Afficher telepherique.\n");
            printf("0. Quitter.\n");
            printf("\n-------------------------------------------\n");
            scanf("%d", &choix);
        }
        while( choix<0 || choix>4 );

        switch(choix)
        {
        // Ajouter une cabine
        case 1:
            cabine = saisir_cabine();
            L = ajouter_cabine(L, cabine);
            break;

        // Supprimer la premier cabine en panne
        case 2:
            L = supp_cabine(L);
            break;

        // MAJ tel.
        case 3:
            MAJ_telepherique(L);
            break;

        // Afficher le tel.
        case 4:
            capTot = afficher_telepherique(L);
            break;

        case 0:
            break;

        default:
            break;
        }
    }
    while( choix!=0 );

    L = vider_telepherique(L);
    return 0;
}
