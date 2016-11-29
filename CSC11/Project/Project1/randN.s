/* random number generator */
/* store in r1 */
	.global randN
randN:
	push {lr}
	mov r0, #0
	bl time
	bl srand
	bl rand
	mov r1, r0, asr #1
	mov r2, #10
	bl divMod
	mov r7, r1
	bl rand
	mov r1, r0, asr #1
	mov r2, #10
	bl divMod
	mov r8, r1
	bl rand
	mov r1, r0, asr #1
	mov r2, #10
	bl divMod
	mov r1, r7
	mov r2, r8
	mov r3, r9
	pop {lr}
	bx lr

.global time
.global srand
.global random
