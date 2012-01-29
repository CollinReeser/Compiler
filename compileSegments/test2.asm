; 1 2 / 3 * 4.5 + 6 3 / - 8.625 3 * + 2.5 3.4 1.25 / + - 8.2 +
; 31.355 - Note that the actual output is probably more accurate than this
		extern	printf
		SECTION .data
fmt:	db "%f", 10, 0
		SECTION .text
		global main
main:
	push	ebp
	mov		ebp , esp
	sub		esp , 4
	mov		[esp] , dword __float32__(1.0)
	sub		esp , 4
	mov		[esp] , dword __float32__(2.0)
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	fxch
	fdivp
	sub		esp , 4
	fstp	dword [esp]
	sub		esp , 4
	mov		[esp] , dword __float32__(3.0)
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	fmulp
	sub		esp , 4
	fstp	dword [esp]
	sub		esp , 4
	mov		[esp] , dword __float32__(4.5)
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	faddp
	sub		esp , 4
	fstp	dword [esp]
	sub		esp , 4
	mov		[esp] , dword __float32__(6.0)
	sub		esp , 4
	mov		[esp] , dword __float32__(3.0)
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	fxch
	fdivp
	sub		esp , 4
	fstp	dword [esp]
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	fxch
	fsubp
	sub		esp , 4
	fstp	dword [esp]
	sub		esp , 4
	mov		[esp] , dword __float32__(8.625)
	sub		esp , 4
	mov		[esp] , dword __float32__(3.0)
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	fmulp
	sub		esp , 4
	fstp	dword [esp]
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	faddp
	sub		esp , 4
	fstp	dword [esp]
	sub		esp , 4
	mov		[esp] , dword __float32__(2.5)
	sub		esp , 4
	mov		[esp] , dword __float32__(3.4)
	sub		esp , 4
	mov		[esp] , dword __float32__(1.25)
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	fxch
	fdivp
	sub		esp , 4
	fstp	dword [esp]
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	faddp
	sub		esp , 4
	fstp	dword [esp]
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	fxch
	fsubp
	sub		esp , 4
	fstp	dword [esp]
	sub		esp , 4
	mov		[esp] , dword __float32__(8.2)
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	faddp
	sub		esp , 4
	fstp	dword [esp]
	fld		dword [esp]
	fstp	qword [esp]
	push	dword fmt
	call	printf
	add		esp , 8
	mov		esp , ebp
	pop		ebp
	mov		eax , 0
	ret
