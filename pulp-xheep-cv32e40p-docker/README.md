# Pulp/Corev X-Heep with cv32e40p core

Builds x-heep with a 32e40p core, using the pulp riscv toolchain with the purpose of being to compile and execute Xpulp custom instructions. Upon further analysis, it only supports xcorev instructions.

It uses the [core-v toolchain](https://www.embecosm.com/resources/tool-chain-downloads/#corev) provided by embecosm.

WARNING: Please make sure you have the corev toolchain in dependencies with the correct name! If not you can run `sh ./dependencies/get_dependencies.sh` before trying to build the image.

## Status

- In the middle of refactoring...

## Pulp extensions

A list of all extensions supported by the cv32e40p can be found [here](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html).
