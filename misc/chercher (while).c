void chercher_livre(Livre t_livres[], int nl, int code_l, int *pos)
{
    int i = 0;
    (*pos) = -1;
    while ((i < nl) && (*pos == -1))
    {
        if (t_livres[i].code == code_l)
            (*pos) = i;
        else
            i++;
    }
}