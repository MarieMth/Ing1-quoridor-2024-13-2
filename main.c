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

#endif //GESTIONJEU_H

