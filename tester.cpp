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
	//engine->setBackground("background.jpg");
	engine->setKeyboardListener(new keyListen());
	for(int i=0;i<10;i++)
		cout<<"Game object added with id: "<<engine->addGameObject(new GameObject(new Image("background.jpg"),new Point(15*i,20*i)))<<endl;
	//engine->removeGameObject(0);
	engine->refreshScreen();
	engine->delayScreen(3000);
	engine->clearGameObjects();
	engine->refreshScreen();
	while(true)
		engine->checkEvents();
}

