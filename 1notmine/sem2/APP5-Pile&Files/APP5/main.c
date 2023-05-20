#include <stdio.h>
#include <stdlib.h>
#include "pileEtFileDossiers.h"

int main()
{
    int choix;
    Pile pile = NULL;
    File file = initialiser();
    Dossier doss;
    char *fileName = "test.txt";

    do
    {
        do
        {
            printf("\n------------ Partie 1 ---------------------\n");
            printf("1. Empiler un dossier.\n");
            printf("2. depiler un dossier.\n");
            printf("3. Consulter le dernier dossier de la pile.\n");
            printf("4. Trier selon la priorite.\n");
            printf("5. Afficher la pile.\n");
            printf("------------ Partie 2 ---------------------\n");
            printf("6. depiler et enfiler un dossier.\n");
            printf("7. consulter le dernier dossier de la file.\n");
            printf("8. defiler un dossier.\n");
            printf("9. Afficher le fichier texte.\n");
            printf("0. Quitter.");
            printf("\n-------------------------------------------\n");
            scanf("%d", &choix);
        }
        while( choix<0 || choix>9 );

        switch(choix)
        {
        // empiler
        case 1:
            doss = saisirDossier();
            pile = empiler(pile, doss);
            printf("\nLa pile: (pour tester)\n");
            afficherPile(pile);
            break;

        // depiler
        case 2:
            pile = depiler(pile);
            printf("\nApres l'appel de depiler():\n");
            afficherPile(pile);
            break;

        // consulter
        case 3:
            doss = dernierDossierPile(pile);
            printf("\nDernier dossier:\n");
            printf("\tdoss.num: %d\n\tdoss.priorite: %d\n", doss.num, doss.priorite);
            break;

        // trier
        case 4:
            pile = prioriserPileTmp(pile);
            printf("\nApres l'appel de prioriser():\n");
            afficherPile(pile);
            break;

        // affichage
        case 5:
            afficherPile(pile);
            break;

        // depiler et enfiler
        case 6:
            depilerEnfiler(&pile, &file);
            printf("\nApres 1 appel de depilerEnfiler():\n");
            printf("La file:\n");
            AfficherFile(file);
            break;

        // consulter
        case 7:
            printf("\nDernier dossier de la file:\n");
            doss = dernierDossierFile(file);
            printf("num: %d, priorite: %d\n", doss.num, doss.priorite);
            break;

        // defiler
        case 8:
            doss = defiler(&file);
            ecrireDossierFichierTxt(doss, fileName);
            printf("\nLa file apres le retrait d'un dossier de la file:\n");
            AfficherFile(file);
            break;

        // afficher le fichier texte
        case 9:
            afficherFichierTxt(fileName);
            break;

        case 0:
            break;

        default:
            break;
        }
    }
    while( choix!=0 );

    libererPile(&pile);
    libererFile(&file);
    return 0;
}
