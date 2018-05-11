bits 32
section .text
        ;multiboot spec
        align 4
        dd 0x1BADB002
        dd 0x00
        dd - (0x1BADB002 + 0x00)

global start
global keyboard_handler
global read_port
global write_port
global load_idt
global sleep
global kmemset

extern kmain 						;functions in c
extern kdraw 						
extern keyboard_handler_main

read_port:
	mov edx, [esp + 4]
									;al is the lower 8 bits of eax
	in al, dx						;dx is the lower 16 bits of edx
	ret

write_port:
	mov   edx, [esp + 4]
	mov   al, [esp + 4 + 4]
	out   dx, al
	ret

load_idt:
	mov edx, [esp + 4]
	lidt [edx]
	sti 							;turn on interrupts
	ret

keyboard_handler:                 
	call    keyboard_handler_main
	iretd

start:
	cli 							;block interrupts
	mov esp, stack_space
	call kmain
	hlt 							;halt the CPU

sleep:
	mov bp, [esp + 4]
	mov si, [esp + 4]
	imul bp,5
	imul si,5
	call sleep_loop
	ret

sleep_loop:
	dec bp
	nop
	jnz sleep_loop
	dec si
	cmp si,0    
	jnz sleep_loop
	ret

kmemset:      
    push    edi             		; proc uses edi, so save it.

    mov     ecx, [esp + 16] 		; size_t num
    mov     al, [esp + 12]  		; int value 
    mov     edi, [esp + 8]  		; void * ptr
    rep     stosb 

    mov     eax, [esp + 8]  		; return pointer
    pop     edi             		; restore edi
    ret                     		; let caller adjust stack

section .bss
resb 65536							;64KB for stack
stack_space:


