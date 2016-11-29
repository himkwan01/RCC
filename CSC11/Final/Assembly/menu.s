/* CSC 11 final */
/* Tsz, Kwan */
/* 12/07/14 */

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
inD: .asciz "Press 4 to run prog4\n"
.balign 4
inE: .asciz "Press 5 to exit\n"
.balign 4
scanMenu: .asciz "%d"
.balign 4
choice: .word 0
.balign 4
repeat: .asciz "Input %d\n"
.balign 4
exit: .asciz "Press %d to exit\n"



.text
/* menu */
	.global main
main:
	push {r4, lr}
menu:
	ldr r0, =intro
	bl printf
	ldr r0, =inA
	bl printf
	ldr r0, =inB
	bl printf
	ldr r0, =inC
	bl printf
	ldr r0, =inD
	bl printf		@menu
	ldr r0, =inE
	bl printf

	ldr r0, =scanMenu
	ldr r1, =choice
	bl scanf		@input choice
	ldr r0, =repeat
	ldr r1, =choice
	ldr r1, [r1]
	mov r5, r1
	bl printf

	mov r1, r5		@run p1
	cmp r1, #1
	bleq prog1
	beq menu

	mov r1, r5		@run p2
	cmp r1, #2
	bleq prog2
	beq menu

	mov r1, r5		@run p3
	cmp r1, #3
	bleq prog3
	beq menu

	mov r1, r5		@run p4
	cmp r1, #4
	bleq prog4
	beq menu
	bgt end

end:
	ldr r0, =exit
	mov r1, r5
	bl printf
	pop {r4, lr}
	bx lr

/* external */
.global printf
.global scanf
.global strcmp
