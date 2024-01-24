.data

.global _start

.text
_start:
	li a7, 5
	ecall
	
	mv t0, a0
	li t6, 1
	li t5, 1
	li t4, 0
	jal a2, factorial
	
	
	mv a0, t5
	li a7, 1
	ecall
	
exit:
	li a7, 10
	ecall
	
factorial:
	beqz t0, return
	bgt t6, t0, return
	
	mul t5, t5, t6
	
	addi t6, t6, 1
	j factorial
	
return:
	jr a2
