#ifndef _RENDERER_H_
#define _RENDERER_H_

/* there are 25 lines each of 80 columns; each element takes 2 bytes */
#define LINES 25
#define COLUMNS 80
#define BYTES_FOR_EACH_ELEMENT 2
#define LINESIZE BYTES_FOR_EACH_ELEMENT * COLUMNS
#define SCREENSIZE BYTES_FOR_EACH_ELEMENT * COLUMNS * LINES

struct Pixel {
	char c;
	int color;
};


struct STDLine {
	struct Pixel pixels[COLUMNS];
};

struct STDLine lines[512];
struct STDLine kstdin;

int current_loc;
int current_lin;


void stdout_put(const char *str);
void stdout_newline(void);

void stdin_put(const char *str);
void stdin_clear(void);

void move_cursor_left(void);
void move_cursor_right(void);

void clear_screen(void);
void draw(void);

#endif
