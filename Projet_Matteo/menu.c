#include "menu.h"
#include "affichage.h"

void affichageTitre()
{
    printf("\n     (                                                       \n ) \\ )           )                          )    )        \n(()/(     )  ( /(  (     (   (          ( /( ( /(    (   \n /(_)) ( /(  ) \\()) ) \\ )  )(  ) \\   (     ) \\())) \\())  )) \\  \n(_))   )(_))((_) \\ (()/( (() \\((_)  ) \\ ) (_))/((_) \\  /((_) \n| |   ((_)_ | |(_) )(_)) ((_)(_) _(_/( | |_ | |(_)(_))   \n| |__ / _` || '_  \\| || || '_|| || '  \\))|  _|| '  \\ / -_)  \n|____| \\__,_||_.__/  \\_, ||_|  |_||_||_|   \\__||_||_| \\___|  \n                   |__/\n    ");
}

void affichageMenuPrincipal(int lig, int col)
{
    gotoligcol(lig, col);
    printf("Labyrinthe");
    gotoligcol(lig + 2, col);
    printf("1- Jouer");
    gotoligcol(lig + 3, col);
    printf("2- Charger");
    gotoligcol(lig + 4, col);
    printf("3- Regle");
    gotoligcol(lig + 5, col);
    printf("4- Quitter");
    gotoligcol(lig + 6, col);
}

int getUserChoice(char *msg, int min_input, int max_input)
{
    char choice = 0;
    printf(msg);
    scanf("%c", &choice);
    if (choice < min_input + 48 || choice > max_input + 57)
    {
        return -1;
    }
    else
    {
        return (int)choice - 48;
    }
}
