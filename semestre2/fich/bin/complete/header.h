#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct
{
    char nom[10], prenom[10];
    int age;
} person;

void remplir_T(person T[], int n, int k);
void affiche_T(person T[], int n);

#endif
