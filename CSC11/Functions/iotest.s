/* simple output example */
	.global _start
_start:
	mov r0, #1       @output stream 1=montior
	mov r2, #19      @String length
	mov r7, #4       @Syscall num 4=write
	ldr r1, =string  @string loaction
	swi 0            @SoftWare Interrupt
_exit:
	mov r7, #1       @Syscall 1= exit
	swi 0
.data
string:
.ascii "Hello World String\n"
