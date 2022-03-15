.data
    .equ SEG_A,0x80
    .equ SEG_B,0x40
    .equ SEG_C,0x20
    .equ SEG_D,0x08
    .equ SEG_E,0x04
    .equ SEG_F,0x02
    .equ SEG_G,0x01
    .equ SEG_P,0x10
    zero: .byte  0b11101101
    one:  .byte  0b01100000
    two:  .byte  0b01101110
    three:  .byte  0b11111010
    four:  .byte  0b00110011
    five:  .byte  0b10101011
    six:  .byte  0b10101111
    seven: .byte  0b01110000
    eight: .byte  0b11101111
    nine: .byte  0b11100011   
    A:  .byte  0b11100111
    B:  .byte  0b00101111
    C:  .byte  0b10001101
    D:  .byte  0b01101110
    E:  .byte  0b10001111
    F:  .byte  0b10000111

.text
    MOV r6,#16
    LDR r5,=zero 
    
loop:
    CMP r6,#0 
    BEQ end
    SWI 0x202 
    CMP r0,#0x02
    BLEQ print_next
    B loop
    
print_next:
    LDRB r0,[r5],#1 
    SWI 0x200
    SUB r6,r6,#1
    MOV pc,lr
end: .end


