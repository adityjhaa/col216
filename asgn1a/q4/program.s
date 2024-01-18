.global _start

.text
_start:
	li t5, 0
	li t6, 0
first:
	li t0, 10
	li a7, 12
	ecall
	beq a0, t0, second
	addi a0, a0, -48
	addi 
	addi t5, t5, 1
	
exit:	#2022CS11102	
	li a7, 10 #exit with code 0
	ecall
