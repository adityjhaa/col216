.data
buffer:	.space 26

.global _start

.text
_start:
	li a7, 8
	la a0, buffer
	li a1, 26
	ecall
	la t0, buffer
	addi t0, t0, 4
	li t6, 10 #store 10 for multiplication
	li t5, 32
	li t4, 45
	lbu t1, 0(t0)
	beq t1, t4, neg1
	li s2, 1
	j next1
neg1: 
	li s2, -1
	addi t0, t0, 1
next1:
	li t2, 0
	jal a2, stringtoint
	mv s0, t2
	mul s0, s0, s2
	
	addi t0, t0, 1
	lbu t1, 0(t0)
	beq t1, t4, neg2
	li s2, 1
	j next2
neg2: 
	li s2, -1
	addi t0, t0, 1
next2:
	li t2, 0
	jal a2, stringtoint
	mv s1, t2
	mul s1, s1, s2

	la t0, buffer
	li t1, 97
	li t2, 115
	li t3, 109
	li t4, 100
	
operator:
	lbu t5, 0(t0)
	beq t5, t1, addo
	beq t5, t2, subo
	beq t5, t3, mulo
	beq t5, t4, divo
	j exit
addo:
	add a0, s0, s1
	li a7, 1
	ecall
	j exit
subo:
	sub a0, s0, s1
	li a7, 1
	ecall
	j exit
mulo:
	mul a0, s0, s1
	li a7, 1
	ecall
	j exit
divo:
	div a0, s0, s1
	li a7, 1
	ecall
	j exit

exit: #2022CS11102
	li a7, 10
	ecall


stringtoint:
	lbu t1, 0(t0)
	beq t1, t5, returnint
	beq t1, t6, returnint
	addi t1, t1, -48
	mul t2, t2, t6
	add t2, t2, t1
	addi t0, t0, 1
	j stringtoint
	 
returnint:
	
	jr a2
	
	
