#include "bootloader.hpp"
#include "renderer.hpp"

extern "C" void main() {
	drawRect(110, 50, 100, 100, 17);

	drawRect(120, 60, 80, 80, 0);

	drawRect(135, 75, 20, 20, 14);
	drawRect(165, 75, 20, 20, 13);

	drawRect(135, 105, 20, 20, 12);
	drawRect(165, 105, 20, 20, 11);
}