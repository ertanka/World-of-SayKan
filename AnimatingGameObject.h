#ifndef ANIMATING_GAME_OBJECT
#define ANIMATING_GAME_OBJECT
#include <string>
#include <vector>
#include <iostream>
#include "Animation.h"

using namespace std;

/**
 * Firstly added image will be the main image of 
 * animatingGameObject.. In other words it will be 
 * shown when the object is not moving..
 */
class AnimatingGameObject:public GameObject{
	private:
        vector<string> filenames;
        Animation *anim;
	public:
		AnimatingGameObject(){
			location=new Point(0,0);
			speed=1;
			anim=new Animation();
			animating=true;
		}
		AnimatingGameObject(int x ,int y){
			location=new Point(x,y);
			speed=1;
			anim=new Animation();
			animating=true;
		}	
		AnimatingGameObject(int x, int y, vector<string> filenames){
            location=new Point(x,y);
            anim=new Animation(&filenames);
            speed=1;
			animating=true;
		}

		int getCurrentState(){
			if(!anim->isActive()) {
				return 0;
			}
			return anim->getCurrentState();
		}
		int getMaxState(){
			return anim->getMaxState();
		}
		string getFilename(int index){
			return filenames[index];
		}
		bool isText(){
			return false;
		}
		void animate(){
			anim->animate();
		}
		void stopAnimation(){
			anim->stop();
		}
		void toggleAnimation(){
			anim->toggle();
		}
		void increaseState(){
			anim->increaseState();
		}
		bool setState(int s){
			return anim->setState(s);
		}

		int addState(string filename){
			filenames.push_back(filename);
			if(anim!=NULL)
				delete anim;
			anim=new Animation(&filenames);
			return anim->getMaxState()-1;
		}

		Animation* getAnimation(){
			return anim;
		}
		
};
#endif
