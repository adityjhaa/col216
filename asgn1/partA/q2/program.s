.data
prompt:
	.ascii "Enter 10 integers separated by <Enter>.\n"
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
	li t2, 0 #initialize sum with 0
	
take:
	bge t0, t1, sum
	
	li a7, 5
	ecall #take the input number
	addi sp, sp, -4
	sw a0, 0(sp) #store into stack
	addi t0, t0, 1
	j take
	
sum:
	ble t0, zero, print
	lw t1, 0(sp) #load word from stack
	addi sp , sp, 4
	add t2, t2, t1 #add to sum
	addi t0, t0, -1
	j sum
	
print:	
	li a7, 64
	li a0, 1
	la a1, s 
	li a2, 13
	ecall #print the prompt s
	
	li a7, 1
	mv a0, t2
	ecall #print the sum
	#2022CS11102
	#exit with exit-call 0
	li a7, 93
	li a0, 0
	ecall
