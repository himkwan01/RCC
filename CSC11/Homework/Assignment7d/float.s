.data

f:.asciz"%fF\n"
c:.asciz"%fC\n"

.align 4
five: .float 5.0
.align 4
nine: .float 9.0
.align 4
threetwo: .float 32.0
.align 4
farr:.skip 1024

.text
	.global main
main:
	push {r4,lr}
	/* s14=float, s12=32, s11=9, s10=5, s13=temp */

	mov r8, #32
	ldr r1, =threetwo
	vldr s3, [r1]

	ldr r1, =five
	vldr s9, [r1]

	ldr r1, =nine
	vldr s31, [r1]

	ldr r6, addr_farr
	mov r11,#0

	/*vcvt.f64.f32 d10, s9
	vmov r2, r3, d10
	ldr r0, =f
	bl printf*/
fill:
	vmov s0, r8
	vcvt.f32.s32 s1, s0
	vmov r7, s1
	str r7, [r6, r11, lsl #2]


	add r11, r11, #1
	add r8, r8, #5
	cmp r8, #212
	ble fill

	mov r11,#0	@reset
print_farr:
	ldr r1,[r6,r11,lsl#2]
	vmov s14,r1

	vcvt.f64.f32 d5,s14
	vmov r2,r3,d5
	ldr r0,=f		@out in array
	bl printf
	add r11, r11, #1
	cmp r11, #37
	blt print_farr

	mov r11, #0
cov:
	ldr r1, [r6, r11, lsl #2]
	vmov s14, r1
	vsub.f32 s14, s14, s3
	vmul.f32 s14, s14, s9
	vdiv.f32 s14, s14, s31
	vmov r1, s14
	str r1, [r6, r11, lsl #2]
	add r11, r11, #1
	cmp r11, #37
	blt cov

	mov r11, #0
print_cov:
	ldr r1, [r6, r11, lsl #2]
	vmov s14, r1
	vcvt.f64.f32 d5, s14
	vmov r2, r3, d5
	ldr r0, =c
	bl printf
	add r11, r11, #1
	cmp r11, #37
	blt print_cov

	pop {r4,lr}
	bx lr



addr_f:.word f
addr_c:.word c
addr_farr:.word farr

.global printf
.global scanf
