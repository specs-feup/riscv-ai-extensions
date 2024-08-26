# Tests Observations

This file lists all the problems found when adapting the [core-v-verif pulp tests]() to be able to run them in this docker container under x-heep.

## Modifications

In order to get the tests running on x-heep some changes had to be made. First, it appears that the testing infrastructure isn't made to support assembly files. Even after tinkering with the make and cmake files, I couldn't get the tests to compile properly (even after making .S files detectable by cmake and fixing some double declarations of global variables it still didn't work), so instead I opted into transforming the tests into inline assembly inside of a main funtion in a .c file.

As such, I had to remove all the `li` instructions at the beginning of the tests, as including them all on the "clobbered" registers lists doesn't allow for compilation. I also removed everything that didn't seem strictly necessary, though I admit much of the purpose of these instructions went over my head. Nonetheless, I added a print with the number of failed tests at the end, which seems to be working (cv.bitrev instruction caused it to be 1, without it it's 0), and called it a day.

The `zicsr` instruction was added when compiling the test. Explained in [Interrupts and CSRS](#interrupts-and-csrs).

Finally, all the `p.<name>` instructions has to be switched with `cv.<name>`, to be compilable by the core-v embecosm toolchain (due to the re-encoding).


## Errors

### pulp_bit_manipulation

#### .word instructions

Along the test file, some `.word` directives appear, used mainly in tests 91-96 (and in the beginning of the file to set the test_results variable) as way to force a specific instruction already encoded into machine code, however I have found that this stalls the program indefinitely at best and causes illegal memory accesses at worst, as such all of these lines had to be removed.

Additionally, it is unclear why the authors didn't use the `p.bitrev` instruction instead of this hack (the instruction equivalent is even commented next to it), perhaps the gcc at the time didn't support it. At any case, when applicable one could just switch the `.word` directives to the `cv.bitrev` equivalent, but that has its own problems described next.

#### cv.bitrev instructions

Tests 91-93 use illegal `cv.bitrev` instructions, and the next ones yielded incorrect results. The `.word` directives were not translated directly, instead I used the commented out `p.bitrev` (translated to `cv.bitrev`) that would assumedly be the equivalent instructions, however it appears these commented out instructions had the last 2 operands switched. After promptly switching the aforementioned operands, the instructions compiled and yielded correct results.


#### Interrupts and CSRS

At the beginning of the tests a `csrs` instruction is used to enable interrupts. At the end (previously) a "wait for instruction" (`wfi`) instruction was used. The purpose of this is unclear, but the latter was removed as it did not seem necessary. The former requires the `zicsr` extension when compiling the tests.

## Test collections comments

Remarks on the making of each main.c in [core-v-verif-tests](../dependencies/core-v-verif-tests/)

### pulp_bit_manipulation

Standard instruction renaming and reshaping to a C file. Issues with `.word` directives and bitrev instructions detailed [above](#cvbitrev-instructions).

### pulp_general_alu

Standard instruction renaming and reshaping to a C file. No further problems.

### pulp_immediate_branching

Standard instruction renaming and reshaping to a C file. No further problems.

### pulp_multiply_accumulate

Standard instruction renaming and reshaping to a C file. No further problems.

### pulp_post_increment_load_store

Standard instruction renaming and reshaping to a C file.
Most of the instructions have suffered changes in one way or another. Most instructions also support multiple usages. As the changes are similar across usages, they are grouped per usage rather than instruction.
Any and all parenthesis are necessary.

There were a lot of errors with this test, so each "load" and "store" usage type has been split into its own file. I also changed (almost) all register usage to temporary ones. Additionally, hardcoded memory addresses have been changed freely to comply with the default x-heep memory constraints.

Instruction list:
- `cv.lb` - loads a byte from memory and sign extends it. 
- `cv.lbu` - loads a byte from memory and zero-extends it. 
- `cv.lh` - loads a halfword from memory and sign extends it. 
- `cv.lhu` - loads a halfword from memory and zero-extends it. 
- `cv.lw` - loads a word from memory. 
- `cv.sb` - stores a byte to memory. 
- `cv.sh` - stores a halfword to memory. 
- `cv.sw`-  stores a word to memory.

All of these perform post increment from a register or an immediate, or alternatively get the address from the sum of two registers, depending on usage.

#### Load with Post Increment of Immediate Offset (tests 1-30)

Instructions affected:
- `p.lb`
- `p.lbu`
- `p.lh`
- `p.lhu`
- `p.lw` 

Instructions have changed: from `p.<instr> rD, Imm(rs1!)` to `cv.<instr> rD, (rs1), Imm`
Post increment type: rs1 = rs1 + Imm
Old example: `p.lb x18, 0x5(x20!)`
New example: `cv.lb x18, (x20), 0x5`

In both cases Imm is any value of 12 bits.

#### Load with Post Increment of Register Offset (tests 31-60)

Instructions affected:
- `p.lb`
- `p.lbu`
- `p.lh`
- `p.lhu`
- `p.lw` 

Instructions have changed: from `p.<instr> rD, rs2(rs1!)` to `cv.<instr> rD, (rs1), rs2`
Post increment type: rs1 = rs1 + rs2
Old example: `p.lb x18, x22(x20!)`
New example: `cv.lb x18, (x20), x22`

#### Load with Register-Register source (tests 61-90)

Instructions have not changed (apart from the standard renaming).
Instructions are of type `cv.<instr> rD, rs2(rs1)`, where the data is loaded from `rs1 + rs2`.
Post increment type: **None**.

#### Store with Post Increment of Immediate Offset (tests 91-108)

Instructions affected:
- `p.sb`
- `p.sh`
- `p.sw`

Instructions have changed: from `p.<instr> rs2, Imm(rs1!)` to `cv.<instr> rs2, (rs1), Imm`
Post increment type: rs1 = rs1 + Imm
Old example: `p.sb x17, 0x169(x20!)`
New example: `cv.sb x17, (x20), 0x169`

In both cases Imm is any value of 12 bits.

#### Store with Post Increment of Register Offset (tests 109-126)

Instructions affected:
- `p.sb`
- `p.sh`
- `p.sw`

Instructions have changed: from `p.<instr> rs2, rs3(rs1!)` to `cv.<instr> rs2, (rs1), rs3`
Post increment type: rs1 = rs1 + rs3
Old example: `p.sb x17, x22(x20!)`
New example: `cv.sb x17, (x20), x22`

I have elected to keep x26's usage here, as working around it would involve adding more instructions to the tests unless one reuses the t3 register to hold the expected value of the test, which in some weird edge cases may mean that the test isn't failing when supposed to (when storing full words, if the lw instruction that loads the expected value of the test does not alter t3, the test would pass even if the stored value is wrong). It doesn't seem to be causing any issues for now.

### Store with Register-Register source (tests 127-144)

Instructions have not changed (apart from the standard renaming).
Instructions are of type `cv.<instr> rs2, rs3(rs1)`, where the data from rs2 is stored to `rs1 + rs3`.
Post increment type: **None**.

The original tests included an instruction that appeared to be zero'ing out the memory where the value was supposed to be stored, a continuation of what was done in the previous tests, however it appears the authors forgot that the location that was being written to was no longer stored in the same registers as the previous tests, so this was fixed.
