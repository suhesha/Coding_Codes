;Program title : ALP to display numbers 0 to 9 on the screen
;Programmer name : Kevin Francis Fernandes

section .data
	msg1 db " "
	len1 equ $-msg1

section .bss
	num resb 1

section .text
	global _start:
   _start : 
	mov ecx,10
	mov eax,'0'
   up : mov [num] ,eax
	mov eax,4
	mov ebx,1
	push ecx
	
	mov ecx,num
	mov edx,1
	int 80h

	mov eax,4		; code snippet to display msg1
	mov ebx,1
	mov ecx,msg1
	mov edx,len1
	int 80h

	mov eax,[num]
	sub eax,'0'
	inc eax
	add eax,'0'
	pop ecx
	loop up

	mov eax,1
	int 80h

