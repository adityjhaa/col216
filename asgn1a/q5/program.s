.data
prompt:
	.ascii "Enter an integer\n"
buffer:	.space 4
	
.global _start

.text
_start:
	li a7, 64
	li a0, 1
	la a1, prompt
	li a2, 17
	ecall
	
	li a7, 63
	li a0, 0
	la a1, buffer
	li a2, 4
	ecall
	
	li t0, 0
	mv t1, a1
	li t2, 10
	li t3, 0
	li t4, 48
	
loop:
	lb a3, 0(t1)
	beq a3, zero, proceed
	
	sub a3, a3, t4
	mul t0, t0, t2
	add t0, t0, a3
	addi t1, t1, 1
	addi t3, t3, 1
	j loop	
		
proceed:
	li a7, 64
	li a0, 1
	mv a1, t0
	mv a2, t3
	ecall	
	
	li a7, 93
	li a0, 0
	ecall
	