;Program title : ALP to chek even and odd
;Programmer name : Kevin Francis Fernandes



section .data
	pos_msg db "Positive Number ! "
	len1 equ $-pos_msg
	neg_msg db "Negative Number ! "
	len2 equ $-neg_msg
	
section .text
	global _start 
    _start :
	mov eax,12h
	rol eax,1
	jc neg
	
	mov edx,len1
	mov ecx,pos_msg
	mov ebx,1
	mov eax,4
	int 80h
        jmp exit

  

    neg :mov edx,len2
	mov ecx,neg_msg
	mov ebx,1
	mov eax,4
	int 80h


   
	
   exit : mov eax,1
	  int 80h
	
