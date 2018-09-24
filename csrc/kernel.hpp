#ifndef _K_H
#define _K_H

#define COM1 0x3fc   /* COM1 */

extern "C" char read_port(unsigned short port);
extern "C" void write_port(unsigned short port, unsigned char data);

#endif