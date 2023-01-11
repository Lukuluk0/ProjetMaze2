#include "jeu.h"
#include "affichage.h"

void Jouer(t_jeu jeu)
{

    do
    {
        system("cls");
        affichagePlateau(jeu);
        //deplacerTuile(&jeu);
        int dep = -1;
        do{
            system("cls");
            affichagePlateau(jeu);
            dep = deplacerJoueur(&jeu);
        } while(dep == -1);

        jeu.tour_de_jeu++;
        if(jeu.tour_de_jeu > jeu.nbr_player - 1) {jeu.tour_de_jeu = 0;}
    }
    while(1); // faire la fonction de fin de jeu


}

void deplacerTuile(t_jeu* jeu)
{
    gotoligcol(9, 45);
    printf("Veuillez choisir un emplacement ou pousser la tuile (A..L) :");
    char emplacement ;
    scanf("%c",&emplacement);
    switch(emplacement)
    {
    case 'A':
    {
        //PousseDepuis(0,1,&jeu);
        int var = 1;
        shift_row_down(var,jeu->cartes);
        t_carte temp = jeu->cartes[0][var];
        jeu->cartes[0][var] = jeu->tuile_out;
        jeu->tuile_out = temp;
        break;
    }
    case 'B':
    {
        //PousseDepuis(0,3,&jeu);
        int var = 3;
        shift_row_down(var,jeu->cartes);
        t_carte temp = jeu->cartes[0][var];
        jeu->cartes[0][var] = jeu->tuile_out;
        jeu->tuile_out = temp;
        break;
    }
    case 'C':
    {

        //PousseDepuis(0,5,&jeu);
        int var = 5;
        shift_row_down(var,jeu->cartes);
        t_carte temp = jeu->cartes[0][var];
        jeu->cartes[0][var] = jeu->tuile_out;
        jeu->tuile_out = temp;
        break;
    }
    case 'D':
    {
        //PousseDepuis(6,1,&jeu);
        int var = 1;
        shift_row_left(var,jeu->cartes);
        t_carte temp = jeu->cartes[var][6];
        jeu->cartes[var][6] = jeu->tuile_out;
        jeu->tuile_out = temp;
        break;
    }
    case 'E':
    {
        //PousseDepuis(6,3,&jeu);
        int var = 3;
        shift_row_left(var,jeu->cartes);
        t_carte temp = jeu->cartes[var][6];
        jeu->cartes[var][6] = jeu->tuile_out;
        jeu->tuile_out = temp;
        break;
    }
    case 'F':
    {
        //PousseDepuis(6,5,&jeu);
        int var = 5;
        shift_row_left(var,jeu->cartes);
        t_carte temp = jeu->cartes[var][6];
        jeu->cartes[var][6] = jeu->tuile_out;
        jeu->tuile_out = temp;
        break;
    }
    case 'G':
    {
        //PousseDepuis(6,5,&jeu);
        int var = 5;
        shift_row_up(var,jeu->cartes);
        t_carte temp = jeu->cartes[6][var];
        jeu->cartes[6][var] = jeu->tuile_out;
        jeu->tuile_out = temp;
        break;
    }
    case 'H':
    {
        //PousseDepuis(6,3,&jeu);
        int var = 3;
        shift_row_up(var,jeu->cartes);
        t_carte temp = jeu->cartes[6][var];
        jeu->cartes[6][var] = jeu->tuile_out;
        jeu->tuile_out = temp;
        break;
    }
    case 'I':
    {
        //PousseDepuis(6,1,&jeu);
        int var = 1;
        shift_row_up(var,jeu->cartes);
        t_carte temp = jeu->cartes[6][var];
        jeu->cartes[6][var] = jeu->tuile_out;
        jeu->tuile_out = temp;
        break;
    }
    case 'J':
    {
        //PousseDepuis(5,0,&jeu);
        int var = 5;
        shift_row_right(var,jeu->cartes);
        t_carte temp = jeu->cartes[var][0];
        jeu->cartes[var][0] = jeu->tuile_out;
        jeu->tuile_out = temp;
        break;
    }
    case 'K':
    {
        //PousseDepuis(3,0,&jeu);
        int var = 3;
        shift_row_right(var,jeu->cartes);
        t_carte temp = jeu->cartes[var][0];
        jeu->cartes[var][0] = jeu->tuile_out;
        jeu->tuile_out = temp;
        break;
    }
    case 'L':
    {
        //PousseDepuis(1,0,&jeu);
        int var = 1;
        shift_row_right(var,jeu->cartes);
        t_carte temp = jeu->cartes[var][0];
        jeu->cartes[var][0] = jeu->tuile_out;
        jeu->tuile_out = temp;
        break;
    }
    }

}

void shift_row_right(int row, t_carte mat[7][7]) {
    t_carte temp = mat[row][7-1];
    for (int j = 7-1; j > 0; j--) {
        mat[row][j] = mat[row][j-1];
    }
    mat[row][0] = temp;
}

void shift_row_left( int row, t_carte mat[7][7]) {
    t_carte temp = mat[row][0];
    for (int j = 0; j < 7-1; j++) {
        mat[row][j] = mat[row][j+1];
    }
    mat[row][7-1] = temp;
}

void shift_row_down( int col, t_carte mat[7][7]) {
    t_carte temp = mat[7-1][col];
    for (int i = 7-1; i > 0; i--) {
        mat[i][col] = mat[i-1][col];
    }
    mat[0][col] = temp;
}

void shift_row_up( int col, t_carte mat[7][7]) {
    t_carte temp = mat[0][col];
    for (int i = 0; i < 7-1; i++) {
        mat[i][col] = mat[i+1][col];
    }
    mat[7-1][col] = temp;
}

//Deplacement

int testDeplacementJoueur(t_jeu plateau, int lig, int col){
    int test = -1;

    int tour = plateau.tour_de_jeu;
    int lig_j = plateau.joueurs[tour].rang;
    int col_j = plateau.joueurs[tour].colonne;
    int sens = 0; //0 = haut, 1 = droite, 2 = bas, 3=gauche

    // Check que le joueur ne sors par du plateau
    if (lig < 0 || lig > 6 || col < 0 || col > 6){
        return -2;
    }

    //Check que les coordonnées sont a cote du joueur
    if((lig_j + 1 == lig || lig_j - 1 == lig || lig_j == lig) && (col_j + 1 == col || col_j - 1 == col || col_j == col)){

    }else {
        return -3;
    }

    if(col_j == col && lig_j > lig ){ // deplacement vers le haut
        sens = 0;
    } else if (col_j == col && lig_j < lig){ // deplacement vers le bas
        sens = 2;
    } else if(col_j < col && lig_j == lig ){ // deplacement vers la droite
        sens = 1;
    } else if (col_j > col && lig_j == lig){ // deplacement vers la gauche
        sens = 3;
    }

//    for(int i=0; i<3; i++){
//        gotoligcol(25 + i, 45);
//        for(int j=0; j<3; j++){
//            printf("%c", plateau.cartes[lig][col].dessin[i][j]);
//        }
//    }
//    for(int i=0; i<3; i++){
//        gotoligcol(25 + i, 50);
//        for(int j=0; j<3; j++){
//            printf("%c", plateau.cartes[lig_j][col_j].dessin[i][j]);
//        }
//    }

    switch(sens){
        case 0: {
            //si deplacement vers le haut, on check le dessin au mileu bas de la carte du dessus et sur l'extremite de la carte ou le joueur est
            if(plateau.cartes[lig][col].dessin[2][1] != '#' && plateau.cartes[lig_j][col_j].dessin[0][1] != '#') {
                test = 1;
            } else {
//                gotoligcol(18, 45);
//                printf("0-%d,%d/_%c_%c_", lig_j, col_j, plateau.cartes[lig][col].dessin[2][1], plateau.cartes[lig_j][col_j].dessin[0][1]);
                test = -plateau.cartes[lig][col].dessin[2][1];
            }
        break;
        }
        case 1: {
            //si deplacement vers la droite, on check le dessin au milieu gauche de la carte a droite
            if(plateau.cartes[lig][col].dessin[1][0] != '#' && plateau.cartes[lig_j][col_j].dessin[1][2] != '#') {
                test = 1;
            } else {
//                gotoligcol(18, 45);
//                printf("1-%d,%d/_%c_%c_", lig_j, col_j, plateau.cartes[lig][col].dessin[1][0], plateau.cartes[lig_j][col_j].dessin[1][2]);                test = -plateau.cartes[lig][col].dessin[1][0];
            }
        break;
        }
        case 2: {
            //si deplacement vers le bas, on check le dessin au mileu haut de la carte en dessous
            if(plateau.cartes[lig][col].dessin[0][1] != '#' && plateau.cartes[lig_j][col_j].dessin[2][1] != '#') {
                test = 1;
            } else {
//                gotoligcol(18, 45);
//                printf("%2-d,%d/_%c_%c_", lig_j, col_j, plateau.cartes[lig][col].dessin[0][1], plateau.cartes[lig_j][col_j].dessin[2][1]);
                test = -plateau.cartes[lig][col].dessin[0][1];
            }
        break;
        }
        case 3: {
            //si deplacement vers la gauche, on check le dessin au mileu droit de la carte a gauche
            if(plateau.cartes[lig][col].dessin[1][2] != '#' && plateau.cartes[lig_j][col_j].dessin[1][0] != '#') {
                test = 1;
            } else {
//                gotoligcol(18, 45);
//                printf("3-%d,%d/_%c_%c_", lig_j, col_j, plateau.cartes[lig][col].dessin[1][2], plateau.cartes[lig_j][col_j].dessin[1][0]);
                test = -plateau.cartes[lig][col].dessin[1][2];
            }
        break;
        default:
            test = -4;
        }
    }
    return test;
}


int getDirection(int lig, int col) {
    char input;
    int direction = -1;

    while (direction == -1) {
        gotoligcol(lig, col);
        printf("Entrez la direction (Z, D, S, Q, P pour quitter) : ");
        scanf(" %c", &input);

        switch (input) {
            case 'z':
            case 'Z':
                direction = 0;
                break;
            case 'd':
            case 'D':
                direction = 1;
                break;
            case 's':
            case 'S':
                direction = 2;
                break;
            case 'q':
            case 'Q':
                direction = 3;
                break;
            case 'p':
            case 'P':
                return -2;
                break;
            default:
                gotoligcol(lig + 1, col);
                printf("Entree non valide.\n");
                return -1;
                break;
        }
    }

    return direction;
}

int deplacerJoueur(t_jeu* plateau){
    int deplacement = -1;
    int lig_dep, col_dep;

    while(deplacement == -1) {
        deplacement = getDirection(10, 40);
    }
    gotoligcol(11, 40);
    printf("deplacement: %d\n", deplacement);


    switch(deplacement){
    case -2: //le joueur a fini de se deplacer
        return 1;
    case 0: //deplacement vers le haut
        lig_dep = -1;
        col_dep = 0;
        break;
    case 1: //deplacement vers la droite
        lig_dep = 0;
        col_dep = 1;
        break;
    case 2: //deplacement vers le bas
        lig_dep = 1;
        col_dep = 0;
        break;
    case 3: //deplacement vers la gauche
        lig_dep = 0;
        col_dep = -1;
        break;
    default: //deplacement hors du plateau pour generer une erreur
        lig_dep = -50;
        col_dep = -50;
        break;
    }

    int nouvelle_lig = plateau->joueurs[plateau->tour_de_jeu].rang + lig_dep;
    int nouvelle_col = plateau->joueurs[plateau->tour_de_jeu].colonne + col_dep;
    int possible = testDeplacementJoueur(*plateau, nouvelle_lig, nouvelle_col);
    if(possible < 0){
        gotoligcol(12, 35);
        printf("Impossible de se deplacer dans cette direction (error #%d)",
               plateau->joueurs[plateau->tour_de_jeu].rang, plateau->joueurs[plateau->tour_de_jeu].colonne, nouvelle_lig, nouvelle_col, possible);
        Sleep(500);
        return -1; //impossible de se deplacer dans cette direction, on recommence
    } else { //sinon c'est possible, donc on modifie les coordonnées du joueur.
        plateau->joueurs[plateau->tour_de_jeu].rang += lig_dep;
        plateau->joueurs[plateau->tour_de_jeu].colonne += col_dep;
    }

    return -1; // le joueur s'est déplacé mais n'a pas quitté, on retourne -1 pour relancer la fonction apres
}
