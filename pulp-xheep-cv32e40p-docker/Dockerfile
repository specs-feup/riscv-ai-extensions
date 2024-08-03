FROM ubuntu:noble-20240605

RUN apt-get update -y && apt-get upgrade -y && apt-get install -y curl wget git lcov libelf1 libelf-dev libftdi1-2 libftdi1-dev libncurses5-dev libssl-dev libudev-dev libusb-1.0-0 lsb-release texinfo autoconf cmake flex bison libexpat-dev gawk tree xterm python3-venv python3-dev bzip2 bc automake autotools-dev libmpc-dev libmpfr-dev libgmp-dev build-essential bison gperf libtool patchutils zlib1g-dev

# SETUP riscv gnu toolchain
WORKDIR /workspace/
COPY ./dependencies/corev-riscv-toolchain.tar.gz ./corev-riscv-toolchain.tar.gz
RUN tar -xf ./corev-riscv-toolchain.tar.gz
RUN mv ./corev-openhw-gcc-ubuntu2004-20240530 /opt/riscv
RUN rm ./corev-riscv-toolchain.tar.gz

ENV RISCV="/opt/riscv"

# SETUP verilator
WORKDIR /workspace/
ENV VERILATOR_VERSION="4.210"

RUN git clone https://github.com/verilator/verilator.git
WORKDIR /workspace/verilator
RUN git checkout v$VERILATOR_VERSION

RUN autoconf

RUN sed -i '/#include <algorithm>/a #include <memory>' src/V3Const.cpp

RUN ./configure --prefix=/opt/verilator/$VERILATOR_VERSION && make && make install
ENV PATH="/opt/verilator/$VERILATOR_VERSION/bin:$PATH"

# SETUP verible
WORKDIR /tmp/

ENV VERIBLE_VERSION="v0.0-3704-g1d393d43"
RUN wget https://github.com/chipsalliance/verible/releases/download/${VERIBLE_VERSION}/verible-${VERIBLE_VERSION}-linux-static-x86_64.tar.gz
RUN tar -xf verible-${VERIBLE_VERSION}-linux-static-x86_64.tar.gz
RUN mkdir -p /opt/verible/${VERIBLE_VERSION}/
RUN mv verible-${VERIBLE_VERSION}/* /opt/verible/${VERIBLE_VERSION}/
ENV PATH="/opt/verible/${VERIBLE_VERSION}/bin:$PATH"
RUN rm -rf verible-${VERIBLE_VERSION}-linux-static-x86_64.tar.gz verible-${VERIBLE_VERSION}-linux-static-x86_64

# SETUP x-heep
WORKDIR /workspace/

RUN git clone https://github.com/esl-epfl/x-heep.git
ENV X-HEEP-DIR="/workspace/x-heep"

WORKDIR /workspace/x-heep/
RUN sed -e s/pyyaml==6.0/pyyaml==6.0.1/ -e s/yamlfmt==1.1/yamlfmt==1.1.1/ -i python-requirements.txt
RUN make venv

## add test file to be used later
RUN mkdir /workspace/x-heep/sw/applications/pulp_instruction
COPY ./dependencies/test.c /workspace/x-heep/sw/applications/pulp_instruction/main.c

## make verilator
RUN ["/bin/bash", "-c", "source /workspace/x-heep/.venv/bin/activate && make mcu-gen CPU=cv32e40p && make verilator-sim FUSESOC_PARAM='--COREV_PULP=1 --FPU=1'"]
RUN ["/bin/bash", "-c", "source /workspace/x-heep/.venv/bin/activate && make app PROJECT='pulp_instruction' ARCH='rv32imfc_xcvalu_xcvbi_xcvbitmanip_xcvelw_xcvhwlp_xcvmac_xcvmem_xcvsimd_zicsr' COMPILER_PREFIX='riscv32-corev-'"]
RUN ["/bin/bash", "-c", "source /workspace/x-heep/.venv/bin/activate && cd /workspace/x-heep/build/openhwgroup.org_systems_core-v-mini-mcu_0/sim-verilator && ./Vtestharness +firmware=../../../sw/build/main.hex && cat uart0.log"]

## automatically source venv when getting into the container via bash
RUN echo "source /workspace/x-heep/.venv/bin/activate" >> /root/.bashrc
