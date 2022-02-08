.data
    ARR : .WORD 10,20,30,40,50,60,70,80,90,100
    RES : .WORD 
.text 
    LDR r0,=ARR 
    LDR r1,=RES 
    MOV r2,#0
    ADD r7,r0,#36
loop:
    LDR r4,[r0]
    ADD r2,r2,r4
    LDR r4,[r0],#8
    CMP r0,r7
    BGT end
    B loop 
end:
    STR r2,[r1]
    .end
