#include "GraphicsEngine.h"

GraphicsEngine::GraphicsEngine(int width,int height, int bpp){
       	SDL_Init(SDL_INIT_EVERYTHING);
       	screenWidth=width;
       	screenHeight=height;
       	screenBPP=bpp;
       	createScreen();
	}
GraphicsEngine::~GraphicsEngine(){
	killSDL();
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
	SDL_Surface * backgroundImage= loadImage(filename);
	if(backgroundImage==NULL)
		return false;
    addSurface( 0,0,backgroundImage,screen);
    return true;
}
void GraphicsEngine::addSurface(int x, int y, SDL_Surface * source, SDL_Surface * destination){
 	SDL_Rect offset;
 	offset.x=x;
 	offset.y=y;
 	SDL_BlitSurface(source,NULL,destination,&offset);
}
SDL_Surface * GraphicsEngine::loadImage(string filename){
	SDL_Surface * temp=NULL;
	SDL_Surface * opt=NULL;
	temp=IMG_Load(filename.c_str());
	if(temp!=NULL){
		opt=SDL_DisplayFormat(temp);
		SDL_FreeSurface(temp);
	}
	return opt;
}
