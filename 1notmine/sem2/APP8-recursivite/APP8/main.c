#include <stdio.h>
#include <stdlib.h>
#include "Ex1.h"
#include "Ex2.h"
#include "Ex3.h"

int main()
{
    int choix, n, a, *tab;
    char mot[10];
    liste etudiants = NULL;
    Etudiant E;

    do
    {
        do
        {
            printf("\n---------- Exercice 1 ---------------------\n");
            printf("1. Inverser un tableau d'entiers.\n");
            printf("2. Palindrome?\n");
            printf("3. PGCD.\n");
            printf("---------- Exercice 2 ---------------------\n");
            printf("4. Ajouter un etudiant a la liste.\n");
            printf("5. Supprimer un etudiant.\n");
            printf("6. Afficher la liste.\n");
            printf("7. Afficher la liste en inverse.");
            printf("\n----------- Exercice 3 --------------------\n");
            printf("8. Trier un tableau par fusion.\n");
            printf("0. Quitter.\n");
            printf("\n");
            scanf("%d", &choix);
        }
        while( choix<0 || choix>8 );

        switch(choix)
        {
        // Inverser tableau d'entiers
        case 1:
            printf("Donner le nombre d'entiers: ");
            scanf("%d", &n);
            tab = (int*)malloc(n*sizeof(int));
            for(int i=0; i<n; i++)
            {
                printf("entrer tab[%d]: ", i);
                scanf("%d", tab+i);
            }

            printf("Tableau initial:\n");
            printArray(tab, n);
            inverserRec(tab, n);
            printf("Tableau en inverse:\n");
            printArray(tab, n);
            free(tab);
            break;

        // Palindrome
        case 2:
            printf("Donner un mot: ");
            scanf("%s", mot);
            n = getLength(mot);
            palindromeRec(mot, n);
            break;

        // PGCD
        case 3:
            printf("Donner un entier: ");
            scanf("%d", &a);
            printf("Donner un deuxiéme entier: ");
            scanf("%d", &n);
            printf("\nLe PGCD de %d et %d est: %d\n",
                   a, n, pgcdRec(a, n) );
            break;

        // Ex 2 ------------------------------------
        // Ajouter un etudiant
        case 4:
            printf("\nDonner le nom de l'etudiant/e: ");
            fflush(stdin);
            gets(E.nom);
            do
            {
                printf("Donner la moyenne de l'etudiant/e: ");
                scanf("%f", &E.moyenne);
            }
            while(E.moyenne > 20.0 || E.moyenne < 0.0);

            etudiants = ajouter_etudiant(etudiants, E);
            break;

        // Supprimer etudiant/e
        case 5:
            printf("\nDonner le nom de l'etudiant/e a supprimer: ");
            fflush(stdin);
            gets(mot);
            etudiants = supprimer_etudiant(etudiants, mot);
            break;

        // Afficher la liste
        case 6:
            afficher_liste(etudiants);
            break;

        // Afficher la liste en inverse
        case 7:
            afficher_liste_inverse(etudiants);
            break;

        // Ex 3 ------------------------------------
        case 8:
            printf("Donner le nombre d'entiers: ");
            scanf("%d", &n);
            tab = (int*)malloc(n*sizeof(int));
            for(int i=0; i<n; i++)
            {
                printf("entrer tab[%d]: ", i);
                scanf("%d", tab+i);
            }

            printf("Tableau initial:\n");
            printArray(tab, n);
            TriFusion(tab, n, 0, n-1);
            printf("Tableau aprés le tri par fusion:\n");
            printArray(tab, n);
            free(tab);
            break;

        case 0:
            break;

        default:
            break;
        }
    }
    while( choix!=0 );

    freeLC(etudiants);
    return 0;
}
