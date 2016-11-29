/*printf.s*/
.data

/*first message*/
.balign 4
m1:
.asciz "Enter a num"

/*second message*/
.balign 4
m2:
.asciz "%d times 5 is %d\n"   /* %d is var int */

.balign 4
scan:
.asciz "%d"

/*store sacnf data*/
.balign 4
num:
.word 0

.balign 4
return:
.word 0

.balign 4
return2:
.word 0
.text

/*function mul by 5*/
mult_5:
	ldr r1, addr_return2      /*set return2*/
	str lr, [r1]

	add r0, r0, r0, LSL #2  /*r0+=4*/

	ldr lr, addr_return2
	ldr lr, [lr]
	bx lr

addr_return2: .word return2

	.global main
main:
	ldr r1, addr_return
	str lr, [r1]

	ldr r0, addr_m1
	bl printf            /*call printf*/

	ldr r0, addr_scan   /*need to use these 2 var*/
	ldr r1, addr_num
	bl scanf            /*call scanf*/

	ldr r0, addr_num
	ldr r0, [r0]
	bl mult_5          /*call function mul_5*/

	/* need to print 3 parameters: 2int and text */
	mov r2, r0          /* r2 to be third parameter */
	ldr r0, addr_m2	    /* load the text to r0 (display first) */
	ldr r1, addr_num    /* load the addr_input int to second parameter */
	ldr r1, [r1]        /*load the value of r1 into r1*/
	bl printf
	/* end of prog */
	ldr lr, addr_return
	ldr lr, [lr]
	bx lr

addr_m1: .word m1
addr_m2: .word m2
addr_scan: .word scan
addr_num: .word num
addr_return: .word return

.global printf
.global scanf

