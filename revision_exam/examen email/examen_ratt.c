#include <stdio.h>
#include <stdlib.h>
#include "terro.h"
#include<string.h>
int main()
{
    int choix;
    livreur l;
    commande c ;
    livreur tabl[20];
    int nbl;
    char ide[20];
    int code;
    int nbr_nc;
    int totcomd;
    float prc;

    do
    {

        do
        {
            printf("**********bienvenu*********\n");
            printf("****tapez 0 pour quitter\n****");
            printf("****tapez 1 pour ajouter un nouveau livreur\n****");
            printf("****tapez 2 pour afficher les livreurs\n****");
            printf("****tapez 3 pour ajouter une commande a un livreur\n****");
            printf("****tapez 4 pour confirmer une commande\n****");
            printf("****tapez 5 pour afficher le nombre de commande non confirme dun livreur donne\n****");
            printf("****tapez 6 pour afficher le prix total des commandes\n****");
            printf("****tapez 7 pour supprimer une commande \n****");

            printf("*********************************\n");
            printf("veuillez saisir votre choix \n ");
            scanf("%d",&choix);

        }
        while((choix<0)||(choix>7));
        switch(choix){
    case 1:
        saisir_livreur(&l);
        printf("donner le ide\n");
        fflush(stdin);
        gets(l.ide);
        ajouter_livreur(tabl,&nbl,l);
        break;
    case 2:
        afficher_livreur(tabl,nbl);
        break;
    case 3:
        saisir_commande(c);
        printf("donner le ide\n");
        fflush(stdin);
        gets(l.ide);
        ajouter_commande(tabl,nbl,ide,c);
        break;
    case 4:
        printf("donner le ide\n");
        fflush(stdin);
        gets(l.ide);
        printf("veuillez donner le code\n");
        scanf("%d",& code);
        confirmer_commande(tabl,nbl,ide,code);
        break;
    case 5:
        printf("donner le ide\n");
        fflush(stdin);
        gets(l.ide);
        nbr_nc=non_confirmee(tabl,nbl,ide);
        printf("le nbre des commandes non confirme est %d",nbr_nc);
        break;
    case 6:
        pourcentage_nonconf(tabl,nbl,totcomd,prc);
        break;
    case 7:
        printf("veuiller donner le code de commande a supprimer\n");
        scanf("%d",&code);
        printf("veuillez donner ide\n");
        fflush(stdin);
        gets(ide);
        supprimer_commande(tabl,nbl,ide,code);
        break;

        }
    }
    while(choix!=0);
    return 0;
}
*****************************************************
#include <stdio.h>
#include <stdlib.h>
#include "terro.h"
#include<string.h>
void saisir_livreur(livreur *l)
{
    int i;
    printf("veuillez donner le code de livreur\n");
    fflush(stdin);
    gets(l->ide);
    l->nbr_com=0;
    l->prix_tot=0;
}
int chercher_livreur(livreur tabl[],int nbl,char idl[])
{
    int i;
    for(i=0; i<nbl; i++)
    {
        if(strcmp(tabl[i].ide,idl)==0)
            return i;
        else
            return -1;
    }
}
void ajouter_livreur(livreur tabl[],int *nbl,livreur l)
{
    int i;
    if( chercher_livreur(tabl,nbl,l.ide)>=0)
        printf("le livreur excite deja\n");
    else
    {


        printf("veuillez donner l'identifiant du livreur\n");
        fflush(stdin);
        gets(tabl[*nbl].ide);
        printf("veuillez donner le nombre de commande");
        scanf("%d",&tabl[*nbl].nbr_com);
        printf("veuillez donner le prix totale de commande \n");
        scanf("%d",&tabl[*nbl].prix_tot);
        for(i=0; i<tabl[*nbl].nbr_com; i++)
        {
            printf("tab[i]=",i);
            scanf("%d",&tabl[i].tab_c[i].code);
            scanf("%d",&tabl[i].tab_c[i].prix);
            printf("livrer ou non\n");
            fflush(stdin);
            gets(tabl[i].tab_c[i].etat);
        }
    }

    (*nbl)++;

}
void afficher_livreur(livreur tabl[],int nbl)
{
    int i,j;
    for(i=0; i<nbl; i++)
    {
        printf("l'identifiant de livreru est %s \n",tabl[i].ide);
        printf("le nombre des commande de livreur est %d \n",tabl[i].nbr_com);
        printf("le prix totale des commandes est %f \n",tabl[i].prix_tot);
        for(j=0; j<tabl[i].nbr_com; j++)
        {
            printf("le code est %d\n",tabl[i].tab_c[j].code);
            printf("l etat est %s\n",tabl[i].tab_c[j].etat);

        }

    }
}
commande saisir_commande()
{
    commande c;
    printf("veuillez donner le code du commande \n");
    scanf("%d",&c.code);
    printf("veuillez donner le prix du commande \n ");
    scanf("%f",&c.prix);
    c.etat=='non confirmee';
    return c;
}
int chercher_commande(livreur tabl[],int nbl,char idl[],int code)
{
    int i,j;
    for(i=0; i<nbl; i++)
    {
        if(strcmp(tabl[i].ide,idl)==0)

            for(j=0; j<tabl[i].nbr_com; j++)
            {
                if (tabl[i].tab_c[j].code==code)
                    return j;
            }

        else
            return -1;
    }
}
int ajouter_commande(livreur tabl[],int nbl,char idl[],commande c)
{
    int i;
    for(i=0; i<nbl; i++)
    {
        if(strcmp(tabl[i].ide,idl)==0)
        {
            saisir_commande(c);
            tabl[i].nbr_com++;
        }
    }
}
void confirmer_commande(livreur tabl[],int nbl,char idl[],int code)
{
    int i;
    for(i=0; i<nbl; i++)
    {
        if(chercher_commande(tabl,nbl,idl,code)>=0)
            tabl[i].tab_c[i].etat=='confirmer';
        tabl[i].tab_c[i].prix ++;
    }
}
int non_confirmee(livreur tabl[],int nbl,char idl[])
{
    int nb=0,i;
    for(i=0; i<nbl; i++)
    {
        if(strcmp(tabl[i].tab_c[i].etat,' nom confirmer')==0)
            nb ++;
    }
    return nb;
}
void pourcentage_nonconf(livreur tabl[],int nbl,float *totcomd,float prc)
{
    int i;
    totcomd=0;
    for(i=0; i<nbl; i++)
    {
        (*totcomd)= *totcomd+tabl[i].tab_c[i].prix;
        // pourcentage pas fait

    }
}
void supprimer_commande(livreur tabl[],int nbl,char idl[],int code)
{
    int i;
    for (i=0; i<nbl; i++)
    {
        if(chercher_commande(tabl,nbl,idl,code)>=0)
            tabl[i].tab_c[i] =tabl[i+1].tab_c[i+1];
        i--;
        tabl[i].nbr_com--;

    }
}


***************************************************
#ifndef TERRO_H_INCLUDED
#define TERRO_H_INCLUDED
#include "terro.h"
#include<string.h>
typedef struct
{
    int code;
    float prix;
    char etat[20];
} commande;
typedef struct
{
    char ide[20];
    int nbr_com;
    float prix_tot;
    commande tab_c[20];
} livreur;
void saisir_livreur(livreur *l);
int chercher_livreur(livreur tabl[],int nbl,char idl[]);
void ajouter_livreur(livreur tabl[],int *nbl,livreur l);
void afficher_livreur(livreur tabl[],int nbl);
commande saisir_commande();
int chercher_commande(livreur tabl[],int nbl,char idl[],int code);
int ajouter_commande(livreur tabl[],int nbl,char idl[],commande c);
void confirmer_commande(livreur tabl[],int nbl,char idl[],int code);
int non_confirmee(livreur tabl[],int nbl,char idl[]);
void pourcentage_nonconf(livreur tabl[],int nbl,float *totcomd,float prc);


#endif // TERRO_H_INCLUDED