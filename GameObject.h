#ifndef GAME_OBJECT
#define GAME_OBJECT
#include "Point.h"
#include "Image.h"
using namespace std;

class GameObject{
	protected:
		Point * location;
		Image * image;
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
};                    
#endif
