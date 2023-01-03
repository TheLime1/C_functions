#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;

typedef struct
{
    Date d;
} Lettre;

void inputDate(Lettre *L)
{
    do
    {
        printf("Enter the day: ");
        scanf("%d", &(L->d.jour));
    } while (((L->d.jour) < 0) && ((L->d.jour) > 32));
    do
    {
        printf("Enter the month: ");
        scanf("%d", &(L->d.mois));
    } while (((L->d.mois) < 0) && ((L->d.mois) > 13));
    do
    {
        printf("Enter the year: ");
        scanf("%d", &(L->d.annee));
    } while ((L->d.annee) < 0);
}

int main()
{
    Lettre L;
    inputDate(&L);
    return 0;
}
