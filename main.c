#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "affichage.h"
#include "gestionJeu.h"

////////////////////////////////
// Nom du Sous-programme : afficherMenu 
// Role : afficher le Menu principal du Jeu 
////////////////////////////////
void afficherMenu () {
    printf("\n===%c Menu Principal du Jeu Quoridor %c===\n", 0x03, 0x03);
    printf("1. Lancer une nouvelle partie\n ");
    printf("2. Reprendre une partie sauvegardee \n ");
    printf("3. Afficher l'aide \n ");
    printf("4. Afficher le score des joueurs \n ");
    printf("5. Quitter le jeu \n ");
}
////////////////////////////////
// Nom du Sous-programme : afficherAide
// Role : afficher l'aide lorsque l'utilisateur le demande 
////////////////////////////////
void afficherAide ()  {
    printf("\n===%c Aide %c===\n ", 0x03, 0x03);
    printf("--> Le but du jeu est d'atteindre le cote oppose du plateau en premier <-- \n");
    printf("--> Vous pouvez deplacer votre pion verticalement ou horizontalement, en avant ou en arriere si aucune barriere ne bloque votre chemin sinon vous rejouez <-- \n");
    printf("--> Il est possible afin de bloquer son/ ses adversaires de poser des barrieres entre deux blocs de case de maniere verticale ou horizontale, cela est uniquement possible si vous disposez encore des barrieres dans votre zone de stockage <--\n");
    printf("--> Le premier joueur a arriver au bord oppose du plateau a celui de depart remporte la partie <--\n");
}
///////////////////////////////
// Nom du Sous-programme : afficherScoresJoueurs
// Role : affiche le score des joueurs de la partie en cours
///////////////////////////////
void afficherScoresJoueurs  () {
    printf("\n===%c Scores des joueurs %c===\n ", 0x03, 0x03);
    for (int i = 0; i<NB_JOUEURS; i++) {
        int score_joueurs[i];
        printf("Joueur %d : Vous avez remporte %d points pour cette partie  \n ", score_joueurs[i], i);
        scanf("%d", &score_joueurs[i]);
    }
}
////////////////////////////////
// Nom du Sous-programme : quitterJeu
// Role : permet de quitter le jeu 
////////////////////////////////
void quitterJeu ()  {
    printf("-- Merci d'avoir joue au Jeu du Quoridor --\n");
    printf("\n A bientot !\n");
}
/////////////////////////////////
// Nom du Sous-programme : afficherMenuPartie 
// Role : affiche un menu entre le tour de chaque joueur afin de lui proposer les actions possibles
////////////////////////////////
void afficherMenuPartie () {
    struct joueurs Joueurs[NB_JOUEURS];
    printf("Joueur %d c'est à votre tour de jouer \n", etatJeu -> joueurActuel+1);
    printf("Que choisissez vous de faire ? : \n");
    printf("1. Déplacer votre pion \n");
    printf("2. Poser une barriere \n");
    printf("3. Passer son tour \n");
    printf("4. Annuler le dernier coup effectue sur le plateau \n");
}



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
// Nom du sous-programme : COLOR
// Rôle : change la couleur du texte dans la console, ainsi que la couleur du fond pour la ligne
// Compatibilité : Xindows
///////////////////////////////////////
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

///////////////////////////////////////
// Nom du sous-programme : couleur
// Rôle : Affiche la couleur des cases, barrieres et pions 
///////////////////////////////////////
void couleur() { 
  int choix_cases, choix_barrieres, choix_pions;
  printf ("Voici les couleurs que vous pouvez choisir pour votre texte et votre fond:\n");
  printf("1. Noir\n");
  printf("2. Blanc\n");
  printf("3. Violet\n");
  printf("4. Bleu\n");
  printf("5. Vert\n");
  printf("6. Rose\n");
  printf("7. Rouge\n");
  printf("8. Orange\n");
  printf("9. Jaune\n");
  do {  //boucle pour vérifier si la couleur est bien comprise dans celles proposées
    printf ("Choisissez la couleur des cases, des barrieres et des pions entre 1 et 9\n");
    scanf ("Couleur des cases: %d, couleur des barrieres: %d et couleur des pions:%d", &choix_cases, &choix_barrieres, &choix_pions);
  } while (choix_cases<1 || choix_cases>9 || choix_barrieres<1 || choix_barrieres>9 || choix_pions<1 || choix_pions>9);
  Color (choix_cases, choix_barrieres, choix_pions);
}

///////////////////////////////////////
// Nom du sous-programme : caracterePion
// Rôle : Demande et affiche le caractere choisi pour le pion de chaque joueur 
///////////////////////////////////////
void caracterePion (int nb_joueur, char* car_pion){ 
nb_joueur = saisirJoueur ()
char car_pion;
  for (int i=0; i<nb_joueur; i++) {
    do {
      printf ("Saisissez le caractere de votre pion dans la table ANSI:");
      scanf("%c", &car_pion);
    } while (car_pion <33 || car_pion >127);
    car_pions[i] = car_pion;
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
// Nom du sous-programme : positionPions
// Rôle : permet de positionner les pions au début de la partie selon le nombre de joueur
///////////////////////////////////////
void position_pions (char plateau[LIGNES][COLONNES], int nb_joueurs{ 
  if (nb_joueurs == 2) {  // si le nombre de joueurs est 2 on doit placer les pions l'un en face de l'autre
    plateau[0][4] = '1';
    plateau[8][4] = '2';
  } else {  // si le nombre de joueurs est 4 on place un pion à chaque extrémité du plateau
    plateau[0][0] = '1';
    plateau[0][8] = '2';
    plateau[8][0] = '3';
    plateau[8][8] = '4';
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

