.DATA
    A : .HWORD 10,20,30,40,50,60,70,80
	B : .HWORD 0,0,0,0,0,0,0,0

.TEXT
    LDR r1,=A
    LDR r2,=B

    mov r5,#1

L1 : 
    LDRH r3,[r1]
    STRH r3,[r2]
    ADD r1,#2
    ADD r2,#2
    ADD r5,#1

    CMP r5,#9
    BNE L1
    B L2
L2 : 
    .end


