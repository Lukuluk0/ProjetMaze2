#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>


typedef struct carte {
    int rang; //ligne
    int colonne;//colonne
    int shape; // soit T=0 soit L=1 ssoit I=2
    char dessin[3][3];
    char tresor;

}t_carte;

typedef struct player
{
    int rang;
    int colonne;
    int id;
    int numero_joueur; // meme chose que ID ? avant c'etait color mais go utiliser id du couo nan ?
    char main_tresors[12];
    int index_tresors;

}t_player;

typedef struct jeu {
    t_carte cartes[7][7]; // 7*7 = 49
    t_player joueurs[4];
    t_carte tuile_out; // + 1 = 50
    int nbr_player;
    int tour_de_jeu;
}t_jeu;

typedef struct sauvegarde {
    t_jeu game;
}t_sauvegarde;

#endif // HEADER_H_INCLUDED
