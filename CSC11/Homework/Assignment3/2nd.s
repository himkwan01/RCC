/*
	find a/b a%b
	a/b -> counter contained in r0
	a%b -> remainder contained in r1
	a -> contained in r2
	b -> contained in r3
	flag -> r4 to reverse contents of r0 and r1
	temp -> r5 position to swap registers
	s -> r6 has the present scale 10^
	sf -> r7 scale factor = r3*r6 to subtract
	factor -> r8 shift factor 10
	shift -> r9 Shift test r7*r8
*/

	.global main
main:

	mov r2, #222      @a=222
	mov r3, #5        @b=5
	mov r4, #0        @swap flag
	mov r5, #0        @temp
	mov r6, #0        @present scale
	mov r7, #0        @scale factor
	mov r8, #10       @shift factor
	mov r9, #0        @shift test
	mov r0, #0        @
	mov r1, r2
	b divmod1
divmod1:
	cmp r1, r3
	bge scale
	blt swapchk
scale:
	mov r6, #1
	mul r7, r3, r6
	mul r9, r7, r8
	cmp r1, r9
	bgt shift
	ble divmod2
shift:
	mul r5, r6, r8
	mov r6, r5
	mul r7, r3, r6
	mul r9, r7, r8
	b divmod2
divmod2:
	add r0, r0, r6
	sub r1, r1, r7
	cmp r1, r7
	bge divmod2
	blt divmodchk
divmodchk:
	cmp r6, #1
	bgt scale
	ble swapchk
swapchk:
	cmp r4, #0
	beq swap
	bne end
swap:
	mov r5, r0
	mov r0, r1
	mov r1, r5
	b end
end:
	bx lr
