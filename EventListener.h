#ifndef EVENT_LISTENER
#define EVENT_LISTENER
class KeyboardEvent{
	private:
		int key;
	public:
		static const int NOT_DEFINED=-1,LEFT=0,RIGHT=1,UP=2,DOWN=3;
		KeyboardEvent(){
			key=-NOT_DEFINED;
		}
		KeyboardEvent(int k){
			key=k;
		}
		int getKey(){
			return key;
		}

};
class MouseEvent{
};
class MouseListener{
	public:
	virtual void mouseStateChanged(MouseEvent)=0;
};
class KeyboardListener{
	public:
	virtual void keyPressed(KeyboardEvent*)=0;
	virtual void keyReleased(KeyboardEvent*)=0;
};
#endif
