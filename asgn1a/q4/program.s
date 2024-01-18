.data


.global _start

.text
_start:
	li t5, 0
	li t6, 0
	li t0, 10
first:
	li a7, 12
	ecall
	beq a0, t0, second
	addi sp, sp, -4
	sw a0, 0(sp)
	addi t5, t5, 4
	j first
second:
	li a7, 12
	ecall
	beq a0, t0, sec
	addi sp, sp, -4
	sw a0, 0(sp)
	addi t6, t6, 4
	j second
sec:
	mv t4, t6
	bge t5, t6, big
	mv t4, t5
	bge t6, t5, small
big:
	blez t4, print
	lw t1, 0(sp)
	add sp, sp, t6
	lw t2, 0(sp)
	sub sp, sp, t6
	
	addi t1, t1, -48
	addi t2, t2, -48
	add t3, t1, t2
	addi t3, t3, 48
	sw t3, 0(sp)
	addi sp, sp, 4
	addi t4, t4, -4
	j big
small:

	lw t1, 0(sp)
	add sp, sp, t6
	lw t2, 0(sp)
	sub sp, sp, t6
	
	addi t1, t1, -48
	addi t2, t2, -48
	add t3, t1, t2
	addi t3, t3, 48
	li a7, 11
	mv a0, t3
	ecall
	j exit
print:
	blez t5, exit
	addi sp, sp, -4
	lw a0, 0(sp)
	li a7, 11
	ecall
	addi t5, t5, -4
	j print
exit:
	
	li a7, 10
	ecall
	