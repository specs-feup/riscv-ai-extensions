#include <stdio.h>

int main() {
    int errors1 = 0;
    int sandbox[1024] = {0};    // no matter how big or small this value, the program inevitably crashes even though in theory only the memory allocated to the buffer should be affected
                                // also, not initializing the array causes the code to not compile, and because of the initialization the running time grows with the size given to the array. With 2048 the execution time is already around 44 seconds.

    __asm__ volatile(
    "lw t6, %[input_ptr_addr]\n\t"  // memory address 1 (base address)
    "li t0, 0x0\n\t"                // memory address 2 (offset)
    "li t1, 0x0\n\t"                // type 1 error count
    "li t2, 0x0\n\t"                // memory address 1 + memory address 2
    "li t3, 0xf61163af\n\t"         // value to store and (partially or fully) load
    "li t4, 0x0\n\t"                // loaded value
    "li t5, 0x0\n\t"                // expected value
    // load from register+register
"test1:\n\t"
    "li t0, 0x00000088\n\t"         // load memory address 2
    "li t3, 0xd926073a\n\t"         // load value to store
    "add t2, t0, t6\n\t"            // get address to store in
    "sw t3, 0(t2)\n\t"              // store value
    "cv.lb t4, t0(t6)\n\t"          // load value
    "li t5, 0x0000003a\n\t"         // load expected value
    "beq t4, t5, test2\n\t"         // check loaded with expected value, skip increasing type 1 error if equal
    "c.addi t1, 0x1\n\t"            // increase type 1 error count
"test2:\n\t"
    "mv %0, t1\n\t"
    : "=r" (errors1)
    : [input_ptr_addr] "m" (sandbox)
    : "t0", "t1", "t2", "t3", "t4", "t5", "t6"
    );

    printf("errors1 = %d", errors1);
    
    return 0;

}

