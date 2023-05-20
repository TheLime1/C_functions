#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choix = -1;
    int file_removed = 0;
    char id[20];
    char* nomFich = "ListeDesScooters.txt";
    Scooter scoot;
    Cellule* pCelScoot;

    Liste l = NULL;
    File file = initialiser();
    Arbre abr = NULL;

    do
    {
        do
        {
            printf("\n-------------------------------------------\n");
            printf("1. Ajouter un nouveau scooter dans la liste.\n");
            printf("2. Louer un scooter.\n");
            printf("3. Afficher la liste des scooters.\n");
            printf("4. Enfiler un scooter.\n");
            printf("5. Entretenir un scooter.\n");
            printf("6. Construire un arbre de scooters.\n");
            printf("7. Afficher le scooter ayant le kilometrage le plus eleve\n");
            printf("0. Quitter.");
            printf("\n-------------------------------------------\n");
            scanf("%d", &choix);
        }
        while( choix<0 || choix>7 );

        switch(choix)
        {
        case 1:
            do
            {
                saisirScooter(&scoot);
                pCelScoot = chercherScooter(l, scoot.ID);

                if(pCelScoot != NULL)
                    printf("\nL'ID doit etre unique.\n");
            }
            while(pCelScoot != NULL);
            l = ajouterScooter(l, scoot);
            break;

        case 2:
            printf("\nDonner l'ID du scooter a louer: ");
            scanf("%s", id);
            louerScooter(l, id);
            break;

        case 3:
            file_removed = remove(nomFich);     // mode d'ouverture du fichier dans afficherScooter(): a
                                                // (sinon, duplication des données dans le fichier à chaque affichage)
            afficherScooter(l, nomFich);
            break;

        case 4:
            printf("\nDonner l'ID du scooter a enfiler: ");
            scanf("%s", id);
            file = enfilerScooter(l, file, id);
            break;

        case 5:
            entretenirScooter(&file, l);
            break;

        case 6:
            abr = construireArbre(abr, l);
            printf("\nArbre: (infixe)");
            afficher_ABR(abr);
            break;

        case 7:
            abr = maxScooter(abr);
            printf("%.2f", abr->scoot.kilometrage);
            break;

        case 0:
            break;

        default:
            break;
        }
    }
    while( choix!=0 );


    liberer_ABR_Rec(abr);
    l = liberer_LSC(l);
    libererFile(&file);
    return 0;
}
