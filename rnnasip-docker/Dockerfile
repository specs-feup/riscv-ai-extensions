FROM centos:centos7.9.2009
RUN sed -i s/mirror.centos.org/vault.centos.org/g /etc/yum.repos.d/*.repo
RUN sed -i s/^#.*baseurl=http/baseurl=http/g /etc/yum.repos.d/*.repo
RUN sed -i s/^mirrorlist=http/#mirrorlist=http/g /etc/yum.repos.d/*.repo

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

WORKDIR /workspace/RNNASIP/

## dependencies

### Enable pip...
RUN yum install -y epel-release
RUN yum install -y python2 python36 python36-devel python36-setuptools gawk texinfo gmp-devel mpfr-devel libmpc-devel swig libjpeg-turbo-devel redhat-lsb-core doxygen python-sphinx sox GraphicsMagick-devel ImageMagick-devel SDL2-devel perl-Switch libftdi-devel cmake3 python36-pip cmake cmake3 scons python2-pip ImageMagick ImageMagick-c++-devel GraphicsMagick-c++-devel

### Make cmake3 the default cmake version
RUN rm /usr/bin/cmake
RUN ln /usr/bin/cmake3 /usr/bin/cmake 

RUN easy_install-3.6 pip

### "--trusted-host pypi.python.org" is necessary because this is old and deprecated
RUN python2 -m pip install --trusted-host pypi.python.org configparser2

RUN python3 -m pip install --upgrade pip
RUN python3 -m pip install artifactory twisted prettytable sqlalchemy pyelftools openpyxl xlsxwriter pyyaml numpy configparser pyvcd scons Sphinx

# force scons to use python3
RUN sed -i "s|#!/usr/bin/python2|#!/usr/bin/python3|" /usr/local/bin/scons

RUN git clone https://github.com/pulp-platform/pulp-sdk.git
WORKDIR /workspace/RNNASIP/pulp-sdk/

RUN git checkout tags/2019.10.01

ENV PULP_RISCV_GCC_TOOLCHAIN="/opt/riscv"
ENV VSIM_PATH="/workspace/RNNASIP/vp/RNNASIP-pulpissimo/sim"

### each RUN command runs in a different shell, so these need to be run all at once.
### Sometimes the /bin/sh is used by default by the RUN command, if that ever happens use RUN ["/bin/bash", "-c", "..."] instead
RUN source configs/pulpissimo_rnnext.sh && source configs/platform-gvsoc.sh && make pulp-tools && sed -i "s|git@github.com:GreenWaves-Technologies/pmsis_api.git|https://github.com/GreenWaves-Technologies/pmsis_api.git|" /workspace/RNNASIP/pulp-sdk/project.cfg && make all && echo "export PULP_RISCV_GCC_TOOLCHAIN=$PULP_RISCV_GCC_TOOLCHAIN" >> sourceme.sh

WORKDIR /workspace/
ENV PULP_PROJECT_HOME="/workspace/RNNASIP/pulp-sdk"

# !!!!!!!!!!!!!
# When adding more tests to be run to this Dockerfile, use this first, followed by && <whatever needs to be run>
# RUN source ${PULP_PROJECT_HOME}/configs/pulpissimo_rnnext.sh && source ${PULP_PROJECT_HOME}/configs/platfom-gvsoc.sh && source ${PULP_PROJECT_HOME}/sourceme.sh
# !!!!!!!!!!!!!

# -------------------- test SDK (standard pulp sdk, not RNNASIP) --------------------
# RUN git clone https://github.com/pulp-platform/pulp-rt-examples.git
# WORKDIR /workspace/pulp-rt-examples/hello

#RUN source ${PULP_PROJECT_HOME}/configs/pulpissimo_rnnext.sh && source ${PULP_PROJECT_HOME}/configs/platform-gvsoc.sh && source ${PULP_PROJECT_HOME}/sourceme.sh && make conf && make clean all run
# hello should be printed to the console...

# -------------------------------------------------------------------------------------


# -------------------- test RNNASIP extensions --------------------

WORKDIR /workspace/RNNASIP/sourcecode/Basic_Kernels/
RUN source ${PULP_PROJECT_HOME}/configs/pulpissimo_rnnext.sh && source ${PULP_PROJECT_HOME}/configs/platform-gvsoc.sh && source ${PULP_PROJECT_HOME}/sourceme.sh && make conf && make clean all run

WORKDIR /workspace/RNNASIP/sourcecode/rnnSampleCode/
RUN source ${PULP_PROJECT_HOME}/configs/pulpissimo_rnnext.sh && source ${PULP_PROJECT_HOME}/configs/platform-gvsoc.sh && source ${PULP_PROJECT_HOME}/sourceme.sh && make conf && make clean all run

# ------------------------------------------------------------------
