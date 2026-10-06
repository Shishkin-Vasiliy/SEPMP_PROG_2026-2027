#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cstdint>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define POIZON_PTR (char *) 13
#define POIZON_CHAR '@'

int OpenFile(const char *file_name);
int GetFileSize(const char *file_name);
int ReadFromFile(char **buf, char **index, int file_size, int fd);
int SplitBuf(char **buf, char **index);
int FreeBuf(char **buf, int file_size);
int ParseBoundaries(char **argv, int *left, int *right);

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("Format: ./a.out a.txt b.txt 2:5");
        printf("Or:     ./a.out a.txt b.txt 5");
        return 1;
    }

    const char *a_file= argv[1];
    const char *b_file = argv[2];

    char *buf = POIZON_PTR;
    int nlines = 0;
    int nbounds = 0;
    int left = 0;
    int right = 0;

    int a_fd = OpenFile(a_file);
    int a_size = GetFileSize(a_file);

    char **index = (char **)calloc(a_size, sizeof(char *));
    if (!index)
    {
        printf("Invalid index pointer\n");
        return 1;
    }

    nlines = ReadFromFile(&buf, index, a_size, a_fd);
    nbounds = ParseBoundaries(argv, &left, &right);

    FILE *b_ptr = fopen(b_file, "w");
    if (nbounds == 1)
    {
        fputs(index[left], b_ptr);
    }
    else if (nbounds == 2)
    {
        for (int i = left; i < right; i++)
        {
            fputs(index[i], b_ptr);
            fputc('\n', b_ptr);
        }
    }
    else
        printf("Wrong Boundaries");

    FreeBuf(&buf, a_size);

    return 0;
}


int OpenFile(const char *file_name)
{
    int fd = open(file_name, O_RDONLY);
    return fd;
}

int GetFileSize(const char *file_name)
{
    struct stat stat_buf = {};
    stat(file_name, &stat_buf);
    int file_size = stat_buf.st_size;

    return file_size;
}

int ReadFromFile(char **buf, char **index, int file_size, int fd)
{
    if (!index)
        return EOF;

    int nlines = 0;

    if (fd == EOF)
        return EOF;

    *buf = (char *)calloc(file_size + 1, sizeof(char));
    if (!(*buf))
        return EOF;

    read(fd, *buf, file_size);

    *(*buf + file_size) = '\0'; 

    nlines = SplitBuf(buf, index);

    return nlines;
}

int SplitBuf(char **buf, char **index)
{
    if (!buf)
        return EOF;

    int i = 0;
    int nlines = 1;

    char *temp = *buf;
    index[i] = temp;

    while (*temp != '\0')
    {
        if (*temp == '\n')
        {
            *temp = '\0';
            temp++;
            i++;
            nlines++;
            while(isspace(*temp))
                temp++;  
            index[i] = temp;
            continue;
        }
        else
            temp++;            
    }
    return nlines;
}

int ParseBoundaries(char **argv, int *left, int *right)
{
    const char *bounds = argv[3];
    int i = 0;

    while (bounds[i] != '\0' && bounds[i] != ':' && isdigit(bounds[i]))
    {
        if (*left > 1)
            *left *= 10;
        *left += (bounds[i] - '0');
        i++;
    }
    if (bounds[i] == '\0')
        return 1;
    else if (bounds[i] == ':')
    {
        i++;
        while (bounds[i] != '\0' && isdigit(bounds[i]))
        {
            if (*right > 1)
                *right *= 10;
            *right += (bounds[i] - '0');
            i++;
        }
        return 2;
    }
    else
        return EOF;
}


int FreeBuf(char **buf, int file_size)
{
    if (!buf)   
        return EOF;

    char *pos = *buf;
    for (int i = 0; i < file_size + 1; i++)
    {
        pos[i] = POIZON_CHAR;
    }
    free(*buf);
    *buf = POIZON_PTR;

    return 0;
} 