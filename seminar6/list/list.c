#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

List init(size_t n)
{
    List new_list = {NULL, NULL, 0};
    for (size_t i = 0; i < n; ++i)
    {
        push_back(&new_list, 0);
    }
    return new_list;
}

void print(const List* pl)
{
    Node* current = pl -> head;
    while (current != NULL)
    {
        printf("%d ", current -> value);
        current = current -> next;
    }
    printf("\n");
}

void push_back(List* pl, int value)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
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

int pop_back(List* pl)
{
    assert(pl -> size > 0);
    Node* last = pl -> tail;
    int val = last -> value;

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

void push_front(List* pl, int value)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
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

int pop_front(List* pl)
{
    assert(pl -> size > 0);
    Node* first = pl -> head;
    int val = first -> value;

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

Node* erase(List* pl, Node* p)
{
    if (p == NULL) return NULL;

    Node* next_node = p -> next;

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

void splice(List* plist, Node* p, List* pother)
{
    if (pother -> size == 0) return;

    Node* other_head = pother -> head;
    Node* other_tail = pother -> tail;
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
        Node* prev_node = p -> prev;
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

void destroy(List* pl)
{
    Node* current = pl -> head;
    while (current != NULL)
    {
        Node* next = current -> next;
        free(current);
        current = next;
    }
    pl -> head = NULL;
    pl -> tail = NULL;
    pl -> size = 0;
}

void advance(Node** pp, size_t n)
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