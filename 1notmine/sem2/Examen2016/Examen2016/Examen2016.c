#include "Examen2016.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

travail saisir()
{
    travail trav;

    printf("\nSaisir le code du travail (chaine de caracteres): ");
    scanf("%s", trav.code);
    printf("Saisir le numero du travail: ");
    scanf("%d", &trav.num);
    printf("Saisir le temps Op du travail: ");
    scanf("%d", &trav.tempsOp);

    return trav;
}

liste ajouter_travail(liste L, travail T)
{
    struct cellule *pNouvCell, *parc;

    pNouvCell = (struct cellule*)malloc(sizeof(struct cellule));
    pNouvCell->trav = T;
    pNouvCell->suiv = NULL;

    if(L == NULL)
    {
        L = pNouvCell;
    }
    else
    {
        parc = L;
        while( (*parc).suiv != NULL )
            parc = parc->suiv;

        (*parc).suiv = pNouvCell;
    }

    return L;
}

int afficher_Liste(liste L)
{
    struct cellule* parc = L;
    int nbTrav = 0;


    if(L == NULL)
    {
        printf("\nLa liste est vide\n");
    }
    else
    {
        while(parc != NULL)
        {
            nbTrav++;
            printf("\nTravail.code: %s\n"
                   "Travail.num: %d\n"
                   "Travail.tempsOp: %d\n",
                   parc->trav.code,
                   parc->trav.num,
                   parc->trav.tempsOp);
            parc = parc->suiv;
        }
   }

   return nbTrav;
}

liste inserer_Travail(liste L, travail T)
{
    struct cellule* nouv = NULL, *precedent = NULL, *courant = L;

    while( courant!=NULL && strcmp(courant->trav.code, T.code) != 0 )
    {
        precedent = courant;
        courant = courant->suiv;
    }

    if( courant == NULL )
        printf("\nIl n y a aucun travail avec le code %s dans la lSC\n", T.code);
    else
    {
        nouv = (struct cellule*)malloc(sizeof(struct cellule));
        nouv->trav = T;
        nouv->suiv = courant;

        if(courant == L)
            L = nouv;
        else
            precedent->suiv = nouv;
    }

    return L;
}

liste supprimer_Travail(liste L, int numero)
{
    struct cellule *temp = L, *prev;

    if( L == NULL )
    {
        printf("\nLa liste est vide.\n");
        return L;
    }

    // suppression au debut
    if ( temp != NULL && temp->trav.num == numero ) {
        L = temp->suiv;
        free(temp);
        return L;
    }

    while ( temp != NULL && temp->trav.num != numero ) {
        prev = temp;
        temp = temp->suiv;
    }

    if ( temp == NULL )
    {
        printf("\nIl n y a aucun travail avec le numero %d dans la LSC\n", numero);
        return L;
    }

    // suppression a la fin et au milieu
    prev->suiv = temp->suiv;

    free(temp);
    return L;
}

travail max_temps_op(liste L)
{
    struct cellule* parc = L;
    travail TravPlusLongTempOp;
    TravPlusLongTempOp.num = -1;
    TravPlusLongTempOp.tempsOp = -1;

    if(L == NULL)
    {
        return TravPlusLongTempOp;
    }
    else
    {
        TravPlusLongTempOp = L->trav;
        while(parc != NULL)
        {
            if( parc->trav.tempsOp > TravPlusLongTempOp.tempsOp)
                TravPlusLongTempOp = parc->trav;
            parc = parc->suiv;
        }
   }

   return TravPlusLongTempOp;
}

pile empiler_Travaux(pile P, liste *L)
{
    struct cellule *nouv;
    nouv = (struct cellule*)malloc(sizeof(struct cellule));

    nouv->trav = max_temps_op(*L);
    nouv->suiv = P;

    *L = supprimer_Travail(*L, nouv->trav.num);

    P = nouv;

    return P;
}

void consulter_pile(pile P)
{
    if( pile_vide(P) == 0 )
            printf("\nTravail.code: %s\n"
                   "Travail.num: %d\n"
                   "Travail.tempsOp: %d\n",
                   P->trav.code,
                   P->trav.num,
                   P->trav.tempsOp);
}


// Libérer la Pile et la liste
int pile_vide(pile P)
{
    if( P == NULL )
        return 1;
    else
        return 0;
}

pile depiler(pile p)
{
    struct cellule *suppr;
    if( pile_vide(p) == 1 )
        printf("\nLa pile est vide. Aucun element a depiler.\n");
    else
    {
        suppr = p;
        p = p->suiv;
        free(suppr);
    }
    return p;
}

void libererPile(pile* p)
{
    while( !pile_vide(*p) )
        *p = depiler(*p);
}

void libererLSC(liste *L)
{
   struct cellule* courant = *L;
   struct cellule* suivant;

   while (courant != NULL)
   {
       suivant = courant->suiv;
       free(courant);
       courant = suivant;
   }

   *L = NULL;
}
