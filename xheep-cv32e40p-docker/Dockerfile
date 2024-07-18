FROM ubuntu:noble-20240605

RUN apt-get update -y && apt-get upgrade -y && apt-get install -y curl wget git lcov libelf1 libelf-dev libftdi1-2 libftdi1-dev libncurses5-dev libssl-dev libudev-dev libusb-1.0-0 lsb-release texinfo autoconf cmake flex bison libexpat-dev gawk tree xterm python3-venv python3-dev bzip2 bc automake autotools-dev libmpc-dev libmpfr-dev libgmp-dev build-essential bison gperf libtool patchutils zlib1g-dev

# SETUP riscv gnu toolchain
WORKDIR /workspace/

RUN git clone --branch 2022.01.17 --recursive https://github.com/riscv/riscv-gnu-toolchain

WORKDIR /workspace/riscv-gnu-toolchain

# possibly alter these flags
RUN ./configure --prefix=/opt/riscv --with-abi=ilp32 --with-arch=rv32imc --with-cmodel=medlow && make

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

RUN echo "source /workspace/x-heep/.venv/bin/activate" >> /root/.bashrc

RUN ["/bin/bash", "-c", "source /workspace/x-heep/.venv/bin/activate && make mcu-gen CPU=cv32e40p && make verilator-sim"]
