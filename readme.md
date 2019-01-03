Lambert Timothée 11708277
Kwansa Yannick 11611442
Verdu Simon 11509717

Projet de LIFAP4 : Zombies at Nautibus

Le joueur doit survivre le plus longtemps possible à des vagues successives de zombies de plus en plus dangereux et nombreux.
Pour s'aider, le joueur pourra ramasser des bonus en cours de jeu.

Commandes:
	ZQSD pour se déplacer
	Clique gauche pour tirer
	R pour recharger l'arme
	P pour faire pause ou reprendre la partie
	ECHAP pour quitter le jeu à tout moment
	
	
	
	
- Code écrit en C++

- Testé sous Linux (Fedora et Ubuntu)

- Toutes les actions si-dessous se font dans un terminal à la racine du repértoire du projet

- Se compile avec gcc avec la commande suivante : 
	make

Ps: Les répertoires src/, obj/, bin/ et data/ sont indispensable pour la compilation et l'exécution du projet

- Ce module a besoin de la librairie SDL2 pour fonctionner, sur Linux voici la commande pour installer la SDL :
	sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev
	
- Pour lancer le jeu une fois compilé, tapez une des commandes suivantes :
	make play
	OU
	bin/zombie

- Pour supprimer les fichiers de compilation et les executables tapez la commande suivante
	make clean

- Pour générer la documentation du code, taper l'une des instructions suivante : 
	make doxy
	OU
	doxygen doc/doxyfile

Ps: La documentation sera générée dans le répertoire "doc"
	
- Pour ouvrir la documentation générée précédement avec Mozilla Firefox sur Linux, tapez une des commandes suivante :
	make opendoc
	OU
	firefox doc/html/index.html &
	
- Pour supprimer la documention générée précédement, tapez une des commandes suivantes:
	make cleandoc
	OU
	rm -r doc/html

Ps: Si doxygen n'est pas installé, il faut l'installer sur Linux avec la commande suivante :
	sudo apt-get install doxygen
	
- Merci de ne supprimer aucun fichier du répertoire data/
