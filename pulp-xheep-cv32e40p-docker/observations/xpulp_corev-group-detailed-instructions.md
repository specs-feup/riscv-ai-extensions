# xpulp extensions/instructions in the core-v group

# TODO fix this
This list was compiled from [here](https://github.com/pulp-platform/riscv-gnu-toolchain/blob/master/pulp.md#extension-groups).

## xpulppostmod extension

Note: These instructions have similar versions in [risc-v opcodes](https://github.com/pulp-platform/riscv-opcodes/).

| Mnemonic | Usage | Description | riscv-opcodes | datasheet |
|----------|-------|-------------|---------------|-----------|
| p.lb | NA | NA | [ ] | [ ] |
| p.lbu | NA | NA | [ ] | [ ] |
| p.lh | NA | NA | [ ] | [ ] |
| p.lhu | NA | NA | [ ] | [ ] |
| p.lw | NA | NA | [ ] | [ ] |
| p.sb | NA | NA | [ ] | [ ] |
| p.sh | NA | NA | [ ] | [ ] |
| p.sw | NA | NA | [ ] | [ ] |

## xpulpabs extension

| Mnemonic | Usage | Description | riscv-opcodes | datasheet |
|----------|-------|-------------|---------------|-----------|
| p.abs | p.abs rd rs1 | NA | [X] | [ ] | (collides with p.avg, only pulp < v2)

## xpulpslet extension

| Mnemonic | Usage | Description | riscv-opcodes | datasheet |
|----------|-------|-------------|---------------|-----------|
| p.slet | p.slet rd rs1 rs2 | NA | [X] | [ ] |
| p.sletu | p.sletu rd rs1 rs2 | NA | [X] | [ ] |

## xpulpminmax extension

| Mnemonic | Usage | Description | riscv-opcodes | datasheet |
|----------|-------|-------------|---------------|-----------|
| p.min | p.min rd rs1 rs2 | NA | [X] | [ ] |
| p.max | p.max rd rs1 rs2 | NA | [X] | [ ] |
| p.minu | p.minu rd rs1 rs2 | NA | [X] | [ ] |
| p.maxu | p.maxu rd rs1 rs2 | NA | [X] | [ ] |
| p.avg | NA | (replaced with p.addN in pulp >= v2) (p.addN is an emulation) | [ ] | [ ] |
| p.avgu | NA | (replaced with p.adduN in pulp >= v2) (p.adduN is an emulation) | [ ] | [ ] |

## xpulpbitop extension

| Mnemonic | Usage | Description | riscv-opcodes | datasheet |
|----------|-------|-------------|---------------|-----------|
| p.extract | p.extract rd rs1 Luimm5 imm5 | NA | [X] | [ ] |
| p.extracti | NA | NA | [ ] | [ ] |
| p.extractr | p.extractr rd rs1 rs2 | NA | [X] | [ ] |
| p.extractu | p.extractu rd rs1 Luimm5 imm5 | NA | [X] | [ ] |
| p.extractui | NA | NA | [ ] | [ ] |
| p.extractur | p.extractur rd rs1 rs2 | NA | [X] | [ ] |
| p.insert | p.insert rd rs1 Luimm5 imm5 | NA | [X] | [ ] |
| p.inserti | NA | NA | [ ] | [ ] |
| p.insertr | p.insertr rd rs1 rs2 | NA | [X] | [ ] |
| p.bset | p.bset rd rs1 Luimm5 imm5 | NA | [X] | [ ] |
| p.bseti | NA | NA | [ ] | [ ] |
| p.bsetr | p.bsetr rd rs1 rs2 | NA | [X] | [ ] |
| p.bclr | p.bclr rd rs1 Luimm5 imm5 | NA | [X] | [ ] |
| p.bclri | NA | NA | [ ] | [ ] |
| p.bclrr | p.bclrr rd rs1 rs2 | NA | [X] | [ ] |
| p.cnt | p.cnt rd rs1 rs2 | NA | [X] | [ ] |
| p.clb | p.clb rd rs1 | NA | [X] | [ ] |
| p.fl1 | p.fl1 rd rs1 | NA | [X] | [ ] |
| p.ff1 | p.ff1 rd rs1 | NA | [X] | [ ] |
| p.ror | p.ror rd rs1 | NA | [X] | [ ] |
| p.exths | p.exths rd rs1 | NA | [X] | [ ] |
| p.exthz | p.exthz rd rs1 | NA | [X] | [ ] |
| p.extbs | p.extbs rd rs1 | NA | [X] | [ ] |
| p.extbz | p.extbz rd rs1 | NA | [X] | [ ] |

## xpulpclip extension

| Mnemonic | Usage | Description | riscv-opcodes | datasheet |
|----------|-------|-------------|---------------|-----------|
| p.clip | p.clip rd rs1 imm5 | NA | [X] | [ ] |
| p.clipi | NA | NA | [ ] | [ ] |
| p.clipr | p.clipr rd rs1 rs2 | NA | [X] | [ ] |
| p.clipu | p.clipu rd rs1 imm5 | NA | [X] | [ ] |
| p.clipui | NA | NA | [ ] | [ ] |
| p.clipur | p.clipur rd rs1 rs2 | NA | [X] | [ ] |

## xpulphwloop extension

| Mnemonic | Usage | Description | riscv-opcodes | datasheet |
|----------|-------|-------------|---------------|-----------|
| lp.starti | lp.starti L imm12 | NA | [X] | [ ] |
| lp.endi | lp.endi L imm12 | NA | [X] | [ ] |
| lp.count | lp.count L rs1 | NA | [X] | [ ] |
| lp.counti | lp.counti L imm12 | NA | [X] | [ ] |
| lp.setup | lp.setup L rs1 imm12 | NA | [X] | [ ] |
| lp.setupi | lp.setupi L imm12 uimms | NA | [X] | [ ] |

## xpulpmacsi extension

| Mnemonic | Usage | Description | riscv-opcodes | datasheet |
|----------|-------|-------------|---------------|-----------|
| p.mac | p.mac rd rs1 rs2 | NA | [X] | [ ] |
| p.msu | p.msu rd rs1 rs2 | NA | [X] | [ ] |

## xpulpmacrnhi extension

| Mnemonic | Usage | Description | riscv-opcodes | datasheet |
|----------|-------|-------------|---------------|-----------|
| p.macsN | | NA | | [ ] |
| p.macuN | | NA | | [ ] |
| p.macsRN | | NA | | [ ] |
| p.macuRN | | NA | | [ ] |
| p.machhsN | | NA | | [ ] |
| p.machhuN | | NA | | [ ] |
| p.machhsRN | | NA | | [ ] |
| p.machhuRN | | NA | | [ ] |

## xpulpmulrnhi extension

| Mnemonic | Usage | Description | riscv-opcodes | datasheet |
|----------|-------|-------------|---------------|-----------|
| p.mulhhs | | NA | | [ ] |
| p.mulhhu | | NA | | [ ] |
| p.muls | | NA | | [ ] |
| p.mulu | | NA | | [ ] |
| p.mulsN | | NA | | [ ] |
| p.mulsRN | | NA | | [ ] |
| p.muluN | | NA | | [ ] |
| p.muluRN | | NA | | [ ] |
| p.mulhhsN | | NA | | [ ] |
| p.mulhhuN | | NA | | [ ] |
| p.mulhhsRN | | NA | | [ ] |
| p.mulhhuRN | | NA | | [ ] |

## xpulppartmac extension

| Mnemonic | Usage | Description | riscv-opcodes | datasheet |
|----------|-------|-------------|---------------|-----------|
| p.macs | | (not in cv32e40p) | | [ ] |
| p.macu | | (not in cv32e40p) | | [ ] |
| p.machhs | | (not in cv32e40p) | | [ ] |
| p.machhu | | (not in cv32e40p) | | [ ] |

## xpulpaddsubrn extension

| Mnemonic | Usage | Description | riscv-opcodes | datasheet |
|----------|-------|-------------|---------------|-----------|
| p.addn | | NA | | [ ] |
| p.addni | | NA | | [ ] |
| p.addnr | | NA | | [ ] |
| p.addun | | NA | | [ ] |
| p.adduni | | NA | | [ ] |
| p.addunr | | NA | | [ ] |
| p.addrn | | NA | | [ ] |
| p.addrni | | NA | | [ ] |
| p.addrnr | | NA | | [ ] |
| p.addurn | | NA | | [ ] |
| p.addurni | | NA | | [ ] |
| p.addurnr | | NA | | [ ] |
| p.subn | | NA | | [ ] |
| p.subni | | NA | | [ ] |
| p.subnr | | NA | | [ ] |
| p.subun | | NA | | [ ] |
| p.subuni | | NA | | [ ] |
| p.subunr | | NA | | [ ] |
| p.subrn | | NA | | [ ] |
| p.subrni | | NA | | [ ] |
| p.subrnr | | NA | | [ ] |
| p.suburn | | NA | | [ ] |
| p.suburni | | NA | | [ ] |
| p.suburnr | | NA | | [ ] |

## xpulpvect extension

| Mnemonic | Usage | Description | riscv-opcodes | datasheet |
|----------|-------|-------------|---------------|-----------|
| pv.add.h | | | | |
| pv.add.sc.h | | | | |
| pv.add.sci.h | | | | |
| pv.add.b | | | | |
| pv.add.sc.b | | | | |
| pv.add.sci.b | | | | |
| pv.sub.h | | | | |
| pv.sub.sc.h | | | | |
| pv.sub.sci.h | | | | |
| pv.sub.b | | | | |
| pv.sub.sc.b | | | | |
| pv.sub.sci.b | | | | |
| pv.avg.h | | | | |
| pv.avg.sc.h | | | | |
| pv.avg.sci.h | | | | |
| pv.avg.b | | | | |
| pv.avg.sc.b | | | | |
| pv.avg.sci.b | | | | |
| pv.avgu.h | | | | |
| pv.avgu.sc.h | | | | |
| pv.avgu.sci.h | | | | |
| pv.avgu.b | | | | |
| pv.avgu.sc.b | | | | |
| pv.avgu.sci.b | | | | |
| pv.min.h | | | | |
| pv.min.sc.h | | | | |
| pv.min.sci.h | | | | |
| pv.min.b | | | | |
| pv.min.sc.b | | | | |
| pv.min.sci.b | | | | |
| pv.minu.h | | | | |
| pv.minu.sc.h | | | | |
| pv.minu.sci.h | | | | |
| pv.minu.b | | | | |
| pv.minu.sc.b | | | | |
| pv.minu.sci.b | | | | |
| pv.max.h | | | | |
| pv.max.sc.h | | | | |
| pv.max.sci.h | | | | |
| pv.max.b | | | | |
| pv.max.sc.b | | | | |
| pv.max.sci.b | | | | |
| pv.maxu.h | | | | |
| pv.maxu.sc.h | | | | |
| pv.maxu.sci.h | | | | |
| pv.maxu.b | | | | |
| pv.maxu.sc.b | | | | |
| pv.maxu.sci.b | | | | |
| pv.srl.h | | | | |
| pv.srl.sc.h | | | | |
| pv.srl.sci.h | | | | |
| pv.srl.b | | | | |
| pv.srl.sc.b | | | | |
| pv.srl.sci.b | | | | |
| pv.sra.h | | | | |
| pv.sra.sc.h | | | | |
| pv.sra.sci.h | | | | |
| pv.sra.b | | | | |
| pv.sra.sc.b | | | | |
| pv.sra.sci.b | | | | |
| pv.sll.h | | | | |
| pv.sll.sc.h | | | | |
| pv.sll.sci.h | | | | |
| pv.sll.b | | | | |
| pv.sll.sc.b | | | | |
| pv.sll.sci.b | | | | |
| pv.or.h | | | | |
| pv.or.sc.h | | | | |
| pv.or.sci.h | | | | |
| pv.or.b | | | | |
| pv.or.sc.b | | | | |
| pv.or.sci.b | | | | |
| pv.xor.h | | | | |
| pv.xor.sc.h | | | | |
| pv.xor.sci.h | | | | |
| pv.xor.b | | | | |
| pv.xor.sc.b | | | | |
| pv.xor.sci.b | | | | |
| pv.and.h | | | | |
| pv.and.sc.h | | | | |
| pv.and.sci.h | | | | |
| pv.and.b | | | | |
| pv.and.sc.b | | | | |
| pv.and.sci.b | | | | |
| pv.abs.h | | | | |
| pv.abs.b | | | | |
| pv.extract.h | | | | |
| pv.extract.b | | | | |
| pv.extractu.h | | | | |
| pv.extractu.b | | | | |
| pv.insert.h | | | | |
| pv.insert.b | | | | |
| pv.dotsp.h | | | | |
| pv.dotsp.sc.h | | | | |
| pv.dotsp.sci.h | | | | |
| pv.dotsp.b | | | | |
| pv.dotsp.sc.b | | | | |
| pv.dotsp.sci.b | | | | |
| pv.dotup.h | | | | |
| pv.dotup.sc.h | | | | |
| pv.dotup.sci.h | | | | |
| pv.dotup.b | | | | |
| pv.dotup.sc.b | | | | |
| pv.dotup.sci.b | | | | |
| pv.dotusp.h | | | | |
| pv.dotusp.sc.h | | | | |
| pv.dotusp.sci.h | | | | |
| pv.dotusp.b | | | | |
| pv.dotusp.sc.b | | | | |
| pv.dotusp.sci.b | | | | |
| pv.sdotsp.h | | | | |
| pv.sdotsp.sc.h | | | | |
| pv.sdotsp.sci.h | | | | |
| pv.sdotsp.b | | | | |
| pv.sdotsp.sc.b | | | | |
| pv.sdotsp.sci.b | | | | |
| pv.sdotup.h | | | | |
| pv.sdotup.sc.h | | | | |
| pv.sdotup.sci.h | | | | |
| pv.sdotup.b | | | | |
| pv.sdotup.sc.b | | | | |
| pv.sdotup.sci.b | | | | |
| pv.sdotusp.h | | | | |
| pv.sdotusp.sc.h | | | | |
| pv.sdotusp.sci.h | | | | |
| pv.sdotusp.b | | | | |
| pv.sdotusp.sc.b | | | | |
| pv.sdotusp.sci.b | | | | |
| pv.cmpeq.h | | | | |
| pv.cmpeq.sc.h | | | | |
| pv.cmpeq.sci.h | | | | |
| pv.cmpeq.b | | | | |
| pv.cmpeq.sc.b | | | | |
| pv.cmpeq.sci.b | | | | |
| pv.cmpne.h | | | | |
| pv.cmpne.sc.h | | | | |
| pv.cmpne.sci.h | | | | |
| pv.cmpne.b | | | | |
| pv.cmpne.sc.b | | | | |
| pv.cmpne.sci.b | | | | |
| pv.cmpgt.h | | | | |
| pv.cmpgt.sc.h | | | | |
| pv.cmpgt.sci.h | | | | |
| pv.cmpgt.b | | | | |
| pv.cmpgt.sc.b | | | | |
| pv.cmpgt.sci.b | | | | |
| pv.cmpge.h | | | | |
| pv.cmpge.sc.h | | | | |
| pv.cmpge.sci.h | | | | |
| pv.cmpge.b | | | | |
| pv.cmpge.sc.b | | | | |
| pv.cmpge.sci.b | | | | |
| pv.cmplt.h | | | | |
| pv.cmplt.sc.h | | | | |
| pv.cmplt.sci.h | | | | |
| pv.cmplt.b | | | | |
| pv.cmplt.sc.b | | | | |
| pv.cmplt.sci.b | | | | |
| pv.cmple.h | | | | |
| pv.cmple.sc.h | | | | |
| pv.cmple.sci.h | | | | |
| pv.cmple.b | | | | |
| pv.cmple.sc.b | | | | |
| pv.cmple.sci.b | | | | |
| pv.cmpgtu.h | | | | |
| pv.cmpgtu.sc.h | | | | |
| pv.cmpgtu.sci.h | | | | |
| pv.cmpgtu.b | | | | |
| pv.cmpgtu.sc.b | | | | |
| pv.cmpgtu.sci.b | | | | |
| pv.cmpgeu.h | | | | |
| pv.cmpgeu.sc.h | | | | |
| pv.cmpgeu.sci.h | | | | |
| pv.cmpgeu.b | | | | |
| pv.cmpgeu.sc.b | | | | |
| pv.cmpgeu.sci.b | | | | |
| pv.cmpltu.h | | | | |
| pv.cmpltu.sc.h | | | | |
| pv.cmpltu.sci.h | | | | |
| pv.cmpltu.b | | | | |
| pv.cmpltu.sc.b | | | | |
| pv.cmpltu.sci.b | | | | |
| pv.cmpleu.h | | | | |
| pv.cmpleu.sc.h | | | | |
| pv.cmpleu.sci.h | | | | |
| pv.cmpleu.b | | | | |
| pv.cmpleu.sc.b | | | | |
| pv.cmpleu.sci.b | | | | |
| pv.add.h.div2 | | | | |
| pv.add.h.div4 | | | | |
| pv.add.h.div8 | | | | |
| pv.sub.h.div2 | | | | |
| pv.sub.h.div4 | | | | |
| pv.sub.h.div8 | | | | |

## xpulpvectshufflepack extension

| Mnemonic | Usage | Description | riscv-opcodes | datasheet |
|----------|-------|-------------|---------------|-----------|
| pv.shuffle.h | | | | |
| pv.shuffle.sci.h | | | | |
| pv.shuffle.b | | | | |
| pv.shufflei0.sci.b | | | | |
| pv.shufflei1.sci.b | | | | |
| pv.shufflei2.sci.b | | | | |
| pv.shufflei3.sci.b | | | | |
| pv.shuffle2.h | | | | |
| pv.shuffle2.b | | | | |
| pv.pack | | | | |
| pv.pack.h | | | | |
| pv.packhi.b | | | | |
| pv.packlo.b | | | | |

## xpulpvectcomplex extension

| Mnemonic | Usage | Description | riscv-opcodes | datasheet |
|----------|-------|-------------|---------------|-----------|
| pv.cplxmul.h.r | NA | NA | [ ] | [ ] |
| pv.cplxmul.h.r.div | NA | NA | [ ] | [ ] |
| pv.cplxmul.h.r.div | NA | NA | [ ] | [ ] |
| pv.cplxmul.h.r.div | NA | NA | [ ] | [ ] |
| pv.cplxmul.h.i | NA | NA | [ ] | [ ] |
| pv.cplxmul.h.i.div | NA | NA | [ ] | [ ] |
| pv.cplxmul.h.i.div | NA | NA | [ ] | [ ] |
| pv.cplxmul.h.i.div | NA | NA | [ ] | [ ] |
| pv.subrotmj.h | NA | NA | [ ] | [ ] |
| pv.subrotmj.h.div2 | NA | NA | [ ] | [ ] |
| pv.subrotmj.h.div4 | NA | NA | [ ] | [ ] |
| pv.subrotmj.h.div8 | NA | NA | [ ] | [ ] |
| pv.cplxconj.h | pv.cplxconj.h rD, rA | <code> rD[15:0 ] = rA[15:0 ] <br> rD[31:16] = -rA[31:16] </code>| [ ] | [X] |

## xpulpbr extension

| Mnemonic | Usage | Description | riscv-opcodes | datasheet |
|----------|-------|-------------|---------------|-----------|
| p.beqimm | | | | [ ] |
| p.bneimm | | | | [ ] |

## xpulpelw extension

| Mnemonic | Usage | Description | riscv-opcodes | datasheet |
|----------|-------|-------------|---------------|-----------|
| p.elw | | | | [ ] |
