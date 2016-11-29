	.global main
main:
	mov r0, #1 @x=1
	mov r1, #2 @y=2
	cmp r0, r1
	blt true
	bge false
true:
	mov r0, #1
	mov r7, #4
	mov r2, #4
	ldr r1, =t
	swi 0
	b end
false:
	mov r0, #1
	mov r7, #4
	mov r2, #5
	ldr r1, =f
	swi 0
	b end
end:
	bx lr

.data
t:
.ascii "True"
f:
.ascii "False"
