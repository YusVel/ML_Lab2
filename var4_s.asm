extern A ; 32bit
extern RESULT ; 64bit
extern a1 ; 8bit
extern b1 ; 8bit
extern c1 ; 8bit
extern _B ;16 bit
extern _RESULT ;16 bit
extern ostatok_ot_RESULT ;16 bit


section .data
	num1 dw -88
	num2 dw  1.0

global calculate_s
section .text
calculate_s:

	xor ax, ax
	mov ax, 55
	
	xor bx,bx
	movsx bx, [b1]
	
	sub ax,  bx
	
	movsx bx, [a1]
	
	add ax, bx
	
	mov [A], ax ;подсчитали числитель
	xor dx,dx
	xor ax,ax
	mov eax, -88
	movsx bx, [c1]
	cwd
	idiv  bx
	add ax, 1

	mov [_B], ax
	xor dx,dx
	mov bx, ax

	mov ax, [A]
	cwd
	idiv  bx
	mov [ostatok_ot_RESULT], dx 

	mov [_RESULT], ax

	
	ret