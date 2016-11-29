/* Efficient technique for calculating a/b and a%b */

.data

/* input */

.balign 4
intro:
.asciz "Efficient technique for calculating a/b and a%b\n"

.balign 4
in1:
.asciz "Please enter a\n"

.balign 4
in2:
.asciz "Please enter b\n"

/* output text */

.balign 4
output1:
.asciz "%d/%d is %d\n"

.balign 4
output2:
.asciz "%d%%%d is %d\n"

.balign 4
scan:
.asciz "%d"

/*store a b*/
.balign 4
a: .word 0
.balign 4
b: .word 0

.balign 4
return: .word 0
.balign 4
return2: .word 0
.text

/* function divMod */
divMod:
	ldr r1, addr_return2
	str lr, [r1]
	ldr r2, addr_a
	ldr r2, [r2]
	ldr r3, addr_b
	ldr r3, [r3]
	mov r4, #1
	mov r5, r3
	mov r0, #0
	mov r1, r2

	cmp r1, r3
	bge scaleLeft1
	blt end
scaleLeft1:
	mov r4, r4, LSL #1
	mov r5, r5, LSL #1
	cmp r1, r5
	bgt scaleLeft1
	ble scaleLeft2
scaleLeft2:
	mov r4, r4, LSR #1
	mov r5, r5, LSR #1
	b addSub1
scaleRight:
	mov r4, r4, LSR #1
	mov r5, r5, LSR #1
	cmp r1, r5
	blt scaleRight
	bge addSub2
addSub1:
	add r0, r0, r4
	sub r1, r1, r5
	b scaleRight
addSub2:
	cmp r4, #1
	bge addSub1
	blt end
end:
	ldr lr, addr_return2
	ldr lr, [lr]
	bx lr

	.global main
main:
	ldr r1, addr_return
	str lr, [r1]
	/* intput */
	ldr r0, addr_intro
	bl printf
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
	ldr r0, addr_a
	ldr r0, [r0]
	ldr r1, addr_b
	ldr r1, [r1]
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
	ldr lr, addr_return
	ldr lr, [lr]
	bx lr

addr_a: .word a
addr_b: .word b
addr_scan: .word scan
addr_intro: .word intro
addr_in1: .word in1
addr_in2: .word in2
addr_output1: .word output1
addr_output2: .word output2
addr_return: .word return
addr_return2: .word return2
.global printf
.global scanf
