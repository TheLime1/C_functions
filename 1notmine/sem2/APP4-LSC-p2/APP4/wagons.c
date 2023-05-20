#include <stdio.h>
#include <stdlib.h>
#include "wagons.h"

Train ajouterLocomotive(Train train, Wagon locomotive)
{
    struct Cellule* cell = NULL;

//    if( locomotive.type != 0 || locomotive.etat == 0 )
//    {
//        printf("\nLe wagon entre n'est pas de type locomotive ou est en panne.\n");
//        return train;
//    }

    cell = (struct Cellule*)malloc(sizeof(struct Cellule));
    cell->wagon = locomotive;
//    cell->suivant = NULL;

    cell->suivant = train;
    train = cell;

    return train;
}

Train ajouterFin(Train train, Wagon wagon)
{
    struct Cellule *cell, *parc;

//    if( locomotive.type == 1 || locomotive.etat == 0 )
//    {
//        printf("\nLe wagon entre est de type locomotive ou est en panne.\n");
//        return train;
//    }

    cell = (struct Cellule*)malloc(sizeof(struct Cellule));
    cell->wagon = wagon;
    cell->suivant = NULL;

    if(train == NULL)
    {
        train = cell;
    }
    else
    {
        parc = train;
        while( (*parc).suivant != NULL )
            parc = parc->suivant;

        (*parc).suivant = cell;
    }

    return train;
}

void afficherTrain(Train train, int* nbWagons)
{
    struct Cellule* parc = train;

    *nbWagons = 0;

    if(train == NULL)
    {
        printf("\nLa liste est vide\n");
    }
    else
    {
        while(parc != NULL)
        {
            (*nbWagons)++;
            afficherWagon(parc->wagon, *nbWagons);
            parc = parc->suivant;
        }
   }
}

int rechercherWagon(Train train, int num)
{
    struct Cellule* parc;
    parc = train;
    int i = 0;

    if(parc == NULL)
    {
        printf("\nLa liste est vide\n");
    }
    else
    {
        while(parc != NULL )
        {
            if( parc->wagon.num == num )
            {
                printf("Wagon trouve dans le maillon #%d", i);
                afficherWagon(parc->wagon, i+1);
                return 1;
            }

            parc = parc->suivant;
            i++;
        }
    }
    return 0;
}

// Helper functions Partie 1
Wagon saisirWagon(Wagon wagon)
{
    printf("\nDonner le numero du wagon: ");
    scanf("%d", &wagon.num);

    do
    {
        printf("Donner le type du wagon (0: locomotive, 1: wagon): ");
        scanf("%d", &wagon.type);
    }
    while( wagon.type!=0 && wagon.type!=1 );

    do
    {
        printf("Donner l etat du wagon(0: en panne, 1: OK): ");
        scanf("%d", &wagon.etat);
    }
    while( wagon.etat!=0 && wagon.etat!=1 );

    return wagon;
}

void afficherWagon(Wagon wagon, int i)
{
    printf("\nInfo Wagon#%d:\n", i);
    printf("\twagon.num: %d\n", wagon.num);
    printf("\twagon.type: %d\n", wagon.type);
    printf("\twagon.etat: %d\n", wagon.etat);
}



// ---------- Partie 2 -------------
// ---------------------------------
Train supprimerWagonPanne(Train train)
{
    struct Cellule *courant=train, *precedent=NULL;
    int trouve=0;
    if( train != NULL )
    {
        if( train->wagon.etat == 0 )
            train = supprimerDebut(train);
        else
        {
            while( courant!=NULL && !trouve )
            {
                if( courant->wagon.etat == 0 )
                    trouve=1;
                else
                {
                    precedent = courant;
                    courant = courant->suivant;
                }
            }
            if(trouve)
            {
                precedent->suivant = courant->suivant;
                free(courant);
            }
        }
    }
    return train;
}

Train ajouterApres(Train train, Wagon wagon, int num)
{
    struct Cellule* nouv = NULL, *precedent = NULL, *courant = train;

    while( courant!=NULL && courant->wagon.num != num)
    {
        precedent = courant;
        courant = courant->suivant;
    }

    if( courant == NULL )
        printf("\nIl n y a aucun wagon avec le numro %d\n", num);
    else
    {
        nouv = (struct Cellule*)malloc(sizeof(struct Cellule));
        nouv->wagon = wagon;
        nouv->suivant = courant->suivant;

        if(courant == train)
            train->suivant = nouv;
        else
            courant->suivant = nouv;
    }

    return train;
}

Train supprimerListe(Train train)
{
    struct Cellule* current = train;
    struct Cellule* next = NULL;

    while (current != NULL)
    {
        next = current->suivant;
        free(current);
        current = next;
    }

    train = NULL;
    return train;
}

void journal(char* fileName, char* evenement)
{
    FILE* fp;
    fp = fopen(fileName, "a");
    // if fp NULL
    fprintf(fp, "%s\n", evenement);
    fclose(fp);
}


// Helper function partie 2
// --------------------------
int wagonPanneExiste(Train train)
{
    struct Cellule* parc = train;

    if(train == NULL)
    {
        return 0;
    }
    else
    {
        while( parc != NULL )
        {
            if( parc->wagon.etat == 0 )
                return 1;
            else
                parc = parc->suivant;
        }
    }
    return 0;
}

Train supprimerDebut(Train train)
{
    struct Cellule* tmp;

    if( train != NULL )
    {
        tmp = train;
        train = train->suivant;
        free(tmp);
    }
    return train;
}

void afficherJournal(char* fileName)
{
    FILE* fp;
    int c;

    fp = fopen(fileName, "r");
    c = fgetc(fp);

    while ( c != EOF )
    {
        printf("%c", c);
        c = fgetc(fp);
    }

    fclose(fp);
}
