#include <stdio.h>

/*
    Tests the long command, no immediate values format of hwloops
    (cv.start, cv.end, cv.count) on both channels (0 and 1)
*/
int main() {
    int errors = 0, regt0 = 0, regt6 = 0;

    __asm__ volatile(
    "li t0, 0x0\n\t"
    "li t1, 0x0\n\t"                // error counter
    "li t2, 0x0\n\t"
    "li t3, 0x0\n\t"
    "li t4, 0x0\n\t"
    "li t5, 0x0\n\t"
    "li t6, 0x0\n\t"
"nested_longcomm_noimm:\n\t"
    "li t0, 0\n\t"                  // counter to be increased in inner loop
    "li t6, 0\n\t"                  // counter to be increased in outer loop
    "li t2, 3\n\t"                  // outer loop repeat amount
    "la t3, start_outer_1\n\t"      // start address of outer loop
    "la t4, end_outer_1\n\t"        // end address of outer loop
    ".balign 4\n\t"
    "cv.start 1, t3\n\t"
    "cv.end 1, t4\n\t"
    "cv.count 1, t2\n\t"
    ".option norvc\n\t"
"start_outer_1:\n\t"
    "li t2, 4\n\t"                  // inner loop repeat amount
    "la t3, start_inner_1\n\t"      // start address of inner loop
    "la t4, end_inner_1\n\t"        // end address of inner loop
    ".balign 4\n\t"
    "cv.start 0, t3\n\t"
    "cv.end 0, t4\n\t"
    "cv.count 0, t2\n\t"
"start_inner_1:\n\t"
    "add t0, t0, 1\n\t"
    "add t0, t0, 1\n\t"
    "add t0, t0, 1\n\t"
"end_inner_1:\n\t"
    "add t6, t6, 1\n\t"             // there must be at least 2 instructions between the end of the inner loop and the end of the outer loop
    "add t6, t6, 1\n\t"
"end_outer_1:\n\t"
    ".option rvc\n\t"
    "li t5, 36\n\t"                 // expected result for variable increased in inner loop
    "beq t5, t0, outer_check_1\n\t"
    "add t1, t1, 1\n\t"
"outer_check_1:\n\t"
    "li t5, 6\n\t"
    "beq t5, t6, nested_longcomm_imm\n\t"
    "add t1, t1, 1\n\t"
"nested_longcomm_imm:\n\t"
    "li t0, 0\n\t"                  // counter to be increased in inner loop
    "li t6, 0\n\t"                  // counter to be increased in outer loop
    "li t2, 3\n\t"                  // outer loop repeat amount
    "la t3, start_outer_2\n\t"      // start address of outer loop
    "la t4, end_outer_2\n\t"        // end address of outer loop
    ".balign 4\n\t"
    "cv.start 1, t3\n\t"
    "cv.end 1, t4\n\t"
    "cv.count 1, t2\n\t"
    ".option norvc\n\t"
"start_outer_2:\n\t"
    "li t2, 4\n\t"                  // inner loop repeat amount
    "la t3, start_inner_2\n\t"      // start address of inner loop
    "la t4, end_inner_2\n\t"        // end address of inner loop
    ".balign 4\n\t"
    "cv.start 0, t3\n\t"
    "cv.end 0, t4\n\t"
    "cv.count 0, t2\n\t"
"start_inner_2:\n\t"
    "add t0, t0, 1\n\t"
    "add t0, t0, 1\n\t"
    "add t0, t0, 1\n\t"
"end_inner_2:\n\t"
    "add t6, t6, 1\n\t"
    "add t6, t6, 1\n\t"
"end_outer_2:\n\t"
    ".option rvc\n\t"
    "li t5, 36\n\t"
    "beq t5, t0, outer_check_2\n\t"
    "add t1, t1, 1\n\t"
"outer_check_2:\n\t"
    "li t5, 6\n\t"
    "beq t5, t6, exit_check\n\t"
    "add t1, t1, 1\n\t"

"exit_check:\n\t"
    "mv %0, t1\n\t"
    : "=r" (errors)
    :
    : "t0", "t1", "t2", "t3", "t4", "t5", "t6"
    );

    printf("errors = %d\n", errors);

    return 0;
}
