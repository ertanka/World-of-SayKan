#include "../GraphicsEngine.cpp"
#include "../widget/ProgressBar.h"

class keyListen:public KeyboardListener{

	private:
	
		bool keyIsDown;
		
	public:
	
        keyListen(){
        
        keyIsDown = false;
	}
	
	void keyPressed(KeyboardEvent* event){
		cout<<"Aha bastı!\n";
		keyIsDown = true;
	}
	void keyReleased(KeyboardEvent * event){
	
		cout<<"De get\n";	
		keyIsDown = false;
	}
	
	bool isKeyPressed(){
	
		return keyIsDown; 
	
	}
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
	
	//Engine creation and setup
     	GraphicsEngine *engine=new GraphicsEngine(900,400,32);
     	engine->setTitle("Animatee!");
     	engine->setBackground("background.jpg");
     	engine->setClearBGRemainder(false);
     	engine->refreshScreen();
     	keyListen *kl = new keyListen();
	engine->setKeyboardListener( kl );

	//Progress bar addition and setup
	ProgressBar *pb=new ProgressBar(30,200,1);
	engine->addWidget(pb);
	pb->setLocation(new Point(350,250));
	pb->setPercent(0);
	pb->setBarColor(new Color(255,0,0));
	pb->setBorderColor(new Color(0,255,0));

	//Walking guy animation
	AnimatingGameObject *ago = new AnimatingGameObject(10,10);
	ago->setTarget(200,200);
	ago->setSpeed(2);
	ago->addState("adam1.jpeg");
	ago->addState("adam2.jpeg");
	ago->addState("adam3.jpeg");
	ago->animate();
	engine->addGameObject(ago);
	
	int speed = 0;


	while(1){
	
	    	engine->gameLoopStart();
	    	pb->setPercent(ago->getCords()->getX()/2);
	    	
	    	if ( kl -> isKeyPressed() ) {
	    	
	    		cout<<ago->getAnimation()->getCurrentState()<<endl;	    		
	    		if ( speed < 6 ) speed ++;
	    		
	    	}
	    		
	    	else {
	    	
	    		ago -> setState( ago -> getCurrentState()  -1 );	    		
	    		if ( speed > 0 ) speed--;
	    		
	    	}
	    	
	    	ago->setSpeed( speed );	
	    		
	    	engine->checkEvents();
	    	engine->updateGame();
	    	engine->refreshScreen();
	    	engine->delayScreen(120);
	    	engine->gameLoopEnd();
	    	cout<<"FPS: "<<engine->getFPS()<<endl;
		}
	}
                          
