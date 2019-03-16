#include "bootloader.hpp"
#include "renderer.hpp"

extern "C" void main() {
	drawRect(0, 0, 200, 320, 10);	// Background
	drawRect(110, 50, 100, 100, 17);// White Box Center

	drawRect(120, 60, 80, 80, 0);	// White Box Center

	drawRect(135, 75, 20, 20, 14);	// Red
	drawRect(165, 75, 20, 20, 13);	// Cyan

	drawRect(135, 105, 20, 20, 12);	// Green
	drawRect(165, 105, 20, 20, 11);	// Blue
}