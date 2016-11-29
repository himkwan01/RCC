.data
f: .word 0
threetwo: .float 32
five: .float 5
nine: .float 9
in1: .asciz"Input F\n"
scan: .asciz"%f"
result: .asciz"%fC\n"

.text
	.global main
main:
	push {r4, lr}

	ldr r0, addr_in1
	bl printf

	ldr r0, addr_scan
	ldr r1, addr_f
	bl scanf

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

	vcvt.f64.f32 d0, s12

	ldr r0, addr_result
	vmov r2, r3, d0
	bl printf

	pop {r4, lr}
	bx lr

addr_in1: .word in1
addr_f: .word f
addr_threetwo: .word threetwo
addr_five: .word five
addr_nine: .word nine
addr_scan: .word scan
addr_result: .word result
