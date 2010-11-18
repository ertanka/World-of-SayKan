#ifndef GRAPHICS_ENGINE
#define GRAPHICS_ENGINE
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "EventListener.h"
#include "GameObject.h"
#include "Point.h"
#include "Image.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GraphicsEngine{
	private:
	    int screenWidth,screenHeight,screenBPP;
   		SDL_Event event;
	    MouseListener *mouseListener;
	    KeyboardListener *keyboardListener;
	    SDL_Surface *screen;
	    SDL_Surface *background;
	    
	    bool smallBG;
	    SDL_Rect* sideRect,*downRect;
    	
    	vector<GameObject*> screenObjects; 
		vector<SDL_Surface*> objectSurfaces;

		SDL_Surface * loadImage(string);
		KeyboardEvent* defineKey(SDL_Event*);
    	void addSurface(int,int,SDL_Surface*,SDL_Surface*);
    	void addSurface(int,int,SDL_Surface*,SDL_Surface*,SDL_Rect*);
		void drawGameObjects();
	public:
	    GraphicsEngine(int,int,int);
        ~GraphicsEngine();
		void createScreen();
		void killSDL();
		void delayScreen(int);
		bool updateScreen();
		void setTitle(string);
		bool setBackground(string);
		bool refreshScreen();
		void setMouseListener(MouseListener *);
		void setKeyboardListener(KeyboardListener *);
		void checkEvents();
		int addGameObject(GameObject*);
		void removeGameObject(int);
		void removeGameObject(GameObject*);
		void clearGameObjects();
};

#endif                                                
