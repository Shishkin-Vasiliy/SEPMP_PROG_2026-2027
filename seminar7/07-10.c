#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    unsigned char r, g, b;
} Color;

double f1(double x, double y) { return 255.0 * fabs(x * y); }
double f2(double x, double y) { return 255.0 * fabs(sin(10.0 * (x*x + y*y))); }
double f3(double x, double y) { return 255.0 * fabs(sin(5000.0 * (x*x + y*y))); }
double f4(double x, double y) { return 255.0 * fabs(cos(10.0 * x) * sin(10.0 * y)); }
double f5(double x, double y) { return 127.5 * fabs(sin(3.0 / (0.1 + fabs(x))) + sin(3.0 / (0.1 + fabs(y)))); }

void render_function(const char *filename, double (*func)(double, double), int width, int height)
{
    Color *img = (Color *)malloc(width * height * sizeof(Color));

    for (int y = 0; y < height; y++)
    {
        double y_math = (double)y / height * 2.0 - 1.0;
        
        for (int x = 0; x < width; x++)
        {
            double x_math = (double)x / width * 2.0 - 1.0;
            
            double val = func(x_math, y_math);
            
            if (val < 0.0) val = 0.0;
            if (val > 255.0) val = 255.0;
            
            unsigned char gray = (unsigned char)val;
            
            img[y * width + x].r = gray;
            img[y * width + x].g = gray;
            img[y * width + x].b = gray;
        }
    }

    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", width, height);
    fwrite(img, sizeof(Color), width * height, fp);
    fclose(fp);
    
    free(img);
}

int main()
{
    int size = 500;
    
    render_function("func1.ppm", f1, size, size);
    render_function("func2.ppm", f2, size, size);
    render_function("func3.ppm", f3, size, size);
    render_function("func4.ppm", f4, size, size);
    render_function("func5.ppm", f5, size, size);

    return 0;
}