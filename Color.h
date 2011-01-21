#ifndef COLOR_H
#define COLOR_H
#include "GraphicsEngine.h"

class Color{
	private:
		int r,g,b;

	public:
		Color(){
			r=0;
			g=0;
			b=0;
		}
		Color(int r,int g,int b){
			this->r=r;
			this->g=g;
			this->b=b;
		}
		void setR(int r){
			this->r=r;
		}
		void setG(int g){
			this->g=g;
		}
		void setB(int b){
			this->b=b;
		}
		int getR(){
			return r;
		}
		int getG(){
			return g;
		}
		int getB(){
			return b;
		}

		SDL_Color getSDLColor(){
			SDL_Color temp;
			temp.r=r;
			temp.g=g;
			temp.b=b;
			return temp;
		}
};
#endif
