.data
    A: .WORD 2312
    MAGIC: .WORD 0xCCCCCCCD

.text
    mov r0,#0
    LDR r1,=A 
    LDR r2,[r1]
    ldr r4,=MAGIC
    LDR r5,[r4]

loop:
    CMP r2,#10
    BLT endseq
    MOV r3,r2
    B mod
mod:
    CMP r3,#10
    BLT found
    SUB r3,r3,#10
    B mod


found:
    ADD r0,r0,r3
    UMULL r6,r2,r2,r5
    MOV r2,r2,LSR #3
    B loop
endseq: 
    ADD r0,r0,r2
    .end
