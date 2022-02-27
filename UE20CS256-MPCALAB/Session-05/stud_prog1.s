.data
    A: .WORD 10,20,30,40,50,60,70,80,90
    B: .WORD 1,2,3,4,5,6,7,8,9
    C: .WORD 0,0,0,0,0,0,0,0,0

.text

LDR r0,=A
LDR r1,=B 
LDR r2,=C

MOV r9,#9
MOV r8,#0

loop:
    LDR r4,[r1]
    LDR r5,[r0]
    ADD r3,r4,r5
    STR r3,[r2]
    ADD r0,r0,#4
    ADD r2,r2,#4
    ADD r1,r1,#4

    ADD r8,r8,#1
    CMP r8,r9
    BEQ end 
    B loop 
end: .end
