.data
    ARR: .WORD 2,4,7,9,10,14,15
    KEY: .WORD 15
    SIZE: .WORD 7
    OUtPUT1: .ASCIZ "Search Sucessfull"
    OUTPUT2: .ASCIZ "Search Unsucessfull"
.text

LDR r11,=SIZE
LDR r0,[r11]
LDR r1,=ARR
ADD r2,r1,r0,LSL #2
LDR r11,=KEY
LDR r3,[r11]

initloop:
    CMP r1,r2
    BEQ failed
    SUB r4,r2,r1
    MOV r4,r4,LSR #1
    LDR r5,[r4]
    CMP r5,r3
    BEQ found
    BLT gogreater
    B golesser

gogreater:
    MOV r1,r5
    B initloop
golesser:
    MOV r2,r5
    B initloop
found:
    B end
failed:
    B end
end: .end
