FROM ubuntu:noble-20240605

RUN apt-get update -y && apt-get upgrade -y && apt-get install -y wget git cmake build-essential autoconf automake autotools-dev curl python3 libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev libglib2.0-dev binutils-dev libboost-all-dev libssl-dev libpixman-1-dev libpython3-dev python3-pip python3-capstone virtualenv ninja-build pkg-config

WORKDIR /workspace/
RUN git clone https://github.com/XUANTIE-RV/riscv-matrix-extension-spec.git

WORKDIR /workspace/riscv-matrix-extension-spec
RUN sed -e "s|git@github.com:T-head-Semi/qemu.git|https://github.com/T-head-Semi/qemu.git|" -e "s|git@github.com:T-head-Semi/xuantie-gnu-toolchain.git|https://github.com/T-head-Semi/xuantie-gnu-toolchain.git|" -i "/workspace/riscv-matrix-extension-spec/.gitmodules"
RUN git submodule update --init

WORKDIR /workspace/riscv-matrix-extension-spec/xuantie-gnu-toolchain/
RUN git submodule update --remote

WORKDIR /workspace/riscv-matrix-extension-spec/qemu/build/
RUN /workspace/riscv-matrix-extension-spec/qemu/configure --target-list="riscv32-linux-user,riscv64-linux-user"
RUN make

WORKDIR /workspace/riscv-matrix-extension-spec/demos
RUN ["/bin/bash", "-c", "./env.sh"]
#RUN ["/bin/bash", "-c", "./run.sh"]
