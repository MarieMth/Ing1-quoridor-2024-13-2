#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GestionDuJeu.h"
#include "Sauvegarde.h"

////////////////////////////////
// Nom du Sous-programme : sauvegardeScores
// Role : sauvegarde les scores des joueurs dans un fichier 
////////////////////////////////
void sauvegardeScores (const char *fichierScoresJoueurs) {
    FILE *fichierScoresJoueurs = fopen(fichierScoresJoueurs, "w");
    do {
        printf("Erreur, le fichier ne peut s'ouvrir");
    }while (fichierScoresJoueurs == NULL);
    for (int i = 0; i < NB_JOUEURS ; i++) {
        fprintf(fichierScoresJoueurs, "Joueur %d votre score %d est sauvegarde \n,", joueurActuel.nom, joueurActuel.score);
    }
    fclose(fichierScoresJoueurs);
}

/////////////////////////////////
// Nom du Sous-programe : chargementScores 
// Role : charge les scores des joueurs et les affiches
/////////////////////////////////
void chargementScores (const char *fichierScoresJoueurs) {
    miseAJourScores(fichierScoresJoueurs, pointsGagnes, gagne, NB_JOUEURS); 
    FILE *fichierScoresJoueurs = fopen(fichierScoresJoueurs, "r");
    do {
        printf("Erreur, le fichier ne peut s'ouvrir");
    } while (fichierScoresJoueurs == NULL);
    while (fgetc(fichierScoresJoueurs) != EOF && fscanf(fichierScoresJoueurs, "Joueur %d votre score est %d \n", etatJeu -> joueurActuel, joueurActuel.score)) {
        NB_JOUEURS++;
    }
}

//////////////////////////////
// Nom du Sous-programme : miseAJourScores 
// Role : met à jour les scores des joueurs en fin de partie selon s'ils ont gagnés ( +5 points) ou perdus (+0 points)
//////////////////////////////
void miseAJourScores(const char *fichierScoresJoueurs, int pointsGagnes, int gagne, int NB_JOUEURS) {
    FILE *fichierScoresJoueurs = fopen(fichierScoresJoueurs, "w");;
    nbJoueurs(NB_JOUEURS); 
    printf("\n===%c Scores des joueurs %c===\n ", 0x03, 0x03);
    if(joueursActuel=gagne) {
            pointsgagnes =5;
    }
    else {
        pointsGagnes =0;
    }
    if (strcmp(joueursActuel.nom, J)== 0) {
            joueursActuel.score += pointsGagnes;
            printf("Joueur %d votre nouveu score est %d \n", etatJeu -> joueurActuel, pointsGagnes ); 
        }
    }
    for (joueurActuel < NB_JOUEURS ) {
        strcpy(joueurs[nbJoueurs].nom, nomJoueurs);
        joueurActuel[NB_JOUEURS].score =pointsGagnes;
        NB_JOUEURS++;
        printf("Joueur %d votre score est %d", JoueurActuel, pointsGagnes);
    }
}
