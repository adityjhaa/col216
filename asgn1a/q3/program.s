.data
buffer:
	.space 10
name:
	.ascii "Aditya Jha"	
endl:
	.ascii "\n"

.global _start

.text
_start:
	li a7, 63
	li a0, 0
	la a1, buffer
	li a2, 10
	ecall
		
	li a7, 64
	li a0, 1
	la a1, endl
	li a2, 1
	ecall
	
	li t0, 0
	la t1, buffer
	li t2, 10
	la t3, name
print:
	bge t0, t2, exit
	
	li a7, 64
	li a0, 1
	mv a1, t3
	li a2, 1
	ecall
	li a7, 64
	li a0, 1
	mv a1, t1
	li a2, 1
	ecall
	addi t0, t0 ,1
	addi t1, t1, 1
	addi t3, t3, 1
	j print

exit:
	li a7, 64
	li a0, 1
	la a1, endl
	li a2, 1
	ecall
	
	li a7, 93
	li a0, 0
	ecall
