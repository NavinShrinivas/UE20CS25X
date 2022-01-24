mov r0,#10
mov r1,#10

CMP r0,r1
BEQ equal

B notequal

notequal : 
    SUB r3,r0,r1
    B end
equal :
    ADD r3,r0,r1
    B end

end : .end

