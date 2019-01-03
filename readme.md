Timothée LAMBERT  
Yannick KWANSA  
Simon VERDU  

# Zombies at Nautibus

Le joueur doit survivre le plus longtemps possible à des vagues successives de zombies de plus en plus dangereux et nombreux.
Pour s'aider, le joueur pourra ramasser des bonus en cours de jeu.

## Commandes

- ZQSD : Se déplacer  
- Clique gauche : Tirer  
- R : Recharger l'arme  
- P : Pause/Reprendre  
- ECHAP : Quitter
	
## A propos
	
- Code écrit en C++
- Testé sous Linux (Fedora et Ubuntu)
- Toutes les actions si-dessous se font dans un terminal à la racine du repértoire du projet

Les répertoires "src", "obj", "bin" et "data" sont indispensable pour la compilation et l'exécution du jeu  

Ce module a besoin de la librairie SDL2 pour fonctionner, sur Linux voici la commande pour installer la SDL :  
```
sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev
```

## Jouer au jeu

Pour compiler le jeu utilisez la commande suivante :
```
make
```
	
Pour lancer le jeu une fois compilé, tapez une des commandes suivantes :
```
make play
```

Pour supprimer les fichiers de compilation et les executables tapez la commande suivante
```
make clean
```
### Documentation

Pour generer la documentation, vous aurez besoin du programme Doxygen, vouz pouvez l'installer avec cet commande :
```
sudo apt install doxygen
```

Pour générer la documentation du code, taper l'instruction suivante :
```
make doxy
```

La documentation sera générée dans le répertoire "doc"  
Pour ouvrir la documentation générée précédement avec Mozilla Firefox sur Linux, tapez une des commandes suivante :
```
make opendoc
```
	
Pour supprimer la documention générée précédement, tapez une des commandes suivantes:
```
make cleandoc
```

## Lien utiles

- [SDL](https://www.libsdl.org/)
- [OpenGameArt](https://opengameart.org/) : Site de ressources Open Source
