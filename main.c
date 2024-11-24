#ifndef GESTIONJEU_H
#define GESTIONJEU_H

typedef struct {
    int iFirst, jFirst, iLast, jLast;
} Position;

void zone_stockage (int nb_joueurs, int stockage[]);
void comptage_barrieres(int joueur, int stockage[], int nb_joueurs);
void initialisationPlateau(char plateau[17][17], char nbJoueurs);
void recopierTableau(char plateauARecopier[17][17], char plateau[17][17]);
int validerPositionBarrieres(char plateau[17][17], Position barriere);
void enregistrerBarrieres(char plateau[17][17], char plateauPrec[17][17], Position barriere);
int estTableauIdentique(char plateau1[17][17], char plateau2[17][17]);
void jouerTour(char nom[4][50], int numeros[4], int nbJoueurs);
int Menu (choixDuJoueur, nbJoueurs); 
int menuPartie(choixTour); 
void passerTour(etatJeu *etatJeu); 
void annulerCoup (etatJeu *positionPion, dernier Coup); 

////////////////////////////
// Nom de la Structure : etatJeu 
// Role : tient compte de l'état du Jeu
///////////////////////////
typedef struct {
        int joueurActuel; // Indice du joueur qui joue (0 pour le premier)
        int nbJoueurs; // nombre total de joueurs définis en début de partie
        char type; // 'D' pour un déplacement d'un joueur et 'B' pour le placement d'une barrière
        int plateau [8][8];
        int plateauActuel;
    } etatJeu;
#endif //GESTIONJEU_H

