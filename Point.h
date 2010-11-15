#ifndef POINT
#define POINT
class Point{
	private:
		int x,y;
	public:
		Point(int xCord,int yCord){
			x=xCord;
			y=yCord;
		}
		int getX(){
			return x;
		}
		int getY(){
			return y;
		}
};
#endif
