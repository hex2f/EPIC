#include "epicfont.hpp"
#include "renderer.hpp"

int drawE(int size, int o) {
	int w = 0;
	switch (size) {
		case 1:
			drawRect(o+0,0,1,4); // E Top
			drawRect(o+0,2,1,4); // E Mid
			drawRect(o+0,4,1,4); // E Bot
			w = 4;
			break;
		case 4:
			drawRect(o+(0 * 4),0 * 4,1 * 4,4 * 4); // E Top
			drawRect(o+(0 * 4),2 * 4,1 * 4,4 * 4); // E Mid
			drawRect(o+(0 * 4),4 * 4,1 * 4,4 * 4); // E Bot
			w = 4 * 4;
			break;
	}
	return w;
}

int drawP(int size, int o) {
	int w = 0;
	switch (size) {
		case 1:
			drawRect(o+0,0,1,4); // P Top
			drawRect(o+3,1,1,1); // P Mid
			drawRect(o+0,2,1,4); // P Bot
			w = 4;
			break;
		case 4:

			w = 4 * 4;
			break;
	}
	return w;
}

int drawI(int size, int o) {
	int w = 0;
	switch (size) {
		case 1:
			drawRect(o+0,0,5,1); // I
			w = 1;
			break;
		case 4:

			w = 4 * 4;
			break;
	}
	return w;
}

int drawC(int size, int o) {
	int w = 0;
	switch (size) {
		case 1:
			drawRect(o+0,0,1,4); // C Top
			drawRect(o+0,1,3,1); // C Mid
			drawRect(o+0,4,1,4); // C Bot
			w = 1;
			break;
		case 4:

			w = 4 * 4;
			break;
	}
	return w;
}

void ef_drawText(char* str, int fontSize, int fontSpace) {
	int i = 0;
	int w = 0;

	w += drawE(fontSize, w) + fontSpace;
	w += drawP(fontSize, w) + fontSpace;
	w += drawI(fontSize, w) + fontSpace;
	w += drawC(fontSize, w) + fontSpace;

	while(str[i] != '\0') {
		switch(str[i]) {
			case 'c': w += drawC(fontSize, w) + fontSpace; break;
			case 'e': w += drawE(fontSize, w) + fontSpace; break;
			case 'i': w += drawI(fontSize, w) + fontSpace; break;
			case 'p': w += drawP(fontSize, w) + fontSpace; break;
		}
		drawRect(100, 100, 1, 1);
		i++;
	}
}