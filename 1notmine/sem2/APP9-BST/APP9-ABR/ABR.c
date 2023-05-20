#include "ABR.h"
#include <stdlib.h>
#include <stdio.h>

abr initialiser(Etudiant e)
{
    struct noeud *pNewNode = (struct noeud *)malloc(sizeof(struct noeud));

    if (pNewNode == NULL)
        printf("Espace memoire insuffisant\n");
    else
    {
        pNewNode->e = e;
        pNewNode->pR = NULL;
        pNewNode->pL = NULL;
    }

    return pNewNode;
}

abr inserer(abr a, Etudiant e)
{
    if (a == NULL)
        a = initialiser(e);
    else
    {
        if (e.moyenne <= a->e.moyenne)
            a->pL = inserer(a->pL, e);
        else
            a->pR = inserer(a->pR, e);
    }
    return a;
}

abr construireArbre(abr a, char nomFich[])
{
    Etudiant e;
    FILE *pFileMoyennes = fopen(nomFich, "r");

    if (pFileMoyennes == NULL)
    {
        printf("\nErreur lors de l'ouverture du fichier %s", nomFich);
        return NULL;
        return NULL;
    }

    while (fscanf(pFileMoyennes,
                  "%d %s %s %d %f\n",
                  &e.id,
                  e.nom,
                  e.prenom,
                  &e.niveau,
                  &e.moyenne) != EOF)
    {
        a = inserer(a, e);
    }

    fclose(pFileMoyennes);
    return a;
}

void afficher(abr a)
{
    if (a != NULL)
    {
        afficher(a->pL);
        printf("ID: %d\tNom: %s\tPrenom: %s\t\tNiveau: %d\tMoyenne: %.2f\n",
               a->e.id, a->e.nom, a->e.prenom, a->e.niveau, a->e.moyenne);
        afficher(a->pR);
    }
}

int calculerNombre(abr a)
{
    //    int c = 1;
    if (a == NULL)
        return 0;
    else
        return 1 + calculerNombre(a->pL) + calculerNombre(a->pR);
    //    else
    //    {
    //        c += calculerNombre(a->pL);
    //        c += calculerNombre(a->pR);
    //    }
    //    return c;
}

void construireListe(abr a, LDC *L, float BI, float BS)
{
    if ( a == NULL )
        return;

    if ( BI < a->e.moyenne )
        construireListe(a->pL, L, BI, BS);

    if ( (BI <= a->e.moyenne) && (a->e.moyenne < BS) )
        *L = ajouter_fin(*L, a->e);
    //        L->tete = ajouter_fin_Rec(L->tete, a->e);

    if ( a->e.moyenne < BS )
        construireListe(a->pR, L, BI, BS);
}

///
LDC init_LDC()
{
    LDC L;
    L.tete = NULL;
    L.queu = NULL;
    return L;
}

int listeDC_vide(LDC L)
{
    return (L.tete == NULL && L.queu == NULL);
}

struct noeud *ajouter_fin_Rec(struct noeud *pNode, Etudiant e)
{
    if (pNode == NULL)
        return initialiser(e);
    else
        pNode->pR = ajouter_fin_Rec(pNode->pR, e);

    return pNode;
}

LDC ajouter_fin(LDC L, Etudiant e)
{
    struct noeud *pNouv;

    pNouv = (struct noeud *)malloc(sizeof(struct noeud));
    if (pNouv == NULL)
        printf("Espace memoire insuffisant\n");
    else
    {
        pNouv->e = e;
        pNouv->pR = NULL;
        pNouv->pL = L.queu;
        if (!listeDC_vide(L))
            L.queu->pR = pNouv;
        else
            L.tete = pNouv;
        L.queu = pNouv;
    }
    return L;
}

void afficher_LDC_Rec(struct noeud *node)
{
    if (node == NULL)
        return;

    printf("moyene: %.2f\n", node->e.moyenne);
    afficher_LDC_Rec(node->pR);
}

void freeDLL_Rec(struct noeud *pNode)
{
    if (pNode == NULL)
        return;

    freeDLL_Rec(pNode->pR);
    free(pNode);
}

LDC freeDLL(LDC L)
{
    while (!listeDC_vide(L))
        L = supp_tete_LDC(L);

    return L;
}

LDC supp_tete_LDC(LDC L)
{
    struct noeud *pNode = L.tete;

    if (listeDC_vide(L))
        return L;

    if (L.tete == L.queu)
    {
        L = init_LDC(L);
    }
    else
    {
        L.tete = L.tete->pR;
        L.tete->pL = NULL;
    }
    free(pNode);

    return L;
}

void freeABR_Rec(abr a)
{
    if (a != NULL)
    {
        freeABR_Rec(a->pL);
        freeABR_Rec(a->pR);
        free(a);
    }
}
