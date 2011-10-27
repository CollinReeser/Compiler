; 1.2 2.3 + 3.4 4.5 + + 5.6 6.7 + + 7.8 + 8.9 + 10.111 +
		extern	printf
		SECTION .data
fmt:	db "%f", 10, 0
		SECTION .text
		global main
main:
	push		ebp
	mov		ebp , esp
	sub		esp , 4
	mov		[esp] , dword __float32__(1.2)
	sub		esp , 4
	mov		[esp] , dword __float32__(2.3)
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	faddp
	sub		esp , 4
	fstp		dword [esp]
	sub		esp , 4
	mov		[esp] , dword __float32__(3.4)
	sub		esp , 4
	mov		[esp] , dword __float32__(4.5)
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	faddp
	sub		esp , 4
	fstp		dword [esp]
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	faddp
	sub		esp , 4
	fstp		dword [esp]
	sub		esp , 4
	mov		[esp] , dword __float32__(5.6)
	sub		esp , 4
	mov		[esp] , dword __float32__(6.7)
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	faddp
	sub		esp , 4
	fstp		dword [esp]
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	faddp
	sub		esp , 4
	fstp		dword [esp]
	sub		esp , 4
	mov		[esp] , dword __float32__(7.8)
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	faddp
	sub		esp , 4
	fstp		dword [esp]
	sub		esp , 4
	mov		[esp] , dword __float32__(8.9)
	fld		dword [esp]
	add		esp , 4
	fld		dword [esp]
	add		esp , 4
	faddp
	sub		esp , 4
	fstp		dword [esp]
	sub		esp , 4
	mov		[esp] , dword __float32__(10.111)
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
