#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "affichage.h"
#include "gestionJeu.h"




///////////////////////////////////////
// Nom du sous-programme : gotoligcol
// Rôle : permet de positionner le curseur à la ligne lig et colonne col
///////////////////////////////////////
void gotoligcol( int lig, int col ) {
    // ressources
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}


///////////////////////////////////////
// Nom du sous-programme : color
// Rôle : change la couleur du texte dans la console, ainsi que la couleur du fond pour la ligne
// Compatibilité : Windows
///////////////////////////////////////
void color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}


///////////////////////////////////////
// Nom du sous-programme : afficheTitre
// Rôle : Affiche le titre du jeu
///////////////////////////////////////
void afficheTitre() {
    gotoligcol(1,17);
    color(14,3);
    printf("JEU DU QUORIDOR");
    color(15,0);
}


///////////////////////////////////////
// Nom du sous-programme : afficheLabels
// Rôle : Affiche les labels du plateau (lettres et chiffres)
///////////////////////////////////////
void afficheLabels() {
    int i=0;
    int ligne=6;
    gotoligcol(ligne,4);
    printf("A   B   C   D   E   F   G   H   I\n");
    for(i=0; i<17; i=i+2) {
        gotoligcol(ligne+1+i,0);
        printf("%d", i/2+1);
    }
}

///////////////////////////////////////
// Nom du sous-programme : affichePlateau
// Rôle : Affiche lecontenu du plateau
// In : plateau : tableau qui correspond aux valeurs du plateau
///////////////////////////////////////
void affichePlateau(char plateau[17][17]) {
    int i=0, j=0;
    int ligne=7;
    for(i=0; i<17; i=i+2) {
        for(j=0; j<17; j=j+2) {
            gotoligcol(i+ligne,j*2+4);
            switch(plateau[i][j]) {
                case 0:
                    color(15,0);
                    printf("%c", 0xDB);
                break;

                case 1:
                    color(0,9);
                    printf("%c", 0x03); //coeur
                break;

                case 2:
                    color(0,10);
                    printf("%c", 0x04); //carreau
                break;

                case 3:
                    color(0,13
                        );
                    printf("%c", 0x05); //trefle
                break;

                case 4:
                    color(0,6);
                    printf("%c", 0x06); // pique
                break;

            }

        }
        color(15,0);
    }
}


///////////////////////////////////////
// Nom du sous-programme : afficheBarriereV
// Rôle : Affiche les barrières verticales
// In : plateau : tableau qui correspond aux valeurs du plateau
///////////////////////////////////////
void afficheBarriereV(char plateau[17][17]) {
    int i=0, j=0;
    int ligne=7;
    for(i=0; i<17; i=i+2) {
        for(j=1; j<17; j=j+2) {
            if (plateau[i][j]==5) {
                gotoligcol(ligne+i,j*2+4);
                color(4,0);
                printf("%c", 0xBA);
                color(15,0);
            }
        }
    }
}


///////////////////////////////////////
// Nom du sous-programme : afficheBarriereH
// Rôle : Affiche les barrières horizontales
// In : plateau : tableau qui correspond aux valeurs du plateau
///////////////////////////////////////
void afficheBarriereH(char plateau[17][17]) {
    int i=0, j=0;
    int ligne=7;
    for(i=1; i<17; i=i+2) {
        for(j=0; j<17; j=j+2) {
            if (plateau[i][j]==5) {
                gotoligcol(ligne+i,j*2+4);
                color(4,0);
                printf("%c", 0xCD);
                color(15,0);
            }
        }
    }
}


///////////////////////////////////////
// Nom du sous-programme : afficheMenuJeu
// Rôle : affiche le menu du jeu
///////////////////////////////////////
void afficheMenuJeu() {
    gotoligcol(27,0);
    printf("Actions possibles :\n");
    printf("1-deplacer son pion\n");
    printf("2-poser une barriere\n");
    printf("3-passer son tour\n");
    printf("4-annuler la derniere action\n");
    printf("5-Quitter la partie\n");
}


///////////////////////////////////////
// Nom du sous-programme : afficheStatutJeu
// Rôle : affiche les infos sur le statut du jeu
///////////////////////////////////////
void afficheStatutJeu() {
    int ligne = 8;
    gotoligcol(ligne,70);
    printf("Nombre de joueurs : %d", 2);
    gotoligcol(ligne+2,70);
    printf("Joueur : ");
    gotoligcol(ligne+4,70);
    printf("Score partie :");
    gotoligcol(ligne+6,70);
    printf("Jeton :");
    gotoligcol(ligne+8,70);
    printf("Mur restant :");
}

///////////////////////////////////////
// Nom du sous-programme : iToligne
// Rôle : renvoie la position à l'écran (ligne) pour un indice de tableau
///////////////////////////////////////
int iToligne(int i) {
    return (i+7);
}

///////////////////////////////////////
// Nom du sous-programme : iToCol
// Rôle : renvoie la position à l'écran (ligne) pour un indice de tableau
///////////////////////////////////////
int iToCol(int j) {
    return (2*j+4);
}


///////////////////////////////////////
// Nom du sous-programme : iToCol
// Rôle : renvoie la position à l'écran (ligne) pour un indice de tableau
///////////////////////////////////////
void deplacement(int* i, int* j, int choix) {
    switch(choix) {
        case 'h':
            if (*i>0) {
                *i=*i-1;
            }
        break;

        case 'b':
            if (*i<16) {
                *i=*i+1;
            }
        break;

        case 'd':
            if (*j<16) *j=*j+1;
        break;

        case 'g':
            if (*j>0) *j=*j-1;
        break;
    }
}

void placementPremiereBarriere(int* i, int* j, int choix) {
    switch(choix) {

        case 'h':
            if (*i>0) {
                *i=*i-1;
                if(*i%2==0) {
                    *j=*j-1;
                    if(*j<0) *j=0;
                }
                else {
                    *j=*j+1;
                    if(*j>16) *j=16;
                }
            }
        break;

        case 'b':
            if (*i<16) {
                *i=*i+1;
            if(*i%2==0) {
                *j=*j+1;
                if(*j>15) *j=15;
            }
            else {
                *j=*j-1;
                if(*j>15) *j=15;
            }
        }
        break;

        case 'd':
            if (*j<15) *j=*j+2;
        break;

        case 'g':
            if (*j>1) *j=*j-2;
        break;
    }
}

int placementDeuxiemeBarriere(int iFirst, int jFirst, int* iLast, int* jLast, int choix) {
    switch(choix) {

        case 'h':
            if ((jFirst%2==1) && (iFirst>1)){
                *iLast=iFirst-2;
                *jLast=jFirst;
                return 1;
            }
        break;

        case 'b':
            if ((jFirst%2==1) && (iFirst<15)){
                *iLast=iFirst+2;
                *jLast=jFirst;
                return 1;
             }
        break;

        case 'd':
            if ((iFirst%2==1) && (jFirst<15)){
                *jLast=jFirst+2;
                *iLast=iFirst;
                return 1;
            }
        break;

        case 'g':
            if ((iFirst%2==1) && (jFirst>1)){
                *jLast=jFirst-2;
                *iLast=iFirst;
                return 1;
            }
        break;
    }
}

void refreshScreen(char plateau[17][17]) {
    system("CLS");
    afficheTitre();
    afficheStatutJeu();
    afficheLabels();
    afficheBarriereV(plateau);
    afficheBarriereH(plateau);
    affichePlateau(plateau);
    afficheMenuJeu();
}

