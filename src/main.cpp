#include <iostream>
#include "Image.h"
#include "Vec2.h"
#include "Rectangle.h"
#include "Cercle.h"
#include "Zombie.h"
#include "Joueur.h"
#include "Son.h"
#include "Musique.h"
#include "Input.h"
#include "Jeu.h"
#include "Texte.h"
#include "Bouton.h"

#include <vector>

#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
using namespace std;

const int ETAT_MENU = 0;
const int ETAT_JEU = 1;
const int ETAT_PAUSE = 2;
const int ETAT_GAMEOVER = 3;

float temps ()
{
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC * 1000.0;  // conversion des ms en secondes en divisant par 1000
}

int main()
{
	srand(time(NULL));

	Jeu jeu;

	unsigned int frame_rate (1000/50);
	Uint32 debut_boucle(0), fin_boucle(0), temps_ecoule(0);
	float rot;

	float dernier_tir;
  	float rechargement;

  	bool touchepause;

	//SDL_Window * w = SDL_CreateWindow("Affichage", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_SHOWN);
	SDL_Window * w = SDL_CreateWindow("Zombies at Nautibus", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
	SDL_Renderer * r = SDL_CreateRenderer(w,-1,SDL_RENDERER_ACCELERATED);
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio( MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048 );
	Mix_AllocateChannels(32);
	Mix_VolumeMusic(98); // Son des musiques
	TTF_Init();

	Input m_input;

	// Vie des zombies
	Image i_vie[2] = 
	{
		Image("data/img/hud/vert.png",r),
		Image("data/img/hud/rouge.png",r) 
	};

	// Image des objets ramassables
	Image i_objet[10] = 
	{
		Image("data/img/pistolet.png",r),
		Image("data/img/revolver.png",r),
		Image("data/img/pistolet-mitrailleur.png",r),
		Image("data/img/mitraillette.png",r),
		Image("data/img/kalachnikov.png",r),
		Image("data/img/carabine.png",r),
		Image("data/img/mitrailleuse.png",r),
		Image("data/img/sniper.png",r),
		Image("data/img/soin.png",r),
		Image("data/img/munition.png",r) 
	};

	string s_armes[16] = 
	{
		"data/wav/armes/pistolet.wav",
		"data/wav/armes/revolver.wav",
		"data/wav/armes/pistolet-mitrailleur.wav",
		"data/wav/armes/mitraillette.wav",
		"data/wav/armes/kalachnikov.wav",
		"data/wav/armes/carabine.wav",
		"data/wav/armes/mitrailleuse.wav",
		"data/wav/armes/sniper.wav",
		"data/wav/armes/pistolet_r.wav",
		"data/wav/armes/revolver_r.wav",
		"data/wav/armes/pistolet-mitrailleur_r.wav",
		"data/wav/armes/mitraillette_r.wav",
		"data/wav/armes/kalachnikov_r.wav",
		"data/wav/armes/carabine_r.wav",
		"data/wav/armes/mitrailleuse_r.wav",
		"data/wav/armes/sniper_r.wav" 
	};

	// Animation des zombies
    Image i_zombie[17] = 
    {
 	  Image("data/img/zombie/zombie0.png",r),
      Image("data/img/zombie/zombie1.png",r),
      Image("data/img/zombie/zombie2.png",r),
      Image("data/img/zombie/zombie3.png",r),
      Image("data/img/zombie/zombie4.png",r),
      Image("data/img/zombie/zombie5.png",r),
      Image("data/img/zombie/zombie6.png",r),
      Image("data/img/zombie/zombie7.png",r),
      Image("data/img/zombie/zombie8.png",r),
      Image("data/img/zombie/zombie9.png",r),
      Image("data/img/zombie/zombie10.png",r),
      Image("data/img/zombie/zombie11.png",r),
      Image("data/img/zombie/zombie12.png",r),
      Image("data/img/zombie/zombie13.png",r),
      Image("data/img/zombie/zombie14.png",r),
      Image("data/img/zombie/zombie15.png",r),
      Image("data/img/zombie/zombie16.png",r) 
    };

      //Animation du joueur
      Image i_joueurCMMS[20] = 
      {
    	Image("data/img/joueur/corps/joueurCMMS/joueurCMMS0.png",r),
        Image("data/img/joueur/corps/joueurCMMS/joueurCMMS1.png",r),
        Image("data/img/joueur/corps/joueurCMMS/joueurCMMS2.png",r),
        Image("data/img/joueur/corps/joueurCMMS/joueurCMMS3.png",r),
        Image("data/img/joueur/corps/joueurCMMS/joueurCMMS4.png",r),
        Image("data/img/joueur/corps/joueurCMMS/joueurCMMS5.png",r),
        Image("data/img/joueur/corps/joueurCMMS/joueurCMMS6.png",r),
        Image("data/img/joueur/corps/joueurCMMS/joueurCMMS7.png",r),
        Image("data/img/joueur/corps/joueurCMMS/joueurCMMS8.png",r),
        Image("data/img/joueur/corps/joueurCMMS/joueurCMMS9.png",r),
        Image("data/img/joueur/corps/joueurCMMS/joueurCMMS10.png",r),
        Image("data/img/joueur/corps/joueurCMMS/joueurCMMS11.png",r),
        Image("data/img/joueur/corps/joueurCMMS/joueurCMMS12.png",r),
        Image("data/img/joueur/corps/joueurCMMS/joueurCMMS13.png",r),
        Image("data/img/joueur/corps/joueurCMMS/joueurCMMS14.png",r),
        Image("data/img/joueur/corps/joueurCMMS/joueurCMMS15.png",r),
        Image("data/img/joueur/corps/joueurCMMS/joueurCMMS16.png",r),
        Image("data/img/joueur/corps/joueurCMMS/joueurCMMS17.png",r),
        Image("data/img/joueur/corps/joueurCMMS/joueurCMMS18.png",r),
        Image("data/img/joueur/corps/joueurCMMS/joueurCMMS19.png",r),
      };

      Image i_joueurcorpsPPMR[20] =
      {
        Image("data/img/joueur/corps/joueurPPMR/joueurPPMR0.png",r),
        Image("data/img/joueur/corps/joueurPPMR/joueurPPMR1.png",r),
        Image("data/img/joueur/corps/joueurPPMR/joueurPPMR2.png",r),
        Image("data/img/joueur/corps/joueurPPMR/joueurPPMR3.png",r),
        Image("data/img/joueur/corps/joueurPPMR/joueurPPMR4.png",r),
        Image("data/img/joueur/corps/joueurPPMR/joueurPPMR5.png",r),
        Image("data/img/joueur/corps/joueurPPMR/joueurPPMR6.png",r),
        Image("data/img/joueur/corps/joueurPPMR/joueurPPMR7.png",r),
        Image("data/img/joueur/corps/joueurPPMR/joueurPPMR8.png",r),
        Image("data/img/joueur/corps/joueurPPMR/joueurPPMR9.png",r),
        Image("data/img/joueur/corps/joueurPPMR/joueurPPMR10.png",r),
        Image("data/img/joueur/corps/joueurPPMR/joueurPPMR11.png",r),
        Image("data/img/joueur/corps/joueurPPMR/joueurPPMR12.png",r),
        Image("data/img/joueur/corps/joueurPPMR/joueurPPMR13.png",r),
        Image("data/img/joueur/corps/joueurPPMR/joueurPPMR14.png",r),
        Image("data/img/joueur/corps/joueurPPMR/joueurPPMR15.png",r),
        Image("data/img/joueur/corps/joueurPPMR/joueurPPMR16.png",r),
        Image("data/img/joueur/corps/joueurPPMR/joueurPPMR17.png",r),
        Image("data/img/joueur/corps/joueurPPMR/joueurPPMR18.png",r),
        Image("data/img/joueur/corps/joueurPPMR/joueurPPMR19.png",r),
      };

      Image i_joueurcorpsK[20] = 
      {
        Image("data/img/joueur/corps/joueurK/joueurK0.png",r),
        Image("data/img/joueur/corps/joueurK/joueurK1.png",r),
        Image("data/img/joueur/corps/joueurK/joueurK2.png",r),
        Image("data/img/joueur/corps/joueurK/joueurK3.png",r),
        Image("data/img/joueur/corps/joueurK/joueurK4.png",r),
        Image("data/img/joueur/corps/joueurK/joueurK5.png",r),
        Image("data/img/joueur/corps/joueurK/joueurK6.png",r),
        Image("data/img/joueur/corps/joueurK/joueurK7.png",r),
        Image("data/img/joueur/corps/joueurK/joueurK8.png",r),
        Image("data/img/joueur/corps/joueurK/joueurK9.png",r),
        Image("data/img/joueur/corps/joueurK/joueurK10.png",r),
        Image("data/img/joueur/corps/joueurK/joueurK11.png",r),
        Image("data/img/joueur/corps/joueurK/joueurK12.png",r),
        Image("data/img/joueur/corps/joueurK/joueurK13.png",r),
        Image("data/img/joueur/corps/joueurK/joueurK14.png",r),
        Image("data/img/joueur/corps/joueurK/joueurK15.png",r),
        Image("data/img/joueur/corps/joueurK/joueurK16.png",r),
        Image("data/img/joueur/corps/joueurK/joueurK17.png",r),
        Image("data/img/joueur/corps/joueurK/joueurK18.png",r),
        Image("data/img/joueur/corps/joueurK/joueurK19.png",r),
      };

	int Xwin, Ywin;
	SDL_GetWindowSize(w,&Xwin,&Ywin);

	jeu.initialisation(Xwin,Ywin);
	jeu.setEtat(ETAT_MENU);

	float timerzombie = 0.0;
	int animzombies = 0;
  	int animJoueur =0;
  	SDL_Rect * rect_joueur = new SDL_Rect;

	// TERRAIN
	Image terrain("data/img/terrain.png",r);
	SDL_Rect * rterrain = new SDL_Rect;
  	rterrain->x = 0;
	rterrain->y = 0;
	rterrain->w = Xwin;
	rterrain->h = Ywin;
	
  	// Ecran MENU
  	Image menubg("data/img/hud/rouge.png",r);
  	SDL_Rect * rmenubg = new SDL_Rect;
  	rmenubg->x = 50;
	rmenubg->y = 50;
	rmenubg->w = 700;
	rmenubg->h = 700;

  	Texte menu1("data/police.ttf","ZOMBIES AT", r);
  	menu1.setCouleur(0,0,0);
  	SDL_Rect * rmenu1 = new SDL_Rect;
  	rmenu1->x = 360;
	rmenu1->y = 100;
	rmenu1->w = 340;
	rmenu1->h = 80;

  	Texte menu2("data/police.ttf","NAUTIBUS", r);
  	menu2.setCouleur(0,0,0);
  	SDL_Rect * rmenu2 = new SDL_Rect;
  	rmenu2->x = 100;
	rmenu2->y = 150;
	rmenu2->w = 600;
	rmenu2->h = 180;

	Bouton menu_boutonjouer(Vec2(250,350),Vec2(550,450),"data/img/hud/blanc.png","data/img/hud/rouge.png",r);
	Bouton menu_boutonquitter(Vec2(250,550),Vec2(550,650),"data/img/hud/blanc.png","data/img/hud/rouge.png",r);

	Texte menu_jouer("data/police.ttf","JOUER", r);
  	menu_jouer.setCouleur(0,0,0);
  	SDL_Rect * rmenu_jouer = new SDL_Rect;
  	rmenu_jouer->x = 300;
	rmenu_jouer->y = 350;
	rmenu_jouer->w = 200;
	rmenu_jouer->h = 100;

	Texte menu_quitter("data/police.ttf","QUITTER", r);
  	menu_quitter.setCouleur(0,0,0);
  	SDL_Rect * rmenu_quitter = new SDL_Rect;
  	rmenu_quitter->x = 300;
	rmenu_quitter->y = 550;
	rmenu_quitter->w = 200;
	rmenu_quitter->h = 100;
	//
	
	// Ecran PAUSE
  	Image pausebg("data/img/hud/rouge.png",r);
  	SDL_Rect * rpausebg = new SDL_Rect;
  	rpausebg->x = 50;
	rpausebg->y = 50;
	rpausebg->w = 700;
	rpausebg->h = 700;

  	Texte pause("data/police.ttf","pause", r);
  	pause.setCouleur(0,0,0);
  	SDL_Rect * rpause = new SDL_Rect;
  	rpause->x = 150;
	rpause->y = 80;
	rpause->w = 500;
	rpause->h = 180;

	Bouton pause_boutonreprendre(Vec2(250,300),Vec2(550,400),"data/img/hud/blanc.png","data/img/hud/rouge.png",r);
	Bouton pause_boutonquitter(Vec2(250,450),Vec2(550,550),"data/img/hud/blanc.png","data/img/hud/rouge.png",r);

	Texte pause_reprendre("data/police.ttf","REPRENDRE", r);
  	pause_reprendre.setCouleur(0,0,0);
  	SDL_Rect * rpause_reprendre = new SDL_Rect;
  	rpause_reprendre->x = 300;
	rpause_reprendre->y = 300;
	rpause_reprendre->w = 200;
	rpause_reprendre->h = 100;

	Texte pause_quitter("data/police.ttf","QUITTER", r);
  	pause_quitter.setCouleur(0,0,0);
  	SDL_Rect * rpause_quitter = new SDL_Rect;
  	rpause_quitter->x = 300;
	rpause_quitter->y = 450;
	rpause_quitter->w = 200;
	rpause_quitter->h = 100;
	//

  	// Ecran GAMEOVER
  	Texte gameover("data/police.ttf","GAME OVER", r);
  	gameover.setCouleur(255,0,0);
  	SDL_Rect * rgameover = new SDL_Rect;
  	rgameover->x = 100;
	rgameover->y = 100;
	rgameover->w = 600;
	rgameover->h = 180;

	Texte gameover_manche("data/police.ttf","Manche : " + to_string(jeu.getManche()), r);
  	gameover_manche.setCouleur(255,0,0);
  	SDL_Rect * rgameover_manche = new SDL_Rect;
  	rgameover_manche->x = 300;
	rgameover_manche->y = 280;
	rgameover_manche->w = 200;
	rgameover_manche->h = 80;

	Texte gameover_score("data/police.ttf","Score : " + to_string(jeu.getScore()), r);
  	gameover_score.setCouleur(255,0,0);
  	SDL_Rect * rgameover_score = new SDL_Rect;
  	rgameover_score->x = 250;
	rgameover_score->y = 380;
	rgameover_score->w = 300;
	rgameover_score->h = 80;

	Texte gameover_tues("data/police.ttf","Zombies tues : " + to_string(jeu.getZombiesTues()), r);
  	gameover_tues.setCouleur(255,0,0);
  	SDL_Rect * rgameover_tues = new SDL_Rect;
  	rgameover_tues->x = 200;
	rgameover_tues->y = 480;
	rgameover_tues->w = 400;
	rgameover_tues->h = 80;

	Bouton gameover_boutonmenu(Vec2(120,660),Vec2(350,740),"data/img/hud/rouge.png","data/img/hud/blanc.png",r);
	Bouton gameover_boutonretry(Vec2(450,660),Vec2(680,740),"data/img/hud/rouge.png","data/img/hud/blanc.png",r);

	Texte gameover_menu("data/police.ttf","Menu", r);
  	gameover_menu.setCouleur(0,0,0);
  	SDL_Rect * rgameover_menu = new SDL_Rect;
  	rgameover_menu->x = 160;
	rgameover_menu->y = 675;
	rgameover_menu->w = 140;
	rgameover_menu->h = 50;

	Texte gameover_retry("data/police.ttf","Reessayer", r);
  	gameover_retry.setCouleur(0,0,0);
  	SDL_Rect * rgameover_retry = new SDL_Rect;
  	rgameover_retry->x = 465;
	rgameover_retry->y = 675;
	rgameover_retry->w = 200;
	rgameover_retry->h = 50;
  	//
  	
  	// Musiques
  	//Musique mmenu("data/ogg/menu.ogg");
  	//Musique mgameover("data/ogg/gameover.ogg");
  	//Musique mjeu;
  	int changement_etat = 0;
  	
  	/*string s_mjeu[10] = 
  	{
  		"data/ogg/musique0.ogg",
  		"data/ogg/musique1.ogg",
  		"data/ogg/musique2.ogg",
  		"data/ogg/musique3.ogg",
  		"data/ogg/musique4.ogg",
  		"data/ogg/musique5.ogg",
  		"data/ogg/musique6.ogg",
  		"data/ogg/musique7.ogg",
  		"data/ogg/musique8.ogg",
  		"data/ogg/musique9.ogg"
  	};*/

  	//mjeu.charger(s_mjeu[rand() % 10]);
	//mmenu.jouer();

	// Effet sonores
  	Son shoot(s_armes[0]);
  	Son reload(s_armes[0+8]);

    rect_joueur->w = jeu.getJoueur().getCollision().getRayon()*2;
    rect_joueur->h = jeu.getJoueur().getCollision().getRayon()*2;

	// HUD en JEU
	Texte munc("data/police.ttf","0", r);
	Texte mun("data/police.ttf","0", r);
	Texte hp("data/police.ttf","0", r);
  	Texte manche("data/police.ttf","0", r);
  	Texte score("data/police.ttf","0", r);
  	
  	munc.setCouleur(35,35,120);
	mun.setCouleur(60,60,160);
	hp.setCouleur(0,255,0);
  	manche.setCouleur(255,0,0);
  	score.setCouleur(255,255,0);
  	
	int id_currentarme = 0;
	SDL_Rect* r_currentarme = new SDL_Rect;
	r_currentarme->x = 20;
	r_currentarme->y = 60;
	r_currentarme->w = 80;
	r_currentarme->h = 80;
	
	Image i_sante("data/img/hud/croixsante.png",r);
	SDL_Rect* r_sante = new SDL_Rect;
	r_sante->x = 20;
	r_sante->y = 20;
	r_sante->w = 40;
	r_sante->h = 40;

	SDL_Rect * rmun = new SDL_Rect;
	rmun->x = 110;
	rmun->y = 75;
	rmun->w = 45;
	rmun->h = 50;

	SDL_Rect * rmunc = new SDL_Rect;
	rmunc->x = 170;
	rmunc->y = 75;
	rmunc->w = 35;
	rmunc->h = 50;

	SDL_Rect * rhp = new SDL_Rect;
	rhp->x = 70;
	rhp->y = 15;
	rhp->w = 35;
	rhp->h = 50;

  	SDL_Rect * rmanche = new SDL_Rect;
	rmanche->x = 600;
	rmanche->y = 15;
	rmanche->w = 150;
	rmanche->h = 50;

	SDL_Rect * rscore = new SDL_Rect;
	rscore->x = 550;
	rscore->y = 65;
	rscore->w = 200;
	rscore->h = 50;

	mun.setTexte(to_string(jeu.getJoueur().getArme().getMunition()));
	munc.setTexte(to_string(jeu.getJoueur().getArme().getMunitionChargeur()));
	hp.setTexte("Vie : " + to_string(jeu.getJoueur().getHp()));

	dernier_tir = temps();
  	rechargement = temps();
  	
  	Image flash("data/img/joueur/flash.png",r);
  	Vec2 posflash(0.0,0.0);
  	float rotflash = 0.0;
  	SDL_Rect * rflash = new SDL_Rect;
	rflash->w = 40;
	rflash->h = 40;

	jeu.nouvelleManche();
  	manche.setTexte("Manche : " + to_string(jeu.getManche()));
  	score.setTexte("Score : " + to_string(jeu.getScore()));

	while(!m_input.terminer())
	{

    	debut_boucle = SDL_GetTicks();

    	if(temps() - timerzombie > 1)
    	{
      		if((jeu.getZombies().size() == 0) && (jeu.getnbZombies() == 0))
      		{
        		jeu.nouvelleManche();
            	manche.setTexte("Manche : " + to_string(jeu.getManche()));
      		}
      		else if (jeu.getnbZombies() > 0)
      		{
        		jeu.ajoutZombies(rand());
      		}

      		timerzombie = temps();
      }

		jeu.inertieJoueur();

		int id_a = jeu.recupererObjet();
		if(id_a >= 0 && id_a <= 7)
		{
			id_currentarme = id_a;
			shoot.charger(s_armes[id_a]);
			reload.charger(s_armes[id_a+8]);
		}

		// Gestion des évènements
		m_input.updateEvenements();
		jeu.setCurseur(Vec2(m_input.getX(),m_input.getY()));
		if(m_input.getTouche(SDL_SCANCODE_ESCAPE))
		{
		 break;
		}

		SDL_RenderPresent(r);

		SDL_SetRenderDrawColor(r, 100, 150, 150, 255);
		SDL_RenderClear(r);

		terrain.afficher(rterrain);

		if(m_input.getTouche(SDL_SCANCODE_W))
		{
			jeu.haut();
		}
		if(m_input.getTouche(SDL_SCANCODE_S))
		{
			jeu.bas();
		}
		if(m_input.getTouche(SDL_SCANCODE_A))
		{
			jeu.gauche();
		}
		if(m_input.getTouche(SDL_SCANCODE_D))
		{
			jeu.droite();
		}
		if(m_input.getTouche(SDL_SCANCODE_R))
		{
			if(jeu.getJoueur().getArme().getTempsRechargement() <= temps() - rechargement)
			{
				if(jeu.getJoueur().getArme().getMunition() != 0)
				{
					jeu.recharger();
		    		rechargement = temps();
		    		reload.jouer();
				}
		  	}
		}
		if(m_input.getTouche(SDL_SCANCODE_P))
		{
			if(!touchepause)
			{
				touchepause = true;
				jeu.pause();
			}
		}
		if(!m_input.getTouche(SDL_SCANCODE_P))
		{
			if(touchepause)
			{
				touchepause = false;
			}
		}
		if(m_input.getBoutonSouris(SDL_BUTTON_LEFT))
		{
      		if(jeu.getEtat() == ETAT_JEU)
      		{
		  		if(jeu.getJoueur().getArme().getVitesse() <= temps() - dernier_tir && jeu.getJoueur().getArme().getTempsRechargement()  <= temps() - rechargement)
		 		{
		    		if(jeu.tire(rand()))
		    		{
		          		shoot.jouer();
		      			dernier_tir = temps();
		      			
		      			rotflash = rot;
		      			
		      			Vec2 vecexp;
		      			Vec2 vecexp2;
		      			vecexp.setExp(rotflash,42.0);
		      			vecexp2.setExp(rotflash + M_PI/2.0,10.0);
		      			
		      			posflash = jeu.getJoueur().getPosition() - Vec2(jeu.getJoueur().getCollision().getRayon() - 6,jeu.getJoueur().getCollision().getRayon() - 3) + vecexp + vecexp2;
		      			
						rflash->x = posflash.getX();
						rflash->y = posflash.getY();
		        	}
				    else
				    {
				      	if(jeu.getJoueur().getArme().getMunition() != 0)
				      	{
				      		jeu.recharger();
				      		rechargement = temps();
				      		reload.jouer();
				      	}
				    }
		  		}
      		}
      		else if(jeu.getEtat() == ETAT_MENU)
      		{
      			if(menu_boutonjouer.estFocus(jeu.getCurseur()))
      			{		
      				id_currentarme = 0;
      				shoot.charger(s_armes[0]);
      				reload.charger(s_armes[8]);
      				jeu.initialisation(Xwin,Ywin);
      				jeu.setEtat(ETAT_JEU);
      			}

      			if(menu_boutonquitter.estFocus(jeu.getCurseur()))
      			{
      				break;
      			}
      		}
      		else if(jeu.getEtat() == ETAT_PAUSE)
      		{
      			if(pause_boutonreprendre.estFocus(jeu.getCurseur()))
      			{		
      				jeu.pause();
      			}

      			if(pause_boutonquitter.estFocus(jeu.getCurseur()))
      			{
      				jeu.setEtat(ETAT_MENU);
      			}
      		}
      		else if(jeu.getEtat() == ETAT_GAMEOVER)
      		{	
      			if(gameover_boutonmenu.estFocus(jeu.getCurseur()))
      			{
      				jeu.setEtat(ETAT_MENU);
      			}

      			if(gameover_boutonretry.estFocus(jeu.getCurseur()))
      			{
      				id_currentarme = 0;
      				shoot.charger(s_armes[0]);
      				reload.charger(s_armes[8]);
      				jeu.initialisation(Xwin,Ywin);
      				jeu.setEtat(ETAT_JEU);
      			}
      		}
		}

    	mun.setTexte(to_string(jeu.getJoueur().getArme().getMunition()));
    	munc.setTexte(to_string(jeu.getJoueur().getArme().getMunitionChargeur()));
		jeu.deplacementJoueur();

		fin_boucle = SDL_GetTicks();
		temps_ecoule = fin_boucle - debut_boucle;

		if(temps_ecoule < frame_rate)
		{
			SDL_Delay(frame_rate - temps_ecoule);
		}

		jeu.deplacementZombies();

		// Affichage
		if(temps() - dernier_tir <= 0.08)
        {
        	flash.afficherExp(rflash,rotflash*180/M_PI);
        }
        
		Vec2 posj = jeu.getJoueur().getPosition();

		rect_joueur->x = posj.getX() - jeu.getJoueur().getCollision().getRayon();
        rect_joueur->y = posj.getY() - jeu.getJoueur().getCollision().getRayon();

		if(jeu.getEtat() == ETAT_JEU)
		{
			rot = (jeu.getCurseur() - (jeu.getJoueur().getPosition() + Vec2(jeu.getJoueur().getCollision().getRayon()/2, jeu.getJoueur().getCollision().getRayon()/2))).arg();
		}

        for(unsigned int i = 0; i < jeu.getZombies().size(); i++)
        {
        	SDL_Rect * rz = new SDL_Rect;

			//affichage zombie
        	rz->x = jeu.getZombie(i)->getPosition().getX() - jeu.getZombie(i)->getCollision().getRayon();
          	rz->y = jeu.getZombie(i)->getPosition().getY() - jeu.getZombie(i)->getCollision().getRayon();
          	rz->w = jeu.getZombie(i)->getCollision().getRayon()*2;
          	rz->h = jeu.getZombie(i)->getCollision().getRayon()*2;

            if(jeu.getEtat() == ETAT_JEU)
            {
            	animzombies = (int)(temps()*15.0)%17;
            }

            float rotz = (jeu.getJoueur().getPosition() - jeu.getZombie(i)->getPosition()).arg();
            i_zombie[animzombies].afficherExp(rz,rotz*180.0/M_PI);

            delete rz;
        }

        if(jeu.getEtat() == ETAT_JEU)
        {
          animzombies = (int)(temps()*15.0)%17;
          animJoueur = (int)(temps()*15.0)%20;
        }

        string arme = jeu.getJoueur().getArme().getNom();

        /*Pistolet 15 120 12 2.0 0.4
		Revolver 60 60 6 5.0 0.8
		Pistolet-Mitrailleur 8 240 20 1.4 0.05
		Mitraillette 20 180 30 2.0 0.1
		Kalachnikov 25 160 30 2.5 0.125
		Carabine 35 120 30 2.8 0.2
		Mitrailleuse 12 200 100 5.5 0.08
		Sniper 120 50 5 5.0 3.0*/


        if( (arme == "Carabine") || (arme == "Mitraillette") || (arme == "Mitrailleuse") || (arme == "Sniper") ) 
        {
        	i_joueurCMMS[animJoueur].afficherExp(rect_joueur,rot*180.0/M_PI);
        }
        else if ( (arme == "Pistolet") ||(arme ==  "Pistolet-Mitrailleur") || (arme == "Revolver") )
        {
        	i_joueurcorpsPPMR[animJoueur].afficherExp(rect_joueur,rot*180.0/M_PI);
        }
        else /*if  (arme == "Kalachnikov") */
        {
        	i_joueurcorpsK[animJoueur].afficherExp(rect_joueur,rot*180.0/M_PI);
        }
		
        for(unsigned int i = 0; i < jeu.getZombies().size(); i++)
        {
        	//affichage vie du zombie
        	SDL_Rect * r_vie_rouge = new SDL_Rect;
			SDL_Rect * r_vie_vert = new SDL_Rect;

			r_vie_rouge->x = jeu.getZombie(i)->getPosition().getX() - jeu.getZombie(i)->getCollision().getRayon();
			r_vie_rouge->y = jeu.getZombie(i)->getPosition().getY() - jeu.getZombie(i)->getCollision().getRayon() - 10;
			r_vie_rouge->w = jeu.getZombie(i)->getCollision().getRayon()*2;
			r_vie_rouge->h = 4;

			r_vie_vert->x = r_vie_rouge->x;
			r_vie_vert->y = r_vie_rouge->y;
			r_vie_vert->w = ((float)jeu.getZombie(i)->getHp() / (float)jeu.getHpZombies())*(float)r_vie_rouge->w;

			r_vie_vert->h = r_vie_rouge->h;

			i_vie[1].afficher(r_vie_rouge);
			i_vie[0].afficher(r_vie_vert);


			delete r_vie_rouge;
			delete r_vie_vert;
        }


        for(unsigned int i = 0; i < jeu.getObjets().size(); i++)
        {
        	SDL_Rect * ro = new SDL_Rect;

        	ro->x = jeu.getObjets()[i].getPosition().getX() - jeu.getObjets()[i].getRayon();
          	ro->y = jeu.getObjets()[i].getPosition().getY() - jeu.getObjets()[i].getRayon();
          	ro->w = jeu.getObjets()[i].getRayon()*2;
          	ro->h = jeu.getObjets()[i].getRayon()*2;
          	i_objet[jeu.getObjets()[i].getId()].afficherExp(ro,0.0);

        	delete ro;
        }

        if(jeu.getEtat() == ETAT_MENU)
		{
			menubg.afficher(rmenubg);
			menu1.afficher(rmenu1);
			menu2.afficher(rmenu2);

			menu_boutonjouer.afficher(jeu.getCurseur());
			menu_boutonquitter.afficher(jeu.getCurseur());

			menu_jouer.afficher(rmenu_jouer);
			menu_quitter.afficher(rmenu_quitter);
		}
		
		if(jeu.getEtat() == ETAT_JEU)
		{
			i_objet[id_currentarme].afficher(r_currentarme);
			i_sante.afficher(r_sante);
			hp.setTexte(to_string(jeu.getJoueur().getHp()));
			hp.afficher(rhp);
			
			score.setTexte("Score : " + to_string(jeu.getScore()));
			score.afficher(rscore);
			
			mun.setTexte(to_string(jeu.getJoueur().getArme().getMunition()));
    		munc.setTexte(to_string(jeu.getJoueur().getArme().getMunitionChargeur()));
        	mun.afficher(rmun);
        	munc.afficher(rmunc);
        	
        	manche.afficher(rmanche);
		}
		
		if(jeu.getEtat() == ETAT_PAUSE)
		{
			pausebg.afficher(rpausebg);
			pause.afficher(rpause);

			pause_boutonreprendre.afficher(jeu.getCurseur());
			pause_boutonquitter.afficher(jeu.getCurseur());

			pause_reprendre.afficher(rpause_reprendre);
			pause_quitter.afficher(rpause_quitter);
		}

        if(jeu.getEtat() == ETAT_GAMEOVER)
		{
			gameover.afficher(rgameover);
			gameover_manche.setTexte("Manche : " + to_string(jeu.getManche()));
			gameover_manche.afficher(rgameover_manche);
			gameover_score.setTexte("Score : " + to_string(jeu.getScore()));
			gameover_score.afficher(rgameover_score);
			gameover_tues.setTexte("Zombies tues : " + to_string(jeu.getZombiesTues()));
			gameover_tues.afficher(rgameover_tues);

			gameover_boutonmenu.afficher(jeu.getCurseur());
			gameover_boutonretry.afficher(jeu.getCurseur());
			gameover_menu.afficher(rgameover_menu);
			gameover_retry.afficher(rgameover_retry);
		}
		
		// Gestion Musique
		if(jeu.getEtat() == ETAT_JEU)
		{
			if(jeu.getEtat() != changement_etat)
			{
				if(changement_etat == ETAT_MENU)
				{
					//mmenu.pause();
					//mjeu.jouer();

				}
				else if(changement_etat == ETAT_GAMEOVER)
				{
					//mgameover.pause();
					//mjeu.jouer();
				}
			}
		}
		else if(jeu.getEtat() == ETAT_MENU)
		{
			if(changement_etat == ETAT_GAMEOVER)
			{
				//mgameover.pause();
				//mmenu.jouer();
			}
			else if(changement_etat == ETAT_JEU || changement_etat == ETAT_PAUSE)
			{
				//mjeu.pause();
				//mjeu.charger(s_mjeu[rand() % 10]);
				//mmenu.jouer();
			}
		}
		else if(jeu.getEtat() == ETAT_GAMEOVER)
		{
			if(jeu.getEtat() != changement_etat)
			{
				//mjeu.pause();
				//mjeu.charger(s_mjeu[rand() % 10]);
				//mgameover.jouer();
			}
		}
		
		changement_etat = jeu.getEtat();
	}

	delete rterrain;

	delete rmun;
	delete rmunc;
	delete rhp;
  	delete rmanche;
  	delete rscore;
  	delete rect_joueur;
  	delete rflash;
  	
  	delete rgameover;
  	delete rgameover_manche;
  	delete rgameover_score;
  	delete rgameover_tues;
  	delete rgameover_menu;
  	delete rgameover_retry;
  	
  	delete rmenubg;
  	delete rmenu1;
  	delete rmenu2;
  	delete rmenu_jouer;
  	delete rmenu_quitter;
  	
  	delete rpause;
  	delete rpausebg;
  	delete rpause_reprendre;
  	delete rpause_quitter;

	Mix_Quit();
	SDL_DestroyRenderer(r);
    SDL_DestroyWindow(w);
    SDL_Quit();

}
