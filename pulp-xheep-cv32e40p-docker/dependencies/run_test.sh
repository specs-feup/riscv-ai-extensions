make app PROJECT=$1 ARCH='rv32imfc_xcvalu_xcvbi_xcvbitmanip_xcvelw_xcvhwlp_xcvmac_xcvmem_xcvsimd_zicsr' COMPILER_PREFIX='riscv32-corev-'
cd build/openhwgroup.org_systems_core-v-mini-mcu_0/sim-verilator/
./Vtestharness +firmware=../../../sw/build/main.hex
cat uart0.log
cd ../../../