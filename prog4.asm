;Program title : ALP to print the largest of three numbers
section .data; The main section part 
    n1 db "Enter the first number :",13,10
    l1 equ $-n1
    n2 db "Enter the second number :",13,10
    l2 equ $-n2
    n3 db "Enter the third number :",13,10
    l3 equ $-n3
    msg1 db "Number 1 is the largest number !",13,10
    len1 equ $-msg1
    msg2 db "Number 2 is the largest number !",13,10
    len2 equ $-msg2
    msg3 db "Number 3 is the largest number !",13,10
    len3 equ $-msg3

section .bss; allocating the space
num1 resb 2
num2 resb 2
num3 resb 2


section .text
    global _start
_start:
;Displaying "Please enter the first number :"
mov eax,4
      mov ebx,1
      mov ecx,n1
      mov edx,l1
      int 80h

;Accepting the first number
mov eax,3
      mov ebx,0
      mov ecx,num1
      mov edx,2
      int 80h
     
      ;Displaying "Please enter the second number :"
      mov eax,4
      mov ebx,1
      mov ecx,n2
      mov edx,l2
      int 80h

;accepting the second number
mov eax,3
      mov ebx,0
      mov ecx,num2
      mov edx,2
      int 80h
     
      ;displaying "Please enter the third number :"
      mov eax,4
      mov ebx,1
      mov ecx,n3
      mov edx,l3
      int 80h

;Accepting the third number
mov eax,3
      mov ebx,0
      mov ecx,num3
      mov edx,2
      int 80h
     
mov ax,[num1]
mov bx,[num2]
mov cx,[num3]
cmp ax,bx      ;if(dest < source) CF is set
jc greater
cmp ax,cx
jc three
jmp one

greater:
cmp bx,cx
jc three
jmp two

one :        ;First number is the largest
     mov eax,4
     mov ebx,1
     mov ecx,msg1
     mov edx,len1
     int 80h
     jmp exit
     
two :        ;Second number is the largest
     mov eax,4
     mov ebx,1
     mov ecx,msg2
     mov edx,len2
     int 80h
     jmp exit
     
three:        ;Third number is the largest  
     mov eax,4
     mov ebx,1
     mov ecx,msg3
     mov edx,len3
     int 80h
     jmp exit
     

exit : mov eax,1
int 80h
