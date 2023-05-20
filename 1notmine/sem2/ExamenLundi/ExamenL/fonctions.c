#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// control de saisie (de l'unicité de l'ID) dans case1 main.c
void saisirScooter(Scooter* s)
{
    do
    {
        printf("\nkilometrage: ");
        scanf("%f", &s->kilometrage);
    }
    while(s->kilometrage<0);

    do
    {
        printf("etat: ");
        scanf("%d", &s->etat);
    }
    while(s->etat!=0 && s->etat!= 1);


    printf("ID: ");
    fflush(stdin);
    gets(s->ID);

    printf("Date:");
    printf("\n\tJour/Mois/Annee: ");
    scanf("%d/%d/%d", &s->date.jour
          , &s->date.mois
          , &s->date.annee);
}

Cellule* chercherScooter(Liste l, char id[])
{
    Cellule* parc = l;

    if ( parc == NULL )
        return NULL;
    else
    {
        while( parc != NULL )
        {
            if( strcmp(parc->scoot.ID, id) == 0 )
            {
                return parc;
            }

            parc = parc->suiv;
        }
    }

    return NULL;
}

Liste ajouterScooter(Liste l, Scooter s)
{
    Cellule *nouv, *parc;

    nouv = (Cellule*)malloc(sizeof(Cellule));
    nouv->scoot = s;
    nouv->suiv = NULL;

    if(l == NULL)
    {
        l = nouv;
    }
    else
    {
        parc = l;
        while( (*parc).suiv != NULL )
            parc = parc->suiv;

        parc->suiv = nouv;
    }

    return l;
}

void louerScooter(Liste l, char id[])
{
    Scooter scoot;
    if( chercherScooter(l, id) == NULL )
    {
        printf("\nErreur: le scooter avec l'ID \"%s\" n'existe pas dans la liste.", id);
    }
    else
    {
        Cellule* pCelScoot = chercherScooter(l, id);
        scoot = pCelScoot->scoot;
        if( scoot.etat == 0 )
        {
            printf("\nScooter deja louee.\n");
            return;
        }
        else
        {
            pCelScoot->scoot.etat = 0;
        }
    }
}

void afficherScooter(Liste l, char nomFichier[])
{
    if( !l )
        return;

    afficherScooter(l->suiv, nomFichier);
    afficherInfoScooter(l->scoot);
    ajouter_scooter_dans_fich(nomFichier, l->scoot);
}

void afficherInfoScooter(Scooter s)
{
    printf("\nInfo Scooter:\n");
    printf("\tScoot.ID: %s\n", s.ID);
    printf("\tScoot.etat: %d\n", s.etat);
    printf("\tScoot.Kilometrage: %.2f\n", s.kilometrage);
    printf("\tScoot.date: %d/%d/%d\n", s.date.jour, s.date.mois, s.date.annee);

}

void ajouter_scooter_dans_fich(char* fileName, Scooter s)
{
    FILE* fp;
    fp = fopen(fileName, "a");

    if( fp == NULL )
    {
        printf("\nErreur pendant l'ouverture du fichier: \"%s\"\n", fileName);
        return;
    }

    fprintf(fp, "%s, %d, %.2f, %d/%d/%d\n", s.ID, s.etat, s.kilometrage, s.date.jour, s.date.mois, s.date.annee);
    fclose(fp);
}

File enfilerScooter(Liste l, File f, char id[])
{
    Cellule* pCelScoot = chercherScooter(l, id);
    if( pCelScoot == NULL )
    {
        printf("\nIl n'y a aucun scooter avec l'ID \"%s\" dans la liste.\n", id);
        return f;
    }
    Scooter scoot = pCelScoot->scoot;

    Cellule *nouv = malloc(sizeof(Cellule));

    nouv->scoot = scoot;
    nouv->suiv = NULL;

    if ( FileEstVide(f) )
    {
        f.queu = nouv;
        f.tete = nouv;
    }
    else
    {
        f.queu->suiv = nouv;
        f.queu = nouv;
    }

    return f;
}

void entretenirScooter(File* f, Liste l)
{
    if( FileEstVide(*f) )
    {
        printf("\nErreur: la file est vide.\n");
        return;
    }
    else
    {
        char* id = f->tete->scoot.ID;
        Cellule* pCelScoot = chercherScooter(l, id);
        printf("\nMettre a jour la date de la nouvelle maintenance:");
        printf("\nJour/Mois/Annee: ");
        scanf("%d/%d/%d", &pCelScoot->scoot.date.jour
              , &pCelScoot->scoot.date.mois
              , &pCelScoot->scoot.date.annee);
    }

    defilerScooter(f);
}

void defilerScooter(File *f)
{
    if( FileEstVide(*f) )
    {
        printf("\nLa file est vide.\n");
    }
    else
    {
        Cellule *suppr;
        suppr = f->tete;
        f->tete = f->tete->suiv;
        if( f->tete == NULL )
            f->queu = NULL;
        free(suppr);
    }
}

Arbre insererScooters(Arbre a, Scooter s)
{
    if (a == NULL)
        a = initialiser_espace_Scooter(s);
    else
    {
        if (s.kilometrage <= a->scoot.kilometrage)
            a->pL = insererScooters(a->pL, s);
        else
            a->pR = insererScooters(a->pR, s);
    }
    return a;
}

Arbre initialiser_espace_Scooter(Scooter s)
{
    struct noeud *pNewNode = (struct noeud *)malloc(sizeof(struct noeud));

    if (pNewNode == NULL)
        printf("Espace memoire insuffisant\n");
    else
    {
        pNewNode->scoot = s;
        pNewNode->pR = NULL;
        pNewNode->pL = NULL;
    }

    return pNewNode;
}

Arbre construireArbre(Arbre a, Liste l)
{
    a = NULL;
    Cellule* parc = l;

    if( l == NULL )
    {
        printf("\nLa liste est vide\n");
    }
    else
    {
        while( parc != NULL )
        {
            a = insererScooters(a, parc->scoot);
            parc = parc->suiv;
        }
    }

    return a;
}

Arbre maxScooter(Arbre a)
{
    struct noeud* current = a;

    if( a == NULL )
        printf("\nArbre vide\n");
    else
    {
        while (current->pR != NULL)
            current = current->pR;
    }

    return current;
}

File initialiser()
{
    File f;
    f.tete = NULL;
    f.queu = NULL;
    return f;
}

int FileEstVide(File f)
{
    if( f.queu == NULL && f.tete == NULL )
        return 1;
    else
        return 0;
}

void afficher_ABR(Arbre a)
{
    if ( a != NULL )
    {
        afficher_ABR(a->pL);
        afficherInfoScooter(a->scoot);
        afficher_ABR(a->pR);
    }
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

Liste liberer_LSC(Liste liste)
{
    Cellule* current = liste;
    Cellule* next = NULL;

    while (current != NULL)
    {
        next = current->suiv;
        free(current);
        current = next;
    }

    liste = NULL;
    return liste;
}

void libererFile(File* f)
{
    while( !FileEstVide(*f) )
        defilerScooter(f);
}
