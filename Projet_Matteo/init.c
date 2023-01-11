#include "init.h"

#define N 3

// Function to rotate the matrix 90 degree clockwise
void rotate90Clockwise(char a[N][N]) /// source https://www.geeksforgeeks.org/
{

    // Traverse each cycle
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = i; j < N - i - 1; j++)
        {

            // Swap elements of each cycle
            // in clockwise direction
            char temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}

void dessinI(char dessin[3][3], char tresor)
{
    char carte[3][3] = {{'#', ' ', '#'},
        {'#', tresor, '#'},
        {'#', ' ', '#'}
    };
    memcpy(dessin, carte, sizeof(carte));
}

void dessinT(char dessin[3][3], char tresor)
{
    char carte[3][3] = {{'#', ' ', '#'},
        {'#', tresor, ' '},
        {'#', ' ', '#'}
    };
    memcpy(dessin, carte, sizeof(carte));
}

void dessinL(char dessin[3][3], char tresor)
{
    char carte[3][3] = {{'#', '#', '#'},
        {' ', tresor, '#'},
        {'#', ' ', '#'}
    };
    memcpy(dessin, carte, sizeof(carte));
}

void init_joueurs(t_jeu *jeu)
{
    // tableaudes tresors a attribuer aux joueurs
    char tab[24] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X'};
    // on melange le tableau
    int k;
    for (k = 0; k < 24; k++)
    {
        int x = rand() % 24;
        int y = rand() % 24;
        char temp = tab[x];
        tab[x] = tab[y];
        tab[y] = temp;
    }

    int i;
    int last = 0;
    for (i = 0; i < jeu->nbr_player; i++)
    {
        switch (i) // on init es joueur dans les coins
        {
        case 0:
        {
            jeu->joueurs[i].rang = 0;
            jeu->joueurs[i].colonne = 0;
            break;
        }
        case 1:
        {
            jeu->joueurs[i].rang = 0;
            jeu->joueurs[i].colonne = 6;
            break;
        }
        case 2:
        {
            jeu->joueurs[i].rang = 6;
            jeu->joueurs[i].colonne = 0;
            break;
        }
        case 3:
        {
            jeu->joueurs[i].rang = 6;
            jeu->joueurs[i].colonne = 6;
            break;
        }
        }

        jeu->joueurs[i].id = i;
        jeu->joueurs[i].numero_joueur = i;
        jeu->joueurs[i].index_tresors = 0;

        int j;

        for (j = 0; j < 24 / jeu->nbr_player; j++)
        {
            jeu->joueurs[i].main_tresors[j] = tab[j + last];
        }
        last = last + j;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*for(i=0; i<jeu->nbr_player; i++)
    {
        printf("rang: %d colonnne: %d id : %d main_tresors",jeu->joueurs[i].rang,jeu->joueurs[i].colonne,jeu->joueurs[i].id);
        for(int j = 0;j<12;j++)
        {
            printf("%c",jeu->joueurs[i].main_tresors[j]);
        }
        printf("\n");
    }*/
}

// initialise les tuiles
void init_cartes(t_jeu *jeu)
{
    int i, j;
    int compteur = 0;
    int compteur2 = 0;
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if (i % 2 == 1 || j % 2 == 1)
            {
                if (compteur < 6) // les T
                {
                    jeu->cartes[i][j].shape = 0;
                    jeu->cartes[i][j].tresor = (char)(compteur + 'A');
                    dessinT(jeu->cartes[i][j].dessin, jeu->cartes[i][j].tresor);
                }
                else if (compteur < 12) // L avec tresors
                {
                    jeu->cartes[i][j].shape = 1;
                    jeu->cartes[i][j].tresor = (char)(compteur + 'A');
                    dessinL(jeu->cartes[i][j].dessin, jeu->cartes[i][j].tresor);
                }
                else if (compteur < 22) // L SANS tresors
                {
                    jeu->cartes[i][j].shape = 1;
                    jeu->cartes[i][j].tresor = ' ';
                    dessinL(jeu->cartes[i][j].dessin, jeu->cartes[i][j].tresor);
                }
                else if (compteur < 34) // les I
                {
                    jeu->cartes[i][j].shape = 2;
                    jeu->cartes[i][j].tresor = ' ';
                    dessinI(jeu->cartes[i][j].dessin, jeu->cartes[i][j].tresor);
                }
                compteur++;
            }
            else
            {
                if ((i == 0 && j == 0) || (i == 6 && j == 0) || (i == 0 && j == 6) || (i == 6 && j == 6)) // les coins
                {
                    jeu->cartes[i][j].shape = 1;
                    jeu->cartes[i][j].tresor = ' ';
                    dessinL(jeu->cartes[i][j].dessin, jeu->cartes[i][j].tresor);
                }
                else // les T
                {
                    jeu->cartes[i][j].shape = 0;
                    jeu->cartes[i][j].tresor = (char)(compteur2 + 'L');
                    dessinT(jeu->cartes[i][j].dessin, jeu->cartes[i][j].tresor);
                    compteur2++;
                }
            }
        }
    }

    // Melange des piece qui ne bouge pas
    for(int v = 0; v < 10 ;v++){
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if (i % 2 == 1 || j % 2 == 1)
            {
                int x = rand() % 7;
                int y = rand() % 7;
                while (x % 2 == 0 && y % 2 == 0)
                {
                    x = rand() % 7;
                    y = rand() % 7;
                }
                t_carte temp = jeu->cartes[i][j];
                jeu->cartes[i][j] = jeu->cartes[x][y];
                jeu->cartes[x][y] = temp;
                int t= rand()%4;
                for(int h =0;h<t;h++)
                {
                    rotate90Clockwise(jeu->cartes[i][j].dessin);
                }

            }
        }
    }
    }

    //Rotate les coins
    rotate90Clockwise(jeu->cartes[0][0].dessin);
    rotate90Clockwise(jeu->cartes[0][0].dessin);
    rotate90Clockwise(jeu->cartes[0][0].dessin);

    rotate90Clockwise(jeu->cartes[6][0].dessin);
    rotate90Clockwise(jeu->cartes[6][0].dessin);

    rotate90Clockwise(jeu->cartes[6][6].dessin);

    // Rotate les T en haut
    rotate90Clockwise(jeu->cartes[0][2].dessin);

    rotate90Clockwise(jeu->cartes[0][4].dessin);

    //rotate les T a droite
    rotate90Clockwise(jeu->cartes[2][6].dessin);
    rotate90Clockwise(jeu->cartes[2][6].dessin);

    rotate90Clockwise(jeu->cartes[4][6].dessin);
    rotate90Clockwise(jeu->cartes[4][6].dessin);

    //Rotate les T en bas
    rotate90Clockwise(jeu->cartes[6][2].dessin);
    rotate90Clockwise(jeu->cartes[6][2].dessin);
    rotate90Clockwise(jeu->cartes[6][2].dessin);

    rotate90Clockwise(jeu->cartes[6][4].dessin);
    rotate90Clockwise(jeu->cartes[6][4].dessin);
    rotate90Clockwise(jeu->cartes[6][4].dessin);
///////////////////////////////////////////////////////////////////////////////////////////////////////
    /*int compteurT = 0,compteurI=0,compteurL=0;
    for(i=0; i<7; i++)
    {

        for(j=0; j<7; j++)
        {
            if(jeu->cartes[i][j].shape == 0)
            {
                compteurT++;
            }
            else if (jeu->cartes[i][j].shape == 1)
            {
                compteurL++;
            }
            else if (jeu->cartes[i][j].shape == 2)
            {
                compteurI++;
            }
            printf("[%d%c]",jeu->cartes[i][j].shape,jeu->cartes[i][j].tresor);
        }
        printf("\n");
    }
    printf("T : %d L : %d I : %d",compteurT,compteurL,compteurI);
    char c = getch();*/
}

void init_jeu(t_jeu *jeu, int nbr_player)
{
    jeu->nbr_player = nbr_player;
    jeu->tour_de_jeu = 0;

    init_cartes(jeu);
    init_joueurs(jeu);

    jeu->tuile_out.shape = 2;
    jeu->tuile_out.tresor = ' ';
    dessinI(jeu->tuile_out.dessin, jeu->tuile_out.tresor);
    char c = getch();
    c++; //fix warning unused variable
}
