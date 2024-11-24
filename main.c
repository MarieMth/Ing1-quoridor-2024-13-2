#ifndef GESTIONJEU_H
#define GESTIONJEU_H
#define NB_LIGNES 9
#define NB_COLONNES 9

typedef struct {
    int iFirst, jFirst, iLast, jLast;
} Position;

////////////////////////////
// Nom de la Structure : etatJeu
// Role : tient compte de l'état du Jeu
///////////////////////////

typedef struct {
    int joueurActuel;
    int nbJoueurs;
    char type;
    int plateau [8][8];
    int plateauActuel;
} etatJeu;

typedef struct {
    int x, y;} Pion;

typedef struct {
    Pion pion;
    int barrieresRestantes;} Joueur;

typedef struct {
    char plateau[NB_LIGNES][NB_COLONNES]; // '.' représente une case vide, '|' pour barrière
    Joueur joueurs[4]; // Support de 4 joueurs ou de l'ordinateur
    int nombreJoueurs;
    int dernierCoup[4]; // Pour stocker le dernier coup (x1, y1, x2, y2) pour annulation
    int joueurOrdi; // Indique si l'ordinateur joue
} Quoridor;


void zoneStockage (int nb_joueurs, int stockage[]);
void comptageBarrieres(int joueur, int stockage[], int nb_joueurs);
void initialisationPlateau(char plateau[17][17], char nbJoueurs);
void recopierTableau(char plateauARecopier[17][17], char plateau[17][17]);
int validerPositionBarrieres(char plateau[17][17], Position barriere);
void enregistrerBarrieres(char plateau[17][17], char plateauPrec[17][17], Position barriere);
int estTableauIdentique(char plateau1[17][17], char plateau2[17][17]);
void jouerTour(char nom[4][50], int numeros[4], int nbJoueurs);
int Menu (choixDuJoueur, nbJoueurs);
int menuPartie(choixTour);
void nouvellePartie(int nbJoueurs);
void passerTour(etatJeu *etatJeu);
void annulerCoup (etatJeu *positionPion, dernierCoup);

#endif //GESTIONJEU_H
