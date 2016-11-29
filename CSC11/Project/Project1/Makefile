proj1:proj1.o check.o divMod.o randN.o
	gcc -o proj1 proj1.o check.o divMod.o randN.o
proj1.o:proj1.s
	as -o proj1.o proj1.s
check.o:check.s
	as -o check.o check.s
divMod.o:divMod.s
	as -o divMod.o divMod.s
randN.o:randN.s
	as -o randN.o randN.s
clean:
	rm *.o