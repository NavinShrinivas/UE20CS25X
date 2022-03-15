.data
    txt: .ASCIZ "Hello World"
    delay: .WORD 15000
.text
    MOV r0,#0
    MOV r1,#7
    LDR r2,=txt 
    LDR r3,=delay
    LDR r3,[r3]
    MOV r4,#0
loop:
    SWI 0x206
    SWI 0x204
    BL delay_loop
    CMP r0,#30
    ADDNE r0,r0,#1
    MOVEQ r0,#0
    B loop 
delay_loop:
    CMP r4,r3
    ADDNE r4,r4,#1 
    BNE delay_loop
    MOV r4,#0
    MOV pc,lr



