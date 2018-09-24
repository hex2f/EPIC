section .boot
bits 16
global boot
boot:
	mov ax, 0x2401
	int 0x15

	mov ax, 0x13
	int 0x10

	mov ah, 0 	; initialize port service
	mov al, 0xE3; line settings = 9600, 8, N, 1
	xor dx, dx 	; port = COM1
	int 0x14 	; BIOS serial port services

	mov edi, 0xA0000	;yellow pixel to indicate booting
	mov al, 0x0E
	mov [edi], al

	mov [disk],dl

	mov ah, 0x2    ;read sectors
	mov al, 8      ;sectors to read
	mov ch, 0      ;cylinder idx
	mov dh, 0      ;head idx
	mov cl, 2      ;sector idx
	mov dl, [disk] ;disk idx
	mov bx, copy_target;target pointer
	int 0x13

	mov edi, 0xA0000	;blue pixel to indicate disk read success
	mov al, 0x09
	mov [edi], al

	extern bootloadermain
	call bootloadermain
	cli

	lgdt [gdt_pointer]
	mov eax, cr0
	or eax,0x1
	mov cr0, eax
	mov ax, DATA_SEG
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	jmp CODE_SEG:boot2
gdt_start:
	dq 0x0
gdt_code:
	dw 0xFFFF
	dw 0x0
	db 0x0
	db 10011010b
	db 11001111b
	db 0x0
gdt_data:
	dw 0xFFFF
	dw 0x0
	db 0x0
	db 10010010b
	db 11001111b
	db 0x0
gdt_end:
gdt_pointer:
	dw gdt_end - gdt_start
	dd gdt_start
disk:
	db 0x0
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start

times 510 - ($-$$) db 0
dw 0xaa55
copy_target:
bits 32

global read_port
global write_port

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

boot2:
	mov edi, 0xA0000	;green pixel to indicate success
	mov al, 0x0A
	mov [edi], al
halt:
	mov esp,kernel_stack_top
	extern kernelmain
	call kernelmain
	cli
	hlt

section .bss
align 4
kernel_stack_bottom: equ $
	resb 65536 ; 64 KiB
kernel_stack_top: