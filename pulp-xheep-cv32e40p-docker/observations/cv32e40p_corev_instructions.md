# List of core-v instructions supported by the CV32E40P core

This list was compiled from [the cv32e40p user's manual](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html).

Cross reference to pulp instructions was built from information in [our pulp compilation](./xpulp_corev-group-instructions.md) and [the pulp opcodes list](https://github.com/pulp-platform/riscv-opcodes/tree/master).

## Post-Increment Load & Store Instructions and Register-Register Load & Store Instructions

Description: Can be found [here](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html#post-increment-load-store-instructions-and-register-register-load-store-instructions).

### Load Operations

Matches xpulppostmod and xpulpindregreg ([src](https://github.com/pulp-platform/riscv-gnu-toolchain/blob/master/core-v.rst)).

#### Register-Immediate Loads with Post-Increment

| Mnemonic | Usage | Description | Pulp equivalent |
|----------|-------|-------------|-----------------|
| cv.lb | cv.lb rD, (rs1), Imm | <code> rD = Sext(Mem8(rs1)) <br> rs1 += Sext(Imm[11:0]) </code> | ?? |
| cv.lbu | cv.lbu rD, (rs1), Imm | <code> rD = Zext(Mem8(rs1)) <br> rs1 += Sext(Imm[11:0]) </code> | ?? |
| cv.lh | cv.lh rD, (rs1), Imm | <code> rD = Sext(Mem16(rs1)) <br> rs1 += Sext(Imm[11:0]) </code> | ?? |
| cv.lhu | cv.lhu rD, (rs1), Imm | <code> rD = Zext(Mem16(rs1)) <br> rs1 += Sext(Imm[11:0]) </code> | ?? |
| cv.lw | cv.lw rD, (rs1), Imm | <code> rD = Mem32(rs1) <br> rs1 += Sext(Imm[11:0]) </code> | ?? |

#### Register-Register Loads with Post-Increment

| Mnemonic | Usage | Description | Pulp equivalent |
|----------|-------|-------------|-----------------|
| cv.lb | cv.lb rD, (rs1), rs2 | <code> rD = Sext(Mem8(rs1)) <br> rs1 += rs2 </code> | ?? |
| cv.lbu | cv.lbu rD, (rs1), rs2 | <code> rD = Zext(Mem8(rs1)) <br> rs1 += rs2 </code> | ?? |
| cv.lh | cv.lh rD, (rs1), rs2 | <code> rD = Sext(Mem16(rs1)) <br> rs1 += rs2 </code> | ?? |
| cv.lhu | cv.lhu rD, (rs1), rs2 | <code> rD = Zext(Mem16(rs1)) <br> rs1 += rs2 </code> | ?? |
| cv.lw | cv.lw rD, (rs1), rs2 | <code> rD = Mem32(rs1) <br> rs1 += rs2 </code> | ?? |

#### Register-Register Loads

| Mnemonic | Usage | Description | Pulp equivalent |
|----------|-------|-------------|-----------------|
| cv.lb | cv.lb rD, rs2(rs1) | <code> rD = Sext(Mem8(rs1 + rs2)) </code> | ?? |
| cv.lbu | cv.lbu rD, rs2(rs1) | <code> rD = Zext(Mem8(rs1 + rs2)) </code> | ?? |
| cv.lh | cv.lh rD, rs2(rs1) | <code> rD = Sext(Mem16(rs1 + rs2)) </code> | ?? |
| cv.lhu | cv.lhu rD, rs2(rs1) | <code> rD = Zext(Mem16(rs1 + rs2)) </code> | ?? |
| cv.lw | cv.lw rD, rs2(rs1) | <code> rD = Mem32(rs1 + rs2) </code> | ?? |

### Store Operations

| Mnemonic | Usage | Description | Pulp equivalent |
|----------|-------|-------------|-----------------|
| cv.sb | cv.sb rs2, (rs1), Imm | <code> Mem8(rs1) = rs2 <br> rs1 += Sext(Imm[11:0]) </code> | ?? |
| cv.sh | cv.sh rs2, (rs1), Imm | <code> Mem16(rs1) = rs2 <br> rs1 += Sext(Imm[11:0]) </code> | ?? |
| cv.sw | cv.sw rs2, (rs1), Imm | <code> Mem32(rs1) = rs2 <br> rs1 += Sext(Imm[11:0]) </code> | ?? |
| cv.sb | cv.sb rs2, (rs1), rs3 | <code> Mem8(rs1) = rs2 <br> rs1 += rs3 </code> | ?? |
| cv.sh | cv.sh rs2, (rs1), rs3 | <code> Mem16(rs1) = rs2 <br> rs1 += rs3 </code> | ?? |
| cv.sw | cv.sw rs2, (rs1), rs3 | <code> Mem32(rs1) = rs2 <br> rs1 += rs3 </code> | ?? |
| cv.sb | cv.sb rs2, rs3(rs1) | <code> Mem8(rs1 + rs3) = rs2 </code> | ?? |
| cv.sh | cv.sh rs2 rs3(rs1) | <code> Mem16(rs1 + rs3) = rs2 </code> | ?? |
| cv.sw | cv.sw rs2, rs3(rs1) | <code> Mem32(rs1 + rs3) = rs2 </code> | ?? |

## Event Load Instruction

Description: Can be found [here](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html#event-load-instruction).


| Mnemonic | Usage | Description | Pulp equivalent |
|----------|-------|-------------|-----------------|
| cv.elw | cv.elw rD, Imm(rs1) | <code> rD = Mem32(Sext(Imm) + rs1) </code> | ?? |

## Hardware Loops

Description: Can be found [here](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html#hardware-loops).

| Mnemonic | Usage | Description | Pulp equivalent |
|----------|-------|-------------|-----------------|
| cv.starti | cv.starti L, uimmL | <code> lpstart[L] = PC + (uimmL << 2) </code> | ?? |
| cv.start | cv.start L, rs1 | <code> lpstart[L] = rs1 </code> | ?? |
| cv.endi | cv.endi L, uimmL | <code> lpend[L] = PC + (uimmL << 2) </code> | ?? |
| cv.end | cv.end L, rs1 | <code> lpend[L] = rs1 </code> | ?? |
| cv.counti | cv.counti L, uimmL | <code> lpcount[L] = uimmL </code> | ?? |
| cv.count | cv.count L, rs1 | <code> lpcount[L] = rs1 </code> | ?? |
| cv.setupi | cv.setupi L, uimmL, uimmS | <code> lpstart[L] = PC + 4 <br> lpend[L] = PC + (uimmS << 2) <br> lpcount[L] = uimmL </code> | ?? |
| cv.setup | cv.setup L, rs1, uimmL | <code> lpstart[L] = PC + 4 <br> lpend[L] = PC + (uimmL << 2) <br> lpcount[L] = rs1 </code> | ?? |

## ALU

Description: Can be found [here](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html#alu).

### Bit Manipulation operations


| Mnemonic | Usage | Description | Pulp equivalent |
|----------|-------|-------------|-----------------|
| cv.extract | cv.extract rD, rs1, Is3, Is2 | <code> rD = Sext(rs1[min(Is3+Is2,31):Is2]) <br> Note: Sign extension is done over the MSB of the extracted part. </code> | ?? |
| cv.extractu | cv.extractu rD, rs1, Is3, Is2 | <code> rD = Zext(rs1[min(Is3+Is2,31):Is2]) </code> | ?? |
| cv.extractr | cv.extractr rD, rs1, rs2 | <code> rD = Sext(rs1[min(rs2[9:5]+rs2[4:0],31):rs2[4:0]]) <br> Note: Sign extension is done over the MSB of the extracted part. </code> | ?? |
| cv.extractur | cv.extractur rD, rs1, rs2 | <code> rD = Zext(rs1[min(rs2[9:5]+rs2[4:0],31):rs2[4:0]]) </code> | ?? |
| cv.insert | cv.insert rD, rs1, Is3, Is2 | <code> rD[min(Is3+Is2,31):Is2] = rs1[Is3-(max(Is3+Is2,31)-31):0] <br> The rest of the bits of rD are untouched and keep their previous value. <br> Is3 + Is2 must be < 32. </code>  | ?? |
| cv.insertr | cv.insertr rD, rs1, rs2 | <code>  rD[min(rs2[9:5]+rs2[4:0],31):rs2[4:0]] = rs1[rs2[9:5]-(max(rs2[9:5]+rs2[4:0],31)-31):0] <br>  The rest of the bits of rD are untouched and keep their previous value. <br> Is3 + Is2 must be < 32. </code>  | ?? |
| cv.bclr | cv.bclr rD, rs1, Is3, Is2 | <code>  rD[min(Is3+Is2,31):Is2] bits set to 0 <br> The rest of the bits of rD are passed through from rs1 and are not modified. </code>  | ?? |
| cv.bclrr | cv.bclrr rD, rs1, rs2 | <code>  rD[min(rs2[9:5]+rs2[4:0],31):rs2[4:0]] bits set to 0 <br> The rest of the bits of rD are passed through from rs1 and are not modified. </code>  | ?? |
| cv.bset | cv.bset rD, rs1, Is3, Is2 | <code>  rD[min(Is3+Is2,31):Is2] bits set to 1 <br> The rest of the bits of rD are passed through from rs1 and are not modified. </code>  | ?? |
| cv.bsetr | cv.bsetr rD, rs1, rs2 | <code>  rD[min(rs2[9:5]+rs2[4:0],31):rs2[4:0]] bits set to 1 <br> The rest of the bits of rD are passed through from rs1 and are not modified. </code>  | ?? |
| cv.ff1 | cv.ff1 rD, rs1 | <code>  rD = bit position of the first bit set in rs1, starting from LSB. <br> If bit 0 is set, rD will be 0. If only bit 31 is set, rD will be 31. <br> If rs1 is 0, rD will be 32. </code>  | ?? |
| cv.fl1 | cv.fl1 rD, rs1 | <code>  rD = bit position of the last bit set in rs1, starting from MSB. <br> If bit 31 is set, rD will be 31. If only bit 0 is set, rD will be 0. <br> If rs1 is 0, rD will be 32. </code>  | ?? |
| cv.clb | cv.clb rD, rs1 | <code>  rD = count leading bits of rs1 <br> Number of consecutive 1’s or 0’s starting from MSB. <br> If rs1 is 0, rD will be 0. If rs1 is different than 0, returns (number - 1). </code>  | ?? |
| cv.cnt | cv.cnt rD, rs1 | <code>  rD = Population count of rs1 <br> Number of bits set in rs1. </code>  | ?? |
| cv.ror | cv.ror rD, rs1, rs2 | <code>  rD = RotateRight(rs1, rs2) </code>  | ?? |
| cv.bitrev | cv.bitrev rD, rs1, Is3, Is2 | <code>  Given an input rs1 it returns a bit reversed representation assuming FFT on 2^Is2 points in Radix 2^(Is3+1). <br> Is3 can be either 0 (radix-2), 1 (radix-4) or 2 (radix-8). <br> Note: When Is3 = 3, instruction has the same bahavior as if it was 0 (radix-2). </code>  | ?? |

### General ALU operations

| Mnemonic | Usage | Description | Pulp equivalent |
|----------|-------|-------------|-----------------|
| cv.abs | cv.abs rD, rs1 | <code>  rD = rs1 < 0 ? -rs1 : rs1 </code>  | ?? |
| cv.sle | cv.sle rD, rs1, rs2 | <code>  rD = rs1 <= rs2 ? 1 : 0 <br> Note: Comparison is signed. </code>  | ?? |
| cv.sleu | cv.sleu rD, rs1, rs2 | <code>  rD = rs1 <= rs2 ? 1 : 0 <br> Note: Comparison is unsigned. </code>  | ?? |
| cv.min | cv.min rD, rs1, rs2 | <code>  rD = rs1 < rs2 ? rs1 : rs2 <br> Note: Comparison is signed. </code>  | ?? |
| cv.minu | cv.minu rD, rs1, rs2 | <code>  rD = rs1 < rs2 ? rs1 : rs2 <br> Note: Comparison is unsigned. </code>  | ?? |
| cv.max | cv.max rD, rs1, rs2 | <code>  rD = rs1 < rs2 ? rs2 : rs1 <br> Note: Comparison is signed. </code>  | ?? |
| cv.maxu | cv.maxu rD, rs1, rs2 | <code>  rD = rs1 < rs2 ? rs2 : rs1 <br> Note: Comparison is unsigned. </code>  | ?? |
| cv.exths | cv.exths rD, rs1 | <code>  rD = Sext(rs1[15:0]) </code>  | ?? |
| cv.exthz | cv.exthz rD, rs1 | <code>  rD = Zext(rs1[15:0]) </code>  | ?? |
| cv.extbs | cv.extbs rD, rs1 | <code>  rD = Sext(rs1[7:0]) </code>  | ?? |
| cv.extbz | cv.extbz rD, rs1 | <code>  rD = Zext(rs1[7:0]) </code>  | ?? |
| cv.clip | cv.clip rD, rs1, Is2 | <code>  if rs1 <= -2^(Is2-1), rD = -2^(Is2-1), <br> else if rs1 >= 2^(Is2-1)-1, rD = 2^(Is2-1)-1, <br> else rD = rs1 <br> Note: If Is2 is equal to 0, -2^(Is2-1) is equivalent to -1 while (2^(Is2-1)-1) is equivalent to 0. </code>  | ?? |
| cv.clipu | cv.clipu rD, rs1, Is2 | <code>  if rs1 <= 0, rD = 0, <br> else if rs1 >= 2^(Is2-1)-1, rD = 2^(Is2-1)-1, <br> else rD = rs1 <br> Note: If Is2 is equal to 0, (2^(Is2-1)-1) is equivalent to 0. </code>  | ?? |
| cv.clipr | cv.clipr rD, rs1, rs2 | <code>  rs2’ = rs2 & 0x7FFFFFFF <br> if rs1 <= -(rs2’+1), rD = -(rs2’+1), <br> else if rs1 >=rs2’, rD = rs2’, <br> else rD = rs1 </code>  | ?? |
| cv.clipur | cv.clipur rD, rs1, rs2 | <code>  rs2’ = rs2 & 0x7FFFFFFF <br> if rs1 <= 0, rD = 0, <br> else if rs1 >= rs2’, rD = rs2’, <br> else rD = rs1 </code>  | ?? |
| cv.addN | cv.addN rD, rs1, rs2, Is3 | <code>  rD = (rs1 + rs2) >>> Is3 <br> Note: Arithmetic shift right. <br> Setting Is3 to 1 replaces former cv.avg. </code>  | ?? |
| cv.adduN | cv.adduN rD, rs1, rs2, Is3 | <code>  rD = (rs1 + rs2) >> Is3 <br> Note: Logical shift right. <br> Setting Is3 to 1 replaces former cv.avgu. </code>  | ?? |
| cv.addRN | cv.addRN rD, rs1, rs2, Is3 | <code>  rD = (rs1 + rs2 + 2^(Is3-1)) >>> Is3 <br> Note: Arithmetic shift right. <br> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | ?? |
| cv.adduRN | cv.adduRN rD, rs1, rs2, Is3 | <code>  rD = (rs1 + rs2 + 2^(Is3-1))) >> Is3 <br> Note: Logical shift right. <br> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | ?? |
| cv.subN | cv.subN rD, rs1, rs2, Is3 | <code>  rD = (rs1 - rs2) >>> Is3 <br> Note: Arithmetic shift right. </code>  | ?? |
| cv.subuN | cv.subuN rD, rs1, rs2, Is3 | <code>  rD = (rs1 - rs2) >> Is3 <br> Note: Logical shift right. </code>  | ?? |
| cv.subRN | cv.subRN rD, rs1, rs2, Is3 | <code>  rD = (rs1 - rs2 + 2^(Is3-1)) >>> Is3 <br> Note: Arithmetic shift right. <br> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | ?? |
| cv.subuRN | cv.subuRN rD, rs1, rs2, Is3 | <code>  rD = (rs1 - rs2 + 2^(Is3-1))) >> Is3 <br> Note: Logical shift right. <br> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | ?? |
| cv.addNr | cv.addNr rD, rs1, rs2 | <code>  rD = (rD + rs1) >>> rs2[4:0] <br> Note: Arithmetic shift right. </code>  | ?? |
| cv.adduNr | cv.adduNr rD, rs1, rs2 | <code>  rD = (rD + rs1) >> rs2[4:0] <br> Note: Logical shift right. </code>  | ?? |
| cv.addRNr | cv.addRNr rD, rs1, rs2 | <code>  rD = (rD + rs1 + 2^(rs2[4:0]-1)) >>> rs2[4:0] <br> Note: Arithmetic shift right. <br> If rs2[4:0] is equal to 0, 2^(rs2[4:0]-1) is equivalent to 0. </code>  | ?? |
| cv.adduRNr | cv.adduRNr rD, rs1, rs2 | <code>  rD = (rD + rs1 + 2^(rs2[4:0]-1))) >> rs2[4:0] <br> Note: Logical shift right. <br> If rs2[4:0] is equal to 0, 2^(rs2[4:0]-1) is equivalent to 0. </code>  | ?? |
| cv.subNr | cv.subNr rD, rs1, rs2 | <code>  rD = (rD - rs1) >>> rs2[4:0] <br> Note: Arithmetic shift right. </code>  | ?? |
| cv.subuNr | cv.subuNr rD, rs1, rs2 | <code>  rD = (rD - rs1) >> rs2[4:0] <br> Note: Logical shift right. </code>  | ?? |
| cv.subRNr | cv.subRNr rD, rs1, rs2 | <code>  rD = (rD - rs1+ 2^(rs2[4:0]-1)) >>> rs2[4:0] <br> Note: Arithmetic shift right. <br> If rs2[4:0] is equal to 0, 2^(rs2[4:0]-1) is equivalent to 0. </code>  | ?? |
| cv.subuRNr | cv.subuRNr rD, rs1, rs2 | <code>  rD = (rD - rs1+ 2^(rs2[4:0]-1))) >> rs2[4:0] <br> Note: Logical shift right. <br> If rs2[4:0] is equal to 0, 2^(rs2[4:0]-1) is equivalent to 0. </code>  | ?? |

### Immediate Branching Operations

| Mnemonic | Usage | Description | Pulp equivalent |
|----------|-------|-------------|-----------------|
| cv.beqimm | cv.beqimm rs1, Imm5, Imm12 | <code>  Branch to PC + (Imm12 << 1) if rs1 is equal to Imm5. <br> Note: Imm5 is signed. </code>  | ?? |
| cv.bneimm | cv.bneimm rs1, Imm5, Imm12 | <code>  Branch to PC + (Imm12 << 1) if rs1 is not equal to Imm5. <br> Note: Imm5 is signed. </code>  | ?? |

## Multiply-Accumulate

Description: Can be found [here](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html#multiply-accumulate).

### 16-Bit x 16-Bit Multiplication operations

| Mnemonic | Usage | Description | Pulp equivalent |
|----------|-------|-------------|-----------------|
| cv.muluN | cv.muluN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Zext(rs1[15:0]) * Zext(rs2[15:0])) >> Is3 <br> Note: Logical shift right. </code>  | ?? |
| cv.mulhhuN | cv.mulhhuN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Zext(rs1[31:16]) * Zext(rs2[31:16])) >> Is3 <br> Note: Logical shift right. </code>  | ?? |
| cv.mulsN | cv.mulsN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Sext(rs1[15:0]) * Sext(rs2[15:0])) >>> Is3 <br> Note: Arithmetic shift right. </code>  | ?? |
| cv.mulhhsN | cv.mulhhsN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Sext(rs1[31:16]) * Sext(rs2[31:16])) >>> Is3 <br> Note: Arithmetic shift right. </code>  | ?? |
| cv.muluRN | cv.muluRN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Zext(rs1[15:0]) * Zext(rs2[15:0]) + 2^(Is3-1)) >> Is3 <br> Note: Logical shift right. <br> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | ?? |
| cv.mulhhuRN | cv.mulhhuRN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Zext(rs1[31:16]) * Zext(rs2[31:16]) + 2^(Is3-1)) >> Is3 <br> Note: Logical shift right. <br> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | ?? |
| cv.mulsRN | cv.mulsRN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Sext(rs1[15:0]) * Sext(rs2[15:0]) + 2^(Is3-1)) >>> Is3 <br> Note: Arithmetic shift right. <br> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | ?? |
| cv.mulhhsRN | cv.mulhhsRN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Sext(rs1[31:16]) * Sext(rs2[31:16]) + 2^(Is3-1)) >>> Is3 <br> Note: Arithmetic shift right. <br> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | ?? |

### 16-Bit x 16-Bit Multiplication pseudo-instructions

| Mnemonic | Usage | Base Instruction | Description | Pulp equivalent |
|----------|-------|------------------|-------------|-----------------|
| cv.mulu | cv.mulu rD, rs1, rs2 | cv.muluN rD, rs1, rs2, 0 | <code> rD[31:0] = (Zext(rs1[15:0]) * Zext(rs2[15:0])) >> 0 <br> Note: Logical shift right. </code>  | ?? |
| cv.mulhhu | cv.mulhhu rD, rs1, rs2 | cv.mulhhuN rD, rs1, rs2, 0 | <code> rD[31:0] = (Zext(rs1[31:16]) * Zext(rs2[31:16])) >> 0 <br> Note: Logical shift right. </code>  | ?? |
| cv.muls | cv.muls rD, rs1, rs2 | cv.mulsN rD, rs1, rs2, 0 | <code> rD[31:0] = (Sext(rs1[15:0]) * Sext(rs2[15:0])) >> 0 <br> Note: Arithmetic shift right. </code>  | ?? |
| cv.mulhhs | cv.mulhhs rD, rs1, rs2 | cv.mulhhsN rD, rs1, rs2, 0 | <code> rD[31:0] = (Sext(rs1[31:16]) * Sext(rs2[31:16])) >> 0 <br> Note: Arithmetic shift right. </code>  | ?? |

### 16-Bit x 16-Bit Multiply-Accumulate operations

| Mnemonic | Usage | Description | Pulp equivalent |
|----------|-------|-------------|-----------------|
| cv.macuN | cv.macuN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Zext(rs1[15:0]) * Zext(rs2[15:0]) + rD) >> Is3 <br> Note: Logical shift right. </code>  | ?? |
| cv.machhuN | cv.machhuN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Zext(rs1[31:16]) * Zext(rs2[31:16]) + rD) >> Is3 <br> Note: Logical shift right. </code>  | ?? |
| cv.macsN | cv.macsN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Sext(rs1[15:0]) * Sext(rs2[15:0]) + rD) >>> Is3 <br> Note: Arithmetic shift right. </code>  | ?? |
| cv.machhsN | cv.machhsN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Sext(rs1[31:16]) * Sext(rs2[31:16]) + rD) >>> Is3 <br> Note: Arithmetic shift right. </code>  | ?? |
| cv.macuRN | cv.macuRN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Zext(rs1[15:0]) * Zext(rs2[15:0]) + rD + 2^(Is3-1)) >> Is3 <br> Note: Logical shift right. <br> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | ?? |
| cv.machhuRN | cv.machhuRN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Zext(rs1[31:16]) * Zext(rs2[31:16]) + rD + 2^(Is3-1)) >> Is3 <br> Note: Logical shift right. <br> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | ?? |
| cv.macsRN | cv.macsRN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Sext(rs1[15:0]) * Sext(rs2[15:0]) + rD + 2^(Is3-1)) >>> Is3 <br> Note: Arithmetic shift right. <br> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | ?? |
| cv.machhsRN | cv.machhsRN rD, rs1, rs2, Is3 | <code>  rD[31:0] = (Sext(rs1[31:16]) * Sext(rs2[31:16]) + rD + 2^(Is3-1)) >>> Is3 <br> Note: Arithmetic shift right. <br> If Is3 is equal to 0, 2^(Is3-1) is equivalent to 0. </code>  | ?? |

### 32-Bit x 32-Bit Multiply-Accumulate operations

| Mnemonic | Usage | Description | Pulp equivalent |
|----------|-------|-------------|-----------------|
| cv.mac | cv.mac rD, rs1, rs2 | <code>  rD = rD + rs1 * rs2 </code>  | ?? |
| cv.msu | cv.msu rD, rs1, rs2 | <code>  rD = rD - rs1 * rs2 </code>  | ?? |

## SIMD

Description: Can be found [here](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html#simd).

### SIMD ALU operations

| Mnemonic | Usage | Description | Pulp equivalent |
|----------|-------|-------------|-----------------|
| cv.add | cv.add[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = (rs1[i] + op2[i]) & {0xFFFF, 0xFF} </code>  | ?? |
| cv.sub | cv.sub[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = (rs1[i] - op2[i]) & {0xFFFF, 0xFF} </code>  | ?? |
| cv.avg | cv.avg[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = ((rs1[i] + op2[i]) & {0xFFFF, 0xFF}) >> 1 <br> Note: Arithmetic right shift. </code>  | ?? |
| cv.avgu | cv.avgu[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = ((rs1[i] + op2[i]) & {0xFFFF, 0xFF}) >> 1 <br> Note: Immediate is zero-extended, shift is logical. </code>  | ?? |
| cv.min | cv.min[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = rs1[i] < op2[i] ? rs1[i] : op2[i] </code>  | ?? |
| cv.minu | cv.minu[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = rs1[i] < op2[i] ? rs1[i] : op2[i] <br> Note: Immediate is zero-extended, comparison is unsigned. </code>  | ?? |
| cv.max | cv.max[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = rs1[i] > op2[i] ? rs1[i] : op2[i] </code>  | ?? |
| cv.maxu | cv.maxu[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = rs1[i] > op2[i] ? rs1[i] : op2[i] <br> Note: Immediate is zero-extended, comparison is unsigned. </code>  | ?? |
| cv.srl | cv.srl[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = rs1[i] >> op2[i] <br> Note: Immediate is zero-extended, shift is logical. <br> Only Imm6[3:0] and rs2[3:0] are used for .h instruction and Imm6[2:0] and rs2[2:0] for .b instruction. <br> In .sci case, unused Imm6 bits must be set to 0. </code>  | ?? |
| cv.sra | cv.sra[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = rs1[i] >>> op2[i] <br> Note: Immediate is zero-extended, shift is arithmetic. <br> Only Imm6[3:0] and rs2[3:0] are used for .h instruction and Imm6[2:0] and rs2[2:0] for .b instruction. <br> In .sci case, unused Imm6 bits must be set to 0. </code>  | ?? |
| cv.sll | cv.sll[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = rs1[i] << op2[i] <br> Note: Immediate is zero-extended, shift is logical. <br> Only Imm6[3:0] and rs2[3:0] are used for .h instruction and Imm6[2:0] and rs2[2:0] for .b instruction. <br> In .sci case, unused Imm6 bits must be set to 0. </code>  | ?? |
| cv.or | cv.or[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = rs1[i] \| op2[i] </code>  | ?? |
| cv.xor | cv.xor[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = rs1[i] ^ op2[i] </code>  | ?? |
| cv.and | cv.and[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code>  rD[i] = rs1[i] & op2[i] </code>  | ?? |
| cv.abs | cv.abs{.h,.b} rD, rs1 | <code>  rD[i] = rs1[i] < 0 ? -rs1[i] : rs1[i] </code>  | ?? |

### SIMD Bit Manipulation operations

| Mnemonic | Usage | Description | Pulp equivalent |
|----------|-------|-------------|-----------------|
| cv.extract | cv.extract.h rD, rs1, Imm6 | <code>  rD = Sext(rs1[I0*16+15:I0*16]) <br> Note: Only Imm6[0] bit is used and other Imm6 bits must be set to 0. </code>  | ?? |
| cv.extract | cv.extract.b rD, rs1, Imm6 | <code>  rD = Sext(rs1[(I1:I0)*8+7:(I1:I0)*8]) <br> Note: Only Imm6[1:0] bits are used and other Imm6 bits must be set to 0. </code>  | ?? |
| cv.extractu | cv.extractu.h rD, rs1, Imm6 | <code>  rD = Zext(rs1[I0*16+15:I0*16]) <br> Note: Only Imm6[0] bit is used and other Imm6 bits must be set to 0. </code>  | ?? |
| cv.extractu | cv.extractu.b rD, rs1, Imm6 | <code>  rD = Zext(rs1[(I1:I0)*8+7:(I1:I0)*8]) <br> Note: Only Imm6[1:0] bits are used and other Imm6 bits must be set to 0. </code>  | ?? |
| cv.insert | cv.insert.h rD, rs1, Imm6 | <code>  rD[I0*16+15:I0*16] = rs1[15:0] <br> Note: The rest of the bits of rD are untouched and keep their previous value. <br> Only Imm6[0] bit is used and other Imm6 bits must be set to 0. </code>  | ?? |

### SIMD Dot Product operations

| Mnemonic | Usage | Description | Pulp equivalent |
|----------|-------|-------------|-----------------|
| cv.dotup | cv.dotup[.sc,.sci].h rD, rs1, [rs2, Imm6] | <code> rD = rs1[0] * op2[0] + rs1[1] * op2[1] <br> Note: All operands are unsigned. </code> | ?? |
| cv.dotup | cv.dotup[.sc,.sci].b rD, rs1, [rs2, Imm6] | <code> rD = rs1[0] * op2[0] + rs1[1] * op2[1] +  rs1[2] * op2[2] + rs1[3] * op2[3] <br> Note: All operands are unsigned. </code> | ?? |
| cv.dotusp | cv.dotusp[.sc,.sci].h rD, rs1, [rs2, Imm6] | <code> rD = rs1[0] * op2[0] + rs1[1] * op2[1] <br> Note: rs1 is treated as unsigned, while op2 is treated as signed. </code> | ?? |
| cv.dotusp | cv.dotusp[.sc,.sci].b rD, rs1, [rs2, Imm6] | <code> rD = rs1[0] * op2[0] + rs1[1] * op2[1] +  rs1[2] * op2[2] + rs1[3] * op2[3] <br> Note: rs1 is treated as unsigned, while op2 is treated as signed. </code> | ?? |
| cv.dotsp | cv.dotsp[.sc,.sci].h rD, rs1, [rs2, Imm6] | <code> rD = rs1[0] * op2[0] + rs1[1] * op2[1] <br> Note: All operands are signed. </code> | ?? |
| cv.dotsp | cv.dotsp[.sc,.sci].b rD, rs1, [rs2, Imm6] | <code> rD = rs1[0] * op2[0] + rs1[1] * op2[1] +  rs1[2] * op2[2] + rs1[3] * op2[3] <br> Note: All operands are signed. </code> | ?? |
| cv.sdotup | cv.sdotup[.sc,.sci].h rD, rs1, [rs2, Imm6] | <code> rD = rD + rs1[0] * op2[0] + rs1[1] * op2[1] <br> Note: All operands are unsigned. </code> | ?? |
| cv.sdotup | cv.sdotup[.sc,.sci].b rD, rs1, [rs2, Imm6] | <code> rD = rD + rs1[0] * op2[0] + rs1[1] * op2[1] +  rs1[2] * op2[2] + rs1[3] * op2[3] <br> Note: All operands are unsigned. </code> | ?? |
| cv.sdotusp | cv.sdotusp[.sc,.sci].h rD, rs1, [rs2, Imm6] | <code> rD = rD + rs1[0] * op2[0] + rs1[1] * op2[1] <br> Note: rs1 is treated as unsigned while op2 is treated as signed. </code> | ?? |
| cv.sdotusp | cv.sdotusp[.sc,.sci].b rD, rs1, [rs2, Imm6] | <code> rD = rD + rs1[0] * op2[0] + rs1[1] * op2[1] +  rs1[2] * op2[2] + rs1[3] * op2[3] <br> Note: rs1 is treated as unsigned while op2 is treated as signed. </code> | ?? |
| cv.sdotsp | cv.sdotsp[.sc,.sci].h rD, rs1, [rs2, Imm6] | <code> rD = rD + rs1[0] * op2[0] + rs1[1] * op2[1] <br> Note: All operands are signed. </code> | ?? |
| cv.sdotsp | cv.sdotsp[.sc,.sci].b rD, rs1, [rs2, Imm6] | <code> rD = rD + rs1[0] * op2[0] + rs1[1] * op2[1] +  rs1[2] * op2[2] + rs1[3] * op2[3] <br> Note: All operands are signed. </code> | ?? |

### SIMD Shuffle and Pack operations


| Mnemonic | Usage | Description | Pulp equivalent |
|----------|-------|-------------|-----------------|
| cv.shuffle | cv.shuffle.h rD, rs1, rs2 | <code> rD[31:16] = rs1[rs2[16]*16+15:rs2[16]*16] <br> rD[15:0] = rs1[rs2[0]*16+15:rs2[0]*16] </code> | ?? |
| cv.shuffle | cv.shuffle.sci.h rD, rs1, Imm6 | <code> rD[31:16] = rs1[I1*16+15:I1*16] <br>  rD[15:0] = rs1[I0*16+15:I0*16] <br> Note: Only Imm6[1:0] bits are used and other Imm6 bits must be set to 0. </code> | ?? |
| cv.shuffle | cv.shuffle.b rD, rs1, rs2 | <code> rD[31:24] = rs1[rs2[25:24]*8+7:rs2[25:24]*8] <br>  rD[23:16] = rs1[rs2[17:16]*8+7:rs2[17:16]*8] <br>  rD[15:8] = rs1[rs2[9:8]*8+7:rs2[9:8]*8] <br> rD[7:0] = rs1[rs2[1:0]*8+7:rs2[1:0]*8] </code> | ?? |
| cv.shuffleI0 | cv.shuffleI0.sci.b rD, rs1, Imm6 | <code> rD[31:24] = rs1[7:0] <br>  rD[23:16] = rs1[(I5:I4)*8+7: (I5:I4)*8] <br>  rD[15:8] = rs1[(I3:I2)*8+7: (I3:I2)*8] <br> rD[7:0] = rs1[(I1:I0)*8+7:(I1:I0)*8] </code> | ?? |
| cv.shuffleI1 | cv.shuffleI1.sci.b rD, rs1, Imm6 | <code> rD[31:24] = rs1[15:8] <br>  rD[23:16] = rs1[(I5:I4)*8+7: (I5:I4)*8] <br>  rD[15:8] = rs1[(I3:I2)*8+7: (I3:I2)*8] <br> rD[7:0] = rs1[(I1:I0)*8+7:(I1:I0)*8] </code> | ?? |
| cv.shuffleI2 | cv.shuffleI2.sci.b rD, rs1, Imm6 | <code> rD[31:24] = rs1[23:16] <br>  rD[23:16] = rs1[(I5:I4)*8+7: (I5:I4)*8] <br>  rD[15:8] = rs1[(I3:I2)*8+7: (I3:I2)*8] <br> rD[7:0] = rs1[(I1:I0)*8+7:(I1:I0)*8] </code> | ?? |
| cv.shuffleI3 | cv.shuffleI3.sci.b rD, rs1, Imm6 | <code> rD[31:24] = rs1[31:24] <br>  rD[23:16] = rs1[(I5:I4)*8+7: (I5:I4)*8] <br>  rD[15:8] = rs1[(I3:I2)*8+7: (I3:I2)*8] <br> rD[7:0] = rs1[(I1:I0)*8+7:(I1:I0)*8] </code> | ?? |
| cv.shuffle2 | cv.shuffle2.h rD, rs1, rs2 | <code> rD[31:16] = ((rs2[17] == 1) ? rs1 : rD)[rs2[16]*16+15:rs2[16]*16] <br> rD[15:0] = ((rs2[1] == 1) ? rs1 : rD)[rs2[0]*16+15:rs2[0]*16] </code> | ?? |
| cv.shuffle2 | cv.shuffle2.b rD, rs1, rs2 | <code> rD[31:24] = ((rs2[26] == 1) ? rs1 : rD)[rs2[25:24]*8+7:rs2[25:24]*8] <br>  rD[23:16] = ((rs2[18] == 1) ? rs1 : rD)[rs2[17:16]*8+7:rs2[17:16]*8] <br>  rD[15:8] = ((rs2[10] == 1) ? rs1 : rD)[rs2[9:8]*8+7:rs2[9:8]*8] <br> rD[7:0] = ((rs2[2] == 1) ? rs1 : rD)[rs2[1:0]*8+7:rs2[1:0]*8] </code> | ?? |
| cv.pack | cv.pack rD, rs1, rs2 | <code> rD[31:16] = rs1[15:0] <br> rD[15:0] = rs2[15:0] </code> | ?? |
| cv.pack | cv.pack.h rD, rs1, rs2 | <code> rD[31:16] = rs1[31:16] <br> rD[15:0] = rs2[31:16] </code> | ?? |
| cv.packhi | cv.packhi.b rD, rs1, rs2 | <code> rD[31:24] = rs1[7:0] <br>  rD[23:16] = rs2[7:0] <br> Note: The rest of the bits of rD are untouched and keep their previous value. </code> | ?? |
| cv.packlo | cv.packlo.b rD, rs1, rs2 | <code> rD[15:8] = rs1[7:0] <br>  rD[7:0] = rs2[7:0] <br> Note: The rest of the bits of rD are untouched and keep their previous value. </code> | ?? |

### SIMD Comparison operations

Description: Can be found [here](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html#simd-comparison-operations).

| Mnemonic | Usage | Description | Pulp equivalent |
|----------|-------|-------------|-----------------|
| cv.cmpeq | cv.cmpeq[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code> rD[i] = rs1[i] == op2 ? ‘1 : ‘0 </code> | ?? |
| cv.cmpne | cv.cmpne[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code> rD[i] = rs1[i] != op2 ? ‘1 : ‘0 </code> | ?? |
| cv.cmpgt | cv.cmpgt[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code> rD[i] = rs1[i] > op2 ? ‘1 : ‘0 </code> | ?? |
| cv.cmpge | cv.cmpge[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code> rD[i] = rs1[i] >=op2 ? ‘1 : ‘0 </code> | ?? |
| cv.cmplt | cv.cmplt[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code> rD[i] = rs1[i] < op2 ? ‘1 : ‘0 </code> | ?? |
| cv.cmple | cv.cmple[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code> rD[i] = rs1[i] <= op2 ? ‘1 : ‘0 </code> | ?? |
| cv.cmpgtu | cv.cmpgtu[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code> rD[i] = rs1[i] > op2 ? ‘1 : ‘0 <br> Note: Unsigned comparison. </code> | ?? |
| cv.cmpgeu | cv.cmpgeu[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code> rD[i] = rs1[i] >= op2 ? ‘1 : ‘0 <br> Note: Unsigned comparison. </code> | ?? |
| cv.cmpltu | cv.cmpltu[.sc,.sci]{.h,.b} rD, rs1, [rs2, Imm6] | <code> rD[i] = rs1[i] < op2 ? ‘1 : ‘0 <br> Note: Unsigned comparison. </code> | ?? |

### SIMD Complex-number operations

Description: Can be found [here](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html#simd-complex-number-operations).

| Mnemonic | Usage | Description | Pulp equivalent |
|----------|-------|-------------|-----------------|
| cv.cplxmul | cv.cplxmul.r{/,.div2,.div4,.div8} | <code> rD[1] = rD[1] <br>  rD[0] = (rs1[0]*rs2[0] - rs1[1]*rs2[1]) >> {15,16,17,18} <br> Note: Arithmetic shift right. </code> | ?? |
| cv.cplxmul | cv.cplxmul.i{/,.div2,.div4,.div8} | <code> rD[1] = (rs1[0]*rs2[1] + rs1[1]*rs2[0]) >> {15,16,17,18} <br>  rD[0] = rD[0] <br> Note: Arithmetic shift right. </code> | ?? |
| cv.cplxconj | cv.cplxconj rD, rs1 | <code> rD[1] = -rs1[1] <br> rD[0] = rs1[0] </code> | ?? |
| cv.subrotmj | cv.subrotmj{/,.div2,.div4,.div8} | <code> rD[1] = ((rs2[0] - rs1[0]) & 0xFFFF) >> {0,1,2,3} <br>  rD[0] = ((rs1[1] - rs2[1]) & 0xFFFF) >> {0,1,2,3} <br> Note: Arithmetic shift right. </code> | ?? |
| cv.add | cv.add{.div2,.div4,.div8} | <code> rD[1] = ((rs1[1] + rs2[1]) & 0xFFFF) >> {1,2,3} <br>  rD[0] = ((rs1[0] + rs2[0]) & 0xFFFF) >> {1,2,3} <br> Note: Arithmetic shift right. </code> | ?? |
| cv.sub | cv.sub{.div2,.div4,.div8} | <code> rD[1] = ((rs1[1] - rs2[1]) & 0xFFFF) >> {1,2,3} <br>  rD[0] = ((rs1[0] - rs2[0]) & 0xFFFF) >> {1,2,3} <br> Note: Arithmetic shift right. </code> | ?? |
