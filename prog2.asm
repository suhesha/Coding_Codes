;Program title : ALP to chek even and odd
section .data
	even_msg db "Even Number ! "
	len1 equ $-even_msg
	odd_msg db "Odd Number ! "
	len2 equ $-odd_msg
section .text
	global _start 
    _start :
	mov eax,15h
	and eax,1
	jz even
   odd :mov edx,len2
	mov ecx,odd_msg
	mov ebx,1
	mov eax,4
	int 80h
	jmp exit

   even:mov edx,len1
	mov ecx,even_msg
	mov ebx,1
	mov eax,4
	int 80h
	
   exit : mov eax,1
	  int 80h
	
