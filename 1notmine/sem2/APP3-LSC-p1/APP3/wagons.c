#include <stdio.h>
#include <stdlib.h>
#include "wagons.h"

Train ajouterLocomotive(Train train, Wagon locomotive)
{
    struct Cellule* cell;

    if( locomotive.type != typeLocomotive || locomotive.etat == EnPanne )
    {
        printf("\nLe wagon entré n'est pas de type locomotive ou est en panne.\n");
        return train;
    }

    cell = (struct Cellule*)malloc(sizeof(struct Cellule));
    cell->wagon = locomotive;
    cell->suivant = NULL;

    cell->suivant = train;
    train = cell;

    return(train);
}

Train ajouterFin(Train train, Wagon wagon)
{
    struct Cellule *cell, *parc;

    if( wagon.type == typeLocomotive || wagon.etat == EnPanne)
    {
        printf("\nLe wagon entré est de type locomotive ou est en panne.\n");
        return train;
    }

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
    struct Cellule* parc;
    parc = train;

    *nbWagons = 0;

    if(train == NULL)
    {
        printf("\nLa liste est vide\n");
        return;
    }

    while(parc != NULL)
    {
        (*nbWagons)++;
        afficherWagon(parc->wagon, *nbWagons);
        parc = parc->suivant;
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


// Helper functions
Wagon saisirWagon(Wagon wagon)
{
    printf("\nDonner le numero du wagon: ");
    scanf("%d", &wagon.num);

    do
    {
        printf("Donner le type du wagon (0: locomotive, 1: wagon): ");
        scanf("%d", &wagon.type);
    }while( wagon.type!=0 && wagon.type!=1 );

    do
    {
        printf("Donner l etat du wagon(0: en panne, 1: OK): ");
        scanf("%d", &wagon.etat);
    }while( wagon.etat!=0 && wagon.etat!=1 );

    return wagon;
}

void afficherWagon(Wagon wagon, int i)
{
    printf("\nInfo Wagon#%d:\n", i);
    printf("\twagon.num: %d\n", wagon.num);
    printf("\twagon.type: %d\n", wagon.type);
    printf("\twagon.etat: %d\n", wagon.etat);
}
