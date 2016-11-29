.data
.align 4
iarr: .skip 2047	@int
.align 4
printi: .asciz"int %d\n"

.text
	.global main
main:
	push {lr}
	/* r5=iarr, r3=int, r7=5/9 */
	ldr r7, =0x8e38f

fill:
	mov r3, #32		@init
	ldr r5, addr_iarr
	mov r11, #0		@index counter
fill_loop:
	str r3, [r5, r11, lsl #2]
	add r3, r3, #5	@temp+5
	add r11, r11, #1	@increase counter
	cmp r11, #37
	blt fill_loop
	mov r11, #0		@reset counter
print_int_loop:
	ldr r0, =printi
	ldr r1, [r5, r11, lsl #2]
	bl printf
	add r11, r11, #1
	cmp r11, #37	@int i=0;i<37;i++
	blt print_int_loop
	mov r11, #0
cov_int_loop:
	ldr r3, [r5, r11, lsl #2]
	sub r3, r3, #32
	mul r3, r7, r3
	mov r3, r3, asr #20
	str r3, [r5, r11, lsl #2]
	add r11, r11, #1
	cmp r11, #37
	blt cov_int_loop
	mov r11, #0

print_cov_int:
	ldr r1, [r5, r11, lsl #2]
	ldr r0, =printi
	bl printf
	add r11, r11, #1
	cmp r11, #37
	blt print_cov_int

end:
	pop {lr}
	bx lr

addr_iarr: .word iarr

