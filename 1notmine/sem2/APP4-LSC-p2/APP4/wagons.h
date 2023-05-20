#ifndef WAGONS_H_INCLUDED
#define WAGONS_H_INCLUDED

// typedef enum WAGONINFO WAGONINFO;
//enum WAGONINFO{typeLocomotive, typeWagonSimple, EnPanne=0, OK};

typedef struct
{
    int num;
    int type;   // 0: locomotive ou 1: wagon
    int etat;   // 0: en panne ou 1: ok
} Wagon;

struct Cellule
{
    Wagon wagon;
    struct Cellule* suivant;
};
typedef struct Cellule* Train;

// Partie 1
Train ajouterLocomotive(Train train, Wagon locomotive);
Train ajouterFin(Train tain, Wagon wagon);
int rechercherWagon(Train train, int num);
void afficherTrain(Train train, int* nbWagons);
// Helper functions
Wagon saisirWagon(Wagon wagon);
void afficherWagon(Wagon wagon, int i);

// Partie 2
Train supprimerWagonPanne(Train train);
Train ajouterApres(Train train, Wagon wagon, int num);
Train supprimerListe(Train train);
void journal(char* fileName, char* evenement);
// Helper functions partie 2
int wagonPanneExiste(Train train);
Train supprimerDebut(Train train);
void afficherJournal(char *fileName);


#endif // WAGONS_H_INCLUDED
