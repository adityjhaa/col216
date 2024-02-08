.global _start

.text
_start:
	li a7, 5
	ecall
	
	jal ra, sum
	
	li a7, 1
	ecall
	
	#2022CS11102
	li a7, 10
	ecall
	
sum:
	addi sp, sp, -8
	sw ra, 4(sp)
	sw a0, 0(sp)
	li t0, 1
	bge a0, t0, sum_rec
	addi a0, zero, 0
	addi sp, sp, 8
	jalr zero, 0(ra)
	
sum_rec:
	addi a0, a0, -1
	jal ra, sum
	
	mv t1, a0
	lw a0, 0(sp)
	lw ra, 4(sp)
	addi sp, sp, 8
	add a0, a0, t1
	jalr zero, 0(ra)
	
	