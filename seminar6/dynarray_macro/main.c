#include <stdio.h>

#define TYPE int
#define PREFIX int
#define PRINT_FORMAT(v) printf("%d ", v)
#include "list_template.h"
#undef TYPE
#undef PREFIX
#undef PRINT_FORMAT

#define TYPE double
#define PREFIX double
#define PRINT_FORMAT(v) printf("%.2f ", v)
#include "list_template.h"
#undef TYPE
#undef PREFIX
#undef PRINT_FORMAT

int main()
{
    int_list a = int_init(0);
    int_push_back(&a, 10);
    int_push_back(&a, 20);
    int_push_front(&a, 5);
    
    printf("Int list: ");
    int_print(&a);
    
    printf("Popped: %d\n", int_pop_back(&a));
    printf("After pop: ");
    int_print(&a);
    
    int_destroy(&a);

    printf("\n");

    double_list b = double_init(0);
    double_push_back(&b, 3.14);
    double_push_back(&b, 2.71);
    
    printf("Double list: ");
    double_print(&b);
    
    double_destroy(&b);

    return 0;
}