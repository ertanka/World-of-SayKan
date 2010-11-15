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
	engine->setKeyboardListener(new keyListen());
	cout<<"Game object added with id: "<<engine->addGameObject(new GameObject(new Image("file")))<<endl;
	engine->removeGameObject(0);
	cout<<"Game object Removed!\n";
	engine->refreshScreen();
	while(true)
		engine->checkEvents();
}

