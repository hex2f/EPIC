#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64
#define IDT_SIZE 256
#define INTERRUPT_GATE 0x8e
#define KERNEL_CODE_SEGMENT_OFFSET 0x08

#define LEFT_ARROW_KEY_CODE 0x4B
#define RIGHT_ARROW_KEY_CODE 0x4C
#define BACKSPACE_KEY_CODE 0x0E
#define ENTER_KEY_CODE 0x1C

char keyboard_buffer[64];
unsigned char keyboard_map[128];

void keyboard_handler(void);
char read_port(unsigned short port);
void write_port(unsigned short port, unsigned char data);
void load_idt(unsigned long *idt_ptr);

void idt_init(void);
void kb_init(void);
void keyboard_handler_main(void);

struct IDT_entry {
	unsigned short int offset_lowerbits;
	unsigned short int selector;
	unsigned char zero;
	unsigned char type_attr;
	unsigned short int offset_higherbits;
};

struct IDT_entry IDT[IDT_SIZE];

#endif