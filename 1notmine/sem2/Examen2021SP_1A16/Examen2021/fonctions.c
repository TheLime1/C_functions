#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void saisirCompte(Compte* c)
{
    printf("\nSolde: ");
    scanf("%f", &c->solde);

    printf("\nNumero: ");
    scanf("%d", &c->numero);

    do
    {
        printf("DernTypeOp: ");
        fflush(stdin);
        scanf("%c", &c->typeDernOp);
    }
    while(c->typeDernOp!='R' && c->typeDernOp!= 'V');


    printf("nom: ");
    fflush(stdin);
    gets(c->nom);

    printf("dateDerOp:");
    printf("\n\tJour/Mois/Annee: ");
    scanf("%d/%d/%d", &c->dateDerOp.jour
          , &c->dateDerOp.mois
          , &c->dateDerOp.annee);
}


Cellule* chercherCompte(LDC l, int num)
{
    Cellule *pC;

    if( LDC_vide(l) )
        return NULL;
    else
    {
        pC = l.tete;
        while( pC && (pC->compte.numero != num) )
            pC = pC->suiv;

        return (pC)? pC : NULL;
    }
}


LDC ajouterCompte(LDC L, Compte c)
{
//    Cellule* pCelComp = chercherCompte(L, c.numero);
//    if( pCelComp != NULL )
//    {
//        printf("Le numero du compte doit etre unique");
//        return NULL;
//    }
    Cellule *pC;

    if( LDC_vide(L) )
    {
        L = LDC_ajouter_Tete(L, c);
        return L;
    }
    else
    {
        pC = L.tete;
        while( pC && pC->compte.numero < c.numero)
            pC = pC->suiv;

        if( pC )
            L = LDC_ajouter_avant(L, pC, c);
        else
            L = LDC_ajouter_Fin(L, c);

        return L;
    }
}

LDC LDC_ajouter_Tete(LDC L, Compte compte)
{
    Cellule* pNouv;

    pNouv = (Cellule*)malloc(sizeof(Cellule));
    if(!pNouv )
        printf("Espace memoire insuffisant\n");
    else
    {
        pNouv->compte = compte;
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


LDC LDC_ajouter_Fin(LDC L, Compte compte)
{
    Cellule* pNouv;

    pNouv = (Cellule*)malloc(sizeof(Cellule));
    if(!pNouv)
        printf("Espace memoire insuffisant\n");
    else
    {
        pNouv->compte = compte;
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


LDC LDC_ajouter_avant(LDC L, Cellule *pIndex, Compte compte)
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
            L = LDC_ajouter_Tete(L, compte);
        else
        {
            pNouv->compte = compte;
            pNouv->suiv = pIndex;
            pNouv->prec = pIndex->prec;
            (pIndex->prec)->suiv = pNouv;
            pIndex->prec = pNouv;
        }
    }
    return L;
}

void Operation(LDC l, int num, float montant, char operation, Date d)
{
    Cellule* pCelComp = chercherCompte(l, num);

    if( LDC_vide(l) )
    {
        printf("\nLa liste est vide\n.");
    }
    else if( pCelComp == NULL )
    {
        printf("\nLe compte n'existe pas dans las liste.\n");
    }
    else
    {
        pCelComp->compte.typeDernOp = operation;
        pCelComp->compte.dateDerOp = d;
        pCelComp->compte.solde = montant;
    }
}

void afficherCompte(LDC L)
{
    Cellule *pC = NULL;
    int i = 0;

    if( LDC_vide(L) )
        printf("\nListe vide.\n");
    else
    {
        pC = L.tete;
        while(pC)
        {
            ++i;
            printf("compte.num#%d: %d\ncompte.solde:#%d: %.2f",
                    i, pC->compte.numero , i, pC->compte.solde);
            pC = pC->suiv;
        }
    }
}

void sauvegarderCompte(LDC L, char nomfichier[])
{
    Cellule *pC = NULL;

    if( LDC_vide(L) )
        printf("Liste vide\n");
    else
    {
        pC = L.tete;
        while(pC)
        {
            enregistrer_compte_dans_fichier_binaire(pC->compte, nomfichier);
            pC = pC->suiv;
        }
    }

}

void enregistrer_compte_dans_fichier_binaire(Compte c, char* nomFichier)
{
    FILE* fp;

    fp = fopen(nomFichier, "ab");

    if(fp == NULL)
    {
        printf("\nErreur pendant la creation du fichier: \"%s\"\n", nomFichier);
        return;
    }

    fwrite(&c, sizeof(Compte), 1, fp);

    fclose(fp);
}


Arbre inserer(Arbre a, Compte c)
{
    if (a == NULL)
        a = initialiser_noeud_compte(c);
    else
    {
        if (c.solde <= a->compte.solde)
            a->pL = inserer(a->pL, c);
        else
            a->pR = inserer(a->pR, c);
    }
    return a;
}

Arbre initialiser_noeud_compte(Compte c)
{
    struct noeud *pNewNode = (struct noeud *)malloc(sizeof(struct noeud));

    if (pNewNode == NULL)
        printf("Espace memoire insuffisant\n");
    else
    {
        pNewNode->compte = c;
        pNewNode->pR = NULL;
        pNewNode->pL = NULL;
    }

    return pNewNode;
}

Arbre remplirArbre(Arbre a, LDC l)
{
    liberer_ABR_Rec(a);
    a = NULL;

    Cellule *pC = NULL;

    if( LDC_vide(l) )
        printf("\nListe vide\n");
    else
    {
        pC = l.tete;
        while(pC)
        {
            a = inserer(a, pC->compte);
            pC = pC->suiv;
        }
    }
    return a;
}

void afficher(Arbre a)
{
    if ( a != NULL )
    {
        afficher(a->pR);
        printf("num: %d\tNom: %s\typeDernOp: %c\t\tsolde: %.2f\tdateDerOp: %d/%d/%d\n",
               a->compte.numero,
               a->compte.nom,
               a->compte.typeDernOp,
               a->compte.solde,
               a->compte.dateDerOp.jour, a->compte.dateDerOp.mois, a->compte.dateDerOp.annee);
        afficher(a->pL);

    }
}

int calculerNbr(Arbre a, float montant)
{
    int nbCmptSupMont = 0;
    if ( a != NULL )
    {
        if( a->compte.solde > montant)
        {
            nbCmptSupMont++;
            calculerNbr(a->pR, montant);
        }
        else
        {
            calculerNbr(a->pL, montant);
        }
    }

    return nbCmptSupMont;
}


void liberer_ABR_Rec(Arbre a)
{
    if (a != NULL)
    {
        liberer_ABR_Rec(a->pL);
        liberer_ABR_Rec(a->pR);
        free(a);
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
