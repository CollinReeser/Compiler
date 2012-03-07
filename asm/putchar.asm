; Collin Reeser - October the 29th, 2011
; Link name: putchar_cr
; This is a routine that prints a character
; Takes one argument on the stack: 
;   Arg1: A character!
; On success, eax is filled with the number of bytes written, probably the
; length of the string.
; In the event that there was an error, eax will be filled with a negative
; number.

;; 
; Note, Convention for file descriptors for standard I/O:
;   stdin = 0
;   stdout = 1
;   stderr = 2
;;
      
        SECTION .data
        
SYS_WRITE       EQU      4          ; Interrupt value associated with sys_write
LINUX_SYSCALL   EQU      0x80       ; Interrupt value for the Linux Kernel
STD_OUT         EQU      1          ; stdout file handler
str:			db		 1
   
        SECTION .text
      
        global putchar_cr
        
putchar_cr:
        push    ebp		            ; set up stack frame
        mov     ebp , esp
        
        push	ebx
        push	ecx
        push	edx
        
        mov		eax , [ebp + 8]
        
        mov		[str] , al
        
        mov		edx , 1
        
        mov		ecx , str
        
        mov     ebx , STD_OUT       ; Set edx to stdout file handler, as per
                                    ; the expectations of sys_write
        mov     eax , SYS_WRITE     ; Set eax to linux kernel interrupt code for
                                    ; sys_write
        int     LINUX_SYSCALL       ; Call sys_write
        
        pop		edx
        pop		ecx
        pop		ebx
        
        mov     esp , ebp	        ; takedown stack frame
        pop     ebp
        ret
