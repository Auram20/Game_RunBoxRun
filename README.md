# Game_RunBoxRun
Jeu développé en IMAC 2 - OpenGL/C++ 



RunBoxRun est l’histoire d’un petit cube qui fuit ses ennemis, il se déplace le long d’un dédale et n’a qu’un objectif : retrouver la sortie. 
Aidez-le dans cette aventure en évitant les obstacles et en ramassant les pièces d’or.

Mode d’emploi 

Etape 1 : Lancement du jeu
Pré-Requis
Le jeu est compilable/exécutable sur une machine Unix. 
Il est nécessaire d’avoir les librairies SDL, Assimp, GLEW, GLM … Ainsi que Cmake et make d’installés sur la machine.
 
Pour compiler et exécuter le jeu : 
-Se placer à la racine du dossier et créer un nouveau dossier build. 
(Console : mkdir build )
- Ouvrir la console et se placer dans le build : cd build 
- Taper la commande de compilation suivante : cmake && ../make
- Lancer le jeu : ../runBoxRun
- Afin de générer une documentation, taper : make html 


Etape 2 : Jouer 
- Le menu principal s’affiche, il est possible d’y naviguer grâce aux flèches du clavier et de sélectionner le choix voulu. 

- En jeu, il est possible de se déplacer grâce aux touches : qsdz 
- D’activer la caméra/la bloquer grâce à la touche : l 
- De changer de point de vue avec : c 

A tout moment il est possible de quitter le jeu avec ESC 
