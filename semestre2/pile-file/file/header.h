#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct NoeudFile
{
    int donnee;
    struct NoeudFile *suivant;
} NoeudFile;

typedef struct File
{
    NoeudFile *debut;
    NoeudFile *fin;
} File;

File *creerFile();
int estVide(File *file);
void enfiler(File *file, int donnee);
void defiler(File *file);
int consulterTete(File *file);

#endif
