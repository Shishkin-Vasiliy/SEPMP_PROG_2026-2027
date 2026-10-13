#include <stdio.h>

struct Node
{
    int value;
    struct Node *ptr;
};

int main(void)
{
    Node a = {100, NULL};
    Node b = {200, NULL};
    Node c = {300, NULL};

    a.ptr = &b;
    b.ptr = &c;
    c.ptr = &a;

    Node *cur = &a;
    while (1)
    {
        printf("%d\n", cur->value);
        cur = cur->ptr;
    }

    return 0;
}