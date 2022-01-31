.DATA
    A : .WORD 10,20,30,40,50,60,70,80
	B : .WORD 0,0,0,0,0,0,0,0

.TEXT
    LDR r1,=A
    LDR r2,=B

    mov r5,#1

L1 : 
    LDR r3,[r1]
    STR r3,[r2]
    ADD r1,#4
    ADD r2,#4
    ADD r5,#1

    CMP r5,#9
    BNE L1
    B L2
L2 : 
    .end


