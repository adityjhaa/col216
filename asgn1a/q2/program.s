.data
prompt:
	.ascii "Enter 10 integers separated by <Enter>.\n"
array:
	.space 40
s:
	.ascii "The sum is : "
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
	li t2, 0
	
takeint:
	bge t0, t1, sum
	
	li a7, 5
	ecall
	
	add t2, t2, a0
	addi t0, t0, 1
	j takeint
	
sum:
	li a7, 64
	li a0, 1
	la a1, s
	li a2, 13
	ecall
	
	li a7, 1
	mv a0, t2
	ecall
	
	#exit with exit-call 0
	li a7, 93
	li a0, 0
	ecall
