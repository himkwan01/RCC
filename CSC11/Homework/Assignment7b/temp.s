.data
.balign 4
F: .word 0
.balign 4
in: .asciz "Input F :"
.balign 4
scan: .asciz "%d"
.balign 4
out1: .asciz "C=%d\n";

.text
	.global main
main:
	push {lr}
invalid:
	ldr r0, addr_in
	bl printf
	ldr r0, addr_scan
	ldr r1, addr_F
	bl scanf

	ldr r1, addr_F
	ldr r1, [r1]
	cmp r1, #32
	blt invalid
	ldr r1, addr_F
	ldr r1, [r1]
	ldr r2, =212
	cmp r1, r2
	bgt invalid
cvs:
	ldr r1, addr_F
	ldr r1, [r1]
	sub r1, r1, #32
	ldr r6, =0x8e38f
	mul r1, r6, r1
	asr r1, #20
output:
	ldr r0, addr_out1
	bl printf
end:
	pop {lr}
	bx lr
.global printf
.global scanf

addr_F: .word F
addr_in: .word in
addr_out1: .word out1
addr_scan: .word scan
