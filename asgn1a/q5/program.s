.data
prompt:
	.ascii "Enter an integer n : \n"
wrongp:
	.ascii "Enter valid integer!!\n"
	
.global _start

.text
_start:
	li a7, 64
	li a0, 1
	la a1, prompt
	li a2, 22
	ecall
	
	li a7, 5 #read int
	ecall
	
	li t0, 0
	li t1, 1
	mv t2, a0 #entered integer n
	li t3, 0
	li t4, 1
	blt t2, zero, wrong #anything less than zero, and we exit with a prompt
	ble t2, t1, base #for base case n<=1, where fib(n) = n
fibonacci:
	bge t4, t2, rec
	add t3, t0, t1 #fib(n) = fib(n-2) + fib(n-1)
	mv t0, t1
	mv t1, t3
	addi t4, t4, 1
	j fibonacci				
base:
	li a7, 1
	ecall	
	j exit
rec:
	li a7, 1
	mv a0, t3
	ecall
	j exit
wrong:
	li a7, 64
	li a0, 1
	la a1, wrongp
	li a2, 22
	ecall
	j exit
exit:	#2022CS11102
	#exit with exit-call 0
	li a7, 93
	li a0, 0
	ecall
	
