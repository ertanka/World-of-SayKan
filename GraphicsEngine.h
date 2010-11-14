#ifndef GRAPHICS_ENGINE
#define GRAPHICS_ENGINE
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "EventListener.h"
#include <iostream>
#include <string>

using namespace std;

class GraphicsEngine{
	private:
	    int screenWidth,screenHeight,screenBPP;
   		SDL_Event event;
	    MouseListener *mouseListener;
	    KeyboardListener *keyboardListener;
	    SDL_Surface *screen;
		SDL_Surface * loadImage(string);
		KeyboardEvent* defineKey(SDL_Event*);
    	void addSurface(int,int,SDL_Surface*,SDL_Surface*);
    	void addSurface(int,int,SDL_Surface*,SDL_Surface*,SDL_Rect*);
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
		int addImage(string);
		void setMouseListener(MouseListener *);
		void setKeyboardListener(KeyboardListener *);
		void checkEvents();
};

#endif                                                
