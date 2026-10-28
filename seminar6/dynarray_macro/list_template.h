#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define CONCAT_(a, b) a##b
#define CONCAT(a, b) CONCAT_(a, b)

#define NODE CONCAT(PREFIX, _node)
#define LIST CONCAT(PREFIX, _list)
#define FN(name) CONCAT(PREFIX, name)

struct NODE
{
    TYPE value;
    struct NODE* next;
    struct NODE* prev;
};

typedef struct
{
    struct NODE* head;
    struct NODE* tail;
    size_t size;
} LIST;

void FN(_push_back)(LIST* pl, TYPE value)
{
    struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
    new_node -> value = value;
    new_node -> next = NULL;
    new_node -> prev = pl -> tail;

    if (pl -> tail != NULL)
    {
        pl -> tail -> next = new_node;
    }
    else
    {
        pl -> head = new_node;
    }
    pl -> tail = new_node;
    pl -> size++;
}

void FN(_push_front)(LIST* pl, TYPE value)
{
    struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
    new_node -> value = value;
    new_node -> next = pl -> head;
    new_node -> prev = NULL;

    if (pl -> head != NULL)
    {
        pl -> head -> prev = new_node;
    }
    else
    {
        pl -> tail = new_node;
    }
    pl -> head = new_node;
    pl -> size++;
}

LIST FN(_init)(size_t n)
{
    LIST new_list = {NULL, NULL, 0};
    for (size_t i = 0; i < n; ++i)
    {
        FN(_push_back)(&new_list, 0);
    }
    return new_list;
}

void FN(_print)(const LIST* pl)
{
    struct NODE* current = pl -> head;
    while (current != NULL)
    {
        PRINT_FORMAT(current -> value);
        current = current -> next;
    }
    printf("\n");
}

TYPE FN(_pop_back)(LIST* pl)
{
    assert(pl -> size > 0);
    struct NODE* last = pl -> tail;
    TYPE val = last -> value;

    pl -> tail = last -> prev;
    if (pl -> tail != NULL)
    {
        pl -> tail -> next = NULL;
    }
    else
    {
        pl -> head = NULL;
    }

    free(last);
    pl -> size--;
    return val;
}

TYPE FN(_pop_front)(LIST* pl)
{
    assert(pl -> size > 0);
    struct NODE* first = pl -> head;
    TYPE val = first -> value;

    pl -> head = first -> next;
    if (pl -> head != NULL)
    {
        pl -> head -> prev = NULL;
    }
    else
    {
        pl -> tail = NULL;
    }

    free(first);
    pl -> size--;
    return val;
}

struct NODE* FN(_erase)(LIST* pl, struct NODE* p)
{
    if (p == NULL) return NULL;

    struct NODE* next_node = p -> next;

    if (p -> prev != NULL)
    {
        p -> prev -> next = p -> next;
    }
    else
    {
        pl -> head = p -> next;
    }

    if (p -> next != NULL)
    {
        p -> next -> prev = p -> prev;
    }
    else
    {
        pl -> tail = p -> prev;
    }

    free(p);
    pl -> size--;
    return next_node;
}

void FN(_splice)(LIST* plist, struct NODE* p, LIST* pother)
{
    if (pother -> size == 0) return;

    struct NODE* other_head = pother -> head;
    struct NODE* other_tail = pother -> tail;
    size_t other_size = pother -> size;

    if (p == NULL)
    {
        other_head -> prev = plist -> tail;
        if (plist -> tail != NULL)
        {
            plist -> tail -> next = other_head;
        }
        else
        {
            plist -> head = other_head;
        }
        plist -> tail = other_tail;
    }
    else
    {
        struct NODE* prev_node = p -> prev;
        other_head -> prev = prev_node;

        if (prev_node != NULL)
        {
            prev_node -> next = other_head;
        }
        else
        {
            plist -> head = other_head;
        }

        other_tail -> next = p;
        p -> prev = other_tail;
    }

    plist -> size += other_size;

    pother -> head = NULL;
    pother -> tail = NULL;
    pother -> size = 0;
}

void FN(_destroy)(LIST* pl)
{
    struct NODE* current = pl -> head;
    while (current != NULL)
    {
        struct NODE* next = current -> next;
        free(current);
        current = next;
    }
    pl -> head = NULL;
    pl -> tail = NULL;
    pl -> size = 0;
}

void FN(_advance)(struct NODE** pp, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        if (*pp != NULL)
        {
            *pp = (*pp) -> next;
        }
        else
        {
            break;
        }
    }
}

#undef NODE
#undef LIST
#undef FN
#undef CONCAT
#undef CONCAT_