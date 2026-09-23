#include <stdio.h>
#include <stdint.h>

int main(void)
{
    printf("sizeof(char) = %ld\n", sizeof(char));
    printf("sizeof(short) = %ld\n", sizeof(short));
    printf("sizeof(int) = %ld\n", sizeof(int));
    printf("sizeof(long long) = %ld\n", sizeof(long long));
    printf("sizeof(size_t) = %ld\n", sizeof(size_t));
    printf("sizeof(int8_t) = %ld\n", sizeof(int8_t));
    printf("sizeof(int32_t) = %ld\n", sizeof(int32_t));
    printf("sizeof(uint32_t) = %ld\n", sizeof(uint32_t));
    printf("sizeof(float) = %ld\n", sizeof(float));
    printf("sizeof(double) = %ld\n", sizeof(double));
    printf("sizeof(int[100]) = %ld\n", sizeof(int[100]));
    printf("sizeof(char[100]) = %ld\n", sizeof(char[100]));

    return 0;
}