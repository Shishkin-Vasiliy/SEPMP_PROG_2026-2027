#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cstdint>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define POIZON_CHAR ((char)0xDE)
#define POIZON_PTR ((char *)0xDEADBEEF)

int OpenFileForRead(const char *file_name);
int OpenFileForWrite(const char *file_name);
int GetFileSize(const char *file_name);
int ReadFromFile(char **buf, size_t file_size, int fd, int key);
void WriteBuf(char *buf, int fd, size_t file_size);
int FreeBuf(char **buf, size_t file_size);
void Encrypt(char **buf, int key);

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Format: %s file_from file_to key\n", argv[0]);
        return 1;
    }

    const char *file_from = argv[1];
    const char *file_to = argv[2];
    int key = atoi(argv[3]);

    char *buf = NULL;

    int fd_from = OpenFileForRead(file_from);
    if (fd_from == -1)
    {
        printf("Error: cannot open %s for reading\n", file_from);
        return 1;
    }

    int file_from_size = GetFileSize(file_from);
    if (file_from_size < 0)
    {
        printf("Error: cannot get size of %s\n", file_from);
        close(fd_from);
        return 1;
    }

    if (ReadFromFile(&buf, (size_t)file_from_size, fd_from, key) == EOF)
    {
        printf("Error: failed to read file\n");
        close(fd_from);
        return 1;
    }
    close(fd_from);

    int fd_to = OpenFileForWrite(file_to);
    if (fd_to == -1)
    {
        printf("Error: cannot open %s for writing\n", file_to);
        FreeBuf(&buf, (size_t)file_from_size);
        return 1;
    }

    WriteBuf(buf, fd_to, (size_t)file_from_size);
    close(fd_to);

    FreeBuf(&buf, (size_t)file_from_size);

    return 0;
}

int OpenFileForRead(const char *file_name)
{
    int fd = open(file_name, O_RDONLY);
    return fd;
}

int OpenFileForWrite(const char *file_name)
{
    int fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    return fd;
}

int GetFileSize(const char *file_name)
{
    struct stat stat_buf = {};
    if (stat(file_name, &stat_buf) == -1)
        return -1;

    return (int)stat_buf.st_size;
}

int ReadFromFile(char **buf, size_t file_size, int fd, int key)
{
    if (!buf)
        return EOF;

    if (fd == -1)
        return EOF;

    *buf = (char *)calloc(file_size + 1, sizeof(char));
    if (!(*buf))
        return EOF;

    read(fd, *buf, file_size);

    *(*buf + file_size) = '\0';

    Encrypt(buf, key);

    return 0;
}

void WriteBuf(char *buf, int fd, size_t file_size)
{
    write(fd, buf, file_size);
}

int FreeBuf(char **buf, size_t file_size)
{
    if (!buf)
        return EOF;

    char *pos = *buf;
    for (size_t i = 0; i < file_size + 1; i++)
    {
        pos[i] = POIZON_CHAR;
    }
    free(*buf);
    *buf = POIZON_PTR;

    return 0;
}

void Encrypt(char **buf, int key)
{
    char *temp = *buf;

    while (*temp != '\0')
    {
        if (isupper((unsigned char)*temp))
            *temp = 'A' + (((*temp - 'A') + key) % 26 + 26) % 26;
        else if (islower((unsigned char)*temp))
            *temp = 'a' + (((*temp - 'a') + key) % 26 + 26) % 26;

        temp++;
    }
}