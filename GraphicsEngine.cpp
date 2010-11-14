#include "GraphicsEngine.h"

GraphicsEngine::GraphicsEngine(int width,int height, int bpp){
       	SDL_Init(SDL_INIT_EVERYTHING);
       	screenWidth=width;
       	screenHeight=height;
       	screenBPP=bpp;
       	createScreen();
       	mouseListener=NULL;
       	keyboardListener=NULL;
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
void GraphicsEngine::setMouseListener(MouseListener * mListen){
	mouseListener=mListen;
}
void GraphicsEngine::setKeyboardListener(KeyboardListener *kListen){
	keyboardListener=kListen;
}
KeyboardEvent* GraphicsEngine::defineKey(SDL_Event* ev){
 	switch(ev->key.keysym.sym){
    	case SDLK_LEFT:
    		return new KeyboardEvent(KeyboardEvent::LEFT);
    		break;
    	case SDLK_RIGHT:
    		return new KeyboardEvent(KeyboardEvent::RIGHT);
    		break;
    	case SDLK_UP:
			return new KeyboardEvent(KeyboardEvent::UP);
    		break;
    	case SDLK_DOWN:
    		return new KeyboardEvent(KeyboardEvent::DOWN);
    		break;
    	case SDLK_0:
    		return new KeyboardEvent(KeyboardEvent::NUM0);
    		break;
    	case SDLK_1:
    		return new KeyboardEvent(KeyboardEvent::NUM1);
    		break;
    	case SDLK_2:
    		return new KeyboardEvent(KeyboardEvent::NUM2);
    		break;
    	case SDLK_3:
    		return new KeyboardEvent(KeyboardEvent::NUM3);
    		break;
    	case SDLK_4:
    		return new KeyboardEvent(KeyboardEvent::NUM4);
    		break;
    	case SDLK_5:
    		return new KeyboardEvent(KeyboardEvent::NUM5);
    		break;
    	case SDLK_6:
    		return new KeyboardEvent(KeyboardEvent::NUM6);
    		break;
    	case SDLK_7:
    		return new KeyboardEvent(KeyboardEvent::NUM7);
    		break;
    	case SDLK_8:
    		return new KeyboardEvent(KeyboardEvent::NUM8);
    		break;
    	case SDLK_9:
    		return new KeyboardEvent(KeyboardEvent::NUM9);
    		break;
    	case SDLK_ASTERISK:
    		return new KeyboardEvent(KeyboardEvent::LSTAR);
    		break;
    	case SDLK_MINUS:
    		return new KeyboardEvent(KeyboardEvent::LMINUS);
    		break;
    	default:
    		return new KeyboardEvent();
	}
}
void GraphicsEngine::checkEvents(){
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_KEYDOWN){
			if(keyboardListener==NULL)
				return;
			keyboardListener->keyPressed(defineKey(&event));
		}
		if(event.type == SDL_KEYUP){
			cout<<"Key Released!\n";
			if(keyboardListener== NULL)
				return;
			keyboardListener->keyReleased(defineKey(&event));
		}
		if(event.type == SDL_QUIT){
			cout<<"Quit Event Catched! Killing SDL\n";
			killSDL();
			exit(0);
		}
	}
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
	addSurface(x,y,source,destination,NULL);
}
void GraphicsEngine::addSurface(int x, int y,SDL_Surface * source, SDL_Surface * destination,SDL_Rect * part){

 	SDL_Rect offset;
 	offset.x=x;
 	offset.y=y;
 	SDL_BlitSurface(source,part,destination,&offset);
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
