#include "LDC.h"
#include <stdlib.h>
#include <stdio.h>

LDC LDC_init(LDC L)
{
    L.tete = NULL;
    L.queu = NULL;
    return L;
}


int LDC_vide(LDC L)
{
    return( L.tete == NULL && L.queu == NULL );
}


Exemple_struct* LDC_chercher_int(LDC L, int num)
{
    Cellule *pC;

    if( LDC_vide(L) )
        return NULL;
    else
    {
        pC = L.tete;
        while( pC && (pC->structure.int_num != num) )
            pC = pC->suiv;

        return (pC)? &pC->structure : NULL;
    }
}


LDC LDC_ajouter_en_ordre_croissant(LDC L, Exemple_struct structure)
{
    Cellule *pC;

    if( LDC_vide(L) )
    {
        L = LDC_ajouter_Tete(L, structure);
        return L;
    }
    else
    {
        pC = L.tete;
        while( pC && pC->structure.int_num < structure.int_num)
            pC = pC->suiv;

        if( pC )
            L = LDC_ajouter_avant(L, pC, structure);
        else
            L = LDC_ajouter_Fin(L, structure);

        return L;
    }
}


LDC LDC_ajouter_Tete(LDC L, Exemple_struct structure)
{
    Cellule* pNouv;

    pNouv = (Cellule*)malloc(sizeof(Cellule));
    if(!pNouv )
        printf("Espace memoire insuffisant\n");
    else
    {
        pNouv->structure = structure;
        pNouv->prec = NULL;
        pNouv->suiv = L.tete;
        if(!LDC_vide(L))
            L.tete->prec = pNouv;
        else
            L.queu = pNouv;
        L.tete = pNouv;
    }
    return L;
}


LDC LDC_ajouter_Fin(LDC L, Exemple_struct structure)
{
    Cellule* pNouv;

    pNouv = (Cellule*)malloc(sizeof(Cellule));
    if(!pNouv)
        printf("Espace memoire insuffisant\n");
    else
    {
        pNouv->structure = structure;
        pNouv->suiv = NULL;
        pNouv->prec = L.queu;
        if(!LDC_vide(L))
            L.queu->suiv = pNouv;
        else
            L.tete = pNouv;
        L.queu = pNouv;
    }
    return L;
}


LDC LDC_ajouter_avant(LDC L, Cellule *pIndex, Exemple_struct structure)
{
    Cellule* pNouv;

    pNouv = (Cellule*)malloc(sizeof(Cellule));
    if( !pNouv || LDC_vide(L) )
    {
        printf("Espace memoire insuffisant\n");
        return L;
    }

    if( pIndex )
    {
        if( pIndex == L.tete )
            L = LDC_ajouter_Tete(L, structure);
        else
        {
            pNouv->structure = structure;
            pNouv->suiv = pIndex;
            pNouv->prec = pIndex->prec;
            (pIndex->prec)->suiv = pNouv;
            pIndex->prec = pNouv;
        }
    }
    return L;
}

LDC LDC_ajouter_apres(LDC L, Cellule *pC, Exemple_struct structure)
{
    Cellule *pNouv;

    if( LDC_vide(L) )
        return L;

    pNouv = L.tete;
    if( pC )
    {
        if( pC == L.queu )
            L = LDC_ajouter_Fin(L, structure);
        else
        {
            pNouv = (Cellule*)malloc(sizeof(Cellule));
            pNouv->structure = structure;
            pNouv->prec = pC;
            pNouv->suiv = pC->suiv;
            (pC->suiv)->prec = pNouv;
            pC->suiv = pNouv;
        }
    }
    return L;
}

LDC supp_queu_LDC(LDC L)
{
    if( LDC_vide(L) )
        return L;

    Cellule *pC = L.queu;

    if( L.tete == L.queu )
        L = LDC_init(L);
    else
    {
        L.queu = L.queu->prec;
        L.queu->suiv = NULL;
    }
    free(pC);

    return L;
}

LDC supp_tete_LDC(LDC L)
{
    Cellule *pC = L.tete;

    if( LDC_vide(L) )
        return L;

    if( L.tete == L.queu )
        L = LDC_init(L);
    else
    {
        L.tete = L.tete->suiv;
        L.tete->prec = NULL;
    }
    free(pC);

    return L;
}

LDC supp_1ereOcc_LDC(LDC L, Cellule* pC)
{
    if( LDC_vide(L) )
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


LDC supp_structure(LDC L)
{
    Cellule *pC = chercher_structure(L);

    if( pC )
        L = supp_1ereOcc_LDC(L, pC);

    return L;
}

LDC ajouter_element(LDC L, Exemple_struct structure)
{
    Cellule *pC = chercher_structure(L);

    if( pC )
        L = LDC_ajouter_apres(L, pC, structure);
    else
        L = LDC_ajouter_Tete(L, structure);
    return L;
}


LDC supp_element(LDC L)
{
    Cellule *pC = chercher_structure(L);

    if( pC )
        L = supp_1ereOcc_LDC(L, pC);

    return L;
}

Cellule* chercher_structure(LDC L)
{
    Cellule *pC;

    if( LDC_vide(L) )
        return NULL;
    else
    {
        pC = L.tete;
        while( pC && (pC->structure.int_num != 0) )
            pC = pC->suiv;

        return (pC)? pC : NULL;
    }
}


void LDC_afficher(LDC L)
{
    Cellule *pC = NULL;
    int i = 0;

    if( LDC_vide(L) )
        printf("Liste vide\n");
    else
    {
        pC = L.tete;
        while(pC)
        {
            printf("strucutre.num#%d: %d\n", ++i, pC->structure.int_num);
            pC = pC->suiv;
        }
    }
}


void LDC_liberer_iter(LDC* L)
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

//LDC LDC_liberer_iter(LDC L)
//{
//    while( !listeDC_vide(L) )
//        L = supp_tete_LDC(L);
//
//    return L;
//}
