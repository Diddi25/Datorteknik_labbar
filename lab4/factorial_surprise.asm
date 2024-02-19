
.text
	addi $a0, $0, 4 #number n 4! = 4*3*2 = 4 + 4 + 4, 12 + 12
	addi $a1, $0, 1 #jämförelse nr
	add $v0, $0, $a0 #initieras till 4
	add $v1, $0, $a0 #initieras till 4
	add $a2, $0, $a0 # a2 = a0 = 4
	
jump_if_0_or_1_fact:
	#beq $a0, $0, one_factorial_value
	#beq $a0, $a1, one_factorial_value
	
determine_if_should_stop:
	addi $v1, $v1, -1 #3, 2
	beq  $v1, $a1, stop #a2 = 1 => stop
	
add_n_minus_one:
	mul $v0, $v0, $v1 #4*3
	beq $0, $0, determine_if_should_stop
	add $0, $0, $0 #måste ha meningslös op annars hazard :/
	
one_factorial_value:
	#add $v0, $0, 1
	
stop: 
	beq $0, $0, stop