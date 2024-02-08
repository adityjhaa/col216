.data

.global _start

.text
_start:
	li a7, 5
	ecall
	mv t6, a0
	
	li a7, 5
	ecall
	mv t5, a0
	
	sub t4, t6, t5
	bltz t4, zeroa
	
	li t0, 1
	mv t1, t6
	jal a2, factorial
	mv s0, t0
	
	li t0, 1
	mv t1, t5
	jal a2, factorial
	mv s1, t0	
	
	li t0, 1
	mv t1, t4
	jal a2, factorial
	mv s2, t0

	div s0, s0, s1
	div s0, s0, s2

	li a7, 1
	mv a0, s0
	ecall
	
exit: #2022CS11102
	li a7, 10
	ecall


factorial:
	blez t1, return
	mul t0, t0, t1
	addi t1, t1, -1
	j factorial
	
return:
	jr a2	

zeroa:
	li a0, 0
	li a7, 1
	ecall
	j exit