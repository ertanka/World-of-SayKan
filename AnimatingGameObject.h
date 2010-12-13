#ifndef ANIMATING_GAME_OBJECT
#define ANIMATING_GAME_OBJECT
#include <string>
#include <vector>
using namespace std;

/**
 * Firstly added image will be the main image of 
 * animatingGameObject.. In other words it will be 
 * shown when the object is not moving..
 */
class AnimatingGameObject:public GameObject{
	private:
		int currentState,maxState;
        bool animating;
        vector<string> filenames;
	public:
		AnimatingGameObject(){
			location=new Point(0,0);
			currentState=0;
			maxState=0;
			animating=false;
		}
		AnimatingGameObject(int x ,int y){
			location=new Point(x,y);
			maxState=0;
			currentState=0;
			animating=false;
		}		
		int getCurrentState(){
			if(!animating)
				return 0;
			return currentState;
		}
		int getMaxState(){
			return maxState;
		}
		string getFilename(int index){
			return filenames[index];
		}
		bool isText(){
			return false;
		}
		bool isAnimating(){
			return animating;
		}
		void animate(){
			animating=true;
		}
		void stopAnimation(){
			animating=false;
		}
		void toggleAnimation(){
			animating= !animating;
		}
		void increaseState(){
			currentState=(currentState+1)%maxState;
		}
		bool setState(int s){
			if(s>=maxState)
                 return false;
            currentState=s;
            return true;
		}
		int addState(string filename){
			filenames.push_back(filename);
			maxState++;
			return maxState-1;
		}
		
};
#endif
