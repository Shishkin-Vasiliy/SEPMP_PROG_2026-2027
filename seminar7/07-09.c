#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    unsigned char r, g, b;
} Color;

void draw_circle(Color* data, int width, int height, int x0, int y0, int r, Color c)
{
    for (int y = y0 - r; y <= y0 + r; y++)
    {
        for (int x = x0 - r; x <= x0 + r; x++)
        {
            if (x >= 0 && x < width && y >= 0 && y < height)
            {
                if ((x - x0) * (x - x0) + (y - y0) * (y - y0) <= r * r)
                {
                    data[y * width + x] = c;
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        return 1;
    }

    int n = atoi(argv[1]);
    int min_r = atoi(argv[2]);
    int max_r = atoi(argv[3]);

    int width = 800;
    int height = 600;
    Color *img = (Color *)malloc(width * height * sizeof(Color));

    Color bg = {255, 255, 255};
    for (int i = 0; i < width * height; i++)
    {
        img[i] = bg;
    }

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        int r = min_r + rand() % (max_r - min_r + 1);
        int x0 = rand() % width;
        int y0 = rand() % height;
        
        Color c;
        c.r = rand() % 256;
        c.g = rand() % 256;
        c.b = rand() % 256;

        draw_circle(img, width, height, x0, y0, r, c);
    }

    FILE *fp = fopen("circles.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", width, height);
    fwrite(img, sizeof(Color), width * height, fp);
    fclose(fp);
    
    free(img);
    return 0;
}