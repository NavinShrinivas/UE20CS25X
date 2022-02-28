.data

    A: .WORD 0,0,0,0,0,0,0,0,0
.text

MOV r9,#3
MOV r8,#0

LDR r0,=A
MOV r1,#3


loop:
    STR r1,[r0]
    ADD r1,r1,#1
    ADD r0,r0,#16
    ADD r8,r8,#1
    CMP r8,r9
    BEQ equal
    B loop

equal: .end



    
    
