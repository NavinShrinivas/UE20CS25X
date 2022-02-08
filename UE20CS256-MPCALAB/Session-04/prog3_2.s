
.data
    ARR : .WORD 10,20,30,40,50,60,70,80,90,100
    RES : .WORD 
.text 
    LDR r0,=ARR 
    LDR r1,=RES 
    MOV r2,#0
    LDR r9,[r0]
    ADD r2,r2,r9
    MOV r3,#2
loop:
    MOV r8,#4
    MUL r5,r3,r8
    LDR r4,[r0,r5]
    ADD r2,r2,r4
    ADD r3,r3,#2
    CMP r3,#9
    BGT end
    B loop 
end:
    STR r2,[r1]
    .end
