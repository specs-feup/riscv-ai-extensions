LOCAL_DIR=$(dirname "$0")
curl https://buildbot.embecosm.com/job/corev-gcc-ubuntu2004/50/artifact/corev-openhw-gcc-ubuntu2004-20240530.tar.gz --output "$LOCAL_DIR/corev-riscv-toolchain.tar.gz"