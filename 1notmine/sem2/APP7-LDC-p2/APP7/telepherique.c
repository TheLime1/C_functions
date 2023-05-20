#include <stdlib.h>
#include <stdio.h>
#include "telepherique.h"

LDC init_telepherique(LDC L)
{
    L.tete = NULL;
    L.queu = NULL;
    return L;
}

int listeDC_vide(LDC L)
{
    return(L.tete == NULL && L.queu == NULL);
}

LDC ajouter_queue(LDC L, Cabine cabine)
{

    Cellule* pNouv;

    pNouv = (Cellule*)malloc(sizeof(Cellule));
    if(!pNouv)
        printf("Espace memoire insuffisant\n");
    else
    {
        pNouv->cabine = cabine;
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

LDC ajouter_tete(LDC L, Cabine cabine)
{
    Cellule* pNouv;

    pNouv = (Cellule*)malloc(sizeof(Cellule));
    if(!pNouv)
        printf("Espace memoire insuffisant\n");
    else
    {
        pNouv->cabine = cabine;
        pNouv->suiv = L.tete;
        pNouv->prec = NULL;
        if(!listeDC_vide(L))
            L.tete->prec = pNouv;
        else
            L.queu = pNouv;
        L.tete = pNouv;
    }
    return L;
}

LDC ajouter_apres(LDC L, Cellule *pC, Cabine cabine)
{
    Cellule *pNouv;

    if( listeDC_vide(L) )
        return L;

    pNouv = L.tete;
    if( pC )
    {
        if( pC == L.queu )
            L = ajouter_queue(L, cabine);
        else
        {
            pNouv = (Cellule*)malloc(sizeof(Cellule));
            pNouv->cabine = cabine;
            pNouv->prec = pC;
            pNouv->suiv = pC->suiv;
            (pC->suiv)->prec = pNouv;
            pC->suiv = pNouv;
        }
    }
    return L;
}

Cabine saisir_cabine()
{
    Cabine cabine;

    printf("\nDonner le numero de la cabine: ");
    scanf("%d", &cabine.num); // not unique

    printf("Donner le nombre maximum de passagers: ");
    scanf("%d", &cabine.capacite);

    // controle de saisie?
    printf("Donner la date de la derniere maintenance: ");
    printf("\njour: ");
    scanf("%d", &cabine.date.jour);
    printf("mois: ");
    scanf("%d", &cabine.date.mois);
    printf("annee: ");
    scanf("%d", &cabine.date.annee);

    do
    {
        printf("l'etat(0 ou 1): ");
        scanf("%d", &cabine.etat);
    }
    while(cabine.etat != 0 && cabine.etat != 1);

    return cabine;
}

Cellule* chercher_cabine(LDC L)
{
    Cellule *pC;

    if(listeDC_vide(L))
        return NULL;
    else
    {
        pC = L.tete;
        while( pC && (pC->cabine.etat != 0) )
            pC = pC->suiv;

        return (pC)? pC : NULL;
    }
}

LDC ajouter_cabine(LDC L, Cabine cabine)
{
    Cellule *pC = chercher_cabine(L);

    if( pC )
        L = ajouter_apres(L, pC, cabine);
    else
        L = ajouter_tete(L, cabine);
    return L;
}

LDC supp_cabine(LDC L)
{
    Cellule *pC = chercher_cabine(L);

    if( pC )
        L = supp_1ereOcc_LDC(L, pC);

    return L;
}

LDC supp_queu_LDC(LDC L)
{
    if( listeDC_vide(L) )
        return L;

    Cellule *pC = L.queu;

    if( L.tete == L.queu )
        L = init_telepherique(L);
    else
    {
        L.queu = L.queu->prec;
        L.queu->suiv = NULL;
    }
    free(pC);

    return L;
}

LDC supp_1ereOcc_LDC(LDC L, Cellule* pC)
{
    if( listeDC_vide(L) )
        return L;

    if( pC )
    {
        if( pC == L.tete )
            L = supp_tete_LDC(L);
        else
        {
            if( pC == L.queu )
                L = supp_queu_LDC(L);
            else
            {
                (pC->prec)->suiv = pC->suiv;
                (pC->suiv)->prec = pC->prec;
                free(pC);
            }
        }
    }

    return L;
}

void MAJ_telepherique(LDC L)
{
    Cellule *pC = NULL;

    do
    {
        pC = chercher_cabine(L);

        if( pC )
        {
            pC->cabine.date.mois = ((pC->cabine.date.mois + 6) % 12)+1;
            pC->cabine.etat = 1;
        }
    }
    while( pC );
}

int afficher_telepherique(LDC L)
{
    Cellule *pC = NULL;
    int capPassTotal = 0, i=0;

    if(listeDC_vide(L))
        printf("Liste vide\n");
    else
    {
        pC = L.tete;
        while(pC)
        {
            printf("Cabine#%d: %d\n", ++i, pC->cabine.num);
            capPassTotal += pC->cabine.capacite;
            pC = pC->suiv;
        }
    }
    return capPassTotal;
}

LDC vider_telepherique(LDC L)
{
    while( !listeDC_vide(L) )
        L = supp_tete_LDC(L);

    return L;
}

LDC supp_tete_LDC(LDC L)
{
    Cellule *pC = L.tete;

    if( listeDC_vide(L) )
        return L;

    if( L.tete == L.queu )
        L = init_telepherique(L);
    else
    {
        L.tete = L.tete->suiv;
        L.tete->prec = NULL;
    }
    free(pC);

    return L;
}
