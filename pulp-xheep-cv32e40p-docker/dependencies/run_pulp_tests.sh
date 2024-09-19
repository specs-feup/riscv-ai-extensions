GREY="\033[90m"
RED="\033[91m"
GREEN="\033[92m"
BLUE="\033[94m"
DARK_BLUE="\033[34m"
PINK="\033[95m"
RESET="\033[0m"

test_time_limit=300 # 5 minutes

cleanup() {
    echo -e "\n   ${RED}Terminating the simulation...${RESET}"
    kill $simulation_pid 2>/dev/null
}

if ! [ -f /workspace/x-heep/pulp_tests.txt ]; then
  echo -e "${RED}Could not find ${PINK}/workspace/x-heep/pulp_tests.txt${RED}; which should be created in the Dockerfile${RESET}"
  exit 1
fi

log_path=/workspace/x-heep/pulp_tests_log.txt
echo "" > "$log_path"

echo -e "${GREY}Starting pulp tests...${RESET}"
echo -e "${GREY}Saving log to ${PINK}$log_path${RESET}"

while read pulp_test_name
do
    echo -e "${BLUE}Building ${PINK}$pulp_test_name${GREY}...${RESET}"
    make app --silent PROJECT=$pulp_test_name ARCH='rv32imfc_xcvalu_xcvbi_xcvbitmanip_xcvelw_xcvhwlp_xcvmac_xcvmem_xcvsimd_zicsr' COMPILER_PREFIX='riscv32-corev-' > /dev/null 2>&1 || {\
        echo -e "   ${RED}Compilation failed!${RESET}";\
        echo "Compilation of $pulp_test_name failed!" >> "$log_path";\
        continue;\
    }

    echo -e "   ${DARK_BLUE}Executing${GREY}...${RESET}"

    cd build/openhwgroup.org_systems_core-v-mini-mcu_0/sim-verilator/
    
    #if ! timeout "$test_time_limit" ./Vtestharness +firmware=../../../sw/build/main.hex > /dev/null 2>&1; then
    #    echo -e "   ${RED}Simulation exceeded the time limit!${RESET}"
    #    echo "   Simulation exceeded the time limit!" >> "$log_path"
    #    cd ../../..
    #    continue
    #fi

    ./Vtestharness +firmware=../../../sw/build/main.hex > /dev/null 2>&1 &
    simulation_pid=$!

    trap cleanup SIGINT

    start_time=$(date +%s)

    while kill -0 $simulation_pid 2>/dev/null; do
        current_time=$(date +%s)
        elapsed=$((current_time - start_time))
        echo -ne "\r   ${GREY}$elapsed seconds elapsed..."

        if [ "$elapsed" -ge "$test_time_limit" ]; then
            echo -e "\n   ${RED}Simulation exceeded the time limit!${RESET}"
            cleanup
            cd ../../..
            continue
        fi

        sleep 1
    done
    echo ""

    trap - SIGINT

    while IFS= read -r uartline; do
        if [[ $uartline =~ [[:space:]]*=[[:space:]]*0$ ]]; then
            echo -e "   ${GREEN}No errors were found!${RESET}"
            echo "  Found no errors in $pulp_test_name!" >> "$log_path"
        else
            echo -e "   ${RED}Errors were found!${RESET}"
            echo "  Found errors in $pulp_test_name!" >> "$log_path"
            break
        fi
    done < ./uart0.log

    cd ../../..

done < /workspace/x-heep/pulp_tests.txt