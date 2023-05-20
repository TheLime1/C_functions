#include "Examen2018.h"
#include <stdio.h>
#include <stdlib.h>

Ouvrage Saisir_ouvrage()
{
    Ouvrage ouvrage;

    printf("\nSaisir le code de l'ouvrage (int): ");
    scanf("%d", &ouvrage.code);
    printf("Saisir le titre du travail (chaine de caracteres): ");
    fflush(stdin);
    gets(ouvrage.titre);

    return ouvrage;
}

void Remplir_bibio(char nomfich[], int n)
{
    FILE *pBFile = NULL;
    Ouvrage *ouvrages = (Ouvrage*)malloc(n*sizeof(Ouvrage));
    if( ouvrages == NULL )
    {
        printf("\nespace memoire insuffisant.\n");
        return;
    }

    pBFile = fopen(nomfich, "wb");
    if( pBFile == NULL )
    {
        printf("\nErreur lors de l'ouverture de fichier \"%s\"\n", nomfich);
        return;
    }

    for(int i=0; i<n; i++)
        ouvrages[i] = Saisir_ouvrage();

    fwrite(ouvrages, sizeof(Ouvrage), n, pBFile);

    free(ouvrages);
    fclose(pBFile);
}

void Saisir_Abonne(Abonne* x)
{
    printf("\nDonner le numero d'inscription de l'abonne/e: ");
    scanf("%d", &x->numInsc);
    printf("Donner le nom de l'abonne/e: ");
    fflush(stdin);
    gets(x->nom);
    x->ouvrageEmp = NULL;
}

Abr Inserer_abonne(Abr a, Abonne x)
{
    if ( a == NULL )
    {
        struct noeudABR *pNewNode = (struct noeudABR*)malloc(sizeof(struct noeudABR));

        if (pNewNode == NULL)
            printf("Espace memoire insuffisant\n");
        else
        {
            pNewNode->abonne = x;
            pNewNode->pR = NULL;
            pNewNode->pL = NULL;
        }

        a = pNewNode;
    }
    else
    {
        if ( x.numInsc <= a->abonne.numInsc )
            a->pL = Inserer_abonne(a->pL, x);
        else
            a->pR = Inserer_abonne(a->pR, x);
    }

    return a;
}

Ouvrage chercher_ouvrage(char nomfich[], int code)
{
    FILE *fp = NULL;
    Ouvrage ouvrage;
    ouvrage.code = -1;

    fp = fopen(nomfich, "rb");
    if( fp == NULL )
    {
        printf("erreur lors de l'ouverture du fichier \"%s\"\n", nomfich);
        return ouvrage;
    }

    while( fread(&ouvrage, sizeof(Ouvrage), 1, fp) )
    {
        if( ouvrage.code == code )
        {
            fclose(fp);
            return ouvrage;
        }
    }

    ouvrage.code = -1;
    fclose(fp);
    return ouvrage;
}

struct noeudABR* chercher_Abonne(Abr a, int num)
{
    if ( a == NULL || a->abonne.numInsc == num )
        return a;

    if( num < a->abonne.numInsc )
        return chercher_Abonne(a->pL, num);
    else
        return chercher_Abonne(a->pR, num);
}

Abonne Ajouter_ouvrage(Abonne x, Ouvrage Ouv)
{
    struct celluleLSC *cell, *parc;

    cell = (struct celluleLSC*)malloc(sizeof(struct celluleLSC));
    cell->oeuvre = Ouv;
    cell->suiv = NULL;

    if( x.ouvrageEmp == NULL )
    {
        x.ouvrageEmp = cell;
    }
    else
    {
        parc = x.ouvrageEmp;
        while( (*parc).suiv != NULL )
            parc = parc->suiv;

        (*parc).suiv = cell;
    }

    return x;
}

void Emprunter_ouvrage(Abr A, int code_ouv, int num)
{
    Ouvrage ouvrageAEmp;
    struct noeudABR* noeud;

    if( A == NULL )
    {
        printf("\nAucun abonne n'est inscrit.\n");
        return;
    }

    ouvrageAEmp = chercher_ouvrage("biblio.bin", code_ouv);
    if( ouvrageAEmp.code == -1 )
    {
        printf("\nL'ouvrage avec le code %d n'existe pas.\n", code_ouv);
        return;
    }

    noeud = chercher_Abonne(A, num);
    if( noeud == NULL )
    {
        printf("\nL'abonne avec le num %d n'existe pas.\n", num);
        return;
    }

    noeud->abonne = Ajouter_ouvrage(noeud->abonne, ouvrageAEmp);
}

void Afficher_Abonne(Abonne x)
{
    printf("\nNom de l'abonne: %s", x.nom);
    printf("\nNum inscription: %d", x.numInsc);
    afficherLSC(x.ouvrageEmp);
}

void afficherLSC(listeLSC L)
{
    struct celluleLSC* parc = L;

    if(L == NULL)
    {
        printf("\nLa liste des ouvrages empruntes est vide\n");
    }
    else
    {
        while(parc != NULL)
        {
            printf("\n\tcode: %d", parc->oeuvre.code);
            printf("\n\ttitre: %s", parc->oeuvre.titre);
            parc = parc->suiv;
        }
    }
}

void Afficher_ABR(Abr a)
{
    if (a != NULL)
    {
        Afficher_ABR(a->pR);
        Afficher_Abonne(a->abonne);
        Afficher_ABR(a->pL);
    }
}


void Liberer_ABR_et_LSC(Abr a)
{
    if (a != NULL)
    {
        Liberer_ABR_et_LSC(a->pL);
        Liberer_ABR_et_LSC(a->pR);
        libererLSC(&a->abonne.ouvrageEmp);
        free(a);
    }
}

void libererLSC(listeLSC *L)
{
    struct celluleLSC* courant = *L;
    struct celluleLSC* suivant;

    while (courant != NULL)
    {
        suivant = courant->suiv;
        free(courant);
        courant = suivant;
    }

    *L = NULL;
}


