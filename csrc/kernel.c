#include "kernel.h"
#include "keyboard.h"
#include "renderer.h"

void kmain(void)
{
	clear_screen();
	stdin_clear();
	stdout_put("+---EPIC Kernel---+"); stdout_newline();
	stdout_put("| Build  18-06-23 |"); stdout_newline();
	stdout_put("+-----------------+"); stdout_newline();
	//kprint_newline();
	//kprint_newline();

	// Init Keyboard
	idt_init();
	kb_init();

	while (1) {
		draw();
		sleep(1000 / 60);
	}
}