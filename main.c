#include <stdio.h>
#include <stdlib.h>
#include "affichageDuJeu.h"
#include "gestionDuJeu.h"
#include "sauvegardeDuJeu.h"

int main() {
    int choixMenu = 0;
    int nbJoueurs = 0;
    char plateau[17][17];
    char carPion[4];
    Quoridor jeu;

    do {
        system("CLS"); // Nettoyer l'écran
        afficherMenu();
        printf("\nEntrez votre choix : ");
        scanf("%d", &choixMenu);

        switch (choixMenu) {
            case 1:
                // Nouvelle partie
                printf("\nCombien de joueurs (2 ou 4) ? ");
                do {
                    scanf("%d", &nbJoueurs);
                    if (nbJoueurs != 2 && nbJoueurs != 4) {
                        printf("Nombre invalide. Veuillez saisir 2 ou 4 : ");
                    }
                } while (nbJoueurs != 2 && nbJoueurs != 4);

                caracterePion(nbJoueurs, carPion); // Demander les caractères des pions
                initialiserPlateau(plateau, nbJoueurs, carPion); // Initialiser le plateau
                jeu.NB_JOUEURS = nbJoueurs;
                jeu.joueurActuel = 0; // Premier joueur

                refreshScreen(plateau); // Afficher le plateau initial
                printf("\nLa partie commence !\n");

                // Lancer la partie
                jouerPartie(&jeu, plateau, carPion);

                break;

            case 2:
                // Reprendre une partie sauvegardée
                if (chargerPartie(&jeu)) {
                    initialiserPlateau(plateau, jeu.NB_JOUEURS, carPion);
                    printf("\nPartie chargée avec succès !\n");
                    refreshScreen(plateau);
                    jouerPartie(&jeu, plateau, carPion);
                } else {
                    printf("Aucune sauvegarde disponible.\n");
                }
                break;

            case 3:
                // Afficher l'aide
                system("CLS");
                afficherAide();
                printf("\nAppuyez sur une touche pour revenir au menu principal...\n");
                getch();
                break;

            case 4:
                // Afficher les scores
                system("CLS");
                printf("\n=== Scores des joueurs ===\n");
                sauvegardeScores("scores.txt"); // Sauvegarder les scores
                chargementScores("scores.txt"); // Charger et afficher les scores
                printf("\nAppuyez sur une touche pour revenir au menu principal...\n");
                getch();
                break;

            case 5:
                // Quitter le jeu
                quitterJeu();
                break;

            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }

    } while (choixMenu != 5);

    return 0;
}
