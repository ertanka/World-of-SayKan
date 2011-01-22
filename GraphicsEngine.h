#ifndef GRAPHICS_ENGINE
#define GRAPHICS_ENGINE
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "EventListener.h"
#include "GameObject.h"
#include "Point.h"
#include "Image.h"
#include "AnimatingGameObject.h"
#include "TextObject.h"
#include "Color.h"
#include "Widget.h"
#include <iostream>
#include <string>
#include <vector>

/*
 * TODO: toolbox or some kind of button container may be useful
 * TODO: basic gui objects like buttons may be good
 */
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
	    vector<Widget*> widgets;

		Color textColor;
		TTF_Font *textFont;
		
    	void addSurface(int,int,SDL_Surface*,SDL_Surface*);
    	void addSurface(int,int,SDL_Surface*,SDL_Surface*,SDL_Rect*);
		bool drawGameObjects();
		void drawWidgets();
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
		void fixFPS(int); //TODO may try to fix FPS to the given value
		bool setTextFont(string,int);
		void setTextColor(int,int,int);
		int addText(string,int,int);
		int addWidget(Widget*);
		void removeWidget(Widget*);
		void removeWidget(int);
		void setClearBGRemainder(bool);

};

#endif                                                
