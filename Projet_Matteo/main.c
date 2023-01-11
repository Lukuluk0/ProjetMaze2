#include "header.h"
#include "affichage.h"
#include "menu.h"
#include "init.h"
#include "jeu.h"
#include "sauvegarde.h"

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
            init_jeu(&jeu, number_player);
            Jouer(jeu);
            //Sleep(50000);
            break;
        }
        case 2:
        {
            menu = -1;
            t_jeu jeu;
            char_jeu(&jeu);
            Jouer(jeu);
            // sauvegarde
            break;
        }
        case 3:
        {
            menu = -1;
            // affiche regle
            printf("\nLes joueurs peuvent deplacer les murs du labyrinthe en utilisant la piece de plus pour creer un passage vers les tresors.");
            printf("\nChaque joueur doit collecter tous ses propres tresors avant les autres joueurs.");
            printf("\nLe joueur qui recupere tous ses tresors en premier gagne la partie.");
            printf("\nLes joueurs peuvent egalement bloquer les passages des autres joueurs en utilisant la piece de plus, mais ils doivent faire attention a ne pas se bloquer eux-memes.");
            char c = getch();
            c++;
            break;
        }
        case 4:
        {
            menu = 4;
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
