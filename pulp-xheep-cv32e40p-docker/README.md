# Pulp/Corev X-Heep with cv32e40p core

Builds x-heep with a cv32e40p core, using the pulp riscv toolchain with the purpose of being to compile and execute xcorev custom instructions.

It uses the [core-v toolchain](https://www.embecosm.com/resources/tool-chain-downloads/#corev) provided by embecosm.

WARNING: Please make sure you have the corev toolchain in dependencies with the correct name! If not you can run `sh ./dependencies/get_dependencies.sh` before trying to build the image.

## Status

- Complete

## core-v extensions

A list of all extensions supported by the cv32e40p can be found [here](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html).

## Building Observations

For a thorough explanation of the build steps and utilization tips, check the [observations' README](./observations/README.md).

Additionally, [x-heep's documentation](https://github.com/esl-epfl/x-heep/tree/main/docs/source) may also be of aid.
