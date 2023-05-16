#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

int main()
{
    person *tab;
    int n, m;
    printf("le nombre de persons");
    scanf("%d", &n);
    tab = (person *)malloc(n * sizeof(person));
    if (tab == NULL)
    {
        printf("espace memoir insufficient")
    }
    else
    {
        remplir_T(tab, n);
    }
    printf("\n");
    printf("le nombre de person a ajouter");
    scanf("%d", &m);
    tab = (person *)realloc(tab, (n + m) * sizeof(person));
    if (tab == NULL)
    {
        printf("espace insufficient")
    }
    else
    {
        for (size_t i = 0; i < count; i++)
        {
            remplir_T(tab, n + m, n);
            affiche_T(tab, n + m);
        }
    }
    free(tab);
}