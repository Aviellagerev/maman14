.define sz = 2
MAIN: mov r3, LIST[sz]
LOOP: jmp L1
mcr m_mcr
cmp r3, #sz
 bne END
endmcr
mcr b_cr
cmp r1,r2
cmp r2,r3
add r3,r3
endmcr
 prn #-5
 mov STR[5], STR[2]
 sub r1, r4
 m_mcr
L1: inc K
 bne LOOP
END: hlt
.define len = 4
b_cr
STR: .string “abcdef”
LIST: .data 6, -9, len
K: .data 22 