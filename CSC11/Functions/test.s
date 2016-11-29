/* find a/b, a%b*/
	.global _start

_start:
	mov r1, #11  @r1? 11
	mov r2, #5   @r2? 5
	mov r3, #0   @counter
	mov r4, #0   @swap flag
	cmp r1,r2    @update the cpsr
	bge _subtract
	blt _swapcheck
_subtract:
	sub r1, r1, r2    @r0-=r1
	add r3, r3, #1    @counter++
	mov r0, r1
	cmp r1, r2        @check a>b again
	bge _subtract
	blt _swapcheck
_swapcheck:
	cmp r4, #1
	beq end
	bne _swap
_swap:
	mov r5, r0
	mov r0, r3
	mov r3, r5
	b end
end:
	mov r7, #1
	swi 0
