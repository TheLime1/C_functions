#include <stdio.h>
#include <stdlib.h>
#include "escalade.h"

int main()
{
    int choix;
    Station station;
    LDC L = init_chemin(L);

    do
    {
        do
        {
            printf("\n------------ Partie 1 ---------------------\n");
            printf("1. Ajouter une station.\n");
            printf("2. Afficher le chemin de la competition.\n");
            printf("3. Mettre a jour tous les stations.\n");
            printf("4. Afficher les scores des quatres alipinistes.\n");
            printf("0. Quitter.\n");
            printf("\n-------------------------------------------\n");
            scanf("%d", &choix);
        }
        while( choix<0 || choix>4 );

        switch(choix)
        {
        // Ajouter une station
        case 1:
            station = saisir_station(L);
            L = ajouter_station(L, station);
            break;

        // Afficher LDC
        case 2:
            afficher_chemin(L);
            break;

        // MAJ les stations
        case 3:
            MAJ_tous_stations(L);
            break;

        // Afficher les scores de tous les alpinistes
        case 4:
            for(int i=0; i<4; i++)
                printf("Le temps de l'alpniste#%d: %d\n", i, Score_Alpiniste(L.queu->station, i));
            break;

        case 0:
            break;

        default:
            break;
        }
    }
    while( choix!=0 );

    libererLDC(&L);
    return 0;
}
