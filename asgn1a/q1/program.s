.data
name:
	.ascii "Aditya Jha\n"
entry:
	.ascii "2022CS11102\n"

.global _start
.text
_start:
	#print name
	addi a7, zero, 64
	addi a0, zero, 1
	la a1, name
	addi a2, zero, 11
	ecall
	
	#print entry
	addi a7, zero, 64
	addi a0, zero, 1
	la a1, entry
	addi a2, zero, 12
	ecall
	
	#exit with call 0
	addi a7, zero, 93
	addi a0, zero, 0
	ecall


	
