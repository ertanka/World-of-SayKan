#include "GraphicsEngine.h"

GraphicsEngine::GraphicsEngine(int width,int height, int bpp){
       	SDL_Init(SDL_INIT_EVERYTHING);
       	TTF_Init();
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
       	//Default text color
       	textColor.r=0xFF;
       	textColor.g=0xFF;
       	textColor.b=0xFF;
       	textFont=NULL;
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
    TTF_Quit();
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
	addSurface(0,0,background,screen);
	(this->*funcToCall)();
	refreshTime=SDL_GetTicks()-start;
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
	if(smallBG)
		funcToCall=&GraphicsEngine::clearBGRemainder;
	else 
		funcToCall=&GraphicsEngine::drawGameObjects;
    return true;
}
bool GraphicsEngine::clearBGRemainder(){
	bool result=drawGameObjects();
	//Fill rectangles with black; 0x000000
	SDL_FillRect(screen,sideRect,0x000000);
	SDL_FillRect(screen,downRect,0x000000);
	return result;
}
void GraphicsEngine::setClearBGRemainder(bool flag){
	if(flag)
		funcToCall=&GraphicsEngine::clearBGRemainder;
	else 
		funcToCall=&GraphicsEngine::drawGameObjects;
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
void GraphicsEngine::setTextColor(int r,int g,int b){
	textColor.r=r;
	textColor.g=g;
	textColor.b=b;
}
void GraphicsEngine::setTextFont(string fontName,int size){
	textFont=TTF_OpenFont(fontName.c_str(),size);
	cout<<TTF_GetError()<<endl;
}
int GraphicsEngine::addText(string text,int x,int y){
    if(textFont==NULL){
    	return -1;
	}
    SDL_Surface *textSurface=TTF_RenderText_Solid(textFont,text.c_str(),textColor);
    if(textSurface==NULL){
    	return -1;
	}
	return addGameObject(new GameObject(text,x,y,true),textSurface);
}
bool GraphicsEngine::drawGameObjects(){
	if(screenObjects.size()==0)
		return false;
	for(int i=0;i<screenObjects.size();i++){
    	GameObject* temp=screenObjects[i];
    	if(temp->isText()){
    		cout<<"Here is a text"<<endl;
    		cout<<temp->getCords()->getX()<<endl;
		}
    	addSurface(temp->getCords()->getX(),temp->getCords()->getY(),objectSurfaces[i],screen); 	
	}
	return true;	
}
int GraphicsEngine::addGameObject(GameObject * obj,SDL_Surface* surface){
	screenObjects.push_back(obj);
    objectSurfaces.push_back(surface);
	return screenObjects.size()-1;
}
int GraphicsEngine::addGameObject(GameObject* obj){
	return addGameObject(obj,loadImage(obj->getImage()->getFilename()));
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
/**gameLoopStart and gameLoopEnd is to calculate time pass for
 * one loop..Only one frame should be processed in order to
 * use getFPS.. otherwise calling getFPS would return useless results..
 * using get**Time functions may be usefull for calculating fps otherwise
 */
void GraphicsEngine::gameLoopStart(){
	loopStartTime=SDL_GetTicks();
}
void GraphicsEngine::gameLoopEnd(){
	loopEndTime=SDL_GetTicks();
}
/**
 * gameLoopStart and gameLoopEnd
 * should have been called before getting the FPS
 * this result may be wrong otherwise..
 * use getUpdateTime,getEventTime and getRefreshTime if you wont
 * call all functions
 * !!Returns maximum fps possible.. not the actual FPS!!
 * TODO: real FPS may be? :)
 */
int GraphicsEngine::getFPS(){
	int totalTime=loopEndTime-loopStartTime;
if(totalTime==0)
		return -1;
	return 1000/totalTime;
}
