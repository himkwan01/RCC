/* CSC 11 midterm */
/* Tsz, Kwan */
/* 10/20/14 */

.data
/* Menu */
.balign 4
intro: .asciz "Menu\n"
.balign 4
inA: .asciz "Press 1 to run prog1\n"
.balign 4
inB: .asciz "Press 2 to run prog2\n"
.balign 4
inC: .asciz "Press 3 to run prog3\n"
.balign 4
scanMenu: .asciz "%d"
.balign 4
choice: .word 0
.balign 4
repeat: .asciz "Input %d to run prog%d\n"
.balign 4
exit: .asciz "Press %d to exit\n"

/* prog 1 data */
.balign 4
p1m1: .asciz "Please enter the hours worked and rate of pay\n"
.balign 4
p1m2: .asciz "The gross pay is $%d\n"
.balign 4
hr: .word 0
.balign 4
payrt: .word 0
.balign 4
p1scan: .asciz "%d %d";
.balign 4
p1m3: .asciz "Invalid input\n"

/* prog 2 data */
.balign 4
p2m1: .asciz "Input the plan(a,b,c) and hours with space\n"
.balign 4
p2m2: .asciz "The total cost is $%d\n"
.balign 4
p2m3: .asciz "invalid\n"
.balign 4
package: .word 0
.balign 4
p2hr: .word 0
.balign 4
p2scanS: .asciz "%s"
.balign 4
p2scan: .asciz "%d"
.balign 4
a: .asciz "a"
.balign 4
b: .asciz "b"
.balign 4
c: .asciz "c"

/* prog 3 data */
.balign 4
p3m1: .asciz "Which terms do you want to ouptut?\n"
.balign 4
num: .word 0
.balign 4
p3scan: .asciz "%d"
.balign 4
p3m2: .asciz "%d term of Fibonacci sequence is %d\n"

.text
/* menu */
	.global main
main:
	push {lr}
menu:
	ldr r0, addr_intro
	bl printf
	ldr r0, addr_inA
	bl printf
	ldr r0, addr_inB
	bl printf
	ldr r0, addr_inC
	bl printf
	ldr r0, addr_scanMenu
	ldr r1, addr_choice
	bl scanf
	ldr r0, addr_repeat
	ldr r1, addr_choice
	ldr r1, [r1]
	ldr r2, addr_choice
	ldr r2, [r2]
	bl printf
	ldr r1, addr_choice
	ldr r1,[r1]
	cmp r1, #1
	beq c1
	cmp r1, #2
	beq c2
	cmp r1, #3
	beq c3
	bgt end
c1:
	bl prog1
	b menu
c2:
	bl prog2
	b menu
c3:
	bl prog3
	b menu
end:
	ldr r0, addr_exit
	bl printf
	pop {lr}
	bx lr

/* prog 1 text */
prog1:
	push {lr}
	mov r3, #0
	ldr r0, addr_p1m1
	bl printf
	ldr r0, addr_p1scan
	ldr r1, addr_hr
	ldr r2, addr_payrt
	bl scanf
	ldr r1, addr_hr
	ldr r1, [r1]
	ldr r2, addr_payrt
	ldr r2, [r2]
	cmp r1, #0
	blt invalid
	cmp r1, #20
	ble normal
	cmp r1, #40
	ble double
	cmp r1, #60
	ble triple
	bgt invalid
normal:
	mul r0, r1, r2
	b p1end
double:
	mov r3, #20
	ldr r1, addr_hr
	ldr r1, [r1]
	sub r1, r1, #20
	ldr r2, addr_payrt
	ldr r2, [r2]
	mul r0, r2, r3       /* r2*20 */
	mov r2, r2, lsl #1   /* rt*2 */
	mul r1, r2, r1
	add r0, r0, r1
	b p1end
triple:
	mov r3, #60         /* 20*rt+20*rt*2=60*rt */
	mul r0, r2, r3      /* r0=rtpay*60 */
	sub r1, r1, #40
	mov r3, #3
	mul r1, r3, r1
	mul r1, r2, r1
	add r0, r0, r1
	b p1end
invalid:
	ldr r0, addr_p1m3
	bl printf
	b p1end
p1end:
	mov r1, r0
	ldr r0, addr_p1m2
	bl printf
	pop {lr}
	bx lr

/* prog 2 text */
prog2:
	push {lr}
	ldr r0, addr_p2m1
	bl printf

	ldr r0, addr_p2scanS
	ldr r1, addr_package
	bl scanf

	ldr r0, addr_p2scan
	ldr r1, addr_p2hr
	bl scanf

	ldr r0, addr_a
	ldr r1, addr_package
	bl strcmp
	beq caseA

	ldr r0, addr_b
	ldr r1, addr_package
	bl strcmp
	beq caseB

	ldr r0, addr_c
	ldr r1, addr_package
	bl strcmp
	beq caseC

caseA:
	ldr r2, addr_p2hr
	ldr r2, [r2]
	mov r0, #30
	cmp r2, #0
	blt p2invalid
	cmp r2, #11
	ble p2end
	cmp r2, #22
	ble addA1
	blt addA2

caseB:
	ldr r2, addr_hr
	ldr r2, [r2]
	mov r0, #35
	cmp r2, #0
	blt p2invalid
	cmp r2, #22
	ble p2end
	cmp r2, #44
	ble addB1
	blt addB2

caseC:
	ldr r2, addr_hr
	ldr r2, [r2]
	mov r0, #40
	cmp r2, #0
	blt p2invalid
	cmp r2, #33
	ble p2end
	cmp r2, #66
	ble addC1
	blt addC2

addA1:
	sub r2, r2, #11
	mov r3, #3
	mul r2, r3, r2
	add r0, r0, r2
	b p2end
addA2:
	add r0, r0, #33
	sub r2, r2, #22
	mov r3, #6
	mul r2, r3, r2
	add r0, r0, r2
	b p2end
addB1:
	sub r2, r2, #22
	mov r2, r2, lsl #11
	add r0, r0, r2
	b p2end
addB2:
	add r0, r0, #44
	sub r2, r2, #44
	mov r2, r2, lsl #2
	add r0, r0, r2
	b p2end
addC1:
	sub r2, r2, #33
	add r0, r0, r2
	b p2end
addC2:
	add r0, r0, #33
	sub r2, r2, #66
	mov r2, r2, lsl #1
	add r0, r0, r2
	b p2end
	
p2invalid:
	ldr r0, addr_p2m3
	bl printf
	b p2end
p2end:
	mov r1, r0
	ldr r0, addr_p2m2
	bl printf
	pop {lr}
	bx lr

/* prog 3 text */
prog3:
	push {lr}
	ldr r0, addr_p3m1
	bl printf

	ldr r0, addr_p3scan
	ldr r1, addr_num
	bl scanf

	ldr r0, addr_num
	ldr r0,[r0]

	mov r1, #0
	mov r2, #1
	sub r4, r0, #1
	cmp r0, #1
	beq first
	bne loop
first:
	mov r2, r1
	b p3end
loop:
	cmp r4, #1
	ble p3end
	add r2, r2, r1
	sub r1, r2, r1
	sub r4, r4, #1
	b loop
p3end:
	ldr r1, addr_num
	ldr r1, [r1]
	ldr r0, addr_p3m2
	bl printf
	pop {lr}
	bx lr

/* menu addr */
addr_intro: .word intro
addr_inA: .word inA
addr_inB: .word inB
addr_inC: .word inC
addr_scanMenu: .word scanMenu
addr_choice: .word choice
addr_exit: .word exit
addr_repeat: .word repeat

/* prog1 addr */
addr_hr: .word hr
addr_p1m1: .word p1m1
addr_p1m2: .word p1m2
addr_p1m3: .word p1m3
addr_payrt: .word payrt
addr_p1scan: .word p1scan

/* prog2 addr */
addr_a: .word a
addr_b: .word b
addr_c: .word c
addr_p2hr: .word p2hr
addr_p2m1: .word p2m1
addr_p2m2: .word p2m2
addr_p2m3: .word p2m3
addr_p2scan: .word p2scan
addr_p2scanS: .word p2scanS
addr_package: .word package

/* prog3 addr */
addr_p3m1: .word p3m1
addr_p3m2: .word p3m2
addr_num: .word num
addr_p3scan: .word p3scan

/* external */
.global printf
.global scanf
.global strcmp
