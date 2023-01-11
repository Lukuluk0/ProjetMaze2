#include "affichage.h"

void Color(int couleurDuTexte, int couleurDeFond)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}

void gotoligcol(int lig, int col)
{
    // ressources
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord);
}

void affichagePlateau(t_jeu plateau)
{

    int decalageGauche = 5;
    int decalageHaut = 2;
    int espaceBlockHorizontal = 2;
    int espaceBlockVertical = 1;

    // for(int i=0; i<plateau.nbr_player; i++)
    // {
    //     printf("j_%d - %d,%d    ", i, plateau.joueurs[i].rang, plateau.joueurs[i].colonne);
    // }
    // char mur = 'x';
    // t_carte carte;
    // t_jeu plateauTest;
    // plateauTest.nbr_player = 3;
    // plateauTest.tour_de_jeu = 1;
    // t_player j1;
    // char tab[12] = {'A', 'B', 'A','B','A', 'B','A', 'B', 'A', 'B','A', 'B'};
    // strcmp(j1.main_tresors, tab);
    // j1.index_tresors = 3;
    // plateauTest.joueurs[1] = j1;
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         carte.dessin[i][j] = 'mur';
    //     }
    // }
    // for (int i = 0; i < 7; i++)
    // {
    //     for (int j = 0; j < 7; j++)
    //     {
    //         plateau.cartes[i][j] = carte;
    //     }
    // }

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    gotoligcol(decalageHaut + i * (3 + espaceBlockVertical) + k, decalageGauche + j * (3 + espaceBlockHorizontal) + l);
                    if(plateau.cartes[i][j].dessin[k][l] == '#')
                    {
                        for(int m=0; m<plateau.nbr_player; m++)
                        {
                            if(plateau.joueurs[m].rang == i && plateau.joueurs[m].colonne == j)
                            {
                                Color(9 + m, 9 + m);
                                break;
                            }
                            else
                            {
                                Color(15, 15);
                            }
                        }
                        printf("%c", plateau.cartes[i][j].dessin[k][l]);
                        Color(15, 0);
                    }
                }
            }
        }
    }


    gotoligcol(5, 45);
    printf("C'est au joueur %d de joueur !", plateau.tour_de_jeu);
    gotoligcol(7, 45);
    printf("Vos tresors : ");
    for (int j = 0; j < 24 / plateau.nbr_player; j++)
    {
        if (j == plateau.joueurs[plateau.tour_de_jeu].index_tresors)
        {
            Color(9 + plateau.tour_de_jeu, 0);
        }
        printf("%c ", plateau.joueurs[plateau.tour_de_jeu].main_tresors[j]);
        Color(15, 0);
    }

}


int testDeplacement(t_jeu plateau, int lig, int col){
    int test = -1;

    int tour = plateau.tour_de_jeu;
    int lig_j = plateau.joueurs[tour].rang;
    int col_j = plateau.joueurs[tour].colonne;
    int sens = 0; //0 = haut, 1 = droite, 2 = bas, 3=gauche

    // Check que le joueur ne sors par du plateau
    if (lig < 0 || lig > || col < 0 || col > 6){
        return -1;
    }

    if(col_j == col && lig_j < lig ){ // deplacement vers le haut
        sens = 0;
    } else if (col_j == col && lig_j > lig){ // deplacement vers le bas
        sens = 2;
    } else if(col_j < col && lig_j == lig ){ // deplacement vers la droite
        sens = 1;
    } else if (col_j > col && lig_j == lig){ // deplacement vers la gauche
        sens = 3;
    }

    switch(sens){
        case 0: {
            //si deplacement vers le haut, on check le dessin au mileu bas de la carte du dessus
            if(plateau.cartes[lig][col].dessin[2][1] != '#') {
                test = 1;
            }
        break;
        }
        case 1: {
            //si deplacement vers le haut, on check le dessin au milieu gauche de la carte a droite
            if(plateau.cartes[lig][col].dessin[1][0] != '#') {
                test = 1;
            }
        break;        }
        case 2: {
            //si deplacement vers le haut, on check le dessin au mileu haut de la carte en dessous
            if(plateau.cartes[lig][col].dessin[0][1] != '#') {
                test = 1;
            }
        break;
        }
        case 3: {
            //si deplacement vers le haut, on check le dessin au mileu droit de la carte a gauche
            if(plateau.cartes[lig][col].dessin[1][2] != '#') {
                test = 1;
            }
        break;
        }
    }
    return test;
}
