#ifndef ESCALADE_H_INCLUDED
#define ESCALADE_H_INCLUDED

typedef struct station Station;
typedef struct alpiniste Alpiniste;
typedef struct cellule Cellule;
typedef struct listeDC LDC;

struct alpiniste
{
    int arriv_mont;
    int arriv_desc;
};

struct station
{
    int num; // unique et >=1
    Alpiniste Aalp[4];
};

struct cellule
{
    Station station;
    struct cellule* suiv;
    struct cellule* prec;
};

struct listeDC
{
    Cellule* tete;
    Cellule* queu;
};


LDC init_chemin(LDC L);
Station saisir_station(LDC L);

Station* chercher_station(LDC L, int num);
LDC ajouter_station(LDC L, Station station);

void afficher_chemin(LDC L);

void MAJ_Station(Station station);
void MAJ_tous_stations(LDC L);

int Score_Alpiniste(Station derniere_station, int indice);

/////////////////////////
LDC ajout_Fin(LDC L, Station station);
LDC ajout_En_Tete(LDC L, Station station);
LDC ajout_avant(LDC L, Cellule *pIndex, Station station);

int listeDC_vide(LDC L);
void libererLDC(LDC* L);

#endif // ESCALADE_H_INCLUDED
