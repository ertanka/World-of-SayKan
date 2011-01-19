#include "GraphicsEngine.h"

class keyListen:public KeyboardListener{
	public:
        keyListen(){
		}
		void keyPressed(KeyboardEvent* event){
			cout<<"Aha bastı!\n";
		}
		void keyReleased(KeyboardEvent * event){}
};

//FPS Test main    
/*
    int main(int argc, char* args[]){
	GraphicsEngine *engine=new GraphicsEngine(640,480,32);
	engine->setTitle("deneme");
	engine->setBackground("background.jpg");
    engine->setClearBGRemainder(false);
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
			engine->delayScreen(5);
		}
		engine->gameLoopEnd();
		cout<<engine->getFPS()<<endl;
	}
	//engine->removeGameObject(0);
	engine->refreshScreen();    
	engine->clearGameObjects();
	engine->refreshScreen();
}                                    */

	int main(int argc,char * args[]){
     	GraphicsEngine *engine=new GraphicsEngine(640,480,32);
     	engine->setTitle("Animatee!");
     	engine->setBackground("background.jpg");
     	engine->setClearBGRemainder(false);
     	engine->refreshScreen();
	    engine->setKeyboardListener(new keyListen());
	    AnimatingGameObject *ago = new AnimatingGameObject(10,10);
	    ago->setTarget(200,200);
	    ago->setSpeed(30);
	    ago->addState("anim1.jpg");
	    ago->addState("anim2.jpg");
	    ago->addState("anim3.jpg");
	    ago->animate();
	    engine->addGameObject(ago);
	    while(1){
	    	engine->gameLoopStart();
	    	engine->checkEvents();
	    	engine->updateGame();
	    	engine->refreshScreen();
	    	engine->delayScreen(150);
	    	engine->gameLoopEnd();
	    	cout<<"FPS: "<<engine->getFPS()<<endl;
		}
	}
                          
