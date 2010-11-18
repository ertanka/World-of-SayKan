#include "GraphicsEngine.h"
#include <time.h>


class keyListen:public KeyboardListener{
	public:
        keyListen(){
		}
		void keyPressed(KeyboardEvent* event){}
		void keyReleased(KeyboardEvent * event){}
};

int main(int argc, char* args[]){
	time_t start;
	GraphicsEngine *engine=new GraphicsEngine(640,480,32);
	engine->setTitle("deneme");
	engine->setBackground("background.jpg");
	engine->setKeyboardListener(new keyListen());
	int i,total=0;;
	for(int j=0;j<10;j++){
    	start=time(NULL);
		GameObject *obj=new GameObject(new Image("background.jpg"));
		engine->addGameObject(obj);
		for(i=0;(time(NULL)-start)<3;i++)   {
	   		obj->setCords(new Point(2*i,i));
			engine->refreshScreen();
			engine->delayScreen(5);
		}
		cout<<"Total number of "<<i<<" frames on 3 seconds\n"; 
		cout<<"(FPS: "<<(i/3)<<")\n";	
		total+=i;
	}
	cout<<"Average: "<<total/30<<endl;
	//engine->removeGameObject(0);
	engine->refreshScreen();
	engine->delayScreen(3000);
	engine->clearGameObjects();
	engine->refreshScreen();
	while(true)
		engine->checkEvents();
}

