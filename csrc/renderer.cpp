#include "renderer.hpp"
namespace Renderer {

    void drawRect(unsigned int ox, unsigned int oy, unsigned int h, unsigned int w) {
        char* vga = (char*)VGA;
        unsigned int x, y, o;

        o = (SCREEN_WIDTH * oy) + ox;

        for (y = 0; y < h; y++) {
            for (x = 0; x < w; x++) {
            	vga[(o + (SCREEN_WIDTH * y) + x)+1] = 0xF;
            }
        }
    }

    void drawBitmap (unsigned int ox, unsigned int oy) {
        char* vga = (char*)VGA;
        oy++;
        ox++;
        unsigned int x = 0;
        unsigned int y = 0;

    	while (y < 10) {
            x = 0;
            while (x < 4) {
                vga[SCREEN_WIDTH * y + x] = 0x3;
                x++;
            }
            y++;
        }
    }

    void drawHome() {
    	// static char str[] = "abcdefghijklmnopqrstuvwxyz";
    	// ef_drawText(str, 136, 86, 4, 0);
    	// STDFont::drawText(str, 2, 2, 2, 4);
        clearScreen();

    	drawBitmap(10, 10);
        drawRect(30, 40, 10, 40);
    }


    void clearScreen() {
        char* vga = (char*)VGA;
        unsigned int i = 0;

        while (i <= SCREEN_SIZE) {
            vga[i] = 0x9;
            i++;
        }
    }
}