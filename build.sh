echo "=== EPIC Kernel ==="
echo "    Version 0.2    "
echo "==================="

echo Assembling bootloader.asm...
nasm -f elf32 asmsrc/bootloader.asm -o out/basm.o

echo Compiling C++...
gcc -m64 \
	csrc/bootloader.cpp\
	out/basm.o\
	-o kernel.bin -nostdlib -ffreestanding -std=c++11 -mno-red-zone -fno-exceptions -nostdlib -fno-rtti -Wall -Wextra -Werror -T link.ld

echo "Successfully built EPIC Kernel v0.2"