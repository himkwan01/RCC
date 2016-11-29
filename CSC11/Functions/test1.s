	.global _start
_start:
read:
	mov r0, #0
	mov r7, #3
	mov r2, #1
	ldr r1, =string
	swi 0
load:
	ldr r2, =input
	cmps [r1],[r2]
	beq true
	bne false
true:
	mov r0, #1
	mov r7, #4
	mov r2, #4
	ldr r1, =t
	swi 0
false:
	mov r0, #1
	mov r7, #4
	mov r2, #5
	ldr r1, =f
	swi 0
exit:
	mov r7, #1
	swi 0
.data
t:
.ascii "true"
f:
.ascii "false"
