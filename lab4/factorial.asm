
.text
	addi $a0, $0, 4 #number n 4! = 4*3*2 = 4 + 4 + 4, 12 + 12
	addi $a1, $0, 1 #jämförelse nr
	add $v0, $0, $a0 #initieras till n
	add $a2, $0, $a0 # a2 = a0 = 4
	
add_n_minus_one:
	addi $a2, $a2, -1 #a2 = 3, 2, 1
	beq  $a2, $a1, stop #a2 = 1 => stop
	add $a3, $a1, $a2 #a3 = 1 + a2 = 1 + 2 = 3
	add $v1, $v0, $0 #4, 12
	
determine_if_a3_is_1:
	addi $a3, $a3, -1  #a3 = 3, 2, 1 ## 2, 1
	beq $a3, $a1, add_n_minus_one #om a3 = 0 => gå upp
	add $0, $0, $0
	
add_a3_times:
	add $v0, $v0, $v1 #v0 = 4, 8, 12, 24
	beq $0, $0, determine_if_a3_is_1
	add $0, $0, $0 #måste ha meningslös op annars hazard :/
	
stop: 
	beq $0, $0, stop


#3! = 3 * 2 * 1 = 3 + 3 
#4! = 4 * 3 * 2 = 4 + 4 + 4, x + x
#5! = 5 * 4 * 3 * 2 = 5 + 5 + 5 + 5, 

# a1 = a0 - 1
# så länge 


