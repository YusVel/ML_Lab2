all:
	nasm -f elf64 var4.asm -F dwarf -o var4.o
	gcc -g -ggdb -c ml_lab2.c -o ml_lab2.o
	gcc -g var4.o ml_lab2.o -o lab2 -no-pie
	./lab2