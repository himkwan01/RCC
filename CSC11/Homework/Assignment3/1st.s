	.global main
main:
	mov r2, #111
	mov r3, #5
	mov r4, #0
	mov r0, #0
	mov r1, r2
	cmp r1, r3
	bge subtract
	blt swapchk

subtract:
	add r0, r0, #1
	sub r1, r1, r3
	cmp r1, r3
	bge subtract
	blt swapchk
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
