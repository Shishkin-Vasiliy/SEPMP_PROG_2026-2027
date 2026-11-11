
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void print_hex(unsigned char a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%02X ", a[i]);
    printf("\n");
}

void print_dec(unsigned char a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%u ", a[i]);
    printf("\n");
}

void print_ascii(unsigned char a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Index: %02d Hex: 0x%02X ASCII: %c\n",
               i, a[i], isprint(a[i]) ? a[i] : '.');
    }
}

int main()
{
    unsigned char a[16] = {
        0x00, 0x10, 0x20, 0x30,
        0x40, 0x50, 0x60, 0x70,
        0x80, 0x90, 0xA0, 0xB0,
        0xC0, 0xD0, 0xE0, 0xF0
    };

    print_hex(a, 16);
    print_dec(a, 16);
    print_ascii(a, 16);

    a[5] = 0xE5;

    memmove(a + 3, a, 6);

    memcpy(a, a + 11, 5);

    memset(a + 5, 0, 6);

    print_hex(a, 16);

    return 0;
}
