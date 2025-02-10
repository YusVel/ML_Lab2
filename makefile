all:
	nasm -f elf64 var4us.asm -F dwarf -o var4us.o
	gcc -g -ggdb -c ml_lab2.c -o ml_lab2.o
	gcc -g var4us.o ml_lab2.o -o lab2 -no-pie
	./lab2