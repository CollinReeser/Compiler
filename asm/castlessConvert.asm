; Name: fltBitsToInt
; Description: This program takes in a float as a parameter, and then forces
; the return value to be an integer that simply contains the bits of the float
; passed, without cast-converting it

		global	fltBitsToInt
		
		SECTION .data
		SECTION .text


fltBitsToInt:
		push	ebp					; Setup stack frame
		mov		ebp , esp
		mov		eax , [ebp+8]		; Get the return value in eax
		mov     esp , ebp	        ; takedown stack frame
        pop     ebp
        ret
