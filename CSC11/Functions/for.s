/* for loop 
   for(int i=0;i<5;i++) */

	.global main
main:
	mov r0, #1   @int r1=1
	mov r1, #0   @int i=0
	cmp r1, #5   @i<5
	blt for      @loop
	bge end
for:
	add r0, r0, r1
	add r1, r1, #1
	cmp r1, #5
	blt for
	bge end
end:
	bx lr