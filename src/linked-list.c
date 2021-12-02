#include <stdlib.h>
#include <string.h>

#include "linked-list.h"

list_t list_new(size_t size)
{
    list_t new = { 0 };
    new.size = size;
    return new;
}

list_node_t *list_node(const void *data, size_t size)
{
    if (!data || size == 0)
        return NULL;

    list_node_t *new = malloc(sizeof(list_node_t) + size);
    if (new)
    {
        memmove(new->data, data, size);
        new->next = NULL;
    }
    return new;
}

void list_node_free(list_node_t *node)
{
    free(node);
}

void list_free(list_t *list)
{

    while (list_pop_back(list, NULL))
        ;
}

list_node_t *list_tail(const list_t *list)
{
    list_node_t *node;
    for (node = list->head; node && node->next; node = node->next)
        ;

    return node;
}

size_t list_length(const list_t *list)
{
    size_t length = 0;
    for (list_node_t *node = list->head; node; node = node->next)
        length++;
    return length;
}

list_node_t *list_push_back(list_t *list, void *data)
{
    if (!list || !data)
        return NULL;

    list_node_t *new = list_node(data, list->size);
    if (new)
    {
        list_node_t *tail = list_tail(list);
        if (tail)
            tail->next = new;
        else
            list->head = new;
    }

    return new;
}

list_node_t *list_push_front(list_t *list, void *data)
{
    if (!list || !data)
        return NULL;

    list_node_t *new = list_node(data, list->size);
    if (new)
    {
        new->next = list->head;
        list->head = new;
    }

    return new;
}

list_node_t *list_insert_after(list_node_t *list_node, list_node_t *node)
{
    if (!list_node || !node)
        return NULL;

    node->next = list_node->next;
    list_node->next = node;

    return list_node;
}

void *list_pop_back(list_t *list, void *data)
{
    if (!list)
        return NULL;

    list_node_t *prev = NULL, *last;
    for (last = list->head; last && last->next; last = last->next)
        prev = last;

    if (last)
    {
        if (data)
            memmove(data, last->data, list->size);
        else
            data = list;

        list_node_free(last);

        if (prev)
            prev->next = NULL;
        else
            list->head = NULL;
    }
    else
        data = NULL;

    return data;
}

void *list_pop_front(list_t *list, void *data)
{
    if (!list)
        return NULL;

    list_node_t *first, *second = NULL;
    first = list->head;
    if (list->head)
        second = list->head->next;

    if (first)
    {
        if (data)
            memmove(data, first->data, list->size);
        else
            data = list;

        list_node_free(first);

        list->head = second;
    }
    else
        data = NULL;

    return data;
}

void list_map(list_t *list, void (*func)(list_node_t *))
{
    for (list_node_t *node = list->head; node; node = node->next)
        func(node);
}

