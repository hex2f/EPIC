echo "=== EPIC Kernel ==="
echo "    Version 0.2    "
echo "==================="

if [ ! -d out ]; then
  mkdir out;
fi

missing=
for cmd in nasm gcc; do
  command -v "$cmd" > /dev/null || missing+="$cmd, "
done

if [ -n "$missing" ]; then
  printf 'Please install the following dependencies: %s\n' "${missing%, }"
  exit 2
fi

echo Assembling bootloader.asm...
nasm -f elf64 asmsrc/bootloader.asm -o out/basm.o

if [ $? -eq 0 ]; then
	echo "Successfully assembled bootloader.asm"
else
	echo "An error occurred while assembling. Exiting..."
	exit 1
fi

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
if [ $? -eq 0 ]; then
	echo "Successfully built EPIC Kernel"
else
	echo "An error occurred while compiling."
fi