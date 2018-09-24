#ifndef _R_H
#define _R_H

#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 200
#define SCREEN_SIZE SCREEN_WIDTH * SCREEN_HEIGHT
#define VGA 0x000A0000

namespace Renderer {

	struct bitmap {
		unsigned int h;
		unsigned int w;
		char data[];
	};

	void drawRect(unsigned int ox, unsigned int oy, unsigned int w, unsigned int h);
	void drawHome(void);
	void clearScreen(void);
}
#endif