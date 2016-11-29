/*data section*/
.data
.balign 4    @4byte var
x:
	.word 0   @contents of x is 3
.balign 4
y:
	.word 0   @y is 4

/*code section*/
.text

.balign 4  @make sure var  4bytes aligned
	.global main
main:
	ldr r1, addr_of_x   @&x
	mov r3, #3          @store a value
	str r3, [r1]        @put addr to r3 like pointer?
	ldr r2, addr_of_y
	mov r3, #4          @store another value
	str r3, [r2]

	ldr r1, addr_of_x
	ldr r1, [r1]
	ldr r2, addr_of_y
	ldr r2, [r2]
	add r0, r1, r2
	bx lr

addr_of_x: .word x
addr_of_y: .word y
