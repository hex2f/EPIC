echo "=== EPIC Kernel ==="
echo "    Version 0.2    "
echo "==================="

echo Assembling bootloader.asm...
nasm -f bin asmsrc/bootloader.asm -o out/basm.bin

# echo Compiling kernel.c ...
# gcc -m32 -c csrc/kernel.c -o out/kernelc.o

# echo Compiling keyboard.c ...
# gcc -m32 -c csrc/keyboard.c -o out/keyboardc.o

# echo Compiling renderer.c ...
# gcc -m32 -c csrc/renderer.c -o out/rendererc.o

# echo Compiling esh.c ...
# gcc -m32 -c csrc/esh.c -o out/eshc.o

# echo Linking...
# ld -m elf_i386 -T link.ld -o out/kernel \
#	out/kasm.o \
#	out/kernelc.o \
#	out/keyboardc.o \
#	out/rendererc.o \
#	out/eshc.o \

echo "Successfully built EPIC Kernel v0.2"