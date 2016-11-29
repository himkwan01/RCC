/*function example*/
.data
@greeting(label) contains addr of the text
greeting:
.asciz "Hello World"
@will keep the value of return at lr
.balign 4
return: .word 0

.text

	.global main
main:
	ldr r1, addr_of_return      @addr->r1
	str lr, [r1]                @lr->*r1

	ldr r0, addr_of_greeting    @addr->r0
				    @1st parameter of puts
	@call function
	bl puts                     @call to puts
				    @addr_of_next_intruction->lr
	ldr r1, addr_of_return      @addr->r1
	ldr lr, [r1]		    @lr->*r1
	bx lr			    @return from main

addr_of_greeting: .word greeting
addr_of_return: .word return

/*External*/
.global puts
