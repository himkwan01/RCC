/* Efficient technique for calculating a/b and a%b */

.data

.balign 4
in1:
.asciz "Please enter a\n"
.balign 4
in2:
.asciz "Please enter b\n"

/* output text */
.balign 4
output1:
.asciz "Calculated %d/%d = %d\n"

.balign 4
output2:
.asciz "Calculated %d%%%d is %d\n"

.balign 4
scan:
.asciz "%d"

/*store a b*/
.balign 4
a: .word 0
.balign 4
b: .word 0

.text
/* function divMod */
divMod:
	push {lr}
	mov r0, #0
	mov r3, #1
	cmp r1, r2
	bge greater
	b dend
greater:
	bl scaleLeft
	bl addSub
	b dend
dend:
	pop {lr}
	bx lr
<<<<<<< HEAD

/* function scaleLeft */
scaleLeft:
	push {r4, lr}
sLstart:
	mov r3, r3, lsl #1
	mov r2, r2, lsl #1
	cmp r1, r2
	bge sLstart
	mov r3, r3, lsr #1
	mov r2, r2, lsr #1
	pop {r4, lr}
	bx lr

/* fucntion scaleRight */
scaleRight:
	push {r4, lr}
sRstart:
	mov r3, r3, lsr #1
	mov r2, r2, lsr #1
	cmp r1, r2
	blt sRstart
	pop {r4, lr}
	bx lr

/* function addSub */
addSub:
	push {r4, lr}
aSstart:
	add r0, r0, r3
	sub r1, r1, r2
	bl scaleRight
	cmp r3, #1
	bge aSstart
	pop {r4, lr}
=======
	
/* function scaleLeft */
scaleLeft:
	push {lr}
startL:
	mov r3, r3, lsl #1
	mov r2, r2, lsl #1
	cmp r1, r2
	bge startL
	mov r3, r3, lsr #1
	mov r3, r3, lsr #1
	pop {lr}
	bx lr

/* function addSub */
addSub:
	push {lr}
startaS:
	add r0, r0, r3
	sub r1, r1, r2
	bl scaleRight
	cmp r3, #1
	bge startaS
	pop {lr}
	bx lr

/* function scaleRight */
scaleRight:
	push {lr}
startR:
	mov r3, r3, lsr #1
	mov r2, r2, lsr #1
	cmp r1, r2
	blt startR
	pop {lr}
>>>>>>> 900cce10a4ad1994ea1765030d03284fdcbf6687
	bx lr


	.global main
main:
	push {lr}
	/* intput */
	ldr r0, addr_in1
	bl printf
	ldr r0, addr_scan
	ldr r1, addr_a
	bl scanf

	ldr r0, addr_in2
	bl printf
	ldr r0, addr_scan
	ldr r1, addr_b
	bl scanf
	/* call function */
	ldr r1, addr_a
	ldr r1, [r1]
	ldr r2, addr_b
	ldr r2, [r2]
	bl divMod

	/* output */
	mov r5, r1
	mov r3, r0
	ldr r0, addr_output1
	ldr r1, addr_a
	ldr r1, [r1]
	ldr r2, addr_b
	ldr r2, [r2]
	bl printf
	mov r3, r5
	ldr r0, addr_output2
	ldr r1, addr_a
	ldr r1, [r1]
	ldr r2, addr_b
	ldr r2, [r2]
	bl printf
	/* exit */
	pop {lr}
	bx lr

addr_a: .word a
addr_b: .word b
addr_scan: .word scan
addr_in1: .word in1
addr_in2: .word in2
addr_output1: .word output1
addr_output2: .word output2

/* external */
.global printf
.global scanf
