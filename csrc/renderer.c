#include "renderer.h"
#include "kernel.h"

/* video memory begins at address 0xb8000 */
char *vidptr = (char*)0xb8000;

int frame = 0;

void stdout_put(const char *str)
{
	unsigned int i = 0;
	while (str[i] != '\0') {
		lines[current_lin].pixels[current_loc].c = str[i++];
		lines[current_lin].pixels[current_loc].color = 0x9f;
		current_loc++;
	}
}

void stdin_put(const char *str)
{
	unsigned int i = 0;
	while (str[i] != '\0') {
		if (current_loc >= COLUMNS) {
			return;
		}
		lines[current_lin].pixels[current_loc].c = str[i++];
		lines[current_lin].pixels[current_loc].color = 0xf0;
		current_loc++;
	}
}

void stdout_newline(void)
{
	current_loc = 0;
	current_lin += 1;
}

void stdin_clear(void)
{
	unsigned int c = 0;
	while (c < COLUMNS) {
		kstdin.pixels[c].c = ' ';
		kstdin.pixels[c].color = 0xf0;
		c++;
	}
	current_loc = 0;
}

void move_cursor_left(void) {
	if(current_loc <= 0) {
		//if(current_lin <= 0) {
		//	return;
		//}
		//current_lin--;
		//current_loc = COLUMNS - 1;
		return;
	}
	current_loc--;
}

void move_cursor_right(void) {
	if(current_loc >= COLUMNS) {
		//if(current_lin >= LINES) {
		//	return;
		//}
		//current_lin++;
		//current_loc = 0;
		return;
	}
	current_loc++;
}

void clear_screen(void)
{
	current_loc = 0;
	unsigned int l = 0;
	while (l < LINES) {
		unsigned int c = 0;
		while (c < COLUMNS) {
			lines[l].pixels[c].c = ' ';
			lines[l].pixels[c].color = 0x99;
			c++;
		}
		l++;
	}
}

int l = 0;

void draw(void)
{
	unsigned int i = 0;
	unsigned int l = 0;
	while (l < LINES - 1) {
		unsigned int c = 0;
		while (c < COLUMNS) {
			vidptr[i++] = lines[l].pixels[c].c;
			vidptr[i++] = lines[l].pixels[c].color;
			c++;
		}
		l++;
	}

	unsigned int c = 0;
	while (c < COLUMNS) {
		vidptr[i++] = kstdin.pixels[c].c;
		vidptr[i++] = kstdin.pixels[c].color;
		c++;
	}

	if(frame % 60 > 30) {
		vidptr[(COLUMNS * (LINES - 1) + current_loc) * 2 + 1] = 0x00;
	}
	frame++;
}