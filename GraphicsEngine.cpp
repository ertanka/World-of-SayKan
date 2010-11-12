#include "GraphicsEngine.h"

GraphicsEngine::GraphicsEngine(int width,int height, int bpp){
       	SDL_Init(SDL_INIT_EVERYTHING);
       	screenWidth=width;
       	screenHeight=height;
       	screenBPP=bpp;
       	createScreen();
	}
void GraphicsEngine::createScreen(){
	screen=SDL_SetVideoMode(screenWidth,screenHeight,screenBPP,SDL_SWSURFACE);
}
void GraphicsEngine::killSDL(){
    SDL_FreeSurface(screen);
	SDL_Quit();
}
void GraphicsEngine::setTitle(string title){
	SDL_WM_SetCaption(title.c_str(),NULL);
}
void GraphicsEngine::delayScreen(int time){
	SDL_Delay(time);
}
bool GraphicsEngine::refreshScreen(){
	return SDL_Flip(screen)!= -1;
}
bool GraphicsEngine::setBackground(string filename){

}

