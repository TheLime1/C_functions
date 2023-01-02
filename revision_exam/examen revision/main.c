#include <stdio.h>
#include <stdlib.h>
#include "livre.h"
int main()
{
    Livre p_livre, t_livres[55];
    Emprunt p_emprunt, t_emprunts[55];
    int i, code_l, choix, nl, ne, pos, code, num;
    do
    {
        menu(&choix);
        switch (choix)
        {
        case 1:
            saisir_livre(&p_livre);
            printf("dooner le code\n");
            scanf("%d", &code_l);
            ajouter_livre(t_livres, &nl, p_livre);
            break;
        case 2:
            afficher_livres(t_livres, nl);
            break;
        case 3:
            saisir_emprunt(&p_emprunt);
            printf("saisir le num\n");
            scanf("%d", &num);
            ajouter_emprunt(t_emprunts, &ne, t_livres, nl);
            break;
        case 4:

        case 5:
            afficher_emprunts_retournes(t_emprunts, ne);
            break;
            return 0;
        }
    } while (choix != 0);
}
