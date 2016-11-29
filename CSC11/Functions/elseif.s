	.global main
main:
	mov r1, #1 @x=1
	mov r2, #2 @y=2
	cmp r1, r2
	blt if
	bge else
if:
	mov r0, #1
	mov r2, #13
	mov r7, #4
	ldr r1, =ifs
	swi 0
	b end
else:
	mov r0, #1
	mov r2, #15
	mov r7, #4
	ldr r1, =elses
	swi 0
	b end
end:
	bx lr

.data
ifs:
.ascii "If statement\n"
elses:
.ascii "Else statemnet\n"
