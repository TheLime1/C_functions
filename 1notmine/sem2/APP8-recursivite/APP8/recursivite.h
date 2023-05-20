#ifndef RECURSIVITE_H_INCLUDED
#define RECURSIVITE_H_INCLUDED

void inverserRec(int*, int);
void palindromeRec(char*, int);
int pgcdRec(int, int);
void permuter(int*, int*);
int getLength(char*);


typedef struct
{
    char nom[10];
    float moyenne;
} Etudiant;

struct cellule
{
    Etudiant et;
    struct cellule* suiv;
};

typedef struct cellule* liste;

void afficher_liste(liste l);
void afficher_liste_inverse(liste l);
liste ajouter_etudiant(liste l, Etudiant E);
liste supprimer_etudiant(liste l, char *nom);

struct cellule* newNode(Etudiant E);
void freeLC(liste l);


void TriFusion(int Tab[], int n, int deb, int fin);
void interclasser(int tab[], int n, int deb, int milieu, int fin);
#endif // RECURSIVITE_H_INCLUDED
