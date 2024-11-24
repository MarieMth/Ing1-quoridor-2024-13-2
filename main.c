#include <stdio.h>
#include <stdlib.h>
#include "affichageDuJeu.h"
#include "gestionDuJeu.h"
#include "sauvegardeDuJeu.h"

int main () {
  do {
  	afficherMenu();
  		if (choix == nouvelle partie) {
         	nbJoueurs(int NB_JOUEURS);
  			saisirPseudo(int nb_joueurs);
  			caracterePion(int nb_joueur, char* carPion);
  			intialisePlateau(char plateau[17][17], carPion);
  			affichePlateau(char plateau[17][17]);
  			zoneStockage (int nb_joueurs, int stockage[]);
  			positionPions (char plateau[17][17], int nb_joueurs);
  			refreshScreen(char plateau[17][17]);
  			affichePlateau(char plateau[17][17]);
  			jouerTour(char nom[4][50], int numeros[4], int nbJoueurs);
  			afficherMenuPartie();
  				if (choix == deplacerPion) {
                    gotoligcol( int lig, int col );
					deplacement(int* i, int* j, int choix);
            	} else if (choix == poserBarrieres) {
					placementPremiereBarriere(int* i, int* j, int choix);
					placementDeuxiemeBarriere(int iFirst, int jFirst, int* iLast, int* jLast, int choix);
                    afficheBarriereV(char plateau[17][17]);
					afficheBarriereH(char plateau[17][17]);
            	} else if (choix == passerTour) {
                  	passerTour(etatJeu *etatJeu);
            	} else if (choix == annulerCoup) {
                  	annulerCoup (etatJeu *positionPion, dernierCoup);
            	} else
              	printf("Choisir une action parmi celles proposees \n");
            	}
                refreshScreen(char plateau[17][17]);
    	} else if (choix == sauvegarder partie) {
          sauvegarderPartie(Quoridor *jeu);
		} else if (choix == afficherAide){
          afficherAide();
        } else if (choix == miseAJourScores){
          miseAJourScores (const char *fichierScoresJoueurs, pointsGagnes, gagne);
        } else if (choix == quitterJeu) {
          quitterJeu();
        } else {
           printf("Choix incorrecte, veuillez reessayer en selectionnant une option valide : \n");
            scanf("%d", &choixDuJoueur);
        }
		jouerTour(char nom[4][50], int numeros[4], int nbJoueurs);
        afficherMenu();
    }
  } while (choix menu!= 5 || ni !=16);
return 0; 
