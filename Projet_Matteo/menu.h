#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "header.h"

void affichageTitre();
void affichageMenuPrincipal(int lig, int col);
int getUserChoice(char* msg, int min_input, int max_input);

#endif // MENU_H_INCLUDED
