#include "header.h"
#include "menu.h"

int main()
{
    srand(time(NULL));

    int menu = -1;
    int number_player = 2;
    do
    {
        do
        {
            system("cls");
            affichageTitre();
            affichageMenuPrincipal(13, 15);
            gotoligcol(21, 5);
            menu = getUserChoice("Votre choix : ", 1, 4);
        } while (menu == -1);

        switch (menu)
        {
        case 1:
        {
            menu = -1; // remet le menu a -1 pour recommencer le menu a la fin de la game
            do
            {
                system("cls");
                affichageTitre();
                gotoligcol(13, 5);
                number_player = getUserChoice("Combien de joueur voulez vous (2, 3 ou 4) : ", 2, 4);
            } while (number_player == -1);
            system("cls");
            t_jeu jeu;
            init_jeu(&jeu, 2);
            affichagePlateau(jeu);
            Sleep(50000);
            // jeu
            break;
        }
        case 2:
        {
            menu = -1;
            // sauvegarde
            break;
        }
        case 3:
        {
            menu = -1;
            // affiche regle
            break;
        }
        case 4:
        {
            menu = 4;
            // affiche regle
            break;
        }
        default:
        {
            menu = -1;
            // affiche regle
            break;
        }
        }
    } while (menu != 4);

    return 0;
}
