.DATA
    A : .WORD 16

.TEXT
    LDR r5,=A
    LDR r0,[r5]
    mov r1,#1 
    mov r2,#0 

L1 : 
    ADD r2,r2,r1
    ADD r1,#1

    CMP r1,r0
    BNE L1
    ADD r5,#4
    STR r2,[r5]
    B L2 
L2 : .end
    
    
