#include "GameObject.h"

GameObject::GameObject(){
	image=NULL;
	location=new Point(0,0);
	speed=0;
	animating=false;
}
GameObject::GameObject(string name){
	image=new Image(name);
	location=new Point(0,0);
	speed=0;
	animating=false;
}
GameObject::GameObject(string name, int x,int y){
	image=new Image(name);
	location=new Point(x,y);
	speed=0;
	animating=false;
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
bool GameObject::isAnimating(){
	return animating;
}
int GameObject::getCurrentState(){
	return 0;
}
void GameObject::setTarget(int x,int y){
	target=new Point(x,y);
}
void GameObject::setTarget(Point * newCords){
	target=newCords;
}
void GameObject::stopMotion(){
	target=NULL;
}
bool GameObject::isMoving(){
	return target!=NULL && location!=target;
}
int GameObject::getSpeed(){
	return speed;
}
void GameObject::setSpeed(int s){
	speed=s;
}
