# RNNASIP Dockerfile

To build the image, execute the build script: `./build.sh`


To get a container inside the image, run `./run.sh`. If this command has been run before, you may need to remove the previous image. use `docker rm <container/instance hash>` or `docker rmi <image hash>` beforehand, if needed.

A full list of observations, including errors and necessary adjustments to be able to run the tests can be found [here](./observations/README.md).

## Hardware and supported ISA Specification

This extension was implemented for the PULPissimo microcontroller architecture (single core) with a RI5CY (now CV32E40P) core. It has support for the following standard ISA extensions:

- I (integer operations, mandatory)
- M (hardware multiplication)
- C (compressed instructions aka 16 bit operations)
- F (floating point instructions and registers)

It also supports the XpulpV2 non-standard ISA extension, which allows for:

- hardware loops
- post-incrementing load and store instructions
- multiply-accumulate (MAC) instructions
- packed SIMD operations, such as bit manipulation and dot product

## Custom Instruction Test

A test of the RNNASIP custom instruction (XpulpV2's hardware loops, MAC and packed SIMD instructions) is run automatically when building the container. They can be found on the following path inside the container: `/workspace/RNNASIP/sourcecode/rnnSampleCode/test.c`.
This test uses the default cycle-accurate simulator preconfigured by RNNASIP ([GVSOC](https://github.com/gvsoc/gvsoc)), and (utilizes / is built with) all extensions mentioned above.