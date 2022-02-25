.data
        A: .WORD 2,6,1,5,3,8,1,6,2,8
        RES: .WORD
.text
    LDR r0,=A
    MOV r10,#9
    MOV r9,#0
    LDR r5,=RES
    LDR r1,[r0],#4 
loop:
    LDR r2,[r0],#4
    CMP r2,r1 
    BLS lesser
    SUB r10,r10,#1 
    CMP r10,r9
    BEQ end
    B loop

lesser:
    MOV r1,r2
    B loop
end: 
    STR r1,[r5]
    SWI 0x11

