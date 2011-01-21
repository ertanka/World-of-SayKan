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
		Point* getLocation(){
			return location;
		}
		virtual SDL_Surface getSurface()=0;
};
#endif
