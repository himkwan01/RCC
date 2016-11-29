/* random number generator */
/* store in r1 */
	.global randN
randN:
	push {lr}
	bl rand			@call random function from c
	mov r1, r0, asr #1	@make sure it is positive
	mov r2, #10		@set divisor
	bl divMod		@call divMod function
	str r1, [r4]		@r1=original[0]
	bl rand
	mov r1, r0, asr #1
	mov r2, #10		@r1=original[1]
	bl divMod
	str r1, [r4, #4]
	bl rand
	mov r1, r0, asr #1
	mov r2, #10
	bl divMod
	str r1, [r4, #8]
	pop {lr}
	bx lr

.global time
.global srand
.global random
