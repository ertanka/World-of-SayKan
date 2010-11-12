#ifndef GRAPHICS_ENGINE
#define GRAPHICS_ENGINE
#include "SDL/SDL.h"
#include <iostream>
#include <string>

using namespace std;

class GraphicsEngine{
	private:
	    int screenWidth,screenHeight,screenBPP;
	    SDL_Surface *screen;
	public:
	    GraphicsEngine(int,int,int);
	    void createScreen();
		void killSDL();
		void delayScreen(int);
		bool updateScreen();
		void setTitle(string);
		bool setBackground(string);
		bool refreshScreen();
};

#endif                                                
