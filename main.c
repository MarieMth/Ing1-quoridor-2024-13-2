#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "affichage.h"
#include "gestionDuJeu.h"
#include "sauvegarde.h"


int main(void) {

    char plateau[17][17]={{0}};
    char plateauPrec[17][17]={{0}};
    int choix=0, dep=0, retour=0;

    initialisationPlateau(plateau,4);
    recopierTableau(plateau, plateauPrec);
    refreshScreen(plateau);

    Position barriere;
    barriere.iFirst=7;
    barriere.jFirst=8;
    barriere.iLast=0;
    barriere.jLast=0;

    do {
        choix=getch();
        switch(choix) {

            case '1':
                gotoligcol(20,70);
                printf("Déplacer point");
            break;

            case '2':
                gotoligcol(20,60);
                color(1,10);
                printf("Positionner la premiere barriere et valider par v");
                color(15,0);
                gotoligcol(iToligne(barriere.iFirst),iToCol(barriere.jFirst));

                //1ere barriere
                do {
                    dep=getch();
                    placementPremiereBarriere(&barriere.iFirst, &barriere.jFirst, dep);
                    gotoligcol(iToligne(barriere.iFirst),iToCol(barriere.jFirst));
                } while (dep !='v');
                printf("X");
                gotoligcol(20,60);
                color(1,10);
                printf("Positionner la deuxieme barriere et valider par v");
                color(15,0);
                gotoligcol(iToligne(barriere.iFirst),iToCol(barriere.jFirst));

                //2eme barriere
                do {
                    dep=getch();
                    if (dep=='h' || dep=='b' || dep=='g' || dep=='d') retour = placementDeuxiemeBarriere(barriere.iFirst, barriere.jFirst, &barriere.iLast, &barriere.jLast, dep);
                    if (retour==1) gotoligcol(iToligne(barriere.iLast),iToCol(barriere.jLast));
                } while ((dep !='v') | (retour!=1));
                printf("X");

                if (validerPositionBarrieres(plateau, barriere) == 1) {
                    enregistrerBarrieres(plateau, plateauPrec, barriere);
                    gotoligcol(23,70);
                    color(4,6);
                    printf("Barrieres positionnees");
                    gotoligcol(24,70);
                    printf("Appuyer sur une touche");
                    color(15,0);
                    getch();
                }
                else {
                    gotoligcol(23,70);
                    color(4,6);
                    printf("Barrieres impossible");
                    gotoligcol(24,70);
                    printf("Appuyer sur une touche");
                    color(15,0);
                    getch();
                }
                refreshScreen(plateau);
            break;

            case '4':
                if (estTableauIdentique(plateauPrec, plateau)==0) {
                    recopierTableau(plateauPrec,plateau);
                    gotoligcol(23,70);
                    color(4,6);
                    printf("Action annulee");
                    gotoligcol(24,70);
                    printf("Appuyer sur une touche");
                    getch();
                    color(15,0);
                    refreshScreen(plateau);
                }
                else {
                    gotoligcol(23,70);
                    color(4,6);
                    printf("Annulation impossible");
                    gotoligcol(24,70);
                    printf("Appuyer sur une touche");
                    color(15,0);
                    getch();
                    refreshScreen(plateau);
                }
            break;
        }
    } while (choix !='5');

    return 0;
}
