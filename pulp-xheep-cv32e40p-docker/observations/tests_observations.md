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
