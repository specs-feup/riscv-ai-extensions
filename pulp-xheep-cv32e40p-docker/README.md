# Pulp X-Heep with cv32e40p core

Builds x-heep with a 32e40p core, using the pulp riscv toolchain with the purpose of being to compile and execute Xpulp custom instructions. At this point it is not yet clear this is expressly required.

## Status

- The x-heep baseline tests are still not compilable.

## XpulpV2 / XpulpNN extensions clarification

- XpulpV2 is an ISA extension that enables hardware loops, auto-incrementing load/store operations, bit manipulation instructions, fixed-point and 8-bit and 16-bit packed single-instruction-multiple-data (SIMD) operations.
- XpulpNN is an ISA extension that enables SIMD operations for 4-bit and 2-bit operands.
