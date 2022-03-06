.data
    string: .ASCIZ "this program is for lab 6 MPCA"
    char: .ASCIZ "a"

.text

LDR r0,=string 
LDR r1,=char 
MOV r5,#0

loop:
    LDRB r2,[r0],#1
    LDRB r3,[r1]
    CMP r2,r3
    ADDEQ r5,r5,#1
    CMP r2,#0
    BEQ end
    B loop

end: .end
