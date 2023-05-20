#ifndef PILEDOSSIERS_H_INCLUDED
#define PILEDOSSIERS_H_INCLUDED

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


int pileEstVide(Pile p);
Pile empiler(Pile p, Dossier d);
Pile depiler(Pile p);
Dossier dernierDossierPile(Pile p);
Dossier saisirDossier();
// trier pile
Pile prioriserPileTmp(Pile p);
void afficherPile(Pile p); // pour tester

// Partie 2
File initialiser();
int FileEstVide(File f);
void depilerEnfiler(Pile *p, File *f);
void enfilerDossier(File *f, Dossier doss);
Dossier dernierDossierFile(File f);
Dossier defiler(File *f);
void ecrireDossierFichierTxt(Dossier doss, char* nomFichier);
void AfficherFile(File f); // pour tester

void libererPile(Pile *pile);
void libererFile(File *file);
void afficherFichierTxt(char* fileName);

#endif // PILEDOSSIERS_H_INCLUDED
