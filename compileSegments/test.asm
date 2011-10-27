; 12 19 8 * 2 56 * -304 2 1001 17 16 -22 3 3 12 * + * + - + * - + + + 60 12 / +
		extern	printf
		SECTION .data
fmt:	db "%d", 10, 0
		SECTION .text
		global main
main:
	push	ebp
	mov		ebp , esp
	sub		esp , 4
	mov		[esp] , dword 12
	sub		esp , 4
	mov		[esp] , dword 19
	sub		esp , 4
	mov		[esp] , dword 8
	mov		ebx , [esp]
	add		esp , 4
	mov		eax , [esp]
	add		esp , 4
	mul		ebx
	sub		esp , 4
	mov		[esp] , eax
	sub		esp , 4
	mov		[esp] , dword 2
	sub		esp , 4
	mov		[esp] , dword 56
	mov		ebx , [esp]
	add		esp , 4
	mov		eax , [esp]
	add		esp , 4
	mul		ebx
	sub		esp , 4
	mov		[esp] , eax
	sub		esp , 4
	mov		[esp] , dword -304
	sub		esp , 4
	mov		[esp] , dword 2
	sub		esp , 4
	mov		[esp] , dword 1001
	sub		esp , 4
	mov		[esp] , dword 17
	sub		esp , 4
	mov		[esp] , dword 16
	sub		esp , 4
	mov		[esp] , dword -22
	sub		esp , 4
	mov		[esp] , dword 3
	sub		esp , 4
	mov		[esp] , dword 3
	sub		esp , 4
	mov		[esp] , dword 12
	mov		ebx , [esp]
	add		esp , 4
	mov		eax , [esp]
	add		esp , 4
	mul		ebx
	sub		esp , 4
	mov		[esp] , eax
	mov		eax , [esp]
	add		esp , 4
	mov		ebx , [esp]
	add		esp , 4
	add		eax , ebx
	sub		esp , 4
	mov		[esp] , eax
	mov		ebx , [esp]
	add		esp , 4
	mov		eax , [esp]
	add		esp , 4
	mul		ebx
	sub		esp , 4
	mov		[esp] , eax
	mov		eax , [esp]
	add		esp , 4
	mov		ebx , [esp]
	add		esp , 4
	add		eax , ebx
	sub		esp , 4
	mov		[esp] , eax
	mov		ebx , [esp]
	add		esp , 4
	mov		eax , [esp]
	add		esp , 4
	sub		eax , ebx
	sub		esp , 4
	mov		[esp] , eax
	mov		eax , [esp]
	add		esp , 4
	mov		ebx , [esp]
	add		esp , 4
	add		eax , ebx
	sub		esp , 4
	mov		[esp] , eax
	mov		ebx , [esp]
	add		esp , 4
	mov		eax , [esp]
	add		esp , 4
	mul		ebx
	sub		esp , 4
	mov		[esp] , eax
	mov		ebx , [esp]
	add		esp , 4
	mov		eax , [esp]
	add		esp , 4
	sub		eax , ebx
	sub		esp , 4
	mov		[esp] , eax
	mov		eax , [esp]
	add		esp , 4
	mov		ebx , [esp]
	add		esp , 4
	add		eax , ebx
	sub		esp , 4
	mov		[esp] , eax
	mov		eax , [esp]
	add		esp , 4
	mov		ebx , [esp]
	add		esp , 4
	add		eax , ebx
	sub		esp , 4
	mov		[esp] , eax
	mov		eax , [esp]
	add		esp , 4
	mov		ebx , [esp]
	add		esp , 4
	add		eax , ebx
	sub		esp , 4
	mov		[esp] , eax
	sub		esp , 4
	mov		[esp] , dword 60
	sub		esp , 4
	mov		[esp] , dword 12
	mov		ebx , [esp]
	add		esp , 4
	mov		eax , [esp]
	add		esp , 4
	mov		edx , 0
	div		ebx
	sub		esp , 4
	mov		[esp] , eax
	mov		eax , [esp]
	add		esp , 4
	mov		ebx , [esp]
	add		esp , 4
	add		eax , ebx
	sub		esp , 4
	mov		[esp] , eax
	mov		eax , [esp]
	push	eax
	push	dword fmt
	call	printf
	add		esp , 8
	mov		esp , ebp
	pop		ebp
	mov		eax , 0
	ret
