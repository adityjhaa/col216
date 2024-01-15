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
	
	li a7, 5
	ecall
	
	li t0, 0
	li t1, 1
	mv t2, a0
	
fibonacci:
	beqz t2, z
	beq t2
				
			
exit:
	li a7, 93
	li a0, 0
	ecall
	
