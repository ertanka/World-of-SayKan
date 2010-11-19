#include "GameObject.h"

GameObject::GameObject(string name){
	image=new Image(name);
	location=new Point(0,0);
	text=false;
}
GameObject::GameObject(string name,bool isText){
	if(!isText)
		image=new Image(name);
	location=new Point(0,0);
	this->text=isText;
}
GameObject::GameObject(string name, int x,int y){
	image=new Image(name);
	location=new Point(x,y);
	text=false;
}
GameObject::GameObject(string name,int x,int y,bool isText){
	if(!isText)
		image=new Image(name);
	location=new Point(x,y);
	this->text=isText;
}
void GameObject::setCords(Point * newCords){
	location=newCords;
}
Point* GameObject::getCords(){
	return location;
}
bool GameObject::isText(){
	return text;
}
Image* GameObject::getImage(){
	return image;
}
