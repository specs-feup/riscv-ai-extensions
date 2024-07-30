# X-heep with cv32e40p Core Dockerfile Observations

## Necessary Changes

- Change python venv dependencies to newer versions, included in Dockerfile
- Use a newer version of verilator, details [here](#verilator).
- When compiling applications, make sure to use the appropriate values for the ARCH (`rv32imfcxcorev`) and COMPILER_PREFIX (`riscv32-corev-`) options. Further details on the [x-heep compiling documentation](https://github.com/esl-epfl/x-heep/blob/main/docs/source/How_to/CompileMakefile.md#compiling-software).

## Errors

### Verilator

The required verilator version is v4.210, however it does not compile due to an error as described [here](https://github.com/verilator/verilator/issues/5162). It is necessary to add a `#include <memory>` in `Verilator/src/V3Const.cpp`.

## Supported Extensions

According to the [CV32E40Pv2 Project Approval](https://github.com/openhwgroup/programs/blob/master/Project-Descriptions-and-Plans/CV32E40Pv2/Project_Concept_for_CV32E40Pv2_June-28.md), "Re-encod(ing) in Custom extension" pulp instructions is one of the main objectives. This leads me to believe that not being able to compile pulp instructions (p.cnt), but rather its corev equivalent (cv.cnt) is due to this re-encoding, and also that x-heep is using the v2 version of the core. As such I will proceed based on that assumption.

The tests will be based on [Openhwgroup's core-v-verif pulp tests](https://github.com/openhwgroup/core-v-verif/blob/master/cv32e40p/tests/programs/custom).
Before the tests can be assembled, a cross reference between corev encoded instructions and pulp instructions will be conducted, in order to find any discrepancies and exceptions, so that the tests can be adapted to such scenarios.

The list of sources for this whole endeavour can be found here:

- [core-v-verif cv32e40p xpulp verification plans](https://github.com/openhwgroup/core-v-verif/tree/master/cv32e40p/docs/VerifPlans/Simulation/xpulp_instruction_extensions)
- [core-v-verif cv32e40p (1 month) old  test list](https://github.com/pascalgouedo/core-v-verif/blob/21b510eff576104d84bc9354056fe81c68e116a5/cv32e40p/docs/VerifPlans/Simulation/CV32E40Pv2_test_list.xlsx)
- [yet another old core-v-verif list](https://github.com/openhwgroup/core-v-verif/pull/2476/files?short_path=9a6fd39#diff-9a6fd39efa6158f82548bf64ebb58b26cbc682f69f4be333bfa4ef3baaf8b32d)
- [Raw listings of pulp instructions](https://github.com/pulp-platform/riscv-gnu-toolchain/blob/master/pulp.md)
- [CV32E40P custom instructions (user manual)](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html)
- [core-v instructions cross reference to pulp instructions according to pulp](https://github.com/pulp-platform/riscv-gnu-toolchain/blob/master/core-v.rst)
- [risc-v xpulp instructions opcodes and usage according to riscv-opcodes by pulp](https://github.com/pulp-platform/riscv-opcodes/blob/master/opcodes-xpulppostmod_CUSTOM)
- [old pulp datasheet (manual?)](https://github.com/pulp-platform/pulp/blob/master/doc/datasheet.pdf)
