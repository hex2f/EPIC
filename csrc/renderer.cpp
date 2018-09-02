#include "renderer.hpp"
#include "charmap.hpp"

void drawRect(int ox, int oy, int h, int w, int color) {
	char* vga = (char*)0xA0000;

    int x, y, i;

    i = oy * SCREEN_WIDTH;

    for (y = 0; y < h; y++) {
    	i += ox;
        for (x = 0; x < w; x++) {
        	vga[i++] = color;
        }
    	i += SCREEN_WIDTH - w - ox;
    }
}

void drawHome() {
	drawEPIC(2, 12, 12);
}


void clearScreen() {
	char* vga = (char*)0xA0000;

    int x, y, i;

    for (y = 0; y < SCREEN_HEIGHT; y++) {
        for (x = 0; x < SCREEN_WIDTH; x++) {
        	vga[i++] = 0x0;
        }
    }
}