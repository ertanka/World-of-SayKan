#include "GraphicsEngine.h"


class keyListen:public KeyboardListener{
	public:
        keyListen(){
		}
		void keyPressed(KeyboardEvent* event){}
		void keyReleased(KeyboardEvent * event){}
};

int main(int argc, char* args[]){
	GraphicsEngine *engine=new GraphicsEngine(640,480,32);
	engine->setTitle("deneme");
	engine->setBackground("background.jpg");
	engine->refreshScreen();
	engine->setKeyboardListener(new keyListen());
	while(true)
		engine->checkEvents();
}

