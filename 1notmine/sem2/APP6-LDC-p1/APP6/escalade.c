#include "escalade.h"
#include <stdio.h>
#include <stdlib.h>

LDC init_chemin(LDC L)
{
    L.tete = NULL;
    L.queu = NULL;
    return L;
}

Station saisir_station(LDC L)
{
    Station station;
    int num_station = -1;
    do
    {
        printf("\nDonner le numero de la station a ajouter: ");
        scanf("%d", &num_station);
    }
    while( chercher_station(L, num_station) || num_station < 1 );

    station.num = num_station;

    for(int i=0; i<4; i++)
    {
        station.Aalp[i].arriv_desc = 0;
        station.Aalp[i].arriv_mont = 0;
    }

    return station;
}

Station* chercher_station(LDC L, int num)
{
    Cellule *pC = NULL;

    if(listeDC_vide(L))
        return NULL;
    else
    {
        pC = L.tete;
        while( pC && (pC->station.num != num) )
            pC = pC->suiv;

        return (pC)? &pC->station : NULL;
    }
}

LDC ajouter_station(LDC L, Station station)
{
    Cellule *pC;

    if(listeDC_vide(L))
    {
        L = ajout_En_Tete(L, station);
        return L;
    }
    else
    {
        pC = L.tete;
        while( pC && pC->station.num < station.num )
            pC = pC->suiv;

        if( pC )
            L = ajout_avant(L, pC, station);
        else
            L = ajout_Fin(L, station);

        return L;
    }
}

void afficher_chemin(LDC L)
{
    Cellule *pC;
    int i = 0;

    if(listeDC_vide(L))
        printf("Liste vide\n");
    else
    {
        pC = L.tete;
        while(pC)
        {
            printf("station.num#%d: %d\n", ++i, pC->station.num);
            pC = pC->suiv;
        }
    }
}

void MAJ_Station(Station station)
{
    int indice = -1, sens = -1;
    unsigned int temps = 0;

    // choisir l'alpiniste
    do
    {
        printf("\nDonner l'indice du l'alpiniste a MAJ: ");
        scanf("%d", &indice);
    }
    while( indice<0 || indice>4 );

    // entrer le temps mis par l'alpiniste
    do
    {
        printf("Donner le temps: ");
        scanf("%d", &temps);
    }
    while(temps<=0);

    // choisir un sens (montée ou descente)
    do
    {
        printf("MAJ le temps de la descente ou de montee?: (0:descente, 1: montee)");
        scanf("%d", &sens);
    }
    while(sens!= 0 && sens!=1);

    // MAJ la station
    if(sens==0)
        station.Aalp[indice].arriv_desc += temps;
    else
        station.Aalp[indice].arriv_mont += temps;
}

void MAJ_tous_stations(LDC L)
{
    Cellule *pC;

    if(listeDC_vide(L))
        printf("Liste vide\n");
    else
    {
        pC = L.tete;
        while(pC)
        {
            MAJ_Station(pC->station);
            pC = pC->suiv;
        }
    }
}

int Score_Alpiniste(Station derniere_station, int indice)
{
    int score = derniere_station.Aalp[indice].arriv_desc
                - derniere_station.Aalp[indice].arriv_mont;

    return score;
}

////////////////////////////////////

int listeDC_vide(LDC L)
{
    return(L.tete == NULL && L.queu == NULL);
}

LDC ajout_avant(LDC L, Cellule *pIndex, Station station)
{
    Cellule* pNouv;

    pNouv = (Cellule*)malloc(sizeof(Cellule));
    if(!pNouv || listeDC_vide(L) )
    {
        printf("Espace memoire insuffisant\n");
        return L;
    }

    if( pIndex )
    {
        if( pIndex == L.tete )
            L = ajout_En_Tete(L, station);
        else
        {
            pNouv->station = station;
            pNouv->suiv = pIndex;
            pNouv->prec = pIndex->prec;
            (pIndex->prec)->suiv = pNouv;
            pIndex->prec = pNouv;
        }
    }
    return L;
}

LDC ajout_En_Tete(LDC L, Station station)
{
    Cellule* pNouv;

    pNouv = (Cellule*)malloc(sizeof(Cellule));
    if(!pNouv )
        printf("Espace memoire insuffisant\n");
    else
    {
        pNouv->station = station;
        pNouv->prec = NULL;
        pNouv->suiv = L.tete;
        if(!listeDC_vide(L))
            L.tete->prec = pNouv;
        else
            L.queu = pNouv;
        L.tete = pNouv;
    }
    return L;
}

LDC ajout_Fin(LDC L, Station station)
{
    Cellule* pNouv;

    pNouv = (Cellule*)malloc(sizeof(Cellule));
    if(!pNouv)
        printf("Espace memoire insuffisant\n");
    else
    {
        pNouv->station = station;
        pNouv->suiv = NULL;
        pNouv->prec = L.queu;
        if(!listeDC_vide(L))
            L.queu->suiv = pNouv;
        else
            L.tete = pNouv;
        L.queu = pNouv;
    }
    return L;
}

void libererLDC(LDC* L)
{
    Cellule *maillon, *next;
    maillon = L->tete;
    while(maillon)
    {
        next = maillon->suiv;
        free(maillon);
        maillon = next;
    }
    L->queu = NULL;
    L->tete = NULL;
}
