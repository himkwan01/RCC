/* -- collatz02.s */
.data
.balign 4
m: .asciz "Type a number: "
.balign 4
scan: .asciz "%d"
.balign 4
m2: .asciz "Length of the Hailstone sequence for %d is %d\n"
.balign 4
sec: .asciz "%d second\n"
.text @77031
collatz:
	push {r4}
	sub sp, sp, #4
	mov r4, r0
	mov r3, #4194304
collatz_repeat:
	mov r1, r4
	mov r0, #0
collatz_loop:
	cmp r1, #1
	beq collatz_end
	and r2, r1, #1
	cmp r2, #0
	bne collatz_odd
collatz_even:
	mov r1, r1, asr #1
	b collatz_end_loop
collatz_odd:
	add r1, r1, r1, lsl #1
	add r1, r1, #1
collatz_end_loop:
	add r0, r0, #1
	b collatz_loop
collatz_end:
	sub r3, r3, #1
	cmp r3, #0
	bne collatz_repeat
	add sp, sp, #4
	pop {r4}
	bx lr
collatz2:
	push {r4}
	sub sp, sp, #4
	mov r4, r0
	mov r3, #4194304
collatz2_repeat:
	mov r1, r4
	mov r0, #0
collatz2_loop:
	cmp r1, #1
	beq collatz_end
 	and r2, r1, #1
 	cmp r2, #0
 	addne r1, r1, r1, lsl #1
	addne r1, r1, #1
	moveq r1, r1, asr #1
collatz2_end_loop:
	add r0, r0, #1
	b collatz2_loop
collatz2_end:
	sub r3, r3, #1
	cmp r3, #0
	bne collatz_repeat
	add sp, sp, #4
	pop {r4}
	bx lr

	.global main
main:
	push {lr}
	sub sp, sp, #4

	ldr r0, addr_m
 	bl printf
	ldr r0, addr_scan
 	mov r1, sp
 	bl scanf
	mov r0, #0
	bl time
	mov r5, r0
	ldr r0, [sp]
 	bl collatz
	mov r2, r0
	ldr r1, [sp]
	ldr r0, addr_m2
	bl printf

	mov r0, #0
	bl time
	sub r1, r0, r5
	ldr r0, addr_sec
	bl printf

	mov r0, #0
	bl time
	mov r5, r0
	ldr r0, [sp]
	bl collatz2
	mov r2, r0
	ldr r1, [sp]
	ldr r0, addr_m2
	bl printf
	mov r0, #0
	bl time
	sub r1, r0, r5
	ldr r0, addr_sec
	bl printf

	add sp, sp, #4
	pop {lr}
	bx lr

addr_m: .word m
addr_m2: .word m2
addr_scan: .word scan
addr_sec: .word sec
.global time
.global printf
.global scanf
