#ifndef PILE_FILE_H_INCLUDED
#define PILE_FILE_H_INCLUDED

typedef struct
{
    int num;
    int priorite; // 1 ou 2
} Dossier;

struct cellule
{
    Dossier doss;
    struct cellule *suiv;
};

typedef struct cellule *Pile;

typedef struct
{
    struct cellule* tete;
    struct cellule* queu;
} File;

// Pile
int pileEstVide(Pile p);
Pile empiler(Pile p, Dossier d);
Pile depiler(Pile p);
Dossier dernierDossierPile(Pile p); // consulter sommet
Dossier saisirDossier();
Pile prioriserPileTmp(Pile p); // trier
// la structure de donn�e pile ne comprend
// pas une fonction d'affichage
void afficherPile(Pile p); // � enlever apr�s test

// File
File initialiser();
int FileEstVide(File f);
void depilerEnfiler(Pile *p, File *f);
void enfilerDossier(File *f, Dossier doss);
Dossier dernierDossierFile(File f);
Dossier defiler(File *f);
// la structure de donn�e file ne comprend
// pas une fonction d'affichage
void afficherFile(File f); // � enlever apr�s test

void libererPile(Pile *pile);
void libererFile(File *file);

void ecrireDossierFichierTxt(Dossier doss, char* nomFichier);
void afficherFichierTxt(char* fileName);


#endif // PILE_FILE_H_INCLUDED
