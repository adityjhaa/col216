.global _start

.text
_start:
	
	
exit:
	li a7, 5
	ecall
	
	li a1, 0
	jal ra, sum
	
	li a7, 1
	ecall
	
	#2022CS11102
	li a7, 10 
	ecall
	
sum:
	ble a0, zero, sum_exit
	add a1, a1, a0
	addi a0 ,a0, -1
	jal zero, sum

sum_exit:
	addi a0, a1, 0
	jalr zero, 0(ra)