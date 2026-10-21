#include <stdio.h>
#include <stdlib.h>

int sum(int x, int y) { return x + y; }
int diff(int x, int y) { return x - y; }
int mult(int x, int y) { return x * y; }
int sqdiff(int x, int y) { return x * x - y * y; }
int lin(int x, int y) { return 5 * x - y; }

void print_func_name(FuncPtr p);
void process(FuncCtx* data, size_t n, int x, int y);
int cmp_funcs(const void* a, const void* b);
void sort_funcs(FuncPtr* a, size_t n, int x, int y);
void print_array_names(FuncPtr* array, size_t n);
 
typedef int (*FuncPtr)(int, int);

struct FuncCtx {
    FuncPtr func;
    const char* name;
    int ret_val; 
};

FuncCtx all_funcs[5] = {
    {sum, "sum", 0},
    {diff, "diff", 0},
    {mult, "mult", 0},
    {sqdiff, "sqdiff", 0},
    {lin, "lin", 0}
};

void print_func_name(FuncPtr p) 
{
    for (size_t i = 0; i < 5; i++) 
    {
        if (all_funcs[i].func == p) 
        {
            printf("%s\n", all_funcs[i].name);
            return;
        }
    }
}

void process(FuncCtx* data, size_t n, int x, int y) 
{
    for (size_t i = 0; i < n; i++) 
    {
        data[i].ret_val = data[i].func(x, y);
    }
}

int cmp_funcs(const void* a, const void* b) 
{
    const FuncCtx* f1 = (const FuncCtx*)a;
    const FuncCtx* f2 = (const FuncCtx*)b;

    if (f1 -> ret_val < f2 -> ret_val)
        return -1;

    if (f1 -> ret_val > f2 -> ret_val) 
        return 1;

    return 0;
}

void sort_funcs(FuncPtr* a, size_t n, int x, int y) 
{
    FuncCtx* data = (FuncCtx*)calloc(n, sizeof(FuncCtx));

    for (size_t i = 0; i < n; i++) 
    {
        data[i].func = a[i];
        data[i].ret_val = 0;

        for (int j = 0; j < 5; j++) {
            if (a[i] == all_funcs[j].func) {
                data[i].name = all_funcs[j].name;
                break;
            }
        }
    }

    process(data, n, x, y);

    qsort(data, n, sizeof(FuncCtx), cmp_funcs);

    for (size_t i = 0; i < n; i++) {
        a[i] = data[i].func;
    }

    free(data);
}

void print_array_names(FuncPtr* array, size_t n) 
{
    for (size_t i = 0; i < n; i++) 
    {
        print_func_name(array[i]);
    }
}