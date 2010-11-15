#ifndef GAME_OBJECT
#define GAME_OBJECT
#include "Point.h"
#include "Image.h"

class GameObject{
	private:
		Point * location;
		Point * target;
		Image * image;
		bool moving;
	public:
		GameObject(Image*);
		GameObject(Image*,Point*);
		void setCords(Point*);
		void setTarget(Point*);
		Point* getCords();
		Point* getTarget();
		bool isMoving(); 
		Image* getImage();
};                    
#endif
