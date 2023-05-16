#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

void remplir_T(person T[], int n, int k)
{
    int i;
    for (i = k; i < n; i++)
    {
        printf("nom\n");
        fflush(stdin);
        gets(T[i].nom);
        printf("prenom\n");
        gets(T[i].prenom);
        printf("age\n");
        scanf("%d", &T[i].age);
    }
}

void affiche_T(person T[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("nom %s,prenom %s,age %d", T[i].nom, T[i].prenom, T[i].age);
    }
}