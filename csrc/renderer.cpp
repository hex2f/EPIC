#include "renderer.hpp"

void drawRect(unsigned int ox, unsigned int oy, unsigned int h, unsigned int w, char color) {
    unsigned int x, y;

    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
        	((char*)0xA0000)[(y+oy)*SCREEN_WIDTH + (x+ox)] = color;
        }
    }
}


void clearScreen() {
    unsigned int x, y;

    for (y = 0; y < SCREEN_HEIGHT; y++) {
        for (x = 0; x < SCREEN_WIDTH; x++) {
        	((char*)0xA0000)[y*SCREEN_WIDTH + x] = 0x1;
        }
    }
}
