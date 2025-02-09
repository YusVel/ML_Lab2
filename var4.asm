section .data
	a dw 0
	b dw 0
	c dw 0
global calculate_us
section .text
calculate_us:
	mov [a], di
	mov [b], si
	mov [c], dx
	xor ax, ax
	add ax, 55
	sub ax, [b]
	add ax, [a]
	xor ebx,ebx
	movzx ebx, ax
	mov ax, -88
	cwd 
	xor ecx,ecx
	mov ecx, [c]
	idiv cx
	add ax, 1 
	xchg eax, ebx
	idiv bx
	ret