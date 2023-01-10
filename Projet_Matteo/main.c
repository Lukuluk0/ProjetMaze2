#include "header.h"

void affichage()
{
    gotoligcol(8,20);
    printf("Labyrinthe");
    gotoligcol(10,20);
    printf("1- Jouer");
    gotoligcol(11,20);
    printf("2- Charger");
    gotoligcol(12,20);
    printf("3- Regle");
    gotoligcol(13,20);
    printf("4- Quitter");
    gotoligcol(14,20);
}

int main()
{
    srand(time(NULL));

    int menu = -1;
    do
    {
        system("cls");
        affichage();
        do
        {
            scanf("%d",&menu);
        }
        while (menu<0 || menu >4);
        switch(menu)
        {
        case 1:
        {
            menu = -1;
            t_jeu jeu;
            //jeu
            break;
        }
        case 2:
        {
            //sauvegarde
            break;
        }
        case 3:
        {
            menu = -1;
            //affiche regle
            break;
        }
        }

    }
    while(menu != 4);
        return 0;
}
