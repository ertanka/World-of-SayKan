#ifndef GRAPHICS_ENGINE
#define GRAPHICS_ENGINE
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "EventListener.h"
#include "GameObject.h"
#include "Point.h"
#include "Image.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GraphicsEngine{
typedef bool (GraphicsEngine::*cleaningFunc)();
	private:
	    int screenWidth,screenHeight,screenBPP;

	    uint updateTime,eventTime,refreshTime;
	    uint loopStartTime,loopEndTime;

   		SDL_Event event;
	    MouseListener *mouseListener;
	    KeyboardListener *keyboardListener;

	    SDL_Surface *screen;
	    SDL_Surface *background;
	    
	    bool smallBG;
	    SDL_Rect* sideRect,*downRect;	 
       	cleaningFunc funcToCall;

    	vector<GameObject*> screenObjects; 
		vector<SDL_Surface*> objectSurfaces;

		SDL_Color textColor;
		TTF_Font *textFont;
		
		SDL_Surface * loadImage(string);
		KeyboardEvent* defineKey(SDL_Event*);
    	void addSurface(int,int,SDL_Surface*,SDL_Surface*);
    	void addSurface(int,int,SDL_Surface*,SDL_Surface*,SDL_Rect*);
		bool drawGameObjects();
		int addGameObject(GameObject*,SDL_Surface*);
		bool clearBGRemainder();
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
		void checkEvents();
		void updateGame();
		void setMouseListener(MouseListener *);
		void setKeyboardListener(KeyboardListener *);
		int addGameObject(GameObject*);
		void removeGameObject(int);
		void removeGameObject(GameObject*);
		void clearGameObjects();
		uint getUpdateTime();
		uint getEventTime();
		uint getRefreshTime();
		void gameLoopStart();
		void gameLoopEnd();
		int getFPS();
		void setTextFont(string,int);
		void setTextColor(int,int,int);
		int addText(string,int,int);
		void setClearBGRemainder(bool);
};

#endif                                                
