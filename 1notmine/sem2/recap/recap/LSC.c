#include "LSC.h"
#include <stdlib.h>
#include <stdio.h>

int LSC_vide(LSC pListe)
{
    return( pListe == NULL );
}

void LSC_parcours(LSC pListe, int* nbCellules)
{
    struct Cellule* parc = pListe;

    *nbCellules = 0;

    if(pListe == NULL)
    {
        printf("\nLa liste est vide\n");
    }
    else
    {
        while(parc != NULL)
        {
            (*nbCellules)++;
            afficherStructure(pListe->structure, *nbCellules);
            parc = parc->suivant;
        }
    }
}

LSC LSC_ajouter_debut(LSC pListe, Exemple_struct structure)
{
    struct Cellule* nouv = NULL;

    nouv = (struct Cellule*)malloc(sizeof(struct Cellule));
    nouv->structure = structure;
    nouv->suivant = NULL;

    nouv->suivant = pListe;
    pListe = nouv;

    return pListe;
}

LSC LSC_ajouter_Fin(LSC pListe, Exemple_struct structure)
{
    struct Cellule *nouv, *parc;

    nouv = (struct Cellule*)malloc(sizeof(struct Cellule));
    nouv->structure = structure;
    nouv->suivant = NULL;

    if(pListe == NULL)
    {
        pListe = nouv;
    }
    else
    {
        parc = pListe;
        while( (*parc).suivant != NULL )
            parc = parc->suivant;

        parc->suivant = nouv;
    }

    return pListe;
}


int LSC_rechercher_int(LSC pListe, int num)
{
    struct Cellule* parc;
    parc = pListe;
    int i = 0;

    if(parc == NULL)
    {
        printf("\nLa liste est vide\n");
    }
    else
    {
        while(parc != NULL )
        {
            if( parc->structure.int_num == num )
            {
                printf("Structure se trouve dans le maillon #%d", i);
                afficherStructure(parc->structure, i+1);
                return 1;
            }

            parc = parc->suivant;
            i++;
        }
    }
    return 0;
}


LSC LSC_ajouter_Apres(LSC pListe, Exemple_struct structure, int num)
{
    struct Cellule* nouv = NULL, *courant = pListe;

    while( courant!=NULL && courant->structure.int_num != num )
    {
        courant = courant->suivant;
    }

    if( courant == NULL )
        printf("\nIl n y a aucun wagon avec le numro %d\n", num);
    else
    {
        nouv = (struct Cellule*)malloc(sizeof(struct Cellule));
        nouv->structure = structure;
        nouv->suivant = courant->suivant;

        courant->suivant = nouv;
    }

    return pListe;
}

LSC LSC_ajouter_Avant(LSC pListe, Exemple_struct structure, int num)
{
    struct Cellule* nouv = NULL, *precedent = NULL, *courant = pListe;

    while( courant!=NULL && courant->structure.int_num != num )
    {
        precedent = courant;
        courant = courant->suivant;
    }

    if( courant == NULL )
        printf("\nIl n y a aucun wagon avec le numro %d\n", num);
    else
    {
        nouv = (struct Cellule*)malloc(sizeof(struct Cellule));
        nouv->structure = structure;
        nouv->suivant = courant;

        if(courant == pListe)
            pListe = nouv;
        else
            precedent->suivant = nouv;
    }

    return pListe;
}


// supprimer au debut, au milieu et a la fin
void LSC_supprimer_int(LSC pListe, int key)
{
    struct Cellule *temp = pListe, *prev;

    if( pListe == NULL )
    {
        printf("\nLa liste est vide.\n");
        return;
    }

    // si key est dans la premiere cellule
    if (temp != NULL && temp->structure.int_num == key)
    {
        pListe = temp->suivant;
        free(temp);
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->suivant'
    while (temp != NULL && temp->structure.int_num != key)
    {
        prev = temp;
        temp = temp->suivant;
    }

    // If key was not present in linked list
    if (temp == NULL)
    {
        printf("\nKey not present in the LSC");
        return;
    }

    // key found, deletion
    // Unlink the node from linked list
    prev->suivant = temp->suivant;

    free(temp);
}

LSC LSC_supprimer_Debut(LSC pListe)
{
    struct Cellule* tmp;

    if( pListe != NULL )
    {
        tmp = pListe;
        pListe = pListe->suivant;
        free(tmp);
    }
    return pListe;
}

LSC LSC_supprimer_Fin(LSC pListe)
{
    struct Cellule *tmp, *courant;

    if( pListe != NULL )
    {
        if( pListe->suivant == NULL )
        {
            free(pListe);
            pListe = NULL;
        }
        else
        {
            tmp = pListe;
            courant = pListe;

            while( tmp->suivant != NULL )
            {
                courant = tmp;
                tmp = tmp->suivant;
            }

            courant->suivant = NULL;
            free(tmp);
        }
    }

    return pListe;
}

LSC LSC_supprimer_Milieu(LSC pListe, int num)
{
    struct Cellule* courant = pListe, *precedent = NULL;
    int trouve = 0;

    if( pListe != NULL )
    {
        if( pListe->structure.int_num == num )
            pListe = LSC_supprimer_Debut(pListe);
        else
        {
            while( courant != NULL && !trouve )
            {
                if( courant->structure.int_num == num )
                    trouve = 1;
                else
                {
                    precedent = courant;
                    courant = courant->suivant;
                }
            }
            if( trouve )
            {
                precedent->suivant = courant->suivant;
                free(courant);
            }
        }
    }
    return pListe;
}

LSC LSC_liberer(LSC liste)
{
    struct Cellule* current = liste;
    struct Cellule* next = NULL;

    while (current != NULL)
    {
        next = current->suivant;
        free(current);
        current = next;
    }

    liste = NULL;
    return liste;
}
