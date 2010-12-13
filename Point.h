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
		bool operator==(Point &p){
			return this->getX()==p.getX() && this->getY()==p.getY();
		}
		bool operator!=(Point &p){
			return *this!=p;
		}
};
#endif
