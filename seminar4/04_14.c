#include <stdio.h>
#include <stddef.h>

struct cat   { char x; size_t y; };
struct dog   { size_t y; char x; };
struct mouse { char x; char y; size_t z; };
struct rat   { char x; size_t z; char y; };
struct fox   { char x; struct mouse y; };

int main(void)
{
    printf("%-20s size = %2zu  align = %zu\n", "char",         sizeof(char),        _Alignof(char));
    printf("%-20s size = %2zu  align = %zu\n", "int",          sizeof(int),         _Alignof(int));
    printf("%-20s size = %2zu  align = %zu\n", "size_t",       sizeof(size_t),      _Alignof(size_t));
    printf("%-20s size = %2zu  align = %zu\n", "int[10]",      sizeof(int[10]),     _Alignof(int[10]));
    printf("%-20s size = %2zu  align = %zu\n", "int*",         sizeof(int*),        _Alignof(int*));
    printf("%-20s size = %2zu  align = %zu\n", "struct cat",   sizeof(struct cat),  _Alignof(struct cat));
    printf("%-20s size = %2zu  align = %zu\n", "struct dog",   sizeof(struct dog),  _Alignof(struct dog));
    printf("%-20s size = %2zu  align = %zu\n", "struct mouse", sizeof(struct mouse),_Alignof(struct mouse));
    printf("%-20s size = %2zu  align = %zu\n", "struct rat",   sizeof(struct rat),  _Alignof(struct rat));
    printf("%-20s size = %2zu  align = %zu\n", "struct fox",   sizeof(struct fox),  _Alignof(struct fox));
    return 0;
}