mov r0,#-2
cmp r0,#0

Beq L1
Bmi L2

mov r1,#2
B L3

L1 : 
    mov r1,#1
    B L3 

L2 :
    mov r1,#3
    B L3

L3 : .end

