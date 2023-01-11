#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "header.h"

int testDeplacementJoueur(t_jeu plateau, int lig, int col);
int deplacerJoueur(t_jeu* plateau);
int getDirection(int lig, int col);


#endif // JEU_H_INCLUDED
