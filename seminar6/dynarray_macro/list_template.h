#include <stdlib.h>
#include <assert.h>

struct PREFIX##_node
{
    TYPE value;
    struct PREFIX##_node* next;
    struct PREFIX##_node* prev;
};

typedef struct
{
    struct PREFIX##_node* head;
    struct PREFIX##_node* tail;
    size_t size;
} PREFIX##_list;

PREFIX##_list PREFIX##_init(size_t n)
{
    PREFIX##_list new_list = {NULL, NULL, 0};
    for (size_t i = 0; i < n; ++i)
    {
        PREFIX##_push_back(&new_list, 0);
    }
    return new_list;
}

void PREFIX##_print(const PREFIX##_list* pl)
{
    struct PREFIX##_node* current = pl -> head;
    while (current != NULL)
    {
        PRINT_FORMAT(current -> value);
        current = current -> next;
    }
    printf("\n");
}

void PREFIX##_push_back(PREFIX##_list* pl, TYPE value)
{
    struct PREFIX##_node* new_node = (struct PREFIX##_node*)malloc(sizeof(struct PREFIX##_node));
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

TYPE PREFIX##_pop_back(PREFIX##_list* pl)
{
    assert(pl -> size > 0);
    struct PREFIX##_node* last = pl -> tail;
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

void PREFIX##_push_front(PREFIX##_list* pl, TYPE value)
{
    struct PREFIX##_node* new_node = (struct PREFIX##_node*)malloc(sizeof(struct PREFIX##_node));
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

TYPE PREFIX##_pop_front(PREFIX##_list* pl)
{
    assert(pl -> size > 0);
    struct PREFIX##_node* first = pl -> head;
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

struct PREFIX##_node* PREFIX##_erase(PREFIX##_list* pl, struct PREFIX##_node* p)
{
    if (p == NULL) return NULL;

    struct PREFIX##_node* next_node = p -> next;

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

void PREFIX##_splice(PREFIX##_list* plist, struct PREFIX##_node* p, PREFIX##_list* pother)
{
    if (pother -> size == 0) return;

    struct PREFIX##_node* other_head = pother -> head;
    struct PREFIX##_node* other_tail = pother -> tail;
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
        struct PREFIX##_node* prev_node = p -> prev;
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

void PREFIX##_destroy(PREFIX##_list* pl)
{
    struct PREFIX##_node* current = pl -> head;
    while (current != NULL)
    {
        struct PREFIX##_node* next = current -> next;
        free(current);
        current = next;
    }
    pl -> head = NULL;
    pl -> tail = NULL;
    pl -> size = 0;
}

void PREFIX##_advance(struct PREFIX##_node** pp, size_t n)
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