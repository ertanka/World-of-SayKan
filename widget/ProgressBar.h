#ifndef PROGRESS_BAR
#define PROGRESS_BAR
#include "../GraphicsEngine.h"

class ProgressBar{
	private:
		int h,w;
		int percent;
		int borderSize;
        Color borderColor,barColor;

	public:
		ProgressBar(){
			h=0;
			w=0;
			borderSize=1;
		}

		ProgressBar(int height,int width,int borderSize){
			h=height;
			w=width;
			this->borderSize=borderSize;
		}

		ProgressBar(int height,int width,int borderSize,Color borderC,Color barC){
			h=height;
			w=width;
			this->borderSize=borderSize;
			borderColor=borderC;
			barColor=barC;
		}

		void setPercent(int p){
			percent=p;
		}
		int getPercent(){
			return percent;
		}

		SDL_Surface* getSurface(){
			//Super seyler hep bura
		}

};
#endif
