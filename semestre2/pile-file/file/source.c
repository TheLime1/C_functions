#include <stdio.h>
#include <stdlib.h>
#include "header.h"

File *creerFile()
{
    File *file = (File *)malloc(sizeof(File));
    file->debut = NULL;
    file->fin = NULL;
    return file;
}

int estVide(File *file)
{
    return (file->debut == NULL);
}

void enfiler(File *file, int donnee)
{
    NoeudFile *nouveauNoeud = (NoeudFile *)malloc(sizeof(NoeudFile));
    nouveauNoeud->donnee = donnee;
    nouveauNoeud->suivant = NULL;

    if (estVide(file))
    {
        file->debut = nouveauNoeud;
        file->fin = nouveauNoeud;
    }
    else
    {
        file->fin->suivant = nouveauNoeud;
        file->fin = nouveauNoeud;
    }

    printf("Élément %d ajouté à la fin de la file.\n", donnee);
}

void defiler(File *file)
{
    if (estVide(file))
    {
        printf("La file est vide. Impossible de défiler un élément.\n");
        return;
    }

    NoeudFile *temp = file->debut;
    file->debut = file->debut->suivant;
    int elementDefile = temp->donnee;
    free(temp);

    printf("Élément %d retiré de la tête de la file.\n", elementDefile);

    // Vérifier si la file est maintenant vide
    if (estVide(file))
    {
        file->fin = NULL;
    }
}

int consulterTete(File *file)
{
    if (estVide(file))
    {
        printf("La file est vide. Impossible de consulter la tête de la file.\n");
        return -1;
    }

    return file->debut->donnee;
}

int main()
{
    File *file = creerFile();

    enfiler(file, 10);
    enfiler(file, 20);
    enfiler(file, 30);

    printf("Élément en tête de la file : %d\n", consulterTete(file));

    defiler(file);
    defiler(file);
    defiler(file);

    return 0;
}
