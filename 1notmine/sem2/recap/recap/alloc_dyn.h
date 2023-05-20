#ifndef ALLOC_DYN_H_INCLUDED
#define ALLOC_DYN_H_INCLUDED
#include "general.h"

Exemple_struct* ajouter_elem_tableau(Exemple_struct v, Exemple_struct* tab, int* n);

void supprimer_elem_tableau(Exemple_struct* tab ,char id[], int* n);

void liberer_tableau(Exemple_struct* tab);

#endif // ALLOC_DYN_H_INCLUDED
