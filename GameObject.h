#ifndef GAME_OBJECT
#define GAME_OBJECT
#include "Point.h"
#include "Image.h"
using namespace std;

class GameObject{
	protected:
		Point * location;
		Image * image;
		Point * target;
		int speed;
	public:
		GameObject(string);
		GameObject(string,int,int);
		GameObject();
		void setCords(Point*);
		Point* getCords();
		Image* getImage();
		bool isText();
		bool isMoving();
		bool isAnimating();
		int getCurrentState();
		void setTarget(int,int);
		void setTarget(Point *);
		void stopMotion();
		int getSpeed();
		void setSpeed(int);
};                    
#endif
