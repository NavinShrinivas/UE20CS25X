.DATA
    A : .byte 10,20,30,40,50,60,70,80
	B : .byte 0,0,0,0,0,0,0,0

.TEXT
    LDR r1,=A
    LDR r2,=B

    mov r5,#1

L1 : 
    LDRB r3,[r1]
    STRB r3,[r2]
    ADD r1,#1
    ADD r2,#1
    ADD r5,#1

    CMP r5,#9
    BNE L1
    B L2
L2 : 
    .end
