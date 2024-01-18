#2022CS11102
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
	li s0, 0
	mv t4, t6
	bge t5, t6, big
	mv t4, t5
	bge t6, t5, small
big:
	sub t0, t5, t6
	blez t4, big2
	lw t1, 0(sp)
	add sp, sp, t6
	lw t2, 0(sp)
	sub sp, sp, t6
	addi t1, t1, -48
	addi t2, t2, -48
	add t3, t1, t2
	add t3, t3, s0
	jal a2, mod
	addi t3, t3, 48
	sw t3, 0(sp)
	addi sp, sp, 4
	addi t4, t4, -4
	j big
big2:
	blez t0, print5
	add sp, sp, t6
	lw t1, 0(sp)
	addi t1, t1, -48
	add t3, t1, zero
	jal a2, mod
	addi t3, t3, 48
	sub sp, sp, t6
	sw t3, 0(sp)
	addi sp, sp, 4
	addi t0, t0, -4
	j big2
small:
	sub t0, t6, t5
	blez t4, small2
	lw t1, 0(sp)
	add sp, sp, t6
	lw t2, 0(sp)
	sub sp, sp, t6
	addi t1, t1, -48
	addi t2, t2, -48
	add t3, t1, t2
	add t3, t3, s0
	jal a2, mod
	addi t3, t3, 48
	sw t3, 0(sp)
	addi sp, sp, 4
	addi t4, t4, -4
	j small
small2:
	blez t0, print6
	lw t1, 0(sp)
	addi t1, t1, -48
	add t3, t1, zero
	jal a2, mod
	addi t3, t3, 48
	sw t3, 0(sp)
	addi sp, sp, 4
	addi t0, t0, -4
	j small2
print5:
	jal a2, pmod
print51:	
	blez t5, exit
	addi sp, sp, -4
	lw a0, 0(sp)
	li a7, 11
	ecall
	addi t5, t5, -4
	j print51
print6:
	jal a2, pmod
print61:
	blez t6, exit
	addi sp, sp, -4
	lw a0, 0(sp)
	li a7, 11
	ecall
	addi t6, t6, -4
	j print61
exit:
	li a7, 10
	ecall
	
mod:
	li a1, 10
	blt t3, a1, nomod
	addi t3, t3, -10
	li s0, 1
	jr a2
nomod:
	li s0, 0
	jr a2

pmod:
	beqz s0, pnomod
	mv a0, s0
	li a7, 1
	ecall
	jr a2
pnomod:
	jr a2
