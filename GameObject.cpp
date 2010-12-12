#include "GameObject.h"

GameObject::GameObject(){
	image=NULL;
	location=new Point(0,0);
}
GameObject::GameObject(string name){
	image=new Image(name);
	location=new Point(0,0);
}
GameObject::GameObject(string name, int x,int y){
	image=new Image(name);
	location=new Point(x,y);
}
void GameObject::setCords(Point * newCords){
	location=newCords;
}
Point* GameObject::getCords(){
	return location;
}
bool GameObject::isText(){
	return false;
}
Image* GameObject::getImage(){
	return image;
}
bool GameObject::isMoving(){
	return false;
}
bool GameObject::isAnimating(){
	return false;
}
int GameObject::getCurrentState(){
	return 0;
}
