#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int output_var = 0;
    printf("(1) output_var = %d\n\n", output_var);
    asm volatile (
        "li t1, 3\n"
        "li t2, 7\n"
        "cv.cnt t2, t1\n"
        "sw t2, %0\n"
        : "=m" (output_var)
        :
        : "t1", "t2"
    );
    printf("(2) output_var = %d\n\n", output_var);

    return EXIT_SUCCESS;
}