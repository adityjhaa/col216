.global _start

.text
_start:


	#exit with exit-call 0
	li a7, 93
	li a0, 0
	ecall
