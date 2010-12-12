#ifndef TEXT_OBJECT
#define TEXT_OBJECT

/**
 * TextObject is currently only the place holder.
 * Since we dont even keep the text here, texts are immutable
 * and there is no way to change after adding. 
 */
class TextObject:public GameObject{
  	public:
  		
		TextObject(){
			location= new Point(0,0);
			image=NULL;
		}
		TextObject(int x,int y){
			location=new Point(x,y);
			image=NULL;
		}
		bool isText(){
			return true;
		}
		
};
#endif
