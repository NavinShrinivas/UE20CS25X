.data
    A: .ASCIZ "HELLO WORLD"

.text
LDR R1,=A 
LOOP:
    LDRB R0,[R1],#1 
    CMP R0,#0 
    SWINE 0x00 
    BNE LOOP 
    SWI 0x11     
