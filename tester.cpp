#include "GraphicsEngine.h"


int main(int argc, char* args[]){

	GraphicsEngine *engine=new GraphicsEngine(640,480,32);
	engine->delayScreen(2000);
	engine->setTitle("deneme");
    engine->delayScreen(2000);
	engine->refreshScreen();
}
