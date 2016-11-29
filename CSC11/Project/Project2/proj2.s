/* CSC 11 Project 2 */
/* Mastermind */
.data
/* message */
intro1: .asciz"Mastermind\n"
intro2: .asciz"3 digit number\n"
intro3: .asciz"10 chances\n"
intro4: .asciz"Game start\n"
outresult: .asciz"%d right place, %d right digit\n"	@r1=x, r2=o
outacc: .asciz"Accuracy: %f\n"				@r2, r3 =float
yn: .asciz"Do you want to play again? (y/n)\n"		@Play again question
invM: .asciz"Invalid input\n"				@invalid message
winM: .asciz "You win!\nYou guess %d times\n"		@win message
loseM: .asciz "You lose!\n"				@lose message
echoM: .asciz "You input %d%d%d\n"			@echo message
testM: .asciz "%d\n"
inprompt: .asciz "Please enter 3 digits with space\n"	@input prompt
ansM: .asciz"The correct number is %d%d%d\n"		@answer message
countM: .asciz"%d try\n"				@try counter message
/* scan format */
scan: .asciz"%d"					@scan format 1 digit with space
scanYN: .asciz"%s"					@string scan format

/* variables */
.align 4
input: .word 0		@input digit 3 loop
.align 4
original: .skip 12	@correct answer, skip 12 bytes 3 int
.align 4
copy: .skip 12		@used to check
.align 4
inarr: .skip 12		@store input array, 3 int, 12byte
.align 4
onef: .float 1		@float counter
.align 4
tenf: .float 10		@float total 10
.align 4
y: .asciz"y"		@string y
.align 4
n: .asciz"n"		@string n
.align 4
ansYN: .word 0		@store y/n ans

/* accuracy start from ten one try -1 */
/* r4=ans array, r5=input array */
.text
	.global main
main:
	push {r4, lr}			@8 bytes

intro:
	ldr r0, addr_intro1
	bl printf
	ldr r0, addr_intro2
	bl printf
	ldr r0, addr_intro3
	bl printf

start:
	ldr r0, addr_intro4
	bl printf
	mov r7, #1			@set try counter
	/* r4=input, r5=original, r6=copy */
	/* generate 3 digit answer */
	mov r0, #0
	bl time				@set clock
	bl srand			@set time seed
	mov r8, #0			@reset index counter
	ldr r4, addr_original		@r4=correct answer
	ldr r5, addr_inarr		@r5=input array address
	ldr r6, addr_copy		@r6=copy
rand_number:
	bl randN			@call random function
	mov r8, #0			@reset index counter
	ldr r0, =ansM
	ldr r1, [r4]
	ldr r2, [r4, #4]
	ldr r3, [r4, #8]
	bl printf			@out number for debug
copy_real:
	ldr r1, [r4, r8, lsl #2]
	str r1, [r6, r8, lsl #2]
	add r8, r8, #1
	cmp r8, #3
	blt copy_real
	mov r8, #0

loop:	@try loop
	mov r1, r7			@r1=try
	ldr r0, =countM
	bl printf
	mov r8, #0			@reset index counter
	ldr r0, addr_inprompt
	bl printf			@output input prompt
inputloop:
	ldr r0, addr_scan		@%d
	ldr r1, addr_input		@one word width
	bl scanf
	ldr r1, addr_input		@r1=input address
	ldr r1, [r1]			@r1=input
	str r1, [r5, r8, lsl #2]	@r5=inarr[r11] address, inarr[r11]=r1
	add r8, r8, #1			@index counter++
	cmp r8, #3
	blt inputloop			@r11<3 go inputloop
outinput:				@Your input is %d%d%d
	mov r8, #0			@reset index counter
	ldr r0, addr_echoM
	ldr r1, [r5, r8, lsl #2]	@r1=inarr[0]
	add r8, r8, #1			@index counter++
	ldr r2, [r5, r8, lsl #2]	@r2=inarr[1]
	add r8, r8, #1			@index counter++
	ldr r3, [r5, r8, lsl #2]	@addr of input + 8bytes input[3]
	bl printf
	mov r8, #0			@reset index counter
chkinput:				@input validation
	ldr r1, [r5, r8, lsl #2]	@inarr[r8]
	mov r2, r1
	cmp r1, #0
	blt invalid_digit
	mov r1, r2
	cmp r1, #9
	bgt invalid_digit
	add r8, r8, #1			@index++
	cmp r8, #3
	blt chkinput			@index<3 go chkinput

/* check function */
/* chk function r1=X, r2=O */
check:
	mov r8, #0
	bl chk				@call chk function
	mov r10, r1			@r10=X
	mov r11, r2			@r11=O

checkresult:				@ ?X ?O
	ldr r0, addr_outresult
	bl printf			@output result
	cmp r10, #3
	beq win				@r10==3 -> win
	addne r7, r7, #1		@incorrect try++
	bne countchk			@r10<3 ->chk try counter

countchk:
	cmp r7, #10
	ble loop			@try counter<10 loop
	b lose				@try counter>=10 lose

win:
	ldr r0, addr_winM
	mov r1, r7			@r7=counter
	bl printf
	b accresult

lose:
	mov r8, #0
	ldr r0, addr_loseM
	bl printf
	ldr r0, =ansM
	ldr r1, [r4, r8, lsl #2]
	add r8, r8, #1
	ldr r2, [r4, r8, lsl #2]
	add r8, r8, #1
	ldr r3, [r4, r8, lsl #2]
	bl printf
	b again

accresult:
	mov r8, #10			@r8=10
	sub r7, r8, r7			@r7=10-try
	add r7, r7, #1
	vmov s14, r7			@s14=10-try (int)
	vcvt.f32.s32 s0, s14		@s0=10-try (float)
	ldr r1, =tenf			@address of float 10
	vldr s14, [r1]			@s14=10f
	vdiv.f32 s31, s0, s14		@s31=(10-try)/10
	vcvt.f64.f32 d5, s31		@convert to double d5
	ldr r0, addr_outacc
	vmov r2, r3, d5			@store accuracy in r2, r3
	bl printf			@output accuracy
	b again				@ask yn question

again:
	ldr r0, addr_yn			@again yn question
	bl printf

	ldr r0, addr_scanYN
	ldr r1, addr_ansYN
	bl scanf			@take yn input

	ldr r1, addr_ansYN
	ldr r0, addr_y
	bl strcmp
	beq start
	ldr r1, addr_ansYN
	ldr r0, addr_n
	bl strcmp
	beq end
	bne invalidYN

invalid_digit:	@invalid input digit
	mov r8, #0
	ldr r0, addr_invM
	bl printf			@output invalid message
	b loop				@go back to loop

invalidYN:
	ldr r0, addr_invM
	bl printf			@output invalid message
	b again				@loop back to yn question

end:
	pop {r4, lr}
	bx lr				@exit stage right

/* address */
addr_intro1: .word intro1
addr_intro2: .word intro2
addr_intro3: .word intro3
addr_intro4: .word intro4
addr_outresult: .word outresult
addr_outacc: .word outacc
addr_yn: .word yn
addr_invM: .word invM
addr_winM: .word winM
addr_loseM: .word loseM
addr_echoM: .word echoM
addr_inprompt: .word inprompt
addr_scan: .word scan
addr_scanYN: .word scanYN

addr_inarr: .word inarr
addr_original: .word original
addr_copy: .word copy
addr_input: .word input
addr_onef: .word onef
addr_tenf: .word tenf
addr_y: .word y
addr_n: .word n
addr_ansYN: .word ansYN


/* external */
.global printf
.global scanf
.global strcmp
.global time
.global srand
