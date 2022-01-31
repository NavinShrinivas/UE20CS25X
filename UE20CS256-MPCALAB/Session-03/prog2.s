.DATA 
   A : .WORD 10,20,30,40,50
   B : .HWORD 10,20,30,40,50
   C : .byte 10,20,30,40,50

.TEXT 
    LDR r1,=A
    LDR r2,=B 
    LDR r3,=C
    LDR r9,=C 

    ADD r9,r9,#6

    mov r4,#0
    mov r5,#0
    mov r6,#0
    mov r7,#0
L1 :
        LDR r8,[r1]
        ADD r5,r5,r8
        ADD r1,#4

        ADD r4,#1
        CMP r4,#5
        BNE L1
        STR r5,[r9]
        ADD r9,#4
        mov r4,#0

L2 : 
        LDRH r8,[r2]
        ADD r6,r6,r8
        ADD r2,#2

        ADD r4,#1
        CMP r4,#5
        BNE L2
        STR r6,[r9]
        ADD r9,#4
        mov r4,#0

L3 :
        LDRB r8,[r3]
        ADD r7,r7,r8
        ADD r3,#1

        ADD r4,#1
        CMP r4,#5
        BNE L3
        STR r7,[r9]
        ADD r9,#4
        B L4

L4 : .end

