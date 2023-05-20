#include <stdio.h>
#include "Ex3.h"

void interclasser(int tab[], int n, int deb, int milieu, int fin)
{
    int n1 = milieu - deb + 1;
    int n2 = fin - milieu;

    int L[n1], R[n2];

    for (int i=0; i<n1; i++)
        L[i] = tab[deb + i];
    for (int j=0; j<n2; j++)
        R[j] = tab[milieu +1 + j];

    int i = 0;
    int j = 0;
    int k = deb;

    while ( i<n1 && j<n2 ) {
        if (L[i] <= R[j]) {
            tab[k] = L[i];
            i++;
        }
        else {
            tab[k] = R[j];
            j++;
        }
        k++;
    }

    while ( i<n1 ) {
        tab[k] = L[i];
        i++;
        k++;
    }

    while ( j<n2 ) {
        tab[k] = R[j];
        j++;
        k++;
    }
}

void TriFusion(int tab[], int n, int deb, int fin)
{
    if( deb >= fin )
        return;

    int m = (fin+deb)/2;
    TriFusion(tab, n, deb, m);
    TriFusion(tab, n, m+1, fin);

    interclasser(tab, n, deb, m, fin);
}
