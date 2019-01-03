SDL = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf


all : bin/zombie

bin/zombie : obj/main.o obj/Image.o obj/Vec2.o obj/Rectangle.o obj/Cercle.o obj/Zombie.o obj/Joueur.o obj/Humanoide.o obj/Son.o obj/Musique.o obj/Arme.o obj/Jeu.o obj/Input.o obj/Texte.o obj/Objet.o obj/Bouton.o
	g++ -g obj/main.o obj/Image.o obj/Vec2.o obj/Rectangle.o obj/Cercle.o obj/Zombie.o obj/Joueur.o obj/Humanoide.o obj/Son.o  obj/Musique.o obj/Arme.o obj/Jeu.o obj/Input.o obj/Texte.o obj/Objet.o obj/Bouton.o $(SDL) -o bin/zombie

obj/main.o : src/main.cpp
	g++ -g -Wall -c -std=c++11 src/main.cpp && mv main.o obj/main.o

obj/Bouton.o : src/Bouton.cpp src/Bouton.h obj/Vec2.o obj/Rectangle.o obj/Image.o
	g++ -g -Wall -c src/Bouton.cpp && mv Bouton.o obj/Bouton.o

obj/Texte.o : src/Texte.cpp src/Texte.h
	g++ -g -Wall -c src/Texte.cpp && mv Texte.o obj/Texte.o

obj/Image.o : src/Image.cpp src/Image.h
	g++ -g -Wall -c src/Image.cpp && mv Image.o obj/Image.o

obj/Musique.o : src/Musique.cpp src/Musique.h
	g++ -g -Wall -c src/Musique.cpp && mv Musique.o obj/Musique.o

obj/Son.o : src/Son.cpp src/Son.h
	g++ -g -Wall -c src/Son.cpp && mv Son.o obj/Son.o

obj/Joueur.o : src/Joueur.cpp src/Joueur.h obj/Vec2.o obj/Cercle.o obj/Rectangle.o obj/Humanoide.o
	g++ -g -Wall -c src/Joueur.cpp && mv Joueur.o obj/Joueur.o

obj/Zombie.o : src/Zombie.cpp src/Zombie.h obj/Vec2.o obj/Cercle.o obj/Rectangle.o obj/Humanoide.o
	g++ -g -Wall -c src/Zombie.cpp && mv Zombie.o obj/Zombie.o

obj/Humanoide.o : src/Humanoide.cpp src/Humanoide.cpp src/Humanoide.h
	g++ -g -Wall -c src/Humanoide.cpp && mv Humanoide.o obj/Humanoide.o

obj/Objet.o : src/Objet.cpp src/Objet.h obj/Vec2.o obj/Cercle.o
	g++ -g -Wall -c src/Objet.cpp && mv Objet.o obj/Objet.o

obj/Cercle.o : src/Cercle.cpp src/Cercle.h 
	g++ -g -Wall -c src/Cercle.cpp && mv Cercle.o obj/Cercle.o

obj/Rectangle.o : src/Rectangle.cpp src/Rectangle.h
	g++ -g -Wall -c src/Rectangle.cpp && mv Rectangle.o obj/Rectangle.o

obj/Vec2.o : src/Vec2.cpp src/Vec2.h
	g++ -g -Wall -c src/Vec2.cpp && mv Vec2.o obj/Vec2.o

obj/Arme.o : src/Arme.cpp src/Arme.h 
	g++ -g -Wall -c src/Arme.cpp && mv Arme.o obj/Arme.o

obj/Jeu.o : src/Jeu.cpp src/Jeu.h obj/Joueur.o obj/Arme.o obj/Objet.o
	g++ -g -Wall -c src/Jeu.cpp && mv Jeu.o obj/Jeu.o

obj/Input.o : src/Input.cpp src/Input.h
	g++ -g -Wall -c src/Input.cpp && mv Input.o obj/Input.o

play :
	bin/zombie

clean :
	rm obj/*.o && rm bin/*
	
doxy :
	doxygen doc/doxyfile
	
opendoc :
	firefox doc/html/index.html &
	
cleandoc :
	rm -r doc/html
