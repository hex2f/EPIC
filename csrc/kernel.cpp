#include "kernel.hpp"
#include "renderer.hpp"


void init_serial() {
   write_port(COM1 + 1, 0x00);    // Disable all interrupts
   write_port(COM1 + 3, 0x80);    // Enable DLAB (set baud rate divisor)
   write_port(COM1 + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
   write_port(COM1 + 1, 0x00);    //                  (hi byte)
   write_port(COM1 + 3, 0x03);    // 8 bits, no parity, one stop bit
   write_port(COM1 + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
   write_port(COM1 + 4, 0x0B);    // IRQs enabled, RTS/DSR set
}


/*
	mov   edx, [esp + 4]
	mov   al, [esp + 4 + 4]
	out   dx, al
	ret
*/

extern "C" void kernelmain() {
	Renderer::drawHome();
}