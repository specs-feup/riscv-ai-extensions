FROM ubuntu:24.04
RUN apt-get update
RUN apt-get install openocd minicom -y
RUN apt-get install autoconf automake autotools-dev curl python3 python3-pip libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev libslirp-dev -y

RUN mkdir /workspace/
WORKDIR /workspace/

RUN git clone https://github.com/Fraunhofer-IMS/airisc_core_complex.git
RUN git clone https://github.com/riscv/riscv-gnu-toolchain

ENV PATH="$PATH:/opt/riscv/bin"
WORKDIR /workspace/riscv-gnu-toolchain
RUN /workspace/riscv-gnu-toolchain/configure --prefix=/opt/riscv --with-arch=rv32gc --with-abi=ilp32d
RUN make linux

RUN apt-get install iverilog -y

WORKDIR /workspace/airisc_core_complex/.ci

CMD ["/bin/bash"]
