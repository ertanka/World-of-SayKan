#ifndef GRAPHICS_ENGINE
#define GRAPHICS_ENGINE
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>
#include <string>

using namespace std;

class GraphicsEngine{
	private:
	    int screenWidth,screenHeight,screenBPP;
	    SDL_Surface *screen;
		SDL_Surface * loadImage(string);
    	void addSurface(int,int,SDL_Surface*,SDL_Surface*);
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
};

#endif                                                
