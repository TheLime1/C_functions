#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED

typedef struct exemple_struct Exemple_struct;

struct exemple_struct
{
    char nom[10];
    int int_num;
    float float_num;
};

Exemple_struct saisir();

void saisirVoid(Exemple_struct* ES);

void afficherStructure(Exemple_struct structure, int i);

void afficher_tableau(Exemple_struct* tab, int n);

int chercher_chaine_dans_tableau(Exemple_struct* tab, char id[], int n);

void printArray(int*, int);

#endif // GENERAL_H_INCLUDED
