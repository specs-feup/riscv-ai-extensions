# xpulp extensions/instructions in the core-v group

This list was compiled from [here](https://github.com/pulp-platform/riscv-gnu-toolchain/blob/master/pulp.md#extension-groups).

## xpulppostmod extension
Description: post-increment and reg-reg load and store (PULP_POSTMOD in gcc)

- p.lb
- p.lbu
- p.lh
- p.lhu
- p.lw
- p.sb
- p.sh
- p.sw

## xpulpindregreg extension

Description: register indirect store and load (PULP_INDREGREG in gcc)

## xpulpabs extension

Description: Abs

- p.abs (collides with p.avg, only pulp < v2)

## xpulpslet extension

Description: (PULP_SLET in gcc)

- p.slet
- p.sletu

## xpulpminmax extension

Description: min/max functions (PULP_MINMAX in gcc)

- p.min
- p.max
- p.minu
- p.maxu
- p.avg (replaced with p.addN in pulp >= v2) (p.addN is an emulation)
- p.avgu (replaced with p.adduN in pulp >= v2) (p.adduN is an emulation)

## xpulpbitop extension

Description: bit manipulation (PULP_BITOP in gcc)

- p.extract
- p.extracti
- p.extractr
- p.extractu
- p.extractui
- p.extractur
- p.insert
- p.inserti
- p.insertr
- p.bset
- p.bseti
- p.bsetr
- p.bclr
- p.bclri
- p.bclrr
- p.cnt
- p.clb
- p.fl1
- p.ff1
- p.ror
- p.exths
- p.exthz
- p.extbs
- p.extbz

## xpulpclip extension

Description: clip instructions (PULP_CLIP in gcc)

- p.clip
- p.clipi
- p.clipr
- p.clipu
- p.clipui
- p.clipur

## xpulphwloop extension

Description: hardware loops (PULP_HWLOOP in gcc)

- lp.starti
- lp.endi
- lp.count
- lp.counti
- lp.setup
- lp.setupi

## xpulpmacsi extension

Description: mac 32x32 into 32 (PULP_MAC_SI in gcc)

- p.mac
- p.msu

## xpulpmacrnhi extension

Description: partial mac (16x16 into 32) with rounding and norm (PULP_MACRN_HI in gcc)

- p.macsN
- p.macuN
- p.macsRN
- p.macuRN
- p.machhsN
- p.machhuN
- p.machhsRN
- p.machhuRN

## xpulpmulrnhi extension

Description: partial mul (16x16 into 32) (PULP_MULRN_HI in gcc)

- p.mulhhs
- p.mulhhu
- p.muls
- p.mulu
- p.mulsN
- p.mulsRN
- p.muluN
- p.muluRN
- p.mulhhsN
- p.mulhhuN
- p.mulhhsRN
- p.mulhhuRN

## xpulppartmac extension

Description: partial mac 16x16 into 32 (PULP_PARTMAC in gcc)

- p.macs (not in cv32e40p)
- p.macu (not in cv32e40p)
- p.machhs (not in cv32e40p)
- p.machhu (not in cv32e40p)

## xpulpaddsubrn extension

Description: add/sub with norm/round (PULP_ADDSUBRN in gcc)

- p.addn
- p.addni
- p.addnr
- p.addun
- p.adduni
- p.addunr
- p.addrn
- p.addrni
- p.addrnr
- p.addurn
- p.addurni
- p.addurnr
- p.subn
- p.subni
- p.subnr
- p.subun
- p.subuni
- p.subunr
- p.subrn
- p.subrni
- p.subrnr
- p.suburn
- p.suburni
- p.suburnr

## xpulpvect extension

Description: Integer SIMD instructions (PULP_VECT in gcc)

- pv.add.h
- pv.add.sc.h
- pv.add.sci.h
- pv.add.b
- pv.add.sc.b
- pv.add.sci.b
- pv.sub.h
- pv.sub.sc.h
- pv.sub.sci.h
- pv.sub.b
- pv.sub.sc.b
- pv.sub.sci.b
- pv.avg.h
- pv.avg.sc.h
- pv.avg.sci.h
- pv.avg.b
- pv.avg.sc.b
- pv.avg.sci.b
- pv.avgu.h
- pv.avgu.sc.h
- pv.avgu.sci.h
- pv.avgu.b
- pv.avgu.sc.b
- pv.avgu.sci.b
- pv.min.h
- pv.min.sc.h
- pv.min.sci.h
- pv.min.b
- pv.min.sc.b
- pv.min.sci.b
- pv.minu.h
- pv.minu.sc.h
- pv.minu.sci.h
- pv.minu.b
- pv.minu.sc.b
- pv.minu.sci.b
- pv.max.h
- pv.max.sc.h
- pv.max.sci.h
- pv.max.b
- pv.max.sc.b
- pv.max.sci.b
- pv.maxu.h
- pv.maxu.sc.h
- pv.maxu.sci.h
- pv.maxu.b
- pv.maxu.sc.b
- pv.maxu.sci.b
- pv.srl.h
- pv.srl.sc.h
- pv.srl.sci.h
- pv.srl.b
- pv.srl.sc.b
- pv.srl.sci.b
- pv.sra.h
- pv.sra.sc.h
- pv.sra.sci.h
- pv.sra.b
- pv.sra.sc.b
- pv.sra.sci.b
- pv.sll.h
- pv.sll.sc.h
- pv.sll.sci.h
- pv.sll.b
- pv.sll.sc.b
- pv.sll.sci.b
- pv.or.h
- pv.or.sc.h
- pv.or.sci.h
- pv.or.b
- pv.or.sc.b
- pv.or.sci.b
- pv.xor.h
- pv.xor.sc.h
- pv.xor.sci.h
- pv.xor.b
- pv.xor.sc.b
- pv.xor.sci.b
- pv.and.h
- pv.and.sc.h
- pv.and.sci.h
- pv.and.b
- pv.and.sc.b
- pv.and.sci.b
- pv.abs.h
- pv.abs.b
- pv.extract.h
- pv.extract.b
- pv.extractu.h
- pv.extractu.b
- pv.insert.h
- pv.insert.b
- pv.dotsp.h
- pv.dotsp.sc.h
- pv.dotsp.sci.h
- pv.dotsp.b
- pv.dotsp.sc.b
- pv.dotsp.sci.b
- pv.dotup.h
- pv.dotup.sc.h
- pv.dotup.sci.h
- pv.dotup.b
- pv.dotup.sc.b
- pv.dotup.sci.b
- pv.dotusp.h
- pv.dotusp.sc.h
- pv.dotusp.sci.h
- pv.dotusp.b
- pv.dotusp.sc.b
- pv.dotusp.sci.b
- pv.sdotsp.h
- pv.sdotsp.sc.h
- pv.sdotsp.sci.h
- pv.sdotsp.b
- pv.sdotsp.sc.b
- pv.sdotsp.sci.b
- pv.sdotup.h
- pv.sdotup.sc.h
- pv.sdotup.sci.h
- pv.sdotup.b
- pv.sdotup.sc.b
- pv.sdotup.sci.b
- pv.sdotusp.h
- pv.sdotusp.sc.h
- pv.sdotusp.sci.h
- pv.sdotusp.b
- pv.sdotusp.sc.b
- pv.sdotusp.sci.b
- pv.cmpeq.h
- pv.cmpeq.sc.h
- pv.cmpeq.sci.h
- pv.cmpeq.b
- pv.cmpeq.sc.b
- pv.cmpeq.sci.b
- pv.cmpne.h
- pv.cmpne.sc.h
- pv.cmpne.sci.h
- pv.cmpne.b
- pv.cmpne.sc.b
- pv.cmpne.sci.b
- pv.cmpgt.h
- pv.cmpgt.sc.h
- pv.cmpgt.sci.h
- pv.cmpgt.b
- pv.cmpgt.sc.b
- pv.cmpgt.sci.b
- pv.cmpge.h
- pv.cmpge.sc.h
- pv.cmpge.sci.h
- pv.cmpge.b
- pv.cmpge.sc.b
- pv.cmpge.sci.b
- pv.cmplt.h
- pv.cmplt.sc.h
- pv.cmplt.sci.h
- pv.cmplt.b
- pv.cmplt.sc.b
- pv.cmplt.sci.b
- pv.cmple.h
- pv.cmple.sc.h
- pv.cmple.sci.h
- pv.cmple.b
- pv.cmple.sc.b
- pv.cmple.sci.b
- pv.cmpgtu.h
- pv.cmpgtu.sc.h
- pv.cmpgtu.sci.h
- pv.cmpgtu.b
- pv.cmpgtu.sc.b
- pv.cmpgtu.sci.b
- pv.cmpgeu.h
- pv.cmpgeu.sc.h
- pv.cmpgeu.sci.h
- pv.cmpgeu.b
- pv.cmpgeu.sc.b
- pv.cmpgeu.sci.b
- pv.cmpltu.h
- pv.cmpltu.sc.h
- pv.cmpltu.sci.h
- pv.cmpltu.b
- pv.cmpltu.sc.b
- pv.cmpltu.sci.b
- pv.cmpleu.h
- pv.cmpleu.sc.h
- pv.cmpleu.sci.h
- pv.cmpleu.b
- pv.cmpleu.sc.b
- pv.cmpleu.sci.b
- pv.add.h.div2
- pv.add.h.div4
- pv.add.h.div8
- pv.sub.h.div2
- pv.sub.h.div4
- pv.sub.h.div8

## xpulpvectshufflepack extension

Description: Additional SIMD instructions for shuffle and pack (PULP_\VECT_SHUFFLEPACK in gcc)

- pv.shuffle.h
- pv.shuffle.sci.h
- pv.shuffle.b
- pv.shufflei0.sci.b
- pv.shufflei1.sci.b
- pv.shufflei2.sci.b
- pv.shufflei3.sci.b
- pv.shuffle2.h
- pv.shuffle2.b
- pv.pack
- pv.pack.h
- pv.packhi.b
- pv.packlo.b

## xpulpvectcomplex extension

Description: PULP SIMD complex instructions (PULP_\VECT_COMPLEX in gcc)

- pv.cplxmul.h.r
- pv.cplxmul.h.r.div
- pv.cplxmul.h.r.div
- pv.cplxmul.h.r.div
- pv.cplxmul.h.i
- pv.cplxmul.h.i.div
- pv.cplxmul.h.i.div
- pv.cplxmul.h.i.div
- pv.subrotmj.h
- pv.subrotmj.h.div2
- pv.subrotmj.h.div4
- pv.subrotmj.h.div8
- pv.cplxconj.h

## xpulpbr extension

Description: Immediate branching instructions (PULP_BR in gcc)

- p.beqimm
- p.bneimm

## xpulpelw extension

Description: (PULP_ELW in gcc)

- p.elw
