#include "renderer.hpp"
#include "epicfont.hpp"

void drawRect(int ox, int oy, int h, int w) {
	char* vga = (char*)0xA0000;

    int x, y, i;

    i = oy * SCREEN_WIDTH;

    for (y = 0; y < h; y++) {
    	i += ox;
        for (x = 0; x < w; x++) {
        	vga[i++] = 0xf;
        }
    	i += SCREEN_WIDTH - w - ox;
    }
}

void drawHome() {
	char str[] = "epic";
	ef_drawText(str, 1, 0);
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