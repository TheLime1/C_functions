void menu(int *choix)
{
    do
    {
        printf("\n1-Ajouter un livre\n");
        printf("2-Afficher tous les livres\n");
        printf("3-Ajouter un emprunt \n");
        printf("4-Retourner un emprunt \n");
        printf("5-Afficher tous les emprunts retourn�s\n");
        scanf("%d", choix);
    } while ((*choix < 1) || (*choix > 5));
}

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
