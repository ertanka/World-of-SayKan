This test codes are written by ynmehel to demonstrate the basic functionality of the GraphicsEngine. It uses;
*Basic window functionality
*KeyboardListener
*Widget
*AnimatingGameObject

Compiling this test code needs again the same parameters;
g++ -lSDL -lSDL_image -lSDL_ttf tester.cpp -o tester

**This test includes the GraphicsEngine headers by relative addresses so if you compile it in some different directory you should check these import lines;
#include "../../GraphicsEngine.cpp"
#include "../../widget/ProgressBar.h"

