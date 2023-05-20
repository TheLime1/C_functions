#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choix = -1;
    int file_removed = 0;
    float montant = 0.0;
    Compte compte;
    Cellule* pCelCompte = NULL;
    char* nomFich = "Comptes.bin";


    LDC l;
    l = LDC_init(l);

    Arbre abr = NULL;

    do
    {
        do
        {
            printf("\n-------------------------------------------\n");
            printf("1. Ajouter un compte dans la listeDC.\n");
            printf("2. Afficher la liste des comptes.\n");
            printf("3. Effectuer une operation de virement ou de retrait sur un compte.\n");
            printf("4. sauvegarder les donnees dans un fichier bin compte.bin.\n");
            printf("5. remplir l'arbre a partir de la liste.\n");
            printf("6. afficher les comptes selong l'ordre decroissant.\n");
            printf("7. afficher le nombre des comptes ayant un solde superieur a un montant donne\n");
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
                saisirCompte(&compte);
                pCelCompte = chercherCompte(l, compte.numero);

                if(pCelCompte != NULL)
                    printf("\nL'ID doit etre unique.\n");
            }
            while(pCelCompte != NULL);

            l = ajouterCompte(l, compte);
            break;

        case 2:
            afficherCompte(l);
            break;

        case 3:
            printf("\nDonner le numero du compte: ");
            scanf("%d", &compte.numero);

            printf("Nouveau Solde: ");
            scanf("%f", &compte.solde);

            do
            {
                printf("Nv type Op: ");
                scanf("%c", &compte.typeDernOp);
            }
            while(compte.typeDernOp!='R' && compte.typeDernOp!= 'V');

            printf("Nouvelle dateDerOp:");
            printf("\n\tJour/Mois/Annee: ");
            scanf("%d/%d/%d", &compte.dateDerOp.jour
                  , &compte.dateDerOp.mois
                  , &compte.dateDerOp.annee);

            Operation(l, compte.numero, compte.solde, compte.typeDernOp, compte.dateDerOp);
            break;

        case 4:
            file_removed = remove(nomFich); // ab
            sauvegarderCompte(l, nomFich);
            break;

        case 5:
            abr = remplirArbre(abr, l);
            break;

        case 6:
            afficher(abr);
            break;

        case 7:
            printf("\nDonner un montant: ");
            scanf("%f", &montant);
            printf("\nNb comptes avec un sole sup a %d: ", calculerNbr(abr, montant));
            break;

        case 0:
            break;

        default:
            break;
        }
    }
    while( choix!=0 );


    LDC_liberer_iter(&l);
    liberer_ABR_Rec(abr);
    return 0;
}
