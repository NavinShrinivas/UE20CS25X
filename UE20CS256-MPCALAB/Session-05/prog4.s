.data

    src: .WORD 11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,1111,11,11,11,11,11,11,11,11,11,11,11,11,11,11,1111,11,11,11,11,11,11,11,11,11,11,11,11,11,11,1111,11,11,11,11,11,11,11,11,11,11,11,11,11,11,1111,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11
    dest: .WORD 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,00,0,0,0,0,0,0,0,0,0,0,0,0,0,0,00,0,0,0,0,0,0,0,0,0,0,0,0,0,0,00,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

.text

MOV r0,#7
LDR r9,=src 
LDR r10,=dest

loop:
    LDMIA r9!,{r1-r8}
    STMIA r10!,{r1-r8}
    SUB r0,r0,#1 
    CMP r0,#0 
    BEQ end 
    B loop

end: SWI 0x11
   