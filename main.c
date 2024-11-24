#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GestionDuJeu.h"
#include "Sauvegarde.h"
#include "affichage.h"


/////////////////////////////////////
// Nom du Sous-programme : Menu
// Role : permet au joueur de choisir ce qu'il souhaite faire
/////////////////////////////////////
int Menu () {
    int choixDuJoueur;
    int NB_JOUEURS;
    do {
        afficherMenu();
        printf("Entrer votre choix : \n");
        scanf("%d", &choixDuJoueur);
        switch (choixDuJoueur) {
            case 1:
                nouvellePartie(NB_JOUEURS);
            break;
            case 2:
                sauvegarderPartie(Quoridor *jeu);
            break;
            case 3:
                afficherAide();
            break;
            case 4:
                miseAJourScores(fichierScoresJoueurs, pointsGagnes, gagne);
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
    printf("Joueur %d a %d barrieres\n", i + 1, stockage [i]); //affichage du nombre de barrieres par joueur
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

/////////////////////////////////////
// Nom du Sous-programme : nbJoueurs
// Role : permet au joueurs de choisir si ils font une partie à 2 ou à 4 joueurs
/////////////////////////////////////
void nbJoueurs(int NB_JOUEURS) {
    do {
        printf("nombre de joueurs: ");
        scanf("%d", &NB_JOUEURS);
    }while (NB_JOUEURS != 2 || NB_JOUEURS != 4);}

/////////////////////////////////////
// Nom du Sous-programme : intitialisationPlateau
// Role : Le plateau s'initialise, le placement des pions et des barrières est supprimé ce qui est utile lors du lancement d'une nouvelle partie
/////////////////////////////////////
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

/////////////////////////////////////
// Nom du Sous-programme : validerPositionBarrieres
// Role : Permet aux joueurs de placer leur barrières uniquement sur les endroits autorisés c'est-à-dire entre les cases du plateau
/////////////////////////////////////
int validerPositionBarrieres(char plateau[17][17], Position barriere) {
    if ((plateau[barriere.iFirst][barriere.jFirst]==5) || (plateau[barriere.iLast][barriere.jLast]==5)){
        return 0;
    }
    else return 1;
}

/////////////////////////////////////
// Nom du Sous-programme : enregistrerBarrieres
// Role : Permet d'afficher le plateau avec le placement des barrières qui a été fait par le joueur
/////////////////////////////////////
void enregistrerBarrieres(char plateau[17][17], char plateauPrec[17][17], Position barriere) {
    recopierTableau(plateau, plateauPrec);
    plateau[barriere.iFirst][barriere.jFirst]=5;
    plateau[barriere.iLast][barriere.jLast]=5;
}

/////////////////////////////////////
// Nom du Sous-programme : recopierTableau
// Role : Permet de copier le plateau
/////////////////////////////////////
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
void passerTour (etatJeu *etatJeu, NB_JOUEURS_MAX) {
        etatJeu->joueurActuel++;
        if (etatJeu-> joueurActuel > NB_JOUEURS_MAX) {
            etatJeu-> joueurActuel =0;
        }
        printf("Joueur %d c'est a votre tour de joueur :) \n", etatJeu->joueurActuel + 1);
}
///////////////////////////////////////
// Nom du sous-programme : peutDeplacer
// Rôle : Vérifie si un déplacement est valide
// In : plateau : tableau du plateau de jeu
//      i, j : position actuelle du pion
//      direction : direction du déplacement ('h', 'b', 'g', 'd')
// Out : 1 si le déplacement est valide, 0 sinon
///////////////////////////////////////
int peutDeplacer(char plateau[17][17], int i, int j, char direction) {
    switch (direction) {
        case 'h': 
            return (i > 1 && plateau[i-2][j] == 0 && plateau[i-1][j] != 5);
        case 'b': 
            return (i < 15 && plateau[i+2][j] == 0 && plateau[i+1][j] != 5);
        case 'g': 
            return (j > 1 && plateau[i][j-2] == 0 && plateau[i][j-1] != 5);
        case 'd': 
            return (j < 15 && plateau[i][j+2] == 0 && plateau[i][j+1] != 5);
    }
    return 0;
}

///////////////////////////////////////
// Nom du sous-programme : peutSauter
// Rôle : Vérifie si un saut par-dessus un autre pion est valide
// In : plateau : tableau du plateau de jeu
//      i, j : position actuelle du pion
//      direction : direction du saut ('h', 'b', 'g', 'd')
// Out : 1 si le saut est valide, 0 sinon
///////////////////////////////////////
int peutSauter(char plateau[17][17], int i, int j, char direction) {
    switch (direction) {
        case 'h': 
            return (i > 3 && plateau[i-2][j] != 0 && plateau[i-4][j] == 0 && plateau[i-3][j] != 5);
        case 'b': 
            return (i < 13 && plateau[i+2][j] != 0 && plateau[i+4][j] == 0 && plateau[i+3][j] != 5);
        case 'g': 
            return (j > 3 && plateau[i][j-2] != 0 && plateau[i][j-4] == 0 && plateau[i][j-3] != 5);
        case 'd': 
            return (j < 13 && plateau[i][j+2] != 0 && plateau[i][j+4] == 0 && plateau[i][j+3] != 5);
    }
    return 0;
}

///////////////////////////////////////
// Nom du sous-programme : deplacerPion
// Rôle : Déplace un pion sur le plateau
// In : plateau : tableau du plateau de jeu
//      i, j : position actuelle du pion
//      direction : direction du déplacement ('h', 'b', 'g', 'd')
// Out : 1 si le déplacement a été effectué, 0 sinon
///////////////////////////////////////
int deplacerPion(char plateau[17][17], int* i, int* j, char direction) {
    int ni = *i, nj = *j;

    if (peutDeplacer(plateau, ni, nj, direction)) {
        switch (direction) {
            case 'h': ni -= 2; break;
            case 'b': ni += 2; break;
            case 'g': nj -= 2; break;
            case 'd': nj += 2; break;
        }
    } else if (peutSauter(plateau, ni, nj, direction)) {
        switch (direction) {
            case 'h': ni -= 4; break;
            case 'b': ni += 4; break;
            case 'g': nj -= 4; break;
            case 'd': nj += 4; break;
        }
    } else {
        return 0; // Déplacement non valide

    // Mise à jour du plateau
    plateau[*i][*j] = 0;
    plateau[ni][nj] = plateau[*i][*j];
    *i = ni;
    *j = nj;
    return 1;
    
    if (ni == 16) {   //Victoire du joueur 
        printf ("Le joueur a gagne !\n");
        return 2;       //Gagne si il s'est déplacé de 16 cases à droite ou à gauche
    } else {
        return 1;       //Si il ne s'est pas déplacé de 16 cases alors le déplecément est validé
    }
}

/////////////////////////////////////
// Nom du Sous-programme : Afficher le menu de la partie
// Role : permet au joueur de choisir ce qu'il souhaite faire 
/////////////////////////////////////
void afficherMenuPartie(char plateau[17][17], int* i, int* j) {
    int choixTour;
    char direction;
    int deplacementValide = 0;

    do {
        // Affichage du menu
        printf("\n--- Menu Partie ---\n");
        printf("1 - Deplacer son pion\n");
        printf("2 - Poser une barriere\n");
        printf("3 - Passer son tour\n");
        printf("4 - Annuler le dernier coup\n");
        printf("Choisissez une action : ");
        scanf("%d", &choixTour);

        switch (choixTour) {
            case 1: // Déplacement du pion
                printf("Choisissez la direction ('h'=haut, 'b'=bas, 'g'=gauche, 'd'=droite) : ");
                scanf(" %c", &direction);

                // Tenter de déplacer le pion
                if (deplacerPion(plateau, i, j, direction)) {
                    deplacementValide = 1; // Déplacement réussi, sortir de la boucle
                } else {
                    printf("Deplacement non valide ! Une barriere bloque le chemin ou la case est occupée.\n");
                    deplacementValide = 0; // Refaire un choix
                }
                break;

            case 2: // Poser une barrière
                poserBarrieres();
                deplacementValide = 1; // Pour sortir de la boucle si c'est une action valide
                break;

            case 3: // Passer son tour
                passerTour();
                deplacementValide = 1; // Pour sortir de la boucle si c'est une action valide
                break;

            case 4: // Annuler le dernier coup
                annulerCoup();
                deplacementValide = 1; // Pour sortir de la boucle si c'est une action valide
                break;

            default:
                printf("Choisir une action parmi celles proposees.\n");
                deplacementValide = 0; // Refaire un choix
                break;
        }
    } while (!deplacementValide); // La boucle continue tant que le déplacement n'est pas valide
}

///////////////////////////////////////
// Nom du sous-programme : peutDeplacer
// Rôle : Vérifie si un déplacement est valide
// In : plateau : tableau du plateau de jeu
//      i, j : position actuelle du pion
//      direction : direction du déplacement ('h', 'b', 'g', 'd')
// Out : 1 si le déplacement est valide, 0 sinon 
///////////////////////////////////////
int peutDeplacer(char plateau[17][17], int i, int j, char direction) {
    switch (direction) {
        case 'h': 
            return (i > 1 && plateau[i-2][j] == 0 && plateau[i-1][j] != 5); // Vérifie si la case est libre
        case 'b': 
            return (i < 15 && plateau[i+2][j] == 0 && plateau[i+1][j] != 5); // Vérifie si la case est libre
        case 'g': 
            return (j > 1 && plateau[i][j-2] == 0 && plateau[i][j-1] != 5); // Vérifie si la case est libre
        case 'd': 
            return (j < 15 && plateau[i][j+2] == 0 && plateau[i][j+1] != 5); // Vérifie si la case est libre
    }
    return 0; // Si aucune direction valide, renvoie 0
}

///////////////////////////////////////
// Nom du sous-programme : peutSauter
// Rôle : Vérifie si un saut par-dessus un autre pion est valide
// In : plateau : tableau du plateau de jeu
//      i, j : position actuelle du pion
//      direction : direction du saut ('h', 'b', 'g', 'd')
// Out : 1 si le saut est valide, 0 sinon
///////////////////////////////////////
int peutSauter(char plateau[17][17], int i, int j, char direction) {
    switch (direction) {
        case 'h': 
            return (i > 3 && plateau[i-2][j] != 0 && plateau[i-4][j] == 0 && plateau[i-3][j] != 5); // Vérifie si un saut est valide
        case 'b': 
            return (i < 13 && plateau[i+2][j] != 0 && plateau[i+4][j] == 0 && plateau[i+3][j] != 5); // Vérifie si un saut est valide
        case 'g': 
            return (j > 3 && plateau[i][j-2] != 0 && plateau[i][j-4] == 0 && plateau[i][j-3] != 5); // Vérifie si un saut est valide
        case 'd': 
            return (j < 13 && plateau[i][j+2] != 0 && plateau[i][j+4] == 0 && plateau[i][j+3] != 5); // Vérifie si un saut est valide
    }
    return 0;
}

///////////////////////////////////////
// Nom du sous-programme : deplacerPion
// Rôle : Déplace un pion sur le plateau
// In : plateau : tableau du plateau de jeu
//      i, j : position actuelle du pion
//      direction : direction du déplacement ('h', 'b', 'g', 'd')
// Out : 1 si le déplacement a été effectué, 0 sinon
///////////////////////////////////////
int deplacerPion(char plateau[17][17], int* i, int* j, char direction) {
    int ni = *i, nj = *j;

    if (peutDeplacer(plateau, ni, nj, direction)) {
        switch (direction) {
            case 'h': ni -= 2; break;
            case 'b': ni += 2; break;
            case 'g': nj -= 2; break;
            case 'd': nj += 2; break;
        }
    } else if (peutSauter(plateau, ni, nj, direction)) {
        switch (direction) {
            case 'h': ni -= 4; break;
            case 'b': ni += 4; break;
            case 'g': nj -= 4; break;
            case 'd': nj += 4; break;
        }
    } else {
        return 0; // Déplacement non valide
    }

    // Mise à jour du plateau
    plateau[*i][*j] = 0;
    plateau[ni][nj] = plateau[*i][*j];
    *i = ni;
    *j = nj;
    return 1; // Déplacement réussi
}

