#ifndef GAME_OBJECT
#define GAME_OBJECT
#include "Point.h"
#include "Image.h"
using namespace std;

class GameObject{
	private:
		Point * location;
		Image * image;
		bool text;
	public:
		GameObject(string);
		GameObject(string,bool);
		GameObject(string,int,int);
		GameObject(string,int,int,bool);
		void setCords(Point*);
		Point* getCords();
		Image* getImage();
		bool isText();
};                    
#endif
