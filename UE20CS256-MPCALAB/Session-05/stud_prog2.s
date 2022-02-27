.data
    A: .WORD 10,20,30,40,50,60,70,80,90
    B: .WORD 0,0,0
    ANS: .WORD 0

.text

mov r9,#3
mov r8,#0
LDR r0,=A
LDR r4,=B


loop:
    LDR r1,[r0]
    LDR r2,[r0,#12]
    LDR r3,[r0,#24]
    ADD r0,r0,#4
    ADD r8,r8,#1

    ADD r1,r1,r2
    ADD r1,r1,r3
    STR r1,[r4],#4

    CMP r8,r9
    BEQ end 
    B loop 
end:
    CMP r1,r2
    BGT R1
    .end
    
