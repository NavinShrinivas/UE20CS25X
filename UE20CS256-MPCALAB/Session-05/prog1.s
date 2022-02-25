.data 
    A: .WORD 

.text
    MOV r0,#0
    MOV r1,#1
    LDR r3,=A
    STR r0,[r3],#4
    STR r1,[r3],#4


    ADD r4,r0,r1 
    MOV r10,#10
    MOV r9,#1
loop:
    STR r4,[r3],#4
    MOV r0,r1
    MOV r1,r4 
    ADD r4,r0,r1
    SUB r10,r10,#1 
    CMP r10,r9
    BEQ exit
    B loop
exit: SWI 0x11
