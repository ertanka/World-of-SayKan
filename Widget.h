#ifndef WIDGET
#define WIDGET
#include "GraphicsEngine.h"

class Widget{
 	private:
 		Point* location;

	public:

		void setLocation(Point *loc){
			location=loc;
		}
		Point* getCords(){
			return location;
		}
		void setCords(Point* cords){
			location=cords;
		}
		virtual SDL_Surface* getSurface()=0;
		virtual void updateSurface()=0;
};
#endif
