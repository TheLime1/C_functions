#include "ABR.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int choix;
    char *nomFich = "moyennes.txt";
    abr arbre = NULL;
    LDC TresBien = init_LDC();
    LDC Bien = init_LDC();
    LDC AssezBien = init_LDC();
    LDC Passable = init_LDC();

    do
    {
        do
        {
            printf("\n------------------------------------------\n");
            printf("1. Construire un arbre binaire de recherche a patir du fichier texte.\n");
            printf("2. Afficher les etudiant selon l'ordre decroissant de leur moyenne.\n");
            printf("3. calculer le nombre total des etudiants.\n");
            printf("4. Creer des LDCc a partir de l'ABR.\n");
            printf("5. Afficher les LDCs.\n");
            printf("0. Quitter.");
            printf("\n-------------------------------------------\n");
            scanf("%d", &choix);
        } while (choix < 0 || choix > 5);

        switch (choix)
        {
        case 1:
            arbre = construireArbre(arbre, nomFich);
            break;

        case 2:
            afficher(arbre);
            break;

        case 3:
            printf("Le nombre total des etudiants est: %d\n",
                   calculerNombre(arbre));
            break;

        case 4:
            construireListe(arbre, &TresBien, 16, 20);
            construireListe(arbre, &Bien, 14, 16);
            construireListe(arbre, &AssezBien, 12, 14);
            construireListe(arbre, &Passable, 10, 12);
            break;

        case 5:
            printf("Tres bien:\n");
            afficher_LDC_Rec(TresBien.tete);
            printf("\nBien:\n");
            afficher_LDC_Rec(Bien.tete);
            printf("\nAssez bien:\n");
            afficher_LDC_Rec(AssezBien.tete);
            printf("\nPassable:\n");
            afficher_LDC_Rec(Passable.tete);
            break;

        default:
            break;
        }
    } while (choix != 0);

    freeABR_Rec(arbre);
    //    freeDLL(TresBien);
    //    freeDLL(Bien);
    //    freeDLL(AssezBien);
    //    freeDLL(Passable);

    freeDLL_Rec(TresBien.tete);
    freeDLL_Rec(Bien.tete);
    freeDLL_Rec(AssezBien.tete);
    freeDLL_Rec(Passable.tete);
    return 0;
}
