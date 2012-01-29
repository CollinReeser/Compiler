; 1 2 / 3 * 4.5 + 6 3 / - 8.625 3 * + 2.5 3.4 1.25 / + - 8.2 +
; 31.355
		extern	printf
		SECTION .data
fmt:	db "%f", 10, 0
		SECTION .text
		global main
main:
	push		ebp
	mov		ebp , esp
	sub		esp , 4
	mov		[esp] , qword __float64__(1.0)
	sub		esp , 4
	mov		[esp] , qword __float64__(2.0)
	mov		ebx , [esp]
	add		esp , 4
	mov		eax , [esp]
	add		esp , 4
	mov		edx , 0
	div		ebx
	sub		esp , 4
	mov		[esp] , eax
	sub		esp , 4
	mov		[esp] , qword __float64__(3.0)
	mov		ebx , [esp]
	add		esp , 4
	mov		eax , [esp]
	add		esp , 4
	mul		ebx
	sub		esp , 4
	mov		[esp] , eax
	sub		esp , 4
	mov		[esp] , qword __float64__(4.5)
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	faddp
	sub		esp , 4
	fstp		dword [esp]
	sub		esp , 4
	mov		[esp] , qword __float64__(6.0)
	sub		esp , 4
	mov		[esp] , qword __float64__(3.0)
	mov		ebx , [esp]
	add		esp , 4
	mov		eax , [esp]
	add		esp , 4
	mov		edx , 0
	div		ebx
	sub		esp , 4
	mov		[esp] , eax
	mov		ebx , [esp]
	add		esp , 4
	mov		eax , [esp]
	add		esp , 4
	sub		eax , ebx
	sub		esp , 4
	mov		[esp] , eax
	sub		esp , 4
	mov		[esp] , qword __float64__(8.625)
	sub		esp , 4
	mov		[esp] , qword __float64__(3.0)
	mov		ebx , [esp]
	add		esp , 4
	mov		eax , [esp]
	add		esp , 4
	mul		ebx
	sub		esp , 4
	mov		[esp] , eax
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	faddp
	sub		esp , 4
	fstp		dword [esp]
	sub		esp , 4
	mov		[esp] , qword __float64__(2.5)
	sub		esp , 4
	mov		[esp] , qword __float64__(3.4)
	sub		esp , 4
	mov		[esp] , qword __float64__(1.25)
	mov		ebx , [esp]
	add		esp , 4
	mov		eax , [esp]
	add		esp , 4
	mov		edx , 0
	div		ebx
	sub		esp , 4
	mov		[esp] , eax
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	faddp
	sub		esp , 4
	fstp		dword [esp]
	mov		ebx , [esp]
	add		esp , 4
	mov		eax , [esp]
	add		esp , 4
	sub		eax , ebx
	sub		esp , 4
	mov		[esp] , eax
	sub		esp , 4
	mov		[esp] , qword __float64__(8.2)
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	faddp
	sub		esp , 4
	fstp		dword [esp]
	fld		dword [esp]
	fstp		qword [esp]
	push		dword fmt
	call		printf
	add		esp , 8
	mov		esp , ebp
	pop		ebp
	mov		eax , 0
	ret
