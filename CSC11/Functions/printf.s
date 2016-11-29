/*printf.s*/
.data

/*first message*/
.balign 4
m1:
.asciz "Enter a num"

/*second message*/
.balign 4
m2:
.asciz "You enter %d\n"   /* %d is var int */

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

.text
	.global main
main:
	ldr r1, addr_return
	str lr, [r1]

	ldr r0, addr_m1
	bl printf            /*call printf*/

	ldr r0, addr_scan   /*need to use these 2 var*/
	ldr r1, addr_num
	bl scanf            /*call scanf*/

	ldr r0, addr_m2
	ldr r1, addr_num
	ldr r1, [r1]        /*load the value of r1 into r1*/
	bl printf

	ldr r0, addr_num
	ldr r0, [r0]

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

