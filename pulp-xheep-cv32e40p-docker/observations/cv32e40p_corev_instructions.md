# List of core-v instructions supported by the CV32E40P core

This list was compiled from [the cv32e40p user's manual](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html).

Cross reference to pulp instructions was built from information in [our pulp compilation](./xpulp_corev-group-instructions.md) and [the pulp opcodes list](https://github.com/pulp-platform/riscv-opcodes/tree/master).

## Post-Increment Load & Store Instructions and Register-Register Load & Store Instructions

Description: Can be found [here](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html#post-increment-load-store-instructions-and-register-register-load-store-instructions).

### Load Operations

Matches xpulppostmod and xpulpindregreg ([src](https://github.com/pulp-platform/riscv-gnu-toolchain/blob/master/core-v.rst)).

#### Register-Immediate Loads with Post-Increment

| Mnemonic | Usage | Description | Pulp equivalent | Tested |
|----------|-------|-------------|-----------------|:------:|
| cv.lb | cv.lb rD, (rs1), Imm | <code> rD = Sext(Mem8(rs1)) </code> <br> <code> rs1 += Sext(Imm[11:0]) </code> | p.lb | [X] |
| cv.lbu | cv.lbu rD, (rs1), Imm | <code> rD = Zext(Mem8(rs1)) </code> <br> <code> rs1 += Sext(Imm[11:0]) </code> | p.lbu | [X] |
| cv.lh | cv.lh rD, (rs1), Imm | <code> rD = Sext(Mem16(rs1)) </code> <br> <code> rs1 += Sext(Imm[11:0]) </code> | p.lh | [X] |
| cv.lhu | cv.lhu rD, (rs1), Imm | <code> rD = Zext(Mem16(rs1)) </code> <br> <code> rs1 += Sext(Imm[11:0]) </code> | p.lhu | [X] |
| cv.lw | cv.lw rD, (rs1), Imm | <code> rD = Mem32(rs1) </code> <br> <code> rs1 += Sext(Imm[11:0]) </code> | p.lw | [X] |

#### Register-Register Loads with Post-Increment

| Mnemonic | Usage | Description | Pulp equivalent | Tested |
|----------|-------|-------------|-----------------|:------:|
| cv.lb | cv.lb rD, (rs1), rs2 | <code> rD = Sext(Mem8(rs1)) </code> <br> <code> rs1 += rs2 </code> | p.lb | [X] |
| cv.lbu | cv.lbu rD, (rs1), rs2 | <code> rD = Zext(Mem8(rs1)) </code> <br> <code> rs1 += rs2 </code> | p.lbu | [X] |
| cv.lh | cv.lh rD, (rs1), rs2 | <code> rD = Sext(Mem16(rs1)) </code> <br> <code> rs1 += rs2 </code> | p.lh | [X] |
| cv.lhu | cv.lhu rD, (rs1), rs2 | <code> rD = Zext(Mem16(rs1)) </code> <br> <code> rs1 += rs2 </code> | p.lhu | [X] |
| cv.lw | cv.lw rD, (rs1), rs2 | <code> rD = Mem32(rs1) </code> <br> <code> rs1 += rs2 </code> | p.lw | [X] |

#### Register-Register Loads

| Mnemonic | Usage | Description | Pulp equivalent | Tested |
|----------|-------|-------------|-----------------|:------:|
| cv.lb | cv.lb rD, rs2(rs1) | <code> rD = Sext(Mem8(rs1 + rs2)) </code> | p.lb | [X] |
| cv.lbu | cv.lbu rD, rs2(rs1) | <code> rD = Zext(Mem8(rs1 + rs2)) </code> | p.lbu | [X] |
| cv.lh | cv.lh rD, rs2(rs1) | <code> rD = Sext(Mem16(rs1 + rs2)) </code> | p.lh | [X] |
| cv.lhu | cv.lhu rD, rs2(rs1) | <code> rD = Zext(Mem16(rs1 + rs2)) </code> | p.lhu | [X] |
| cv.lw | cv.lw rD, rs2(rs1) | <code> rD = Mem32(rs1 + rs2) </code> | p.lw | [X] |

### Store Operations

| Mnemonic | Usage | Description | Pulp equivalent | Tested |
|----------|-------|-------------|-----------------|:------:|
| cv.sb | cv.sb rs2, (rs1), Imm | <code> Mem8(rs1) = rs2 </code> <br> <code> rs1 += Sext(Imm[11:0]) </code> | p.sb | [X] |
| cv.sh | cv.sh rs2, (rs1), Imm | <code> Mem16(rs1) = rs2 </code> <br> <code> rs1 += Sext(Imm[11:0]) </code> | p.sh | [X] |
| cv.sw | cv.sw rs2, (rs1), Imm | <code> Mem32(rs1) = rs2 </code> <br> <code> rs1 += Sext(Imm[11:0]) </code> | p.sw | [X] |
| cv.sb | cv.sb rs2, (rs1), rs3 | <code> Mem8(rs1) = rs2 </code> <br> <code> rs1 += rs3 </code> | p.sb | [X] |
| cv.sh | cv.sh rs2, (rs1), rs3 | <code> Mem16(rs1) = rs2 </code> <br> <code> rs1 += rs3 </code> | p.sh | [X] |
| cv.sw | cv.sw rs2, (rs1), rs3 | <code> Mem32(rs1) = rs2 </code> <br> <code> rs1 += rs3 </code> | p.sw | [X] |
| cv.sb | cv.sb rs2, rs3(rs1) | <code> Mem8(rs1 + rs3) = rs2 </code> | p.sb | [X] |
| cv.sh | cv.sh rs2 rs3(rs1) | <code> Mem16(rs1 + rs3) = rs2 </code> | p.sh | [X] |
| cv.sw | cv.sw rs2, rs3(rs1) | <code> Mem32(rs1 + rs3) = rs2 </code> | p.sw | [X] |

## Event Load Instruction

Description: Can be found [here](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html#event-load-instruction).


| Mnemonic | Usage | Description | Pulp equivalent | Tested |
|----------|-------|-------------|-----------------|:------:|
| cv.elw | cv.elw rD, Imm(rs1) | <code> rD = Mem32(Sext(Imm) + rs1) </code> | p.elw | [ ] |

## Hardware Loops

Description: Can be found [here](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html#hardware-loops).
Note: The start and end addresses accept flags. For example, `cv.starti 0, loop_start`.

| Mnemonic | Usage | Description | Pulp equivalent | Tested |
|----------|-------|-------------|-----------------|:------:|
| cv.starti | cv.starti L, uimmL | <code> lpstart[L] = PC + (uimmL << 2) </code> | lp.starti | [X] |
| cv.start | cv.start L, rs1 | <code> lpstart[L] = rs1 </code> | ?? | [X] |
| cv.endi | cv.endi L, uimmL | <code> lpend[L] = PC + (uimmL << 2) </code> | lp.endi| [X] |
| cv.end | cv.end L, rs1 | <code> lpend[L] = rs1 </code> | ?? | [X] |
| cv.counti | cv.counti L, uimmL | <code> lpcount[L] = uimmL </code> | lp.counti | [X] |
| cv.count | cv.count L, rs1 | <code> lpcount[L] = rs1 </code> | lp.count | [X] |
| cv.setupi | cv.setupi L, uimmL, uimmS | <code> lpstart[L] = PC + 4 </code> <br> <code> lpend[L] = PC + (uimmS << 2) </code> <br> <code> lpcount[L] = uimmL </code> | lp.setupi | [X] |
| cv.setup | cv.setup L, rs1, uimmL | <code> lpstart[L] = PC + 4 </code> <br> <code> lpend[L] = PC + (uimmL << 2) </code> <br> <code> lpcount[L] = rs1 </code> | lp.setup | [X] |

## ALU

Description: Can be found [here](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html#alu).

### Bit Manipulation operations


| Mnemonic | Usage | Description | Pulp equivalent | Tested |
|----------|-------|-------------|-----------------|:------:|
| cv.extract | cv.extract rD, rs1, Is3, Is2 | <code> rD = Sext(rs1[min(Is3+Is2,31):Is2]) </code> <br> <code> Note: Sign extension is done over the MSB of the extracted part. </code> | p.extract | [X] |
| cv.extractu | cv.extractu rD, rs1, Is3, Is2 | <code> rD = Zext(rs1[min(Is3+Is2,31):Is2]) </code> | p.extractu | [X] |
| cv.extractr | cv.extractr rD, rs1, rs2 | <code> rD = Sext(rs1[min(rs2[9:5]+rs2[4:0],31):rs2[4:0]]) </code> <br> <code> Note: Sign extension is done over the MSB of the extracted part. </code> | p.extractr | [X] |
| cv.extractur | cv.extractur rD, rs1, rs2 | <code> rD = Zext(rs1[min(rs2[9:5]+rs2[4:0],31):rs2[4:0]]) </code> | p.extractur | [X] |
| cv.insert | cv.insert rD, rs1, Is3, Is2 | <code> rD[min(Is3+Is2,31):Is2] = rs1[Is3-(max(Is3+Is2,31)-31):0] </code> <br> <code> The rest of the bits of rD are untouched and keep their previous value. </code> <br> <code> Is3 + Is2 must be < 32. </code>  | p.insert | [X] |
| cv.insertr | cv.insertr rD, rs1, rs2 | <code>  rD[min(rs2[9:5]+rs2[4:0],31):rs2[4:0]] = rs1[rs2[9:5]-(max(rs2[9:5]+rs2[4:0],31)-31):0] </code> <br> <code>  The rest of the bits of rD are untouched and keep their previous value. </code> <br> <code> Is3 + Is2 must be < 32. </code>  | p.insertr | [X] |
| cv.bclr | cv.bclr rD, rs1, Is3, Is2 | <code>  rD[min(Is3+Is2,31):Is2] bits set to 0 </code> <br> <code> The rest of the bits of rD are passed through from rs1 and are not modified. </code>  | p.bclr | [X] |
| cv.bclrr | cv.bclrr rD, rs1, rs2 | <code>  rD[min(rs2[9:5]+rs2[4:0],31):rs2[4:0]] bits set to 0 </code> <br> <code> The rest of the bits of rD are passed through from rs1 and are not modified. </code>  | p.bclrr | [X] |
| cv.bset | cv.bset rD, rs1, Is3, Is2 | <code>  rD[min(Is3+Is2,31):Is2] bits set to 1 </code> <br> <code> The rest of the bits of rD are passed through from rs1 and are not modified. </code>  | p.bset | [X] |
| cv.bsetr | cv.bsetr rD, rs1, rs2 | <code>  rD[min(rs2[9:5]+rs2[4:0],31):rs2[4:0]] bits set to 1 </code> <br> <code> The rest of the bits of rD are passed through from rs1 and are not modified. </code>  | p.bsetr | [X] |
| cv.ff1 | cv.ff1 rD, rs1 | <code>  rD = bit position of the first bit set in rs1, starting from LSB. </code> <br> <code> If bit 0 is set, rD will be 0. If only bit 31 is set, rD will be 31. </code> <br> <code> If rs1 is 0, rD will be 32. </code>  | p.ff1 | [X] |
| cv.fl1 | cv.fl1 rD, rs1 | <code>  rD = bit position of the last bit set in rs1, starting from MSB. </code> <br> <code> If bit 31 is set, rD will be 31. If only bit 0 is set, rD will be 0. </code> <br> <code> If rs1 is 0, rD will be 32. </code>  | p.fl1 | [X] |
| cv.clb | cv.clb rD, rs1 | <code>  rD = count leading bits of rs1 </code> <br> <code> Number of consecutive 1’s or 0’s starting from MSB. </code> <br> <code> If rs1 is 0, rD will be 0. If rs1 is different than 0, returns (number - 1). </code>  | p.clb | [X] |
| cv.cnt | cv.cnt rD, rs1 | <code>  rD = Population count of rs1 </code> <br> <code> Number of bits set in rs1. </code>  | p.cnt | [X] |
| cv.ror | cv.ror rD, rs1, rs2 | <code>  rD = RotateRight(rs1, rs2) </code>  | p.ror | [X] |
| cv.bitrev | cv.bitrev rD, rs1, Is3, Is2 | <code>  Given an input rs1 it returns a bit reversed representation assuming FFT on 2^Is2 points in Radix 2^(Is3+1). </code> <br> <code> Is3 can be either 0 (radix-2), 1 (radix-4) or 2 (radix-8). </code> <br> <code> Note: When Is3 = 3, instruction has the same bahavior as if it was 0 (radix-2). </code>  | possibly p.bitrev | [X] |

### General ALU operations

Note: In cv32e40p's manual, `cv.sle` is mentioned, but the core-v-verif repository uses `cv.slet` instead. I have tested the instructions separately and they appear to behave in the same way. The same applies to its unsigned counterpart, `cv.sleu` and `cv.sletu`.

| Mnemonic | Usage | Description | Pulp equivalent | Tested |
|----------|-------|-------------|-----------------|:------:|
| cv.abs | cv.abs rD, rs1 | <code>  rD = rs1 < 0 ? -rs1 : rs1 </code>  | p.abs | [X] |
| cv.sle[t] | cv.sle[t] rD, rs1, rs2 | <code>  rD = rs1 <= rs2 ? 1 : 0 </code> <br> <code> Note: Comparison is signed. </code>  | p.slet | [X] |
| cv.sle[t]u | cv.sle[t]u rD, rs1, rs2 | <code>  rD = rs1 <= rs2 ? 1 : 0 </code> <br> <code> Note: Comparison is unsigned. </code>  | p.sletu | [X] |
| cv.min | cv.min rD, rs1, rs2 | <code>  rD = rs1 < rs2 ? rs1 : rs2 </code> <br> <code> Note: Comparison is signed. </code>  | p.min | [X] |
| cv.minu | cv.minu rD, rs1, rs2 | <code>  rD = rs1 < rs2 ? rs1 : rs2 </code> <br> <code> Note: Comparison is unsigned. </code>  | p.minu | [X] |
| cv.max | cv.max rD, rs1, rs2 | <code>  rD = rs1 < rs2 ? rs2 : rs1 </code> <br> <code> Note: Comparison is signed. </code>  | p.max | [X] |
| cv.maxu | cv.maxu rD, rs1, rs2 | <code>  rD = rs1 < rs2 ? rs2 : rs1 </code> <br> <code> Note: Comparison is unsigned. </code>  | p.maxu | [X] |
| cv.exths | cv.exths rD, rs1 | <code>  rD = Sext(rs1[15:0]) </code>  | p.exths | [X] |
| cv.exthz | cv.exthz rD, rs1 | <code>  rD = Zext(rs1[15:0]) </code>  | p.exthz | [X] |
| cv.extbs | cv.extbs rD, rs1 | <code>  rD = Sext(rs1[7:0]) </code>  | p.extbs | [X] |
| cv.extbz | cv.extbz rD, rs1 | <code>  rD = Zext(rs1[7:0]) </code>  | p.extbz | [X] |
| cv.clip | cv.clip rD, rs1, Is2 | <code>  if rs1 <= -2^(Is2-1), rD = -2^(Is2-1), </code> <br> <code> else if rs1 >= 2^(Is2-1)-1, rD = 2^(Is2-1)-1, </code> <br> <code> else rD = rs1 </code> <br> <code> Note: If Is2 is equal to 0, -2^(Is2-1) is equivalent to -1 while (2^(Is2-1)-1) is equivalent to 0. </code>  | p.clip | [X] |
| cv.clipu | cv.clipu rD, rs1, Is2 | <code>  if rs1 <= 0, rD = 0, </code> <br> <code> else if rs1 >= 2^(Is2-1)-1, rD = 2^(Is2-1)-1, </code> <br> <code> else rD = rs1 </code> <br> <code> Note: If Is2 is equal to 0, (2^(Is2-1)-1) is equivalent to 0. </code>  | p.clipu | [X] |
| cv.clipr | cv.clipr rD, rs1, rs2 | <code>  rs2’ = rs2 & 0x7FFFFFFF </code> <br> <code> if rs1 <= -(rs2’+1), rD = -(rs2’+1), </code> <br> <code> else if rs1 >=rs2’, rD = rs2’, </code> <br> <code> else rD = rs1 </code>  | p.clipr | [X] |
| cv.clipur | cv.clipur rD, rs1, rs2 | <code>  rs2’ = rs2 & 0x7FFFFFFF </code> <br> <code> if rs1 <= 0, rD = 0, </code> <br> <code> else if rs1 >= rs2’, rD = rs2’, </code> <br> <code> else rD = rs1 </code>  | p.clipur | [X] |
| cv.addN | cv.addN rD, rs1, rs2, Is3 | <code>  rD = (rs1 + rs2) >>> Is3 </code> <br> <code> Note: Arithmetic shift right. </code> <br> <code> Setting Is3 to 1 replaces former cv.avg. </code>  | p.avg or p.addn | [X] |
| cv.adduN | cv.adduN rD, rs1, rs2, Is3 | <code>  rD = (rs1 + rs2) >> Is3 </code> <br> <code> Note: Logical shift right. </code> <br> <code> Setting Is3 to 1 replaces former cv.avgu. </code>  | p.addun | [X] |
| cv.addRN | cv.addRN rD, rs1, rs2, Is3 | <code>  rD = (rs1 + rs2 + 2^(Is3-1)) >>> Is3 </code> <br> <code> Note: Arithmetic shift right. </code> <br> <code> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | p.addrn | [X] |
| cv.adduRN | cv.adduRN rD, rs1, rs2, Is3 | <code>  rD = (rs1 + rs2 + 2^(Is3-1))) >> Is3 </code> <br> <code> Note: Logical shift right. </code> <br> <code> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | p.addurn | [X] |
| cv.subN | cv.subN rD, rs1, rs2, Is3 | <code>  rD = (rs1 - rs2) >>> Is3 </code> <br> <code> Note: Arithmetic shift right. </code>  | p.subn | [X] |
| cv.subuN | cv.subuN rD, rs1, rs2, Is3 | <code>  rD = (rs1 - rs2) >> Is3 </code> <br> <code> Note: Logical shift right. </code>  | p.subun | [X] |
| cv.subRN | cv.subRN rD, rs1, rs2, Is3 | <code>  rD = (rs1 - rs2 + 2^(Is3-1)) >>> Is3 </code> <br> <code> Note: Arithmetic shift right. </code> <br> <code> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | p.subrn | [X] |
| cv.subuRN | cv.subuRN rD, rs1, rs2, Is3 | <code>  rD = (rs1 - rs2 + 2^(Is3-1))) >> Is3 </code> <br> <code> Note: Logical shift right. </code> <br> <code> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | p.suburn | [X] |
| cv.addNr | cv.addNr rD, rs1, rs2 | <code>  rD = (rD + rs1) >>> rs2[4:0] </code> <br> <code> Note: Arithmetic shift right. </code>  | p.addnr | [X] |
| cv.adduNr | cv.adduNr rD, rs1, rs2 | <code>  rD = (rD + rs1) >> rs2[4:0] </code> <br> <code> Note: Logical shift right. </code>  | p.addunr | [X] |
| cv.addRNr | cv.addRNr rD, rs1, rs2 | <code>  rD = (rD + rs1 + 2^(rs2[4:0]-1)) >>> rs2[4:0] </code> <br> <code> Note: Arithmetic shift right. </code> <br> <code> If rs2[4:0] is equal to 0, 2^(rs2[4:0]-1) is equivalent to 0. </code>  | p.addrnr | [X] |
| cv.adduRNr | cv.adduRNr rD, rs1, rs2 | <code>  rD = (rD + rs1 + 2^(rs2[4:0]-1))) >> rs2[4:0] </code> <br> <code> Note: Logical shift right. </code> <br> <code> If rs2[4:0] is equal to 0, 2^(rs2[4:0]-1) is equivalent to 0. </code>  | p.addurnr | [X] |
| cv.subNr | cv.subNr rD, rs1, rs2 | <code>  rD = (rD - rs1) >>> rs2[4:0] </code> <br> <code> Note: Arithmetic shift right. </code>  | p.subnr | [X] |
| cv.subuNr | cv.subuNr rD, rs1, rs2 | <code>  rD = (rD - rs1) >> rs2[4:0] </code> <br> <code> Note: Logical shift right. </code>  | p.subunr | [X] |
| cv.subRNr | cv.subRNr rD, rs1, rs2 | <code>  rD = (rD - rs1+ 2^(rs2[4:0]-1)) >>> rs2[4:0] </code> <br> <code> Note: Arithmetic shift right. </code> <br> <code> If rs2[4:0] is equal to 0, 2^(rs2[4:0]-1) is equivalent to 0. </code>  | p.subrnr | [X] |
| cv.subuRNr | cv.subuRNr rD, rs1, rs2 | <code>  rD = (rD - rs1+ 2^(rs2[4:0]-1))) >> rs2[4:0] </code> <br> <code> Note: Logical shift right. </code> <br> <code> If rs2[4:0] is equal to 0, 2^(rs2[4:0]-1) is equivalent to 0. </code>  | p.suburnr | [X] |

### Immediate Branching Operations

| Mnemonic | Usage | Description | Pulp equivalent | Tested |
|----------|-------|-------------|-----------------|:------:|
| cv.beqimm | cv.beqimm rs1, Imm5, Imm12 | <code>  Branch to PC + (Imm12 << 1) if rs1 is equal to Imm5. </code> <br> <code> Note: Imm5 is signed. </code>  | p.beqimm | [X] |
| cv.bneimm | cv.bneimm rs1, Imm5, Imm12 | <code>  Branch to PC + (Imm12 << 1) if rs1 is not equal to Imm5. </code> <br> <code> Note: Imm5 is signed. </code>  | p.bneimm | [X] |

## Multiply-Accumulate

Description: Can be found [here](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html#multiply-accumulate).

### 16-Bit x 16-Bit Multiplication operations

| Mnemonic | Usage | Description | Pulp equivalent | Tested |
|----------|-------|-------------|-----------------|:------:|
| cv.muluN | cv.muluN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Zext(rs1[15:0]) * Zext(rs2[15:0])) >> Is3 </code> <br> <code> Note: Logical shift right. </code>  | p.muluN | [X] |
| cv.mulhhuN | cv.mulhhuN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Zext(rs1[31:16]) * Zext(rs2[31:16])) >> Is3 </code> <br> <code> Note: Logical shift right. </code>  | p.mulhhuN | [X] |
| cv.mulsN | cv.mulsN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Sext(rs1[15:0]) * Sext(rs2[15:0])) >>> Is3 </code> <br> <code> Note: Arithmetic shift right. </code>  | p.mulsN | [X] |
| cv.mulhhsN | cv.mulhhsN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Sext(rs1[31:16]) * Sext(rs2[31:16])) >>> Is3 </code> <br> <code> Note: Arithmetic shift right. </code>  | p.mulhhsN | [X] |
| cv.muluRN | cv.muluRN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Zext(rs1[15:0]) * Zext(rs2[15:0]) + 2^(Is3-1)) >> Is3 </code> <br> <code> Note: Logical shift right. </code> <br> <code> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | p.muluRN | [X] |
| cv.mulhhuRN | cv.mulhhuRN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Zext(rs1[31:16]) * Zext(rs2[31:16]) + 2^(Is3-1)) >> Is3 </code> <br> <code> Note: Logical shift right. </code> <br> <code> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | p.mulhhuRN | [X] |
| cv.mulsRN | cv.mulsRN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Sext(rs1[15:0]) * Sext(rs2[15:0]) + 2^(Is3-1)) >>> Is3 </code> <br> <code> Note: Arithmetic shift right. </code> <br> <code> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | p.mulsRN | [X] |
| cv.mulhhsRN | cv.mulhhsRN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Sext(rs1[31:16]) * Sext(rs2[31:16]) + 2^(Is3-1)) >>> Is3 </code> <br> <code> Note: Arithmetic shift right. </code> <br> <code> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | p.mulhhsRN | [X] |

### 16-Bit x 16-Bit Multiplication pseudo-instructions

| Mnemonic | Usage | Base Instruction | Description | Pulp equivalent | Tested |
|----------|-------|------------------|-------------|-----------------|:------:|
| cv.mulu | cv.mulu rD, rs1, rs2 | cv.muluN rD, rs1, rs2, 0 | <code> rD[31:0] = (Zext(rs1[15:0]) * Zext(rs2[15:0])) >> 0 </code> <br> <code> Note: Logical shift right. </code>  | p.mulu | [X] |
| cv.mulhhu | cv.mulhhu rD, rs1, rs2 | cv.mulhhuN rD, rs1, rs2, 0 | <code> rD[31:0] = (Zext(rs1[31:16]) * Zext(rs2[31:16])) >> 0 </code> <br> <code> Note: Logical shift right. </code>  | p.mulhhu | [X] |
| cv.muls | cv.muls rD, rs1, rs2 | cv.mulsN rD, rs1, rs2, 0 | <code> rD[31:0] = (Sext(rs1[15:0]) * Sext(rs2[15:0])) >> 0 </code> <br> <code> Note: Arithmetic shift right. </code>  | p.muls | [X] |
| cv.mulhhs | cv.mulhhs rD, rs1, rs2 | cv.mulhhsN rD, rs1, rs2, 0 | <code> rD[31:0] = (Sext(rs1[31:16]) * Sext(rs2[31:16])) >> 0 </code> <br> <code> Note: Arithmetic shift right. </code>  | p.mulhhs | [X] |

### 16-Bit x 16-Bit Multiply-Accumulate operations

| Mnemonic | Usage | Description | Pulp equivalent | Tested |
|----------|-------|-------------|-----------------|:------:|
| cv.macuN | cv.macuN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Zext(rs1[15:0]) * Zext(rs2[15:0]) + rD) >> Is3 </code> <br> <code> Note: Logical shift right. </code>  | p.macuN | [X] |
| cv.machhuN | cv.machhuN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Zext(rs1[31:16]) * Zext(rs2[31:16]) + rD) >> Is3 </code> <br> <code> Note: Logical shift right. </code>  | p.machhuN | [X] |
| cv.macsN | cv.macsN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Sext(rs1[15:0]) * Sext(rs2[15:0]) + rD) >>> Is3 </code> <br> <code> Note: Arithmetic shift right. </code>  | p.macsN | [X] |
| cv.machhsN | cv.machhsN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Sext(rs1[31:16]) * Sext(rs2[31:16]) + rD) >>> Is3 </code> <br> <code> Note: Arithmetic shift right. </code>  | p.machhsN | [X] |
| cv.macuRN | cv.macuRN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Zext(rs1[15:0]) * Zext(rs2[15:0]) + rD + 2^(Is3-1)) >> Is3 </code> <br> <code> Note: Logical shift right. </code> <br> <code> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | p.macuRN | [X] |
| cv.machhuRN | cv.machhuRN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Zext(rs1[31:16]) * Zext(rs2[31:16]) + rD + 2^(Is3-1)) >> Is3 </code> <br> <code> Note: Logical shift right. </code> <br> <code> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | p.machhuRN | [X] |
| cv.macsRN | cv.macsRN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Sext(rs1[15:0]) * Sext(rs2[15:0]) + rD + 2^(Is3-1)) >>> Is3 </code> <br> <code> Note: Arithmetic shift right. </code> <br> <code> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | p.macsRN | [X] |
| cv.machhsRN | cv.machhsRN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Sext(rs1[31:16]) * Sext(rs2[31:16]) + rD + 2^(Is3-1)) >>> Is3 </code> <br> <code> Note: Arithmetic shift right. </code> <br> <code> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | p.machhsRN | [X] |

### 32-Bit x 32-Bit Multiply-Accumulate operations

| Mnemonic | Usage | Description | Pulp equivalent | Tested |
|----------|-------|-------------|-----------------|:------:|
| cv.mac | cv.mac rD, rs1, rs2 | <code>  rD = rD + rs1 * rs2 </code>  | p.mac | [X] |
| cv.msu | cv.msu rD, rs1, rs2 | <code>  rD = rD - rs1 * rs2 </code>  | p.msu | [X] |

## SIMD

Description: Can be found [here](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html#simd).

### SIMD ALU operations

| Mnemonic | Usage | Description | Pulp equivalent | Tested |
|----------|-------|-------------|-----------------|:------:|
| cv.add[.sc,.sci]{.h,.b} | cv.add[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = (rs1[i] + op2[i]) & {0xFFFF, 0xFF} </code>  | pv.add[.sc,.sci]{.h,.b} | [X] |
| cv.sub[.sc,.sci]{.h,.b} | cv.sub[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = (rs1[i] - op2[i]) & {0xFFFF, 0xFF} </code>  | pv.sub[.sc,.sci]{.h,.b} | [X] |
| cv.avg[.sc,.sci]{.h,.b} | cv.avg[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = ((rs1[i] + op2[i]) & {0xFFFF, 0xFF}) >> 1 </code> <br> <code> Note: Arithmetic right shift. </code>  | pv.avg[.sc,.sci]{.h,.b} | [X] |
| cv.avgu[.sc,.sci]{.h,.b} | cv.avgu[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = ((rs1[i] + op2[i]) & {0xFFFF, 0xFF}) >> 1 </code> <br> <code> Note: Immediate is zero-extended, shift is logical. </code>  | pv.avgu[.sc,.sci]{.h,.b} | [X] |
| cv.min[.sc,.sci]{.h,.b} | cv.min[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = rs1[i] < op2[i] ? rs1[i] : op2[i] </code>  | pv.min[.sc,.sci]{.h,.b} | [X] |
| cv.minu[.sc,.sci]{.h,.b} | cv.minu[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = rs1[i] < op2[i] ? rs1[i] : op2[i] </code> <br> <code> Note: Immediate is zero-extended, comparison is unsigned. </code>  | pv.minu[.sc,.sci]{.h,.b} | [X] |
| cv.max[.sc,.sci]{.h,.b} | cv.max[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = rs1[i] > op2[i] ? rs1[i] : op2[i] </code>  | pv.max[.sc,.sci]{.h,.b} | [X] |
| cv.maxu[.sc,.sci]{.h,.b} | cv.maxu[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = rs1[i] > op2[i] ? rs1[i] : op2[i] </code> <br> <code> Note: Immediate is zero-extended, comparison is unsigned. </code>  | pv.maxu[.sc,.sci]{.h,.b} | [X] |
| cv.srl[.sc,.sci]{.h,.b} | cv.srl[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = rs1[i] >> op2[i] </code> <br> <code> Note: Immediate is zero-extended, shift is logical. </code> <br> <code> Only Imm6[3:0] and rs2[3:0] are used for .h instruction and Imm6[2:0] and rs2[2:0] for .b instruction. </code> <br> <code> In .sci case, unused Imm6 bits must be set to 0. </code>  | pv.srl[.sc,.sci]{.h,.b} | [X] |
| cv.sra[.sc,.sci]{.h,.b} | cv.sra[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = rs1[i] >>> op2[i] </code> <br> <code> Note: Immediate is zero-extended, shift is arithmetic. </code> <br> <code> Only Imm6[3:0] and rs2[3:0] are used for .h instruction and Imm6[2:0] and rs2[2:0] for .b instruction. </code> <br> <code> In .sci case, unused Imm6 bits must be set to 0. </code>  | pv.sra[.sc,.sci]{.h,.b} | [X] |
| cv.sll[.sc,.sci]{.h,.b} | cv.sll[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = rs1[i] << op2[i] </code> <br> <code> Note: Immediate is zero-extended, shift is logical. </code> <br> <code> Only Imm6[3:0] and rs2[3:0] are used for .h instruction and Imm6[2:0] and rs2[2:0] for .b instruction. </code> <br> <code> In .sci case, unused Imm6 bits must be set to 0. </code>  | pv.sll[.sc,.sci]{.h,.b} | [X] |
| cv.or[.sc,.sci]{.h,.b} | cv.or[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = rs1[i] \| op2[i] </code>  | pv.or[.sc,.sci]{.h,.b} | [X] |
| cv.xor[.sc,.sci]{.h,.b} | cv.xor[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = rs1[i] ^ op2[i] </code>  | pv.xor[.sc,.sci]{.h,.b} | [X] |
| cv.and[.sc,.sci]{.h,.b} | cv.and[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = rs1[i] & op2[i] </code>  | pv.and[.sc,.sci]{.h,.b} | [X] |
| cv.abs{.h,.b} | cv.abs{.h,.b} rD, rs1 | <code>  rD[i] = rs1[i] < 0 ? -rs1[i] : rs1[i] </code>  | pv.abs{.h,.b} | [X] |

### SIMD Bit Manipulation operations

| Mnemonic | Usage | Description | Pulp equivalent | Tested |
|----------|-------|-------------|-----------------|:------:|
| cv.extract.h | cv.extract.h rD, rs1, Imm6 | <code>  rD = Sext(rs1[I0*16+15:I0*16]) </code> <br> <code> Note: Only Imm6[0] bit is used and other Imm6 bits must be set to 0. </code>  | pv.extract.h | [X] |
| cv.extract.b | cv.extract.b rD, rs1, Imm6 | <code>  rD = Sext(rs1[(I1:I0)*8+7:(I1:I0)*8]) </code> <br> <code> Note: Only Imm6[1:0] bits are used and other Imm6 bits must be set to 0. </code>  | pv.extract.b | [X] |
| cv.extractu.h | cv.extractu.h rD, rs1, Imm6 | <code>  rD = Zext(rs1[I0*16+15:I0*16]) </code> <br> <code> Note: Only Imm6[0] bit is used and other Imm6 bits must be set to 0. </code>  | pv.extractu.h | [X] |
| cv.extractu.b | cv.extractu.b rD, rs1, Imm6 | <code>  rD = Zext(rs1[(I1:I0)*8+7:(I1:I0)*8]) </code> <br> <code> Note: Only Imm6[1:0] bits are used and other Imm6 bits must be set to 0. </code>  | pv.extractu.b | [X] |
| cv.insert.h | cv.insert.h rD, rs1, Imm6 | <code>  rD[I0*16+15:I0*16] = rs1[15:0] </code> <br> <code> Note: The rest of the bits of rD are untouched and keep their previous value. </code> <br> <code> Only Imm6[0] bit is used and other Imm6 bits must be set to 0. </code>  | pv.insert.h | [X] |
| cv.insert.b | cv.insert.b rD, rs1, Imm6 | <code>  rD[(I1:I0)*8+7:(I1:I0)*8] = rs1[7:0] </code> <br> <code> Note: The rest of the bits of rD are untouched and keep their previous value. </code> <br> <code> Only Imm6[1:0] bits are used and other Imm6 bits must be set to 0. </code>  | pv.insert.b | [X] |


### SIMD Dot Product operations

| Mnemonic | Usage | Description | Pulp equivalent | Tested |
|----------|-------|-------------|-----------------|:------:|
| cv.dotup[.sc,.sci].h | cv.dotup[.sc,.sci].h rD, rs1, [rs2, Imm6] | <code> rD = rs1[0] * op2[0] + rs1[1] * op2[1] </code> <br> <code> Note: All operands are unsigned. </code> | pv.dotup[.sc,.sci].h | [X] |
| cv.dotup[.sc,.sci].b | cv.dotup[.sc,.sci].b rD, rs1, [rs2, Imm6] | <code> rD = rs1[0] * op2[0] + rs1[1] * op2[1] +  rs1[2] * op2[2] + rs1[3] * op2[3] </code> <br> <code> Note: All operands are unsigned. </code> | pv.dotup[.sc,.sci].b | [X] |
| cv.dotusp[.sc,.sci].h | cv.dotusp[.sc,.sci].h rD, rs1, [rs2, Imm6] | <code> rD = rs1[0] * op2[0] + rs1[1] * op2[1] </code> <br> <code> Note: rs1 is treated as unsigned, while op2 is treated as signed. </code> | pv.dotusp[.sc,.sci].h | [X] |
| cv.dotusp[.sc,.sci].b | cv.dotusp[.sc,.sci].b rD, rs1, [rs2, Imm6] | <code> rD = rs1[0] * op2[0] + rs1[1] * op2[1] +  rs1[2] * op2[2] + rs1[3] * op2[3] </code> <br> <code> Note: rs1 is treated as unsigned, while op2 is treated as signed. </code> | pv.dotusp[.sc,.sci].b | [X] |
| cv.dotsp[.sc,.sci].h | cv.dotsp[.sc,.sci].h rD, rs1, [rs2, Imm6] | <code> rD = rs1[0] * op2[0] + rs1[1] * op2[1] </code> <br> <code> Note: All operands are signed. </code> | pv.dotsp[.sc,.sci].h | [X] |
| cv.dotsp[.sc,.sci].b | cv.dotsp[.sc,.sci].b rD, rs1, [rs2, Imm6] | <code> rD = rs1[0] * op2[0] + rs1[1] * op2[1] +  rs1[2] * op2[2] + rs1[3] * op2[3] </code> <br> <code> Note: All operands are signed. </code> | pv.dotsp[.sc,.sci].b | [X] |
| cv.sdotup[.sc,.sci].h | cv.sdotup[.sc,.sci].h rD, rs1, [rs2, Imm6] | <code> rD = rD + rs1[0] * op2[0] + rs1[1] * op2[1] </code> <br> <code> Note: All operands are unsigned. </code> | pv.sdotup[.sc,.sci].h | [X] |
| cv.sdotup[.sc,.sci].b | cv.sdotup[.sc,.sci].b rD, rs1, [rs2, Imm6] | <code> rD = rD + rs1[0] * op2[0] + rs1[1] * op2[1] +  rs1[2] * op2[2] + rs1[3] * op2[3] </code> <br> <code> Note: All operands are unsigned. </code> | pv.sdotup[.sc,.sci].b | [X] |
| cv.sdotusp[.sc,.sci].h | cv.sdotusp[.sc,.sci].h rD, rs1, [rs2, Imm6] | <code> rD = rD + rs1[0] * op2[0] + rs1[1] * op2[1] </code> <br> <code> Note: rs1 is treated as unsigned while op2 is treated as signed. </code> | pv.sdotusp[.sc,.sci].h | [X] |
| cv.sdotusp[.sc,.sci].b | cv.sdotusp[.sc,.sci].b rD, rs1, [rs2, Imm6] | <code> rD = rD + rs1[0] * op2[0] + rs1[1] * op2[1] +  rs1[2] * op2[2] + rs1[3] * op2[3] </code> <br> <code> Note: rs1 is treated as unsigned while op2 is treated as signed. </code> | pv.sdotusp[.sc,.sci].b | [X] |
| cv.sdotsp[.sc,.sci].h | cv.sdotsp[.sc,.sci].h rD, rs1, [rs2, Imm6] | <code> rD = rD + rs1[0] * op2[0] + rs1[1] * op2[1] </code> <br> <code> Note: All operands are signed. </code> | pv.sdotsp[.sc,.sci].h | [X] |
| cv.sdotsp[.sc,.sci].b | cv.sdotsp[.sc,.sci].b rD, rs1, [rs2, Imm6] | <code> rD = rD + rs1[0] * op2[0] + rs1[1] * op2[1] +  rs1[2] * op2[2] + rs1[3] * op2[3] </code> <br> <code> Note: All operands are signed. </code> | pv.sdotsp[.sc,.sci].b | [X] |

### SIMD Shuffle and Pack operations


| Mnemonic | Usage | Description | Pulp equivalent | Tested |
|----------|-------|-------------|-----------------|:------:|
| cv.shuffle.h | cv.shuffle.h rD, rs1, rs2 | <code> rD[31:16] = rs1[rs2[16]*16+15:rs2[16]*16] </code> <br> <code> rD[15:0] = rs1[rs2[0]*16+15:rs2[0]*16] </code> | pv.shuffle.h | [X] |
| cv.shuffle.sci.h | cv.shuffle.sci.h rD, rs1, Imm6 | <code> rD[31:16] = rs1[I1*16+15:I1*16] </code> <br> <code>  rD[15:0] = rs1[I0*16+15:I0*16] </code> <br> <code> Note: Only Imm6[1:0] bits are used and other Imm6 bits must be set to 0. </code> | pv.shuffle.sci.h | [X] |
| cv.shuffle.b | cv.shuffle.b rD, rs1, rs2 | <code> rD[31:24] = rs1[rs2[25:24]*8+7:rs2[25:24]*8] </code> <br> <code>  rD[23:16] = rs1[rs2[17:16]*8+7:rs2[17:16]*8] </code> <br> <code>  rD[15:8] = rs1[rs2[9:8]*8+7:rs2[9:8]*8] </code> <br> <code> rD[7:0] = rs1[rs2[1:0]*8+7:rs2[1:0]*8] </code> | pv.shuffle.b | [X] |
| cv.shuffleI0.sci.b | cv.shuffleI0.sci.b rD, rs1, Imm6 | <code> rD[31:24] = rs1[7:0] </code> <br> <code>  rD[23:16] = rs1[(I5:I4)*8+7: (I5:I4)*8] </code> <br> <code>  rD[15:8] = rs1[(I3:I2)*8+7: (I3:I2)*8] </code> <br> <code> rD[7:0] = rs1[(I1:I0)*8+7:(I1:I0)*8] </code> | pv.shufflei0.sci.b | [X] |
| cv.shuffleI1.sci.b | cv.shuffleI1.sci.b rD, rs1, Imm6 | <code> rD[31:24] = rs1[15:8] </code> <br> <code>  rD[23:16] = rs1[(I5:I4)*8+7: (I5:I4)*8] </code> <br> <code>  rD[15:8] = rs1[(I3:I2)*8+7: (I3:I2)*8] </code> <br> <code> rD[7:0] = rs1[(I1:I0)*8+7:(I1:I0)*8] </code> | pv.shufflei1.sci.b | [X] |
| cv.shuffleI2.sci.b | cv.shuffleI2.sci.b rD, rs1, Imm6 | <code> rD[31:24] = rs1[23:16] </code> <br> <code>  rD[23:16] = rs1[(I5:I4)*8+7: (I5:I4)*8] </code> <br> <code>  rD[15:8] = rs1[(I3:I2)*8+7: (I3:I2)*8] </code> <br> <code> rD[7:0] = rs1[(I1:I0)*8+7:(I1:I0)*8] </code> | pv.shufflei2.sci.b | [X] |
| cv.shuffleI3.sci.b | cv.shuffleI3.sci.b rD, rs1, Imm6 | <code> rD[31:24] = rs1[31:24] </code> <br> <code>  rD[23:16] = rs1[(I5:I4)*8+7: (I5:I4)*8] </code> <br> <code>  rD[15:8] = rs1[(I3:I2)*8+7: (I3:I2)*8] </code> <br> <code> rD[7:0] = rs1[(I1:I0)*8+7:(I1:I0)*8] </code> | pv.shufflei3.sci.b | [X] |
| cv.shuffle2.h | cv.shuffle2.h rD, rs1, rs2 | <code> rD[31:16] = ((rs2[17] == 1) ? rs1 : rD)[rs2[16]*16+15:rs2[16]*16] </code> <br> <code> rD[15:0] = ((rs2[1] == 1) ? rs1 : rD)[rs2[0]*16+15:rs2[0]*16] </code> | pv.shuffle2.h | [X] |
| cv.shuffle2.b | cv.shuffle2.b rD, rs1, rs2 | <code> rD[31:24] = ((rs2[26] == 1) ? rs1 : rD)[rs2[25:24]*8+7:rs2[25:24]*8] </code> <br> <code>  rD[23:16] = ((rs2[18] == 1) ? rs1 : rD)[rs2[17:16]*8+7:rs2[17:16]*8] </code> <br> <code>  rD[15:8] = ((rs2[10] == 1) ? rs1 : rD)[rs2[9:8]*8+7:rs2[9:8]*8] </code> <br> <code> rD[7:0] = ((rs2[2] == 1) ? rs1 : rD)[rs2[1:0]*8+7:rs2[1:0]*8] </code> | pv.shuffle2.b | [X] |
| cv.pack | cv.pack rD, rs1, rs2 | <code> rD[31:16] = rs1[15:0] </code> <br> <code> rD[15:0] = rs2[15:0] </code> | pv.pack | [X] |
| cv.pack.h | cv.pack.h rD, rs1, rs2 | <code> rD[31:16] = rs1[31:16] </code> <br> <code> rD[15:0] = rs2[31:16] </code> | pv.pack.h | [X] |
| cv.packhi.b | cv.packhi.b rD, rs1, rs2 | <code> rD[31:24] = rs1[7:0] </code> <br> <code>  rD[23:16] = rs2[7:0] </code> <br> <code> Note: The rest of the bits of rD are untouched and keep their previous value. </code> | pv.packhi.b | [X] |
| cv.packlo.b | cv.packlo.b rD, rs1, rs2 | <code> rD[15:8] = rs1[7:0] </code> <br> <code>  rD[7:0] = rs2[7:0] </code> <br> <code> Note: The rest of the bits of rD are untouched and keep their previous value. </code> | pv.packlo.b | [X] |

### SIMD Comparison operations

Description: Can be found [here](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html#simd-comparison-operations).

| Mnemonic | Usage | Description | Pulp equivalent | Tested |
|----------|-------|-------------|-----------------|:------:|
| cv.cmpeq[.sc,.sci]{.h,.b} | cv.cmpeq[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code> rD[i] = rs1[i] == op2 ? ‘1 : ‘0 </code> | pv.cmpeq[.sc,.sci]{.h,.b} | [X] |
| cv.cmpne[.sc,.sci]{.h,.b} | cv.cmpne[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code> rD[i] = rs1[i] != op2 ? ‘1 : ‘0 </code> | pv.cmpne[.sc,.sci]{.h,.b} | [X] |
| cv.cmpgt[.sc,.sci]{.h,.b} | cv.cmpgt[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code> rD[i] = rs1[i] > op2 ? ‘1 : ‘0 </code> | pv.cmpgt[.sc,.sci]{.h,.b} | [X] |
| cv.cmpge[.sc,.sci]{.h,.b} | cv.cmpge[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code> rD[i] = rs1[i] >=op2 ? ‘1 : ‘0 </code> | pv.cmpge[.sc,.sci]{.h,.b} | [X] |
| cv.cmplt[.sc,.sci]{.h,.b} | cv.cmplt[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code> rD[i] = rs1[i] < op2 ? ‘1 : ‘0 </code> | pv.cmplt[.sc,.sci]{.h,.b} | [X] |
| cv.cmple[.sc,.sci]{.h,.b} | cv.cmple[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code> rD[i] = rs1[i] <= op2 ? ‘1 : ‘0 </code> | pv.cmple[.sc,.sci]{.h,.b} | [X] |
| cv.cmpgtu[.sc,.sci]{.h,.b} | cv.cmpgtu[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code> rD[i] = rs1[i] > op2 ? ‘1 : ‘0 </code> <br> <code> Note: Unsigned comparison. </code> | pv.cmpgtu[.sc,.sci]{.h,.b} | [X] |
| cv.cmpgeu[.sc,.sci]{.h,.b} | cv.cmpgeu[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code> rD[i] = rs1[i] >= op2 ? ‘1 : ‘0 </code> <br> <code> Note: Unsigned comparison. </code> | pv.cmpgeu[.sc,.sci]{.h,.b} | [X] |
| cv.cmpltu[.sc,.sci]{.h,.b} | cv.cmpltu[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code> rD[i] = rs1[i] < op2 ? ‘1 : ‘0 </code> <br> <code> Note: Unsigned comparison. </code> | pv.cmpltu[.sc,.sci]{.h,.b} | [X] |

### SIMD Complex-number operations

Description: Can be found [here](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html#simd-complex-number-operations).

| Mnemonic | Usage | Description | Pulp equivalent | Tested |
|----------|-------|-------------|-----------------|:------:|
| cv.cplxmul.r[.div2,.div4,.div8] | cv.cplxmul.r[.div2,.div4,.div8] | <code> rD[1] = rD[1] </code> <br> <code>  rD[0] = (rs1[0]*rs2[0] - rs1[1]*rs2[1]) >> {15,16,17,18} </code> <br> <code> Note: Arithmetic shift right. </code> | possibly pv.cplxmul.h.r[.div2,.div4,.div8] | [X] |
| cv.cplxmul.i[.div2,.div4,.div8] | cv.cplxmul.i[.div2,.div4,.div8] | <code> rD[1] = (rs1[0]*rs2[1] + rs1[1]*rs2[0]) >> {15,16,17,18} </code> <br> <code>  rD[0] = rD[0] </code> <br> <code> Note: Arithmetic shift right. </code> | possibly pv.cplxmul.h.i[.div2,.div4,.div8] | [X] |
| cv.cplxconj | cv.cplxconj rD, rs1 | <code> rD[1] = -rs1[1] </code> <br> <code> rD[0] = rs1[0] </code> | pv.cplxconj.h | [X] |
| cv.subrotmj[.div2,.div4,.div8] | cv.subrotmj[.div2,.div4,.div8] | <code> rD[1] = ((rs2[0] - rs1[0]) & 0xFFFF) >> {0,1,2,3} </code> <br> <code>  rD[0] = ((rs1[1] - rs2[1]) & 0xFFFF) >> {0,1,2,3} </code> <br> <code> Note: Arithmetic shift right. </code> | possibly pv.subrotmj.h[.div2,.div4,.div8] | [X] |
| cv.add{.div2,.div4,.div8} | cv.add{.div2,.div4,.div8} | <code> rD[1] = ((rs1[1] + rs2[1]) & 0xFFFF) >> {1,2,3} </code> <br> <code>  rD[0] = ((rs1[0] + rs2[0]) & 0xFFFF) >> {1,2,3} </code> <br> <code> Note: Arithmetic shift right. </code> | pv.add{.div2,.div4,.div8} | [X] |
| cv.sub{.div2,.div4,.div8} | cv.sub{.div2,.div4,.div8} | <code> rD[1] = ((rs1[1] - rs2[1]) & 0xFFFF) >> {1,2,3} </code> <br> <code>  rD[0] = ((rs1[0] - rs2[0]) & 0xFFFF) >> {1,2,3} </code> <br> <code> Note: Arithmetic shift right. </code> | pv.sub{.div2,.div4,.div8} | [X] |
