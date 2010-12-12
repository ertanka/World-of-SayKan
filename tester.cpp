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
   // engine->setClearBGRemainder(false);
	engine->setKeyboardListener(new keyListen());
	engine->setTextColor(255,0,0);
	engine->setTextFont("font.ttf",18);
	GameObject *obj=new GameObject("background.jpg",100,100);
	engine->addGameObject(obj);
	cout<<engine->addText(string("Test is in progress..."),50,0)<<endl;
		
    for(int j=0;j<5;j++){
		GameObject *obj=new GameObject("background.jpg");
		engine->addGameObject(obj);
		for(int i=0;i<100;i++)   {
    		engine->gameLoopStart();
    		engine->checkEvents();
	   		obj->setCords(new Point(2*i,i));
	   		engine->checkEvents();
	   		engine->updateGame();
			engine->refreshScreen();
			engine->delayScreen(5000);
		}
		engine->gameLoopEnd();
		cout<<engine->getFPS()<<endl;
	}
	//engine->removeGameObject(0);
	engine->refreshScreen();    
	engine->clearGameObjects();
	engine->refreshScreen();
}

