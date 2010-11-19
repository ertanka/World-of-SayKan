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
	
	for(int j=0;j<5;j++){
		GameObject *obj=new GameObject(new Image("background.jpg"));
		engine->addGameObject(obj);
		for(int i=0;i<100;i++)   {
    		engine->gameLoopStart();
    		engine->checkEvents();
	   		obj->setCords(new Point(2*i,i));
	   		engine->checkEvents();
	   		engine->updateGame();
			engine->refreshScreen();
			engine->delayScreen(5);
		}
		engine->gameLoopEnd();
		cout<<engine->getFPS()<<endl;
	}
	//engine->removeGameObject(0);
	engine->refreshScreen();
	engine->delayScreen(3000);
	engine->clearGameObjects();
	engine->refreshScreen();
}

