; Collin Reeser - October the 29th, 2011
; Link name: fputs_cr
; This is a routine that prints a string exactly as is to output, equivalent to
; the C-library function, fputs, while assuming the standard output for the FILE
; Takes one argument on the stack: 
;   Arg1: A properly null-terminated string pointer. Undefined behavior if the 
;		string is not null terminated.
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

extern  printf
      
        SECTION .data
        
SYS_WRITE       EQU      4          ; Interrupt value associated with sys_write
LINUX_SYSCALL   EQU      0x80       ; Interrupt value for the Linux Kernel
STD_OUT         EQU      1          ; stdout file handler

   
        SECTION .text
      
        global fputs_cr
        
fputs_cr:
        push    ebp		            ; set up stack frame
        mov     ebp , esp
        
        push    ebx                 ; Preserve registers
        push    ecx
        push    edx
        
        mov     ecx , [ebp + 8]     ; Get the string to be printed
        
        mov     edx , 0             ; Initialize edx counter to determine string
                                    ; length
        mov     ebx , 0             ; Initialize pointer offset for string
                                    ; length check
                                    
        mov     eax , 0             ; Zero eax for use in loop

        ;;
        ; So we need to know the length of the string before calling sys_write,
        ; so we count the bytes in the string until the null character.
        ; Clearly this solution is error prone, primarily in both assuming a 
        ; null character, which is an inherent flaw, and in this allowing for an
        ; infinite loop. A better solution is needed
        ;;
countLength:
        mov     al , [ecx + ebx]    ; With eax zeroed, we only modify the lowest
                                    ; byte of eax with the next character in the
                                    ; string
        cmp     eax , 0             ; Check if the current byte we're viewing in
                                    ; the input string is the null character yet
                                    ; and if not, increment the count
                           
        je      countEnd            ; If we are viewing the null-terminator,
                                    ; then exit the loop
        inc     ebx                 ; Increase ebx offset by 1 byte (char)
        inc     edx                 ; Increase edx, at end of loop edx will be
                                    ; the length of the string we're writing
                                                           
        jmp     countLength         ; Loop
        
countEnd:
        mov     ebx , STD_OUT       ; Set edx to stdout file handler, as per
                                    ; the expectations of sys_write
        mov     eax , SYS_WRITE     ; Set eax to linux kernel interrupt code for
                                    ; sys_write
        int     LINUX_SYSCALL       ; Call sys_write
        
        pop     edx                 ; Restore registers
        pop     ecx
        pop     ebx
        
        mov     esp , ebp	        ; takedown stack frame
        pop     ebp
        ret
