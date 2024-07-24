# X-heep with cv32e40p Core Dockerfile Observations

## Necessary Changes

- Change python venv dependencies to newer versions, included in Dockerfile
- Use a newer version of verilator, details [here](#verilator).
- When compiling applications, make sure to use the appropriate values for the ARCH (`rv32imfcxcorev`) and COMPILER_PREFIX (`riscv32-corev-`) options. Further details on the [x-heep compiling documentation](https://github.com/esl-epfl/x-heep/blob/main/docs/source/How_to/CompileMakefile.md#compiling-software).

## Errors

### Verilator

The required verilator version is v4.210, however it does not compile due to an error as described [here](https://github.com/verilator/verilator/issues/5162). It is necessary to add a `#include <memory>` in `Verilator/src/V3Const.cpp`.
