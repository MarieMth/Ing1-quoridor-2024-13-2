#include <stdio.h>
#include "gestionJeu.h"
#include "affichage.h"

///////////////////////////////////////
// Nom du sous-programme : zoneStockage
// Rôle : Attribue une zone de stockage de barrieres à chaque joueur avec une répartition équitable
///////////////////////////////////////
void zoneStockage (int nbJjoueurs, int stockage[]) { //zone de stockage attribuée à chaque joueur avec une répartition équitable de barrieres
  int nb_barrieres;
  if (nbJjoueurs == 2) {
    nb_barrieres = 10;
  } else {
    nb_barrieres = 5;
  }
  for (int i=0; i<nb_barrieres; i++) {
    stockage[i] = nb_barrieres;
    printf("Joueur %d a %d barrieres\n", i + 1, stockage [i]; //affichage du nombre de barrieres par joueur
  }
}

void initialisationPlateau(char plateau[17][17], char nbJoueurs) {
    for (int i=0; i<17; i++)
        for (int j=0; j<17; j++) {
            plateau[i][j]=0;
        }
    if (nbJoueurs ==2) {
        plateau[0][8]=1;
        plateau[16][8]=2;
    }
    else {
        plateau[0][0]=1;
        plateau[0][16]=2;
        plateau[16][0]=3;
        plateau[16][16]=4;
    }
}

int validerPositionBarrieres(char plateau[17][17], Position barriere) {
    if ((plateau[barriere.iFirst][barriere.jFirst]==5) || (plateau[barriere.iLast][barriere.jLast]==5)){
        return 0;
    }
    else return 1;
}


void enregistrerBarrieres(char plateau[17][17], char plateauPrec[17][17], Position barriere) {
    recopierTableau(plateau, plateauPrec);
    plateau[barriere.iFirst][barriere.jFirst]=5;
    plateau[barriere.iLast][barriere.jLast]=5;
}


void recopierTableau(char plateauARecopier[17][17], char plateau[17][17]) {
    int i,j;
    for (i=0;i<17;i++) {
        for (j=0;j<17;j++) {
            plateau[i][j]=plateauARecopier[i][j];
        }
    }
}


// envoie 0 si le tableau est différent
int estTableauIdentique(char plateau1[17][17], char plateau2[17][17]) {
    int identique=1;
    for (int i=0;i<17;i++) {
        for (int j=0;j<17;j++) {
            if (plateau1[i][j]!=plateau2[i][j]) identique=0;
        }
    }
    return identique;
}

