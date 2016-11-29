/* F to C */
.data
.balign 4
scan:.asciz "%d"
.balign 4
F: .word 0
.balign 4
intro: .asciz "Please enter Fahrenheit\n";
.balign 4
output: .asciz "Celsius is %d\n"
.balign 4
sec: .asciz "time=%d\n"
.text
	.global main
main:
	push {lr}
loop:
	ldr r0, addr_intro
	bl printf
	ldr r0, addr_scan
	ldr r1, addr_F
	bl scanf
	ldr r1, addr_F
	ldr r1, [r1]
	cmp r1, #32
	blt loop
	ldr r1, addr_F
	ldr r1,[r1]
	cmp r1, #212
	bgt loop
	mov r0, #0
	bl time
	mov r4, r0
	mov r7, #0
	ldr r8, =1000000
	mov r9, #0
	ldr r10, =20
divTime:
	ldr r1, addr_F
	ldr r1, [r1]
	sub r1, r1, #32
	mov r2, #5
	mul r1, r2, r1
	mov r2, #9
	bl divMod
	mov r1, r0
	add r7, r7, #1
	cmp r7, r8
	blt divTime
	mov r7, #0
	add r9, r9, #1
	cmp r9, r10
	blt divTime
	/* end loop */
	mov r1, r0
	ldr r0, addr_output
	bl printf
	mov r0, #0
	bl time
	mov r5, r0	/* time=r5-r4 */
	ldr r0, addr_sec
	sub r1, r5, r4
	bl printf

	/* shifting int */
	mov r0, #0
	bl time
	mov r4, r0
	mov r7, #0
	mov r9, #0
shifting:
	ldr r1, addr_F
	ldr r1, [r1]
	sub r1, r1, #32
	ldr r6, =0x8e38f
	mul r1, r6, r1
	asr r1, #20
	add r7, r7, #1
	cmp r7, r8
	blt shifting
	mov r7, #0
	add r9, r9, #1
	cmp r9, r10
	blt shifting
	/* end loop */
	ldr r0, addr_output
	bl printf
	mov r0, #0
	bl time
	sub r1, r0, r4
	ldr r0, addr_sec
	bl printf
/* end */
	pop {lr}
	bx lr
scaleRight:
	push {lr}
doWhile_r1_lt_r2:
	mov r3,r3,asr #1
	mov r2,r2,asr #1
	cmp r1,r2
	blt doWhile_r1_lt_r2
	pop {lr}
    bx lr

addSub:
	push {lr}
doWhile_r3_ge_1:
	add r0,r0,r3
	sub r1,r1,r2
	bl scaleRight
	cmp r3,#1
	bge doWhile_r3_ge_1
    pop {lr}
    bx lr

scaleLeft:
	push {lr}
doWhile_r1_ge_r2:
	mov r3,r3,lsl #1
	mov r2,r2,lsl #1
	cmp r1,r2
	bge doWhile_r1_ge_r2
	mov r3,r3,asr #1
	mov r2,r2,asr #1
	pop {lr}
    bx lr 

divMod:
	push {lr}
	mov r0,#0
	mov r3,#1
	cmp r1,r2
	blt end
	bl scaleLeft
	bl addSub
end:
	pop {lr}
    bx lr

addr_intro: .word intro
addr_F: .word F
addr_output: .word output
addr_scan: .word scan
addr_sec: .word sec
.global printf
.global scanf
.global time
