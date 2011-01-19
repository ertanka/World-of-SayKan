#include "GameObject.h"
GameObject::GameObject(){
	image=NULL;
	location=new Point(0,0);
	speed=1;
	animating=false;
	currentState=0;
}
GameObject::GameObject(string name){
	image=new Image(name);
	location=new Point(0,0);
	speed=1;
	animating=false;
	currentState=0;
}
GameObject::GameObject(string name, int x,int y){
	image=new Image(name);
	location=new Point(x,y);
	speed=1;
	animating=false;
	currentState=0;
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
	return currentState;
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
void GameObject::updateMovement(){
	if(target!=NULL){
		if(location==target){
			target=NULL;
		}                                         
		
		else{
			location->setX(calculateLocation(location->getX(),target->getX()));
			location->setY(calculateLocation(location->getY(),target->getY()));
		}
	}
}
int GameObject::calculateLocation(int currLoc,int targetPoint){
	if(currLoc>targetPoint){
		if((currLoc-speed)<targetPoint){
			return targetPoint;
		}
		else{
			return currLoc-speed;
		}
	}else if(currLoc<targetPoint){
		if((currLoc+speed)>targetPoint){
			return targetPoint;
		}else{
			return currLoc+speed;
		}
	}
	return targetPoint;
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
