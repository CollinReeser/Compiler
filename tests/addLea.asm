
        SECTION .data
        
        SECTION .text

		global addLea

addLea:

		push    ebp		            ; set up stack frame
        mov     ebp , esp
        
        mov		eax , [ebp + 8]
        mov		ebx	, [ebp + 12]
        lea		eax , [eax+ebx]
        	
        mov     esp , ebp	        ; takedown stack frame
        pop     ebp
        ret
