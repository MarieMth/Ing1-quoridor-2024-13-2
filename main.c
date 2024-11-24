#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GestionDuJeu.h"

////////////////////////////////
// Nom du Sous-programme : sauvegardeScores
// Role : sauvegarde les scores des joueurs dans un fichier 
////////////////////////////////
void sauvegardeScores (const char *fichierScoresJoueurs) {
    FILE *fichierScoresJoueurs = fopen(fichierScoresJoueurs, "w");
    do {
        printf("Erreur, le fichier ne peut s'ouvrir");
    }while (fichierScoresJoueurs == NULL);
    for (int i = 0; i < nbJoueurs ; i++) {
        fprintf(fichierScoresJoueurs, "Joueur %d votre score %d est sauvegarde \n,", joueur[i].nom, joueurs[i].scores);
    }
    fclose(fichierScoresJoueurs);
}

/////////////////////////////////
// Nom du Sous-programe : chargementScores 
// Role : charge les scores des joueurs et les affiches
/////////////////////////////////
void chargementScores (const char *fichierScoresJoueurs) {
    FILE *fichierScoresJoueurs = fopen(fichierScoresJoueurs, "r");
    do {
        printf("Erreur, le fichier ne peut s'ouvrir");
    } while (fichierScoresJoueurs == NULL);
    while (fgetc(fichierScoresJoueurs) != EOF && fscanf(fichierScoresJoueurs, "Joueur %d votre score est %d \n")) {
        nbJoueurs++;
    }
}

//////////////////////////////
// Nom du Sous-programme : miseAJourScores 
// Role : met à jour les scores des joueurs en fin de partie selon s'ils ont gagnés ( +5 points) ou perdus (+0 points)
//////////////////////////////
void miseAJourScores(const char *fichierScoresJoueurs, int pointsGagnes, int gagne) {
    FILE *fichierScoresJoueurs;
    for (int i =0; i< nbJoueurs; i++)
        if(joueurs[i]=gagne) {
            pointsgagnes =5;
        }
    else {
        pointsGagnes =0;
    }
    for(int i =0 ; i<nbJoueurs; i++) {
        if (strcmp(joueurs[i].nomn nomJoueur)== 0) {
            joueurs[i].score += pointsGagnes;
            printf("Joueur %d votre nouveu score est %d \n"); fflush(stdout);
        }
    }
    for (nbJoueurs < NB_MAX_JOUEURS) {
        strcpy(joueurs[nbJoueurs].nom, nomJoueurs);
        joueurs[nbJoueurs].score =pointsGagnes;
        nbJoueurs++;
        printf("Joueur %d votre score est %d", nomJoueur, pointsGagnes);
    }
}
