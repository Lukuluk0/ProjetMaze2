#include "init.h"



//initialise un jeu     //initialise un jeu
void init_jeu(t_jeu *jeu, int nbr_player)
{
    jeu->nbr_player = nbr_player;
    jeu->tour_de_jeu = 0;
    init_cartes(jeu);
    init_joueurs(jeu);
    init_tuile_out(jeu);
}

//initialise les tuiles
void init_tuiles(t_jeu*jeu){
    int i,j;
    for(i=0;i<7;i++){
        for(j=0;j<7;j++){
            jeu->cartes[i][j].rang = i;
            jeu->cartes[i][j].colonne = j;
            jeu->cartes[i][j].shape = rand()%3;
            jeu->cartes[i][j].tresor = rand()%5;
        }
    }
}
