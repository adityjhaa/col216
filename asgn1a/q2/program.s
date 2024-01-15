.data
prompt:
	.ascii "Enter 10 integers separated by <Enter>.\n"
array:
	.space 40
	
.global _start

.text
_start:
	li a7, 64
	li a0, 1
	la a1, prompt
	li a2, 40
	ecall

	li t0, 0
	li t1, 10
	
takeint:
	bge t0, t1, sum
		
	
	
sum:
	#exit with exit-call 0
	li a7, 93
	li a0, 0
	ecall
