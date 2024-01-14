.data
name:
	.ascii "Aditya Jha\n"
entry:
	.ascii "2022CS11102\n"

.global _start
.text
_start:
	#print name
	li a7, 64
	li a0, 1
	la a1, name
	li a2, 11
	ecall
	
	#print entry
	li a7, 64
	li a0, 1
	la a1, entry
	li a2, 12
	ecall
	
	#exit with exit-call 0
	li a7, 93
	li a0, 0
	ecall


	
