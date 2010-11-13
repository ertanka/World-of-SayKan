#include "GraphicsEngine.h"


int main(int argc, char* args[]){

	GraphicsEngine *engine=new GraphicsEngine(640,480,32);
	engine->setTitle("deneme");
	cout<< engine->setBackground("background.jpg");
	engine->refreshScreen();
	engine->delayScreen(2000);
}
