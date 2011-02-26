#ifndef EVENT_LISTENER
#define EVENT_LISTENER
class KeyboardEvent{
	private:
	
		int key;
		
	public:
	
		static const int NUM0=0,NUM1=1,NUM2=2,NUM3=3,NUM4=4,NUM5=5,NUM6=6,NUM7=7,NUM8=8,NUM9=9;
		static const int NOT_DEFINED=-1,LEFT=10,RIGHT=11,UP=12,DOWN=13;
		static const int LSTAR=14,LMINUS=15;
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
