.global _start

.text
_start:
	li a7, 5
	ecall
	mv t0, a0
	jal ra, sum
	
	li a7, 1
	ecall
	
	#2022CS11102
	li a7, 10
	ecall
	
sum:
	blez t0, sum_exit
	addi t0, t0, -1
	add a0, a0, t0
	j sum
	
sum_exit:
	jr ra