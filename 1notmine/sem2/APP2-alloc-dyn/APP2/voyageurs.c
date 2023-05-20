#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "voyageurs.h"

int nbVoyageurs(char nomFich[])
{
    int nbVoyageurs = 0;
    voyageur vogr;
    FILE* fp;

    fp = fopen(nomFich, "rb");

    if(fp == NULL)
    {
        printf("Erreur: %d", errno);
        return -1;
    }

    while(fread(&vogr, sizeof(voyageur), 1, fp))
        nbVoyageurs++;

    fclose(fp);
    return nbVoyageurs;
}


void saisirVoyageur(voyageur* ptv)
{
    printf("Donner l identifiant du voyageur: ");
    scanf("%s", ptv->ID); // IDs are usually unique
    printf("Donner nom du voyageur: ");
    scanf("%s", ptv->nom);
    printf("Donner l adresse du voyageur: ");
    fflush(stdin);
    gets(ptv->adresse);
    printf("Donner le nombre de voyages: ");
    scanf("%d", &ptv->nbVoyages);
}

//voyageur* charger_donnees(char nomFich[], int* n)
//{
//    int nbV = 0;
//    voyageur* tab;
//    FILE* fp;
//
//    fp = fopen(nomFich, "wb+");
//    if(fp == NULL)
//    {
//        printf("Erreur: %d", errno);
//        return NULL;
//    }
//
//    nbV = nbVoyageurs(nomFich);
//    *n = nbV;
//    tab = (voyageur*)malloc((*n) * sizeof(voyageur));
//
//    fread(tab, sizeof(voyageur), *n, fp);
//
//    fclose(fp);
//    return tab;
//}

// sans l'appel de nbVoyageur ??
voyageur* charger_donnees(char nomFich[], int* n)
{
    int nbV = 0;
    voyageur* tab;
    voyageur vogr;
    FILE* fp;

    fp = fopen(nomFich, "rb");
    if(fp == NULL)
    {
        printf("Erreur: %d", errno);
        return NULL;
    }

    while( fread(&vogr, sizeof(voyageur), 1, fp) )
        nbV++;
    rewind(fp);

    *n = nbV;
    tab = (voyageur*)malloc((*n) * sizeof(voyageur));

    fread(tab, sizeof(voyageur), *n, fp);

    fclose(fp);
    return tab;
}

void sauvegarder_donnees(char nomFich[], voyageur* tab, int n)
{
    FILE* fp;

    fp = fopen(nomFich, "wb");
    if(fp == NULL)
    {
        printf("Erreur: %d", errno);
        return;
    }

    if( !(fwrite(tab, sizeof(voyageur), n, fp) == n) )
        printf("\nErreur de sauvegarde.\n");

    fclose(fp);
}

int trouver(voyageur* tab, char id[], int n)
{
    for(int i=0; i<n; i++)
        if( strcmp( (tab+i)->ID, id ) == 0 )
            return i;

    return -1;
}

voyageur* ajouter(voyageur v, voyageur* tab, int* n)
{
    int index = -2;
    if( (index = trouver(tab, v.ID, *n)) != -1 )
    {
        ((tab+index)->nbVoyages)++;
    }
    else
    {
        tab = (voyageur*)realloc(tab, ((*n)+1) * sizeof(voyageur));
        *(tab + *n) = v;
        (*n)++;
    }

    return tab;
}

void supprimer(voyageur* tab ,char id[], int* n)
{
    int index = -2;
    voyageur* temp = NULL;

    if( (index = trouver(tab, id, *n)) == -1 )
    {
        printf("\nLe voyageur n existe pas dans tab\n");
    }
    else
    {
        (*n)--;
        for(int i=index; i<(*n); i++)
            *(tab+i) = *((tab+i)+1);

        printf("\nVoyageur supprime de tabVgr[%d]\n", index);

        temp = realloc(tab, (*n)*sizeof(voyageur));
        if(temp == NULL && (*n)>1)
        {
            printf("Erreur de reallocation\n");
            return;
        }
        tab = temp;
    }
}

void liberer(voyageur* tab)
{
    if(tab == NULL)
    {
        printf("freeing a NULL pointer.\n");
    }
    free(tab);
}



// ------------

void afficherFichier(char nomFich[])
{
    FILE* fp;
    voyageur vgr;
    int i = 0;

    fp = fopen(nomFich, "rb");
    if(fp == NULL)
    {
        printf("Erreur: %d", errno);
        return;
    }

    if( !fread(&vgr, sizeof(voyageur), 1, fp) )
    {
        printf("Le fichier \"%s\" est vide.\n", nomFich);
        fclose(fp);
        return;
    }
    else
    {
        rewind(fp);
        printf("Fichier:\n");
        while( fread(&vgr, sizeof(voyageur), 1, fp) )
        {
            printf("Voyageur#%d\n", i);
            printf("\tVoyageur#%d.id: %s\n", i, vgr.ID);
            printf("\tVoyageur#%d.nom: %s\n", i, vgr.nom);
            printf("\tVoyageur#%d.adresse: %s\n", i, vgr.adresse);
            printf("\tVoyageur#%d.nom: %d\n", i, vgr.nbVoyages);
            printf("\n");
            i++;
        }
    }

    fclose(fp);
}

void afficherTab(voyageur* tab, int n)
{
    if(n == 0)
    {
        printf("Le tableau Vgr[] est vide.\n");
    }
    else
    {
        printf("Tableau:\n");
        for(int i=0; i<n; i++)
        {
            printf("Voyageur[%d]:\n", i);
            printf("\tvoyageur[%d].ID: %s\n", i, (tab+i)->ID);
            printf("\tvoyageur[%d].nom: %s\n", i, (tab+i)->nom);
            printf("\tvoyageur[%d].adresse: %s\n", i, (tab+i)->adresse);
            printf("\tvoyageur[%d].nbVoyages: %d\n", i, (tab+i)->nbVoyages);
            printf("\n");
        }
    }
}
