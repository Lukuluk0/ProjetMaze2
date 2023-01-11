#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "header.h"

void Jouer(t_jeu jeu);

int testDeplacementJoueur(t_jeu plateau, int lig, int col);
int deplacerJoueur(t_jeu* plateau);
int getDirection(int lig, int col);

int fin_du_jeu(t_jeu jeu);
int rotate(t_jeu*jeu);
void deplacerTuile(t_jeu *jeu);

void shift_row_right(int row, t_carte mat[7][7]);
void shift_row_left(int row, t_carte mat[7][7]);
void shift_row_down(int col, t_carte mat[7][7]);
void shift_row_up(int col, t_carte mat[7][7]);

#endif // JEU_H_INCLUDED
