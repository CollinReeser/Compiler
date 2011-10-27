



		global testsLea
		
testsLea:

		push    ebp		            ; set up stack frame
        mov     ebp , esp
        mov		eax , 5
        div		
        	
        mov     esp , ebp	        ; takedown stack frame
        pop     ebp
        ret
