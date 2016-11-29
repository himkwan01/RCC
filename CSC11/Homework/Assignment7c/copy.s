.data
f: .float 212
threetwo: .float 32
five: .float 5
nine: .float 9
in1: .asciz"%fF\n"
result: .asciz"%fC\n"
sec: .asciz"%d second\n"

.text
	.global main
main:
	push {r4, lr}

	mov r0, #0			@set time
	bl time
	mov r4, r0			@r4=start
	mov r7, #0			@inner loop counter
	ldr r8, =1000000
	mov r9, #0			@outer loop counter
	ldr r10, =20

	ldr r0, addr_in1
	ldr r1, addr_f
	vldr s14, [r1]
	vcvt.f64.f32 d3, s14
	vmov r2, r3, d3
	bl printf			@output ?F
floating:
	ldr r1, addr_f
	vldr s12, [r1]
	ldr r2, addr_threetwo
	vldr s13, [r2]
	ldr r3, addr_five
	vldr s14, [r3]
	ldr r4, addr_nine
	vldr s15, [r4]

	vsub.f32 s12, s12, s13
	vmul.f32 s12, s14, s12
	vdiv.f32 s12, s12, s15

	vcvt.f64.f32 d0, s12	@calculation end

	add r7, r7, #1			@increase inner loop counter
	cmp r7, r8
	blt floating			@inner for loop
	add r9, r9, #1			@increase louter loop counter
	cmp r9, r10
	blt floating			@outer for loop

outputfloat:
	mov r0, #0
	bl time
	mov r5, r0
	sub r5, r5, r4			@difftime(end_r0, start_r4)
	ldr r0, addr_result
	vmov r2, r3, d0
	bl printf

	ldr r0, addr_sec
	mov r5, r4				@r1=difftime
	bl printf

	pop {r4, lr}
	bx lr

addr_in1: .word in1
addr_f: .word f
addr_threetwo: .word threetwo
addr_five: .word five
addr_nine: .word nine
addr_result: .word result
addr_sec: .word sec

.global time
