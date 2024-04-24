FROM centos:centos7.9.2009
RUN yum update -y && yum upgrade -y
  
# main repo and pulp riscv gnu toolchain

## project dependencies

RUN yum install -y git autoconf automake libmpc-devel mpfr-devel gmp-devel gawk  bison flex texinfo patchutils gcc gcc-c++ zlib-devel make

WORKDIR /workspace/


RUN git clone https://github.com/andrire/RNNASIP.git

WORKDIR /workspace/RNNASIP/vp/
RUN git clone https://github.com/pulp-platform/pulp-riscv-gnu-toolchain.git

WORKDIR /workspace/RNNASIP/vp/pulp-riscv-gnu-toolchain/
RUN git checkout 5d39fedd658d81a3ea9765cf9bd03a445b292e4b
RUN git submodule update --init --recursive

ENV PATH="$PATH:/opt/riscv/bin"

RUN ["./configure", "--prefix=/opt/riscv", "--with-arch=rv32imc", "--with-cmodel=medlow", "--enable-multilib"]

RUN make

# RNNASIP pulpissimo

WORKDIR /workspace/RNNASIP/vp/

RUN git clone https://github.com/andrire/RNNASIP-pulpissimo.git

# pulp sdk

WORKDIR /workspace/RNNASIP/vp/

## dependencies

## these probobably don't work (?)
#RUN yum install -y python3 build-essential git libftdi-dev libftdi1 doxygen python3-pip libsdl2-dev curl cmake libusb-1.0-0-dev scons gtkwave libsndfile1-dev rsync autoconf automake texinfo libtool pkg-config libsdl2-ttf-dev
#RUN pip install argcomplete pyelftools

## instead use these

# Enable pip...
RUN yum install -y epel-release

RUN yum install -y python2 python36 python36-devel python36-setuptools gawk texinfo gmp-devel mpfr-devel libmpc-devel swig libjpeg-turbo-devel redhat-lsb-core doxygen python-sphinx sox GraphicsMagick-devel ImageMagick-devel SDL2-devel perl-Switch libftdi-devel cmake
RUN easy_install-3.6 pip
RUN python3 -m pip install --upgrade pip
RUN python3 -m pip install artifactory twisted prettytable sqlalchemy pyelftools openpyxl xlsxwriter pyyaml numpy configparser pyvcd

#RUN python2 -m pip install configparser
#RUN python2 -m pip install --upgrade pip

RUN git clone https://github.com/pulp-platform/pulp-sdk.git
WORKDIR /workspace/RNNASIP/vp/pulp-sdk/

RUN git checkout tags/2019.10.01

# This causes merge conflicts. What's even the point of checking out the tag...
#RUN git config --global user.email "docker@centos.com"
#RUN git config --global user.name "dockermachine"
#RUN git pull origin main

ENV PULP_RISCV_GCC_TOOLCHAIN="/opt/riscv/"
# set env for VSIM_PATH (supposedly it's the pulpissimo repo's root)
ENV VSIM_PATH="/workspace/RNNASIP/vp/RNNASIP-pulpissimo/sim/"

RUN source configs/pulpissimo_rnnext.sh
RUN source configs/platform-gvsoc.sh
RUN make all
RUN echo "export PULP_RISCV_GCC_TOOLCHAIN=$PULP_RISCV_GCC_TOOLCHAIN" >> sourceme.sh

CMD ["/bin/bash"]