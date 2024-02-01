
        # pointers.asm
# By David Broman, 2015-09-14
# This file is in the public domain


.macro	PUSH (%reg)
	addi	$sp,$sp,-4
	sw	%reg,0($sp)
.end_macro

.macro	POP (%reg)
	lw	%reg,0($sp)
	addi	$sp,$sp,4
.end_macro

.data


text1: 	  .asciiz "This is a string." #c=17, ci = 13, w=4
text2:	  .asciiz "Yet another thing."

.align 2
list1: 	.space 80
list2: 	.space 80
count:	.word  0

.text
main:
	jal	work
stop:	j	stop

# function work()
work:
	PUSH	($ra)
	la 	$a0,text1 #laddar addressen för text1 #dvs alla dessa är pekare
	la	$a1,list1 #laddar addressen för list1
	la	$a2,count #laddar addressen för count
	jal	copycodes
	
	la 	$a0,text2
	la	$a1,list2
	la	$a2,count
	jal	copycodes
	POP	($ra)
	
	
# function copycodes()
copycodes: #ADDRESSER: a0 = text1, a1 = list1, a2 = count
loop:
	lb	$t0,0($a0)	#laddar upp 8 bitar som ligger på text1:s address
	beq	$t0,$0,done #när hela texten är klar
	sw	$t0,0($a1)	#sparar 8 bitar från t0 i addressen för list1

	addi	$a0,$a0,1 #går till nästa karaktär i tex1
	addi	$a1,$a1,4 #går till nästa plats i addressen för nästa karaktär
	
	lw	$t1,0($a2)	#laddar upp count i t1
	addi $t1,$t1,1	#stegrar count+1
	sw	$t1,0($a2)	#sparar count på addressen a2
	j	loop
done:
	jr	$ra
		



