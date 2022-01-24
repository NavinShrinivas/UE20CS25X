

mov r1,#8
ands r2,r1,#1
beq even 
mov r0,#0xff

b odd
even : mov r0,#0x00
odd : swi 0x011





