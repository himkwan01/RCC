	.global main 
main: 
	mov r1, #1  @x=1
	cmp r1, #1
	beq case1
	cmp r1, #2
	beq case2
	cmp r1, #3
	beq case3
	bne default
case1:
	mov r0, #1
	mov r2, #6
	mov r7, #4
	ldr r1, =c1
	swi 0
	b end
case2:
	mov r0, #1
	mov r2, #6
	mov r7, #4
	ldr r1, =c2
	swi 0
	b end
case3:
	mov r0, #1
	mov r2, #6
	mov r7, #4
	ldr r1, =c3
	swi 0
	b end
default:
	mov r0, #1
	mov r2, #7
	mov r7, #4
	ldr r1, =def
	swi 0
	b end
end:
	bx lr
.data
c1:
.ascii "case1\n"
c2:
.ascii "case2\n"
c3:
.ascii "case3\n"
def:
.ascii "Default\n"
