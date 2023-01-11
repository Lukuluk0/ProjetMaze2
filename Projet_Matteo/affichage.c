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
    int espaceBlockHorizontal = 3;
    int espaceBlockVertical = 1;
    char mur = 'x';

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

    for (int i = 1; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                gotoligcol(decalageHaut + i * (3 + espaceBlockVertical) + k, decalageGauche + j * (3 + espaceBlockHorizontal));
                for (int l = 0; l < 3; l++)
                {
                    printf("%c", plateau.cartes[i][j].dessin[k][l]);
                }
            }
        }
    }

    for (int i = 0; i < plateau.nbr_player; i++)
    {
        gotoligcol(5, 45);
        printf("C'est au joueur %d de joueur !", i);
        gotoligcol(7, 45);
        printf("Vos tresors : ");
        for (int j = 0; j < 12; j++)
        {
            if (j == plateau.joueurs[i].index_tresors)
            {
                Color(6 + i, 0);
            }
            printf("%c ", plateau.joueurs[i].main_tresors[j]);
            Color(15, 0);
        }
    }
}
