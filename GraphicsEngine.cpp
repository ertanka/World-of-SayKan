#include "GraphicsEngine.h"

GraphicsEngine::GraphicsEngine(int width,int height, int bpp){
       	SDL_Init(SDL_INIT_EVERYTHING);
       	background=NULL;
        smallBG=false;
        sideRect=NULL;
        downRect=NULL;
        //avoid divide by 0 
        updateTime=1;
        eventTime=1;
        refreshTime=1;
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
    if(background!=NULL) SDL_FreeSurface(background);
    if(sideRect!=NULL) delete sideRect;
    if(downRect!=NULL) delete downRect;
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
	uint start=SDL_GetTicks();
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_KEYDOWN){
			if(keyboardListener==NULL)
				return;
			keyboardListener->keyPressed(defineKey(&event));
		}
		if(event.type == SDL_KEYUP){
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
    eventTime=SDL_GetTicks()-start;
}
void GraphicsEngine::updateGame(){
	uint start=SDL_GetTicks();
	updateTime=SDL_GetTicks()-start;
	return;
}
void GraphicsEngine::setTitle(string title){
	SDL_WM_SetCaption(title.c_str(),NULL);
}
void GraphicsEngine::delayScreen(int time){
	SDL_Delay(time);
}
bool GraphicsEngine::refreshScreen(){
	uint start=SDL_GetTicks();
	cout<<start<<"--";
	addSurface(0,0,background,screen);
	drawGameObjects();
	if(smallBG){
		//Fill rectangles with black; 0x000000
    	SDL_FillRect(screen,sideRect,0x000000);
    	SDL_FillRect(screen,downRect,0x000000);
	}
	refreshTime=SDL_GetTicks()-start;
	cout<<SDL_GetTicks()<<endl;
	return SDL_Flip(screen)!= -1;
}
bool GraphicsEngine::setBackground(string filename){
	int sideSpace,downSpace;
	background= loadImage(filename);
	if(background==NULL)
		return false;

	//If background is smaller than the screen then set new SDL_Rects to fill
	//remaining parts of screen
    if(screenWidth>background->w){
    	sideSpace=screenWidth-background->w;
    	sideRect=new SDL_Rect();
    	sideRect->x=background->w;
    	sideRect->y=0;
    	sideRect->w=sideSpace;
    	sideRect->h=background->h;
    	smallBG=true;
	}
    if(screenHeight>background->h){
    	downSpace=screenHeight-background->h;
    	downRect=new SDL_Rect();
    	downRect->x=0;
    	downRect->y=background->h;
    	downRect->w=screenWidth;
    	downRect->h=downSpace;
    	smallBG=true;
	}
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
void GraphicsEngine::drawGameObjects(){
	for(int i=0;i<screenObjects.size();i++){
    	GameObject* temp=screenObjects[i];
    	addSurface(temp->getCords()->getX(),temp->getCords()->getY(),objectSurfaces[i],screen); 	
	}
}
int GraphicsEngine::addGameObject(GameObject * obj){
	screenObjects.push_back(obj);
    objectSurfaces.push_back(loadImage(obj->getImage()->getFilename()));
	return screenObjects.size()-1;
}
void GraphicsEngine::removeGameObject(int id){
	if(id>=screenObjects.size())
		return;
	screenObjects.erase(screenObjects.begin()+id);
	objectSurfaces.erase(objectSurfaces.begin()+id);
}
void GraphicsEngine::removeGameObject(GameObject* obj){
	for(int i=0;i<screenObjects.size();i++){
		if(screenObjects[i]==obj){
			screenObjects.erase(screenObjects.begin()+i);
			objectSurfaces.erase(objectSurfaces.begin()+i);
		}
	}
}
void GraphicsEngine::clearGameObjects(){
	objectSurfaces.clear();
	screenObjects.clear();
}

uint GraphicsEngine::getUpdateTime(){
	return updateTime;
}
uint GraphicsEngine::getEventTime(){
	return eventTime;                
}
uint GraphicsEngine::getRefreshTime(){
	return refreshTime;
}
/**
 * all 3 functions;
 * refreshScreen,checkEvents,updateGame
 * should have been called before getting the FPS
 * this result may be wrong otherwise..
 * use getUpdateTime,getEventTime and getRefreshTime if you wont
 * call all functions
 * !!Returns maximum fps possible.. not the actual FPS!!
 * TODO: real FPS may be? :)
 */
int GraphicsEngine::getFPS(){
	return 1000/((int)(refreshTime+eventTime+updateTime));
}
