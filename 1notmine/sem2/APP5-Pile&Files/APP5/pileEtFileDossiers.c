#include <stdlib.h>
#include <stdio.h>
#include "pileEtFileDossiers.h"

int pileEstVide(Pile p)
{
    if( p == NULL )
        return 1;
    else
        return 0;
}

Pile empiler(Pile p, Dossier d)
{
    struct cellule *nouv;
    nouv = malloc(sizeof(struct cellule));
    nouv->doss = d;
    nouv->suiv = p;
    p = nouv;
    return p;
}

Pile depiler(Pile p)
{
    struct cellule *suppr;
    if( pileEstVide(p) == 1 )
        printf("\nLa pile est vide. Aucun element a depiler.\n");
    else
    {
        suppr = p;
        p = p->suiv;
        free(suppr);
    }
    return p;
}

Dossier dernierDossierPile(Pile p)
{
    Dossier dossErr = {-1, -1};
    if( pileEstVide(p) == 0 )
        return p->doss;
    else
        return dossErr;
}

Dossier saisirDossier()
{
    Dossier doss;
    printf("\nDonner le numero du dossier: ");
    scanf("%d", &(doss.num));
    do
    {
        printf("Donner la priorite du dossier: ");
        scanf("%d", &(doss.priorite));
    }
    while( doss.priorite != 1 && doss.priorite != 2 );
    return doss;
}

Pile prioriserPileTmp(Pile p)
{
    Pile pileTmp1 = NULL;
    Pile pileTmp2 = NULL;
    Dossier doss;

    while( p != NULL )
    {
        doss = dernierDossierPile(p);
        if( p->doss.priorite == 1 )
        {
            pileTmp1 = empiler(pileTmp1, doss);
            p = depiler(p);
        }
        else
        {
            pileTmp2 = empiler(pileTmp2, doss);
            p = depiler(p);
        }
    }

    while( pileTmp2!=NULL )
    {
        p = empiler(p, dernierDossierPile(pileTmp2));
        pileTmp2 = depiler(pileTmp2);
    }
    while( pileTmp1!=NULL )
    {
        p = empiler(p, dernierDossierPile(pileTmp1));
        pileTmp1 = depiler(pileTmp1);
    }

    return p;
}

// pour tester
void afficherPile(Pile p)
{
    Pile parc = p;
    int i = 0;
    if(p == NULL)
    {
        printf("\nLa pile est vide.");
    }
    else
    {
        while( parc!=NULL )
        {
            i++;
            printf("Dossier#%d:\n\tnum: %d\n\tpriorite: %d\n", i, parc->doss.num, parc->doss.priorite);
            parc = parc->suiv;
        }
    }
}


// Partie 2
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

void depilerEnfiler(Pile *p, File *f)
{
    Dossier doss = dernierDossierPile(*p);
    *p = depiler(*p);
    enfilerDossier(f, doss);
}

void enfilerDossier(File *f, Dossier doss)
{
    struct cellule *nouv = malloc(sizeof(struct cellule));

    nouv->doss = doss;
    nouv->suiv = NULL;

    if ( FileEstVide(*f) )
    {
        f->queu = nouv;
        f->tete = nouv;
    }
    else
    {
        f->queu->suiv = nouv;
        f->queu = nouv;
    }
}

Dossier dernierDossierFile(File f)
{
    Dossier doss = {-1, -1};

    if( !FileEstVide(f) )
        return f.tete->doss;
    else
        return doss;
}

Dossier defiler(File *f)
{
    Dossier doss = {-1, -1};

    if( FileEstVide(*f) )
    {
        printf("\nLa file est vide.\n");
    }
    else
    {
        struct cellule *suppr;

        doss = f->tete->doss;
        suppr = f->tete;
        f->tete = f->tete->suiv;
        if( f->tete == NULL )
            f->queu = NULL;
        free(suppr);
    }

    return doss;
}

void ecrireDossierFichierTxt(Dossier doss, char* nomFichier)
{
    FILE *fp = fopen(nomFichier, "a");
    if( !fp )
        printf("\nErreur lors de l'ouverture du fichier \"%s\"", nomFichier);
    else
        fprintf(fp, "Numero: %d\tPriorite: %d\n", doss.num, doss.priorite);

    fclose(fp);
}

// pour tester
void AfficherFile(File f)
{
    int i = 0;
    struct cellule *parc = f.tete;

    if( parc == NULL )
        printf("\nLa file est vide\n");
    else
    {
        while( parc )
        {
            i++;
            printf("\nInfo Dossier#%d: \n", i);
            printf("\tDossier#%d.num: %d\n", i, parc->doss.num);
            printf("\tDossier#%d.priorite: %d\n", i, parc->doss.priorite);
            parc = parc->suiv;
        }
    }
}

void libererPile(Pile* p)
{
    while( !pileEstVide(*p) )
        *p = depiler(*p);
}

void libererFile(File* f)
{
    Dossier doss;
    while( !FileEstVide(*f) )
        doss = defiler(f);
}

void afficherFichierTxt(char* fileName)
{
    FILE* fp = NULL;
    int c;

    fp = fopen(fileName, "r");
    if( fp == NULL )
    {
        printf("\nErreur pendant l'ouverture du fichier: \"%s\"\n", fileName);
        return;
    }

    c = fgetc(fp);
    while ( c != EOF )
    {
        printf("%c", c);
        c = fgetc(fp);
    }
    fclose(fp);
}




