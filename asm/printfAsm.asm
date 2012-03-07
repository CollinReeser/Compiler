; Name: printf
; Dexcription: This assembly program emulates the behavior of the printf C 
; library function.
; Parameters: At [ebp + 8]: The pointer to a control string to use. This control
; string has already been converted by the compiler, such that \n is 10 in the
; character array, and the % control codes have been converted to their
; respective control values. See below for a table of the control values and
; escape codes
;			At [ebp+...]: It is EXPECTED on the stack that there will be values
; corrosponding to each of the control codes in the control string. If a %c is
; the only thing in the control string, then there should be a char at [ebp+9].
; If there was then also a %d for an integer after the %c in the control string,
; there should be an integer at [ebp+13] on the stack. Etc.
; Return parameters: None.
;
; NOTE: This doesn't work at all. Not even a little. Nope. And is also probably
; identical to printf.asm and should be removed. They should both be removed
; probably definitely.
;

; %s should be converted to -1
; %d should be converted to -2
; %f should be converted to -3
; %c should be converted to -4

		global	printfAsm_cr
		extern	fputs_cr
		extern	printf 		; For tests

		SECTION .data
str:	equ		-1
num:	equ		-2
flt:	equ		-3
chr:	equ		-4

		SECTION .bss
ctrl:	resw	1		; Holds the pointer to the control string
temp:	resb	2		; Holds a temp character in the first index, and a null
						; character in the second
		SECTION .text

printfAsm_cr:
		push	ebp					; Setup stack frame
		mov		ebp , esp
		mov		eax , [ebp + 8]		; Get the pointer to the control string and
		mov		[ctrl] , eax		; store it in ctrl
		
		; TESTS
		mov		eax , [ctrl]
		push	eax
		;call	printf
		add		esp , 4
		
		
		
		mov		eax , 0
		mov		[temp+1] , al		; Initialize the null character in the temp,
									; al is a byte (char) register within eax
		
		; Initialize counters and stuff for moving through the format string
		; eax is already 0, and will be used to hold the characters in the
		; control string as each is retrieved
		mov		ebx , 8				; ebx will be used to point to the current
									; thing in the parameter list. By
									; initializing to point to the format string
									; every time a new control code is
									; ecountered in the format string, the
									; length of the type to be printed will be
									; added to ebx before ebx is used to index
									; into the stack for the parameter
		mov		ecx , 0				; ecx will be used to loop through the
									; control string characters	
		
									
									
.loopCtrlStr:							
		mov     al , [ctrl + ecx]	; With eax zeroed, we only modify the lowest
                                    ; byte of eax with the next character in the
                                    ; string
		cmp     eax , 0             ; Check if the current byte we're viewing in
                                    ; the control string is the terminator
		je		.ctrlEnd
		cmp		eax , str			; Check if we need to print a string
									; parameter
		je		.strHandler
		cmp		eax , num			; Check if we need to print an integer
		je		.numHandler
		cmp		eax , flt			; Check if we need to print a float
		je		.fltHandler
		cmp		eax , chr			; Check if we need to print a char
		je		.chrHandler
		
		; Else, we are just printing a character
		
		mov		[temp] , al
		push	temp
		call	fputs_cr
		add		esp , 4
		
.loopWork:							; Here we increment the loop counter
		inc		ecx
		jmp		.loopCtrlStr
		
		
.strHandler:


.numHandler:
		
		
.fltHandler:
		
	
.chrHandler:
		
		
		
		
.ctrlEnd:		
		
		
		mov     esp , ebp	        ; takedown stack frame
        pop     ebp
        ret
