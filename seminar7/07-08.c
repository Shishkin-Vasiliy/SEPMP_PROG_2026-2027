#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned char r, g, b;
} Color;

int main()
{
    int width = 600;
    int height = 400;
    Color *img = (Color *)malloc(width * height * sizeof(Color));

    Color white = {255, 255, 255};
    Color red = {190, 0, 41};

    for (int i = 0; i < width * height; i++)
    {
        img[i] = white;
    }

    int cx = width / 2;
    int cy = height / 2;
    int r = (height * 3 / 5) / 2;

    for (int y = cy - r; y <= cy + r; y++)
    {
        for (int x = cx - r; x <= cx + r; x++)
        {
            if (x >= 0 && x < width && y >= 0 && y < height)
            {
                if ((x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r)
                {
                    img[y * width + x] = red;
                }
            }
        }
    }

    FILE *fp = fopen("flag.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", width, height);
    fwrite(img, sizeof(Color), width * height, fp);
    fclose(fp);
    free(img);

    return 0;
}