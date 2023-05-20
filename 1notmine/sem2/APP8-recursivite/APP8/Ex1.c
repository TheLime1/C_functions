#include "Ex1.h"

// inverser un tableau d'entier
void inverserRec(int* tabEnt, int n)
{
    if( tabEnt >= tabEnt+n-1 )
        return;

    permuter(tabEnt, tabEnt+n-1);
    inverserRec(tabEnt+1, n-2);
}

void palindromeRec(char* mot, int n)
{
    // si mot est composé d'une seule lettre
    if( n == 1 )
    {
        printf("\nLe mot est palindrome.\n");
        return;
    }

    if( mot >= mot+n-1 )
    {
        printf("\nLe mot est palindrome.\n");
        return;
    }

    if( *mot != *(mot+n-1) )
    {
        printf("\nLe mot n'est pas palindrome.\n");
        return;
    }

    palindromeRec(mot+1, n-2);
}

int pgcdRec(int a, int b)
{
    return (b == 0)? a : pgcdRec(b, a%b);
}

int getLength(char* mot)
{
    int i=0;
    while(mot[i] != '\0')
        i++;

    return i;
}

void permuter(int *x, int *y)
{
    int temp;
    if( x!=y )
    {
        temp = *x;
        *x = *y;
        *y = temp;
    }
}

void printArray(int* arr, int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
