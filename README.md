---
date: 2023-01-06
team: lucas saccoman,romain senhadji
topic: dev, game, c
technologies: c
tags: project, school, learning
description: "Game with langage C on theme of a maze."
---

# Labyrinthe


Jeu pour les ING1 en galère fait avec [[Romain Senhadji]].

Structures:
- Tuile
	- type : L ou T our |
	- Orientation : int 0 à 3 (sens des aiguilles d'une montre, 0 = haut et 1  = droite...)
	- Tresor (int) : 0 = pas de tresor, 1,2,3...24 = tresor
	- Position
- Joueur
	- id
	- Pseudo
	- Coordonnée (x, y)
	- couleur
	- cartes tresor : tableau (int) 
	- index carte tresor (int)
- Labyrinthe
	- tableau de tuiles
	- tableau de joueur
	- tuile out 
- Sauvegarde (v2)
	- labyrinthe
	- tour du joueur actuelle

Fonctionnalités:
- Menu principal
	- Le menu principal apparait au lancement du jeu, et à tout moment au cours d'une partie (cela se gèrera par des boucles dans des boucles, pas des appels du sous-programme menu dans lui-même). Le menu proposera par exemple : 
		- Nouvelle partie 
		- Sauvegarde (si la partie est en cours) 
		- Charger une partie • Afficher les règles / crédits 
		- Quitter NB : La sauvegarde et le chargement sont des bonus
- Initialiser:
	- Générer le labyrinthe
	- Générer tuile avec tresor
	- Melanger tuile
	- Remplir labyrinthe
	- distribuer cartes tresor
	- choisir un joueur au hasard
- Afficher labyrinthe
- Deplacer une colonne, contraintes :
	- pas sortir de joueur
	- pas deplacer ce qu'on ne peux pas 
	- pas inserer la tuille la ou elle vient de sortir
	- sauvegarder nouvelle tuile dans labyrinthe
	- si deplacer un joueur, changer coordonnées joueurs
- Modif coordonnées joueurs (int id_joueur, struct labyrinthe, nouvelles coordonnées)
- Tester les deplacement du joueur


Au tour du joueur:
- introduit la tuile
- Colorier sur le labyrinthe le tresor actuel du joueur
- avec les fleches, il se deplace comme il veut
- S'il recupere son tresor, afficher le tresor suivant ou annoncer victoire si finit
- quand il a finit, touche espace pour finir son tour
