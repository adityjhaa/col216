.data
prompt: .ascii "Enter 10 integers\n"
buffer: .space 40 #for 10 integers
array: .space 40 #for 10 integers
.global _start

.text
_start:
	#print the prompt
	li a7, 64
	li a0, 1
	la a1, prompt
	li a2, 18
	ecall
	
	#input into the buffer
	li a7, 63
	li a0, 0
	la a1, buffer
	li a2, 40
	ecall
	
	li t0, 0
	li t1, 0
	mv t2, a1
	
	

	#exit with exit-call 0
	li a7, 93
	li a0, 0
	ecall
