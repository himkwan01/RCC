.data
half: .float 0.5
threetwo: .float 32
rho: .float 0.00237	/* slug/ft^3 */
vel: .word 0		/* velocity */
rad: .word 00237	/* radius */
pi: .float 3.1415926
conv: .float 0.006944444
cd: .float 0.4
scan: .asciz "%f"
in1: .asciz"v="
in2: .asciz"r="
outdynp: .asciz "Floating Dynamic Pressure = %f (lbs)\n";
outarea: .asciz "Cross Section Area x32 = %f (ft^2)\n"
outdrag: .asciz "Floating Drag x 32 = %f (lbs)\n"

.text
	.global main
main:
	push {r4, lr}
	ldr r0, =in1
	bl printf		@output v prompt
	ldr r0, addr_scan
	ldr r1, addr_vel
	bl scanf
	ldr r0, =in2		@output r prompt
	bl printf
	ldr r0, addr_scan
	ldr r1, addr_rad
	bl scanf

	/* dynamic pressure */
	ldr r1, addr_vel	@v
	vldr s5, [r1]		@s1 =v
	ldr r1, addr_half
	vldr s6, [r1]		@s2=0.5
	ldr r1, addr_rho
	vldr s4, [r1]

	vmul.f32 s5, s4, s5	@s5=0.5 rho
	vmul.f32 s4, s5, s6	@s4=0.5 rho * v
	vmul.f32 s4, s4, s5	@s4=0.5 rho * v^2 (dynamic pressure)

	/* area */
	ldr r1, addr_pi
	vldr s7, [r1]		@s7=pi
	ldr r1, addr_rad
	vldr s8, [r1]		@s8=rad
	ldr r1, addr_conv
	vldr s9, [r1]		@s9=conv

	vmul.f32 s6, s7, s8	@s6=pi*rad
	vmul.f32 s6, s6, s8	@s6=pi*rad^2
	vmul.f32 s6, s6, s9	@s6=pi*rad^2*conv

	/* Drag */
	ldr r1, addr_cd
	vldr s3, [r1]		@s3=Cd

	vmul.f32 s8, s4, s6	@s2=dynp*area
	vmul.f32 s8, s8, s3	@s2=dynp*area*Cd

	/* x32 */
	ldr r1, addr_threetwo
	vldr s5, [r1]		@s5=32
	vmul.f32 s8, s8, s5	@dragx32
	vmul.f32 s6, s6, s5	@areax32

	vcvt.f64.f32 d15, s8
	vcvt.f64.f32 d14, s6
	vcvt.f64.f32 d13, s4
Output:
	ldr r0, addr_outdynp
	vmov r2, r3, d13
	bl printf

	ldr r0, addr_outarea
	vmov r2, r3, d14
	bl printf

	ldr r0, addr_outdrag
	vmov r2, r3, d15
	bl printf

end:
	pop {r4, lr}
	bx lr

addr_half: .word half
addr_threetwo: .word threetwo
addr_rho: .word rho
addr_vel: .word vel
addr_rad: .word rad
addr_pi: .word pi
addr_conv: .word conv
addr_cd: .word cd
addr_scan: .word scan
addr_outdynp: .word outdynp
addr_outarea: .word outarea
addr_outdrag: .word outdrag
