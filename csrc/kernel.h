#ifndef _KERNEL_H_
#define _KERNEL_H_
#include <stdlib.h>
#include <string.h>

void sleep(unsigned int time);
void kmemset(void *str, int c, size_t n);
#endif