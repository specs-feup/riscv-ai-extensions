# Pulp/Corev X-Heep with cv32e40p core

Builds x-heep with a cv32e40p core, using the pulp riscv toolchain with the purpose of being to compile and execute xcorev custom instructions.

It uses the [core-v toolchain](https://www.embecosm.com/resources/tool-chain-downloads/#corev) provided by embecosm.

⚠️ WARNING: Please make sure you have the corev toolchain in dependencies with the correct name! If not run `sh ./dependencies/get_dependencies.sh` before trying to build the image.

⚠️ WARNING: The rest of this readme assumes you have sourced the python virtual environment, which should be done automatically if you log into the the container using a bash shell. If not, run `source /workspace/x-heep/.venv/bin/activate`. This must be done every time when running commands on the Dockerfile (check the last few lines of [our Dockerfile](./Dockerfile) for an example).

## Status

- Complete

## Compiling and running a test

In general, compiling and running a test is divided into four parts (assuming you have already sourced the python virtual environment):

1. Compiling the microcontroller
2. Compiling the simulator
3. Compiling the application
4. Running the application under the simulator

The first step can be achieved by running the ```make mcu-gen``` command under the `/workspace/x-heep` directory with the appropriate flags. In our case, `make mcu-gen CPU=cv32e40p` suffices. For further details check [Generate core-v-mini-mcu package](https://github.com/esl-epfl/x-heep/blob/main/docs/source/How_to/CompileMakefile.md#generate-core-v-mini-mcu-package).

The second step can be achieved by running a similar command under the same directory. The command depends on which simulator is being built, more info can be found on [Using different simulators](#using-different-simulators).

The third step can be achieved by running a `make app` command under the same directory with the appropriate flags and values. The most important flags are as follows:

- PROJECT: configures which application is going to be compiled. Applications are directories, under `/workspace/x-heep/sw/applications` with a `main.c` file in it. The name of this directory is the value passed to the `PROJECT` flag. In our example, we copy `./dependencies/test.c` to a directory called `pulp_instruction` (and calling the file `main.c`) and then we call `make app PROJECT="pulp_instruction" ...`

- ARCH: configures the architecture used by the compiler to build the application. If an instruction of the `xcvbitmanip` extension is used, then it should be enabled here, otherwise the compiler will throw an error. The value of this flag is any valid [risc-v arch string](https://github.com/pulp-platform/riscv-gnu-toolchain/blob/master/pulp.md#all-extension-subsets) supported by the compiler specified under `RISCV` environment variable (along with the COMPILER_PREFIX option described below), in this docker container it points to `/opt/riscv`, and the compiler can be found on `/opt/riscv/bin/riscv32-corev-elf-gcc`. On the current version of the compiler, `/opt/riscv/bin/riscv32-corev-elf-gcc -march=help` can be run to enumerate all the supported riscv extensions. Non standard extensions (those beginning with x) can be chained together, delimiting them with underscores like so: `rv32imfc_xcvalu_xcvbi_xcvbitmanip`.
In our case, we enable all supported core-v extensions: `ARCH='rv32imfc_xcvalu_xcvbi_xcvbitmanip_xcvelw_xcvhwlp_xcvmac_xcvmem_xcvsimd'`

- COMPILER_PREFIX: configures the prefix which is used to search for the binaries under the directory specified by the `RISCV` environment variable. By default it's `riscv32-unknown-`, as that is what you get if you simply compile the standard riscv gnu toolchain, but since we are using the core-v toolchain `riscv32-corev-` is required.

Overall, compiling an application under the current setup looks like so:

`make app PROJECT='<project name>' ARCH='rv32imfc_xcvalu_xcvbi_xcvbitmanip_xcvelw_xcvhwlp_xcvmac_xcvmem_xcvsimd' COMPILER_PREFIX='riscv32-corev-'`

Finally, the fourth step consists of changing the directory based on what simulator was compiled and running a command pointing to the compiled binary of the application, which should now be on `/workspace/x-heep/sw/build/main.hex`. Checking the stdout of the program that was run can be achieved by running `cat uart0.log` on the same directory, at least when using Verilog.

For more information check [1](https://github.com/esl-epfl/x-heep/blob/main/docs/source/How_to/GettingStarted.md), [2](https://github.com/esl-epfl/x-heep/blob/main/docs/source/How_to/Simulate.md) and [3](https://github.com/esl-epfl/x-heep/blob/main/docs/source/How_to/CompileMakefile.md).

## Adding more tests

Adding more tests is as simple as writing a main.c file and copying it to a folder under `/workspace/x-heep/sw/applications/`. For example, in the Dockerfile we copy `./dependencies/test.c` to our newly created `pulp_instruction` directory under the applications directory (note how we name it main.c).
The steps required to run the application vary on the simulator used. Further instructions can be found on [Compiling and running a test](#compiling-and-running-a-test) and [Using different simulators](#using-different-simulators).

## Using different simulators

X-Heep currently supports 4 simulators out of the box: [VCS](https://www.synopsys.com/verification/simulation/vcs.html), [Questasim](https://eda.sw.siemens.com/en-US/ic/questa/simulation/advanced-simulator/), [Xcelium](https://www.cadence.com/en_US/home/tools/system-design-and-verification/simulation-and-testbench-verification/xcelium-simulator.html), and [Verilator](https://github.com/verilator/verilator), though the first three require licenses, and as such are not tested here. If you pretend to use them, please acquire a license and install it on top of this container.

The container provided by this repository is set up to support Verilator by default, but it is easy to switch to other simulators.

⚠️ WARNING: You should read [Compiling and running a test](#compiling-and-running-a-test) before running the instructions below.

All instructions below start under the `/workspace/x-heep/` directory.

### VCS

For compiling the simulator use `make vcs-sim`, and for simulating an application run `cd /workspace/x-heep/build/openhwgroup.org_systems_core-v-mini-mcu_0/sim-vcs` and then `./openhwgroup.org_systems_core-v-mini-mcu_0 +firmware=../../../sw/build/main.hex`.

More details [here](https://github.com/esl-epfl/x-heep/blob/main/docs/source/How_to/Simulate.md#compiling-for-vcs).
 
### Questasim

For compiling the simulator use `make questasim-sim`, and for simulating an application run `cd /workspace/x-heep/build/openhwgroup.org_systems_core-v-mini-mcu_0/sim-modelsim/` and then `make run PLUSARGS="c firmware=../../../sw/build/main.hex"`.

More details [here](https://github.com/esl-epfl/x-heep/blob/main/docs/source/How_to/Simulate.md#compiling-for-questasim).

### Xcelium

For compiling the simulator use `make xcelium-sim`, and for simulating an application run `cd /workspace/x-heep/build/openhwgroup.org_systems_core-v-mini-mcu_0/sim-xcelium/` and then `make run PLUSARGS="c firmware=../../../sw/build/main.hex"`.

More details [here](https://github.com/esl-epfl/x-heep/blob/main/docs/source/How_to/Simulate.md#compiling-for-xcelium).

### Verilator

For compiling the simulator use `make verilator-sim`, and for simulating an application run `cd /workspace/x-heep/build/openhwgroup.org_systems_core-v-mini-mcu_0/sim-verilator` and then `./Vtestharness +firmware=../../../sw/build/main.hex"`.

More details [here](https://github.com/esl-epfl/x-heep/blob/main/docs/source/How_to/Simulate.md#compiling-for-verilator).

## core-v extensions

A list of all extensions supported by the cv32e40p can be found [here](https://docs.openhwgroup.org/projects/cv32e40p-user-manual/en/latest/instruction_set_extensions.html).

## Building Observations

For a thorough explanation of the build steps and utilization tips, check the [observations' README](./observations/README.md).

Additionally, [x-heep's documentation](https://github.com/esl-epfl/x-heep/tree/main/docs/source) may also be of aid.
