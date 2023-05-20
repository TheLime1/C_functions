#ifndef EXAMEN2018_H_INCLUDED
#define EXAMEN2018_H_INCLUDED

typedef struct ouvrage Ouvrage;
typedef struct abonne Abonne;
typedef struct celluleLSC* listeLSC;
typedef struct noeudABR* Abr;

struct ouvrage
{
    char titre[50];
    int code;
};

struct abonne
{
    int numInsc;
    char nom[15];
    listeLSC ouvrageEmp;
};

struct celluleLSC
{
    Ouvrage oeuvre;
    struct celluleLSC* suiv;
};

struct noeudABR
{
    Abonne abonne;
    struct noeudABR* pL;
    struct noeudABR* pR;
};



Ouvrage Saisir_ouvrage();

void Remplir_bibio(char nomfich[], int n);

void Saisir_Abonne(Abonne* x);

Abr Inserer_abonne(Abr a, Abonne x);

Ouvrage chercher_ouvrage(char nomfich[], int code);

struct noeudABR* chercher_Abonne(Abr A, int num);

Abonne Ajouter_ouvrage(Abonne x, Ouvrage Ouv);

void Emprunter_ouvrage(Abr A, int code_ouv, int num);

void Afficher_Abonne(Abonne x);
void afficherLSC(listeLSC L);

void Afficher_ABR(Abr Ar);

void Liberer_ABR_et_LSC(Abr a);
void libererLSC(listeLSC *L);

#endif // EXAMEN2018_H_INCLUDED
