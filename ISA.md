# Instruction Set Architecture (ISA)

| Opcode | Mnemonic | Operands         | Example           | Description                               |
|--------|----------|------------------|-------------------|-------------------------------------------|
| 0x01   | MOV      | Rdest, Rsrc      | MOV R1, R2        | Copy contents of R2 into R1               |
| 0x02   | MOV      | Rdest, IMM       | MOV R1, 10        | Load constant 10 into R1                  |
| 0x03   | LOAD     | Rdest, [addr]    | LOAD R1, [200]    | Load value at memory[200] into R1         |
| 0x04   | STORE    | Rsrc, [addr]     | STORE R1, [300]   | Store value in R1 into memory[300]        |
| 0x10   | ADD      | Rdest, Rsrc      | ADD R1, R2        | R1 = R1 + R2                              |
| 0x11   | SUB      | Rdest, Rsrc      | SUB R1, R2        | R1 = R1 - R2                              |
| 0x12   | INC      | Rdest            | INC R1            | Increment R1 by 1                         |
| 0x13   | DEC      | Rdest            | DEC R1            | Decrement R1 by 1                         |
| 0x20   | AND      | Rdest, Rsrc      | AND R1, R2        | Bitwise AND                               |
| 0x21   | OR       | Rdest, Rsrc      | OR R1, R2         | Bitwise OR                                |
| 0x22   | XOR      | Rdest, Rsrc      | XOR R1, R2        | Bitwise XOR                               |
| 0x23   | NOT      | Rdest            | NOT R1            | Bitwise NOT                               |
| 0x30   | SHL      | Rdest, IMM       | SHL R1, 1         | Shift left R1 by 1                        |
| 0x31   | SHR      | Rdest, IMM       | SHR R1, 1         | Shift right R1 by 1                       |
| 0x40   | CMP      | R1, R2           | CMP R1, R2        | Compare R1 and R2 (sets FLAGS)            |
| 0x60   | JMP      | addr             | JMP 400           | Jump to address 400                       |
| 0x61   | JZ       | addr             | JZ 150            | Jump if Zero flag is set                  |
| 0x62   | JNZ      | addr             | JNZ 200           | Jump if Zero flag is clear                |
| 0x63   | JC       | addr             | JC 250            | Jump if Carry flag is set                 |
| 0x64   | JNC      | addr             | JNC 300           | Jump if Carry flag is clear               |
| 0x65   | HLT      | —                | HLT               | Halt execution                            |
