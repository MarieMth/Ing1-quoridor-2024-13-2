#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include "gestionDuJeu.h"
#define NB_LIGNES 9
#define NB_COLONNES 9

void positionPions (char plateau[17][17], int nb_joueurs);
void caracterePion (int nb_joueur, char* car_pion);
void gotoligcol(int lig, int col);
void Color(int couleurDuTexte,int couleurDeFond);
void couleur();
void afficherMenu(); 
void afficherAide(); 
void afficherScoresJoueurs(); 
void quitterJeu(); 
void afficherMenuPartie(); 
void gotoligcol( int lig, int col );
void color(int couleurDuTexte,int couleurDeFond);
void afficheTitre();
void afficheLabels();
void affichePlateau(char plateau[17][17]);
void afficheMenuJeu();
void afficheStatutJeu();
void afficheBarriereV(char plateau[17][17]);
void afficheBarriereH(char plateau[17][17]);
int iToligne(int i);
int iToCol(int j);
void deplacement(int* i, int* j, int choix);
void placementPremiereBarriere(int* i, int* j, int choix);
int placementDeuxiemeBarriere(int iFirst, int jFirst, int* iLast, int* jLast, int choix);
void refreshScreen(char plateau[17][17]);


#endif //AFFICHAGE_H
