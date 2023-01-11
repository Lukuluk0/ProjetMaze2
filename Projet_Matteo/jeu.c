#include "jeu.h"


void Jouer(t_jeu jeu)
{

    do
    {
        system("cls");
        affichagePlateau(jeu);

        if(rotate(&jeu) == 0){
        deplacerTuile(&jeu);

        }

    }
    while(fin_du_jeu(jeu) == 1); // faire la fonction de fin de jeu


}

int fin_du_jeu(t_jeu jeu)
{
    for(int i = 0;i<jeu.nbr_player;i++)
    {
        if(jeu.joueurs[i].index_tresors == 24/jeu.nbr_player)
        {
            return 0;
        }
    }
    return 1;
}

int rotate(t_jeu*jeu)
{
    gotoligcol(9, 45);
    printf("Voulez vous tourner la carte ?(Y/N)");
    char Y;

        Y = getch();
        if(Y=='Y'||Y == 'y'){
        rotate90Clockwise(jeu->carte_restante.dessin);
        return 1;
        }

    return 0;
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
        jeu->cartes[0][var] = jeu->carte_restante;
        jeu->carte_restante = temp;
        break;
    }
    case 'B':
    {
        //PousseDepuis(0,3,&jeu);
        int var = 3;
        shift_row_down(var,jeu->cartes);
        t_carte temp = jeu->cartes[0][var];
        jeu->cartes[0][var] = jeu->carte_restante;
        jeu->carte_restante = temp;
        break;
    }
    case 'C':
    {

        //PousseDepuis(0,5,&jeu);
        int var = 5;
        shift_row_down(var,jeu->cartes);
        t_carte temp = jeu->cartes[0][var];
        jeu->cartes[0][var] = jeu->carte_restante;
        jeu->carte_restante = temp;
        break;
    }
    case 'D':
    {
        //PousseDepuis(6,1,&jeu);
        int var = 1;
        shift_row_left(var,jeu->cartes);
        t_carte temp = jeu->cartes[var][6];
        jeu->cartes[var][6] = jeu->carte_restante;
        jeu->carte_restante = temp;
        break;
    }
    case 'E':
    {
        //PousseDepuis(6,3,&jeu);
        int var = 3;
        shift_row_left(var,jeu->cartes);
        t_carte temp = jeu->cartes[var][6];
        jeu->cartes[var][6] = jeu->carte_restante;
        jeu->carte_restante = temp;
        break;
    }
    case 'F':
    {
        //PousseDepuis(6,5,&jeu);
        int var = 5;
        shift_row_left(var,jeu->cartes);
        t_carte temp = jeu->cartes[var][6];
        jeu->cartes[var][6] = jeu->carte_restante;
        jeu->carte_restante = temp;
        break;
    }
    case 'G':
    {
        //PousseDepuis(6,5,&jeu);
        int var = 5;
        shift_row_up(var,jeu->cartes);
        t_carte temp = jeu->cartes[6][var];
        jeu->cartes[6][var] = jeu->carte_restante;
        jeu->carte_restante = temp;
        break;
    }
    case 'H':
    {
        //PousseDepuis(6,3,&jeu);
        int var = 3;
        shift_row_up(var,jeu->cartes);
        t_carte temp = jeu->cartes[6][var];
        jeu->cartes[6][var] = jeu->carte_restante;
        jeu->carte_restante = temp;
        break;
    }
    case 'I':
    {
        //PousseDepuis(6,1,&jeu);
        int var = 1;
        shift_row_up(var,jeu->cartes);
        t_carte temp = jeu->cartes[6][var];
        jeu->cartes[6][var] = jeu->carte_restante;
        jeu->carte_restante = temp;
        break;
    }
    case 'J':
    {
        //PousseDepuis(5,0,&jeu);
        int var = 5;
        shift_row_right(var,jeu->cartes);
        t_carte temp = jeu->cartes[var][0];
        jeu->cartes[var][0] = jeu->carte_restante;
        jeu->carte_restante = temp;
        break;
    }
    case 'K':
    {
        //PousseDepuis(3,0,&jeu);
        int var = 3;
        shift_row_right(var,jeu->cartes);
        t_carte temp = jeu->cartes[var][0];
        jeu->cartes[var][0] = jeu->carte_restante;
        jeu->carte_restante = temp;
        break;
    }
    case 'L':
    {
        //PousseDepuis(1,0,&jeu);
        int var = 1;
        shift_row_right(var,jeu->cartes);
        t_carte temp = jeu->cartes[var][0];
        jeu->cartes[var][0] = jeu->carte_restante;
        jeu->carte_restante = temp;
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


