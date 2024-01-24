.data
	
num:	
	.space 20

.global _start

.text
_start:
	li t4, 10
	li t5, 48

	li a7, 8
	la a0, num
	li a1, 20
	ecall
	mv t0, a0
	li s0, 0
	jal a4, stringtoint

	li a7, 1	
	mv a0, t1
	ecall
	
exit:
	li a7, 10
	ecall	


stringtoint:
	beq t0, t4, returnnum
	
	sub t0, t0, t5
	mul s0, s0, t4
	add s0, s0, t0
	
	j stringtoint
	
returnnum:
	jr a4