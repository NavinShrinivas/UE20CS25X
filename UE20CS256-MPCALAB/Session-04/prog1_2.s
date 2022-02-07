;find GCD of two numbers

.data
    dat : .WORD 36,60
    RES : .WORD
.text
    LDR r0,=dat
    LDR r3,=RES
    LDR r1,[r0]
    LDR r2,[r0,#4] ;pre indexing without write back
L1:
    CMP r1,#0
    BEQ L2
    CMP r2,#0
    BEQ L3
    CMP r1,r2
    BEQ L4
    BGT DIFF1
    B DIFF2
L2:
    STR r2,[r3]
    B L6
L3:
    STR r2,[r3]
    B L6
L4:
    STR r2,[r3]
    B L6
DIFF1:
    SUB r1,r1,r2
    B L1
DIFF2:
    SUB r2,r2,r1
    B L1
L6: .end




