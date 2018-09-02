echo "=== EPIC Kernel ==="
echo "    Version 0.2    "
echo "==================="

echo Assembling bootloader.asm...
nasm -f elf64 asmsrc/bootloader.asm -o out/basm.o

csrc=""

for F in `find ./csrc -type f`
do
	echo Adding $(basename ${F})...
	csrc="$csrc ${F}"
done

echo Adding basm.o
csrc="$csrc ./out/basm.o"

gcc -m64 \
	${csrc}\
	-o out/kernel.bin -nostdlib -ffreestanding -std=c++11 -mno-red-zone -fno-exceptions -nostdlib -fno-rtti -Wall -Wextra -Werror -T link.ld


echo "Successfully built EPIC Kernel v0.2"