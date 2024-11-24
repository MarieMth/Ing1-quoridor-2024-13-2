#include <stdio.h>
#include "gestionJeu.h"
#include "affichage.h"

/////////////////////////////////////
// Nom du Sous-programme : Menu
// Role : permet au joueur de choisir ce qu'il souhaite faire
/////////////////////////////////////
int Menu () ; {
    int choixDuJoueur;
    int nbJoueurs;
    do {
        afficherMenu();
        printf("Entrer votre choix : \n");
        scanf("%d", &choixDuJoueur);
        switch (choixDuJoueur) {
            case 1:
                nouvellePartie(nombreJoueurs);
            break;
            case 2:
                partieSauvegardee();
            break;
            case 3:
                afficherAide();
            break;
            case 4:
                afficherScoresJoueurs();
            break;
            case 5:
                quitterJeu();
            break;
            default:
                printf("Choix incorrecte, veuillez reessayer en selectionnant une option valide : \n");
            scanf("%d", &choixDuJoueur);
            break;
        }
    } while (choixDuJoueur < 1 || choixDuJoueur > 5);
    return 0;
}

////////////////////////////////
// Nom du Sous-programme : menuPartie
// Role : permet au joueur de choisir l'action à effectuer lorsque c'est à son tour de joueur
////////////////////////////////
int menuPartie () {
    int choixTour;
    do {
        afficherMenuPartie();
        scanf("%d", &choixTour);
        switch (choixTour) {
            case 1:
                deplacementPion();
            break;
            case 2:
                poserBarrieres();
            break;
            case 3:
                passerTour();
            break;
            case 4:
                annulerCoup();
            break;
            default:
                printf("Choisir une action parmi celles proposees \n");
            break;
        }
    } while (choixTour < 1 || choixTour > 4);
}

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

///////////////////////////////////////
// Nom du sous-programme : comptageBarrieres
// Rôle : Compte le nombre de barriere dans la zone de stockage pour vérifier que le joueur a assez de barrieres pour en placer une
///////////////////////////////////////
void comptageBarrieres(int joueur, int stockage[], int nb_joueurs) {  
    if (stockage[joueur] > 0) {
        stockage[joueur]--; 
        printf("Le joueur %d a postionné une barrière. Il lui reste %d barrieres\n", joueur + 1, stockage[joueur]);
    } else {
        printf("Le joueur %d n'a plus de barrieres dans sa zone de stockage\n", joueur + 1);
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

//////////////////////////////////
// Nom du Sous-programme : annulerCoup
// Role : permet lorsque c'est au tour d'un joueur de jouer d'annuler le dernier coup s'il le demande
//////////////////////////////////
int tailleHistoriqueCoup = 0;
char historiqueCoup[];
void annulerCoup(etatJeu *positionPion, char dernierCoup) {
    if (tailleHistoriqueCoup > 0) {
        tailleHistoriqueCoup --;
        if (dernierCoup.type == 'D'){
            etatJeu -> positionPion--;
            printf("Joueur %d votre coup ete annule \n", etatJeu->JoueurActuel);
        }else if (dernierCoup.type == 'B') {
            etatJeu -> plateauActuel--;
            printf("Joueur %d votre mur a ete enleve\n", etatJeu->joueurActuel);
        }
    }
    else {
        printf("Il n'y a aucun coup a annuler \n");
    }
}
/////////////////////////////////////
// Nom du Sous-programme : passerTour
// Role : lorsque le joueur joue et le demande il peut passer son tour
////////////////////////////////////
void passerTour (etatJeu *etatJeu) {
        etatJeu->joueurActuel++;
        if (etatJeu-> joueurActuel > NB_JOUEURS_MAX) {
            etatJeu-> joueurActuel =0;
        }
        printf("Joueur %d c'est a votre tour de joueur :) \n", etatJeu->joueurActuel + 1);
}
