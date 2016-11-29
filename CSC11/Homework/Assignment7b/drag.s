.data
.balign 4
m1:.asciz"Integer Dynamic Pressure=%d lbs\n"
.balign 4
m2:.asciz"Cross Sectional Area*32 =%d fit^2\n"
.balign 4
m3:.asciz"Integer Drag*32=%d lbs\n"
.balign 4
in1:.asciz"Enter the v\n"
.balign 4
in2:.asciz"Enter the radius\n"
.balign 4
scan:.asciz"%d"
.balign 4
v:.word 0
.balign 4
r:.word 0

.text
	.global main
main:
	push {lr}

	ldr r0,addr_in1
	bl printf

	ldr r0,addr_scan
	ldr r1,addr_v
	bl scanf

	ldr r0,addr_in2
	bl printf

	ldr r0, addr_scan
	ldr r1,addr_r
	bl scanf

	mov r3,#1		@1 bit, >>1
	ldr r4,=0x9b5		@12bit >>20
	ldr r5,addr_v
	ldr r5,[r5]			@8bit
	ldr r6,=0x3243f7 	@24bit >>20

	ldr r7,addr_r
	ldr r7,[r7]

	ldr r8,=0x1c7 	@12bit >>12bit
	ldr r9,=0x666 	@12bit >>12bit

	mul r3,r4,r3    @12 bit bp -21
	mul r3,r5,r3    @20 bit bp-21
	mul r3,r5,r3    @28 bit bp-21
	asr r3,#12      @16 bit bp-9, idynp
	mul r6,r7,r6    @28 bit bp-20
	mul r6,r7,r6    @32 bit bp-20
	asr r6,#12      @20 bit bp-8
	mul r6,r8,r6    @32 bit bp-20
	asr r6,#16      @16 bit bp-8, iarea
	mul r10,r3,r6   @32 bit bp-17
	asr r10, #12    @20 bit bp-5
	mul r10,r9,r10  @32 bit bp-17, idrag

	asr r3,#9
	asr r6,#3
	asr r10,#12

	ldr r0,addr_m1
	mov r1,r3
	bl printf


	ldr r0,addr_m2
	mov r1,r6
	bl printf

	ldr r0,addr_m3
	mov r1,r10
	bl printf


	pop {lr}
	bx lr

.global printf
.global scanf

addr_m1:.word m1
addr_m2:.word m2
addr_m3:.word m3
addr_in1:.word in1
addr_in2:.word in2
addr_scan:.word scan
addr_v:.word v
addr_r:.word r
