section .data
	a dd 0
	b dd 0
	c dd 0
global calculate_us
section .text
calculate_us:
	mov [a], di
	mov [b], si
	mov [c], dx
	xor eax, eax
	mov eax, 55
	
	sub ax, [b]
	add ax, [a]
	
	
	xor ebx,ebx
	mov ebx, eax
	mov ax, -88
	cwd 
	xor ecx,ecx
	mov ecx, [c]
	
	;xor edx,edx
	
	idiv cx
	ret
	
	add ax, 1 
	
	xchg eax, ebx
	
	xor edx,edx
	
	idiv bx
	ret