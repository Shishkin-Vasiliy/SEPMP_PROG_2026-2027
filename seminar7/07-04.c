
int is_little_endian()
{
    unsigned int x = 1;

    return *((unsigned char *)&x) == 1;
}
