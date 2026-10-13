void set_characters(char *begin, char *end, char c)
{
    for (char *p = begin; p < end; p++)
        *p = c;
}