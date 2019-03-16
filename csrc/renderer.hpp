#ifndef _R_H
#define _R_H

#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 200
#define SCREEN_SIZE SCREEN_WIDTH * SCREEN_HEIGHT

void drawRect(unsigned int ox, unsigned int oy, unsigned int w, unsigned int h, char color);
void clearScreen(void);

#endif