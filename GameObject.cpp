#include "GameObject.h"

GameObject::GameObject(Image* file){
	image=file;
	location=new Point(0,0);
	target=NULL;
	moving=false;
}
GameObject::GameObject(Image * file, Point* loc){
	image=file;
	location=loc;
	target=NULL;
	moving=false;
}
void GameObject::setCords(Point * newCords){
	location=newCords;
}
void GameObject::setTarget(Point * newTarget){
	target=newTarget;
}
Point* GameObject::getCords(){
	return location;
}
Point* GameObject::getTarget(){
	return target;
}
bool GameObject::isMoving(){
	return moving;
}
Image* GameObject::getImage(){
	return image;
}
