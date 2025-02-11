all:
	nasm -f elf64 var4us.asm -F dwarf -o var4us.o
	nasm -f elf64 var4_s.asm -F dwarf -o var4_s.o
	gcc -g -ggdb -c ml_lab2.c -o ml_lab2.o
	gcc -g var4us.o var4_s.o ml_lab2.o -o lab2 -no-pie -fno-pie
	./lab2