#include <stdio.h>
#include <stdlib.h>

struct color
{
    unsigned char r, g, b;
};
typedef struct color Color;

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("To use this program: ./bw <ppm image>\n");
        exit(1);
    }

    FILE* inputfile = fopen(argv[1], "rb");
    if (inputfile == 0)
    {
        printf("Can't open the file: %s\n", argv[1]);
        exit(1);
    }

    int width, height;
    fscanf(inputfile, "P6\n%d %d\n255\n", &width, &height);
    
    Color* data = (Color*)malloc(sizeof(Color) * width * height);
    fread(data, sizeof(Color), height * width, inputfile);
    fclose(inputfile);

    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            int r = data[i + width * j].r;
            int g = data[i + width * j].g;
            int b = data[i + width * j].b;
            
            unsigned char gray = (r + g + b) / 3;
            
            data[i + width * j].r = gray;
            data[i + width * j].g = gray;
            data[i + width * j].b = gray;
        }
    }

    FILE* outputfile = fopen("result.ppm", "wb");
    fprintf(outputfile, "P6\n%d %d\n255\n", width, height);
    fwrite(data, sizeof(Color), height * width, outputfile);
    fclose(outputfile);
    
    free(data);
    return 0;
}