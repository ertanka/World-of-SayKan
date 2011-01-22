#ifndef PROGRESS_BAR
#define PROGRESS_BAR
#include "../Widget.h"

class ProgressBar:public Widget{
	private:
		int h,w;
		int percent;
		int borderSize;
        Color *borderColor;
        Color *barColor;
        SDL_Surface* surface;

	public:

		ProgressBar(int height,int width,int borderSize){
			h=height;
			w=width;
			this->borderSize=borderSize;
			surface=NULL;
			borderColor=new Color();
			barColor=new Color();
		}

		ProgressBar(int height,int width,int borderSize,Color* borderC,Color* barC){
			h=height;
			w=width;
			this->borderSize=borderSize;
			if(borderC!=NULL){
				borderColor=borderC;
			}
			else{
				borderColor=new Color();
			}
			if(barC!=NULL){
				barColor=barC;
			}
			else{
				barColor=new Color();
			}
			surface=NULL;
			
		}

		void setPercent(int p){
			if(p<0 || p>100){
				return;
			}
			percent=p;
		}
		void setBorderColor(Color * newColor){
			if(newColor!=NULL){
				borderColor=newColor;
			}
		}
		void setBarColor(Color * newColor){
			if(newColor!=NULL){
				barColor=newColor;
			}
		}
		int getPercent(){
			return percent;
		}
		// VIRTUAL FUNCTION IMPLEMENTATIONS

		SDL_Surface* getSurface(){
			return surface;
		}
		
		/**
		 * Updates the surface of progress bar.. 
		 * Creates a new surface, sets its size and then fills the surface
		 * with preset colors. 
		 * TODO there can be 2 colors for the bar;1 for filled side 1 for remainder..
		 * Currently remainder side is being filled with border color..
		 */
        void updateSurface(){

			SDL_FreeSurface(surface);
		  	surface=SDL_CreateRGBSurface(SDL_SWSURFACE,w,h,32,0,0,0,0);
			SDL_FillRect(surface,NULL,0xff);
			
			SDL_Color c=borderColor->getSDLColor();
			Uint32 color=*((Uint32*)&c);
			SDL_FillRect(surface,NULL,color);
			

			//Tries to fill the are that correspounds to the bar
			//If there is a problem with the size or placement of the bar its reason probably here.
			SDL_Surface * bar=SDL_CreateRGBSurface(SDL_SWSURFACE,((w-2*borderSize)*percent)/100,h-2*borderSize,32,0,0,0,0);
		    c=barColor->getSDLColor();
			color=*((Uint32*)&c);
		    SDL_FillRect(bar,NULL,color);

		    SDL_Rect offset;
		    offset.x=borderSize;
		    offset.y=borderSize;
		    SDL_BlitSurface(bar,NULL,surface,&offset);
		}
};
#endif
