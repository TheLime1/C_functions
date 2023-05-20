#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "voyageurs.h"

int main()
{
    int choix;
    int nbVgr = 0;
    int index;
    int duplicate = 0;
    char id[10];
    voyageur vgr;
    voyageur* TabVgr;

    char nomFichier[] = "voyageurs";

    TabVgr = charger_donnees(nomFichier, &nbVgr);

    do
    {
        do
        {
            printf("\n------------------------------\n");
            printf("1. Ajouter un voyageur.\n");
            printf("2. Supprimer un voyageur.\n");
            printf("3. Trouver un voyageur.\n");
            printf("4. Afficher le nombre de voyageurs.\n");
            printf("5. Sauvegarder.\n");
            printf("0. Sauvegardre et Quitter.\n");
            printf("\n6. Afficher le contenu du fichier \"%s\"\n", nomFichier);
            printf("7. Afficher le tableau des voyageurs.\n");
            printf("------------------------------\n");
            scanf("%d", &choix);
        }while(choix<0 || choix>7);

        switch(choix)
        {
            // Ajouter
            case 1:

                do
                {
                    saisirVoyageur(&vgr);
                    duplicate = 0;
                    for(int i=0; i<nbVgr; i++)
                        if( strcmp(vgr.ID, (TabVgr+i)->ID) == 0 )
                        {
                            duplicate = 1;
                            printf("\nID existe deja.\n");
                        }
                } while(duplicate);

                TabVgr = ajouter(vgr, TabVgr, &nbVgr);
                sauvegarder_donnees(nomFichier, TabVgr, nbVgr);
                break;

            // Supprimer
            case 2:
                printf("Donner l identifiant du voyageur a supprimer: ");
                scanf("%s", id);
                supprimer(TabVgr, id, &nbVgr);
                sauvegarder_donnees(nomFichier, TabVgr, nbVgr);
                printf("\n");
                afficherFichier(nomFichier);
                printf("\n");
                afficherTab(TabVgr, nbVgr);
                break;

            // Trouver
            case 3:
                printf("Donner l identifiant du voyageur a rechercher: ");
                scanf("%s", id);
                if ( (index = trouver(TabVgr, id, nbVgr)) != -1 )
                    printf("Voyageur se trouve dans tabVgr[%d]\n", index);
                else
                    printf("Voyageur introuvable dans tabVgr.\n");
                break;

            // Afficher nbV
            case 4:
                printf("nombre de voyageurs enregistres dans le fichier \"%s\" est: %d", nomFichier, nbVoyageurs(nomFichier));
                break;

            // Sauvegarder
            case 5:
                sauvegarder_donnees(nomFichier, TabVgr, nbVgr);
                break;

            // Sauvegarder et Quitter
            case 0:
                sauvegarder_donnees(nomFichier, TabVgr, nbVgr);
                liberer(TabVgr);
                break;

            case 6:
                afficherFichier(nomFichier);
                break;

            case 7:
                afficherTab(TabVgr, nbVgr);
                break;

            default:
                break;
        }

    }while(choix!=0);

//    free(TabVgr);
    return 0;
}
