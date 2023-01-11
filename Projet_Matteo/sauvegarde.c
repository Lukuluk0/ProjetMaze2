#include "sauvegarde.h"
#include "affichage.h"

int sauv_jeu(t_jeu plateau)
{

    // Ouvrir un fichier binaire en écriture
    FILE *fichier = fopen("sauvegarde.bin", "wb");
    if (fichier == NULL)
    {
        printf("Impossible d'ouvrir le fichier!\n");
        return -1;
    }

    // Ecriture de la plateau dans le fichier
    fwrite(&plateau, sizeof(struct jeu), 1, fichier);

    fclose(fichier);
    return 0;
}

int char_jeu(t_jeu *plateau)
{
    // Ouvrir la sauvegarde binaire en lecture
    FILE *fichier = fopen("sauvegarde.bin", "rb");
    if (fichier == NULL)
    {
        printf("Impossible d'ouvrir le fichier!\n");
        return -1;
    }
    // Lecture de la sauvegarde depuis le fichier
    fread(plateau, sizeof(struct jeu), 1, fichier);
    fclose(fichier);
    return 0;
}

int sauv_menu(t_jeu plateau)
{
    int arreter = 0;
    char input;

    system("cls");
    gotoligcol(4, 0);
    printf("Voulez vous sauvegarder la partie actuelle ? Cela ecrasera la précédente sauvegarde. (Y/N)");
    fflush(stdin);
    input = getchar();
    if(input == 'Y' || input == 'y')
    {
        if(sauv_jeu(plateau) == 0)
        {
            printf("Quitter  la partie ? (Y/N)");
            fflush(stdin);
            input = getchar();
            if(input == 'Y' || input == 'y')
            {
                arreter = 1;
            }
        }
        else
        {
            printf("Erreur : impossible de sauvegarder...");
        }
    }
    return arreter;
}
