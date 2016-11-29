/* Efficient technique for calculating a/b and a%b */

.data

/* input */
.balign 4
m1: .asciz "Input:"
.blaign 4
m2: .asciz "Ture\n"
.balign 4
m3: .asciz "False\n"
.balign 4
c1: .asciz "Y"
.balign 4
scan: .asciz "%c"
.balign 4
in1: .word 0

.balign 4
return: .word 0

.text
main:
	ldr r1, addr_reutrn
	str lr, [r1]
	ldr r0, addr_m1
	bl printf
	ldr r0, addr_scan
	ldr r1, addr_in1
	bl scanf
	ldr r2, addr_c1
	cmp r1, r2
	beq true
	bne false
	
true:
	ldr r0, addr_m2
	bl printf
	b end
false:
	ldr r0, addr_m3
	bl printf
	b end
end:
	ldr lr, addr_reutrn
	ldr lr, [lr]
	
addr_m1: .word m1
addr_m2: .word m2
addr_m3: .word m3
addr_scan: .word scan
addr_c1: .word c1
addr_in1: .word in1
.global printf
.global scanf
