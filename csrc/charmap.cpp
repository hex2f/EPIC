#include "charmap.hpp"
#include "renderer.hpp"

void drawEPIC(int s, int x, int y) {
	y = x + y + s;	 		// Make GCC stfu
	drawRect(0,0,1,4,11); // E Top
	drawRect(0,2,1,4,11); // E Mid
	drawRect(0,4,1,4,11); // E Bot

	drawRect(4,0,1,4,12); // P Top
	drawRect(7,1,1,1,12); // P Mid
	drawRect(4,2,1,4,12); // P Bot

	drawRect(8,0,5,1,16); // I Bot

	drawRect(9,0,1,4,14); // C Top
	drawRect(9,1,3,1,14); // C Mid
	drawRect(9,4,1,4,14); // C Bot
}