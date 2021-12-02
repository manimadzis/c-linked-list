#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#include <stddef.h>

typedef struct list_node list_node_t;

struct list_node
{
    list_node_t *next;
    char data[];
};

typedef struct
{
    list_node_t *head;
    size_t size;
} list_t;

/**
 * @brief list_new - return empty list with given data size
 * @param size - size of element in bytes
 * @return list with given element size
 */
list_t list_new(size_t size);

/**
 * @brief list_node - create node with given size and data
 * @param data - pointer to data
 * @param size - data size
 * @return if allocation was success return pointer to new node else NULL
 */
list_node_t *list_node(const void *data, size_t size);

/**
 * @brief list_node_free
 * @param node
 */
void list_node_free(list_node_t *node);

/**
 * @brief list_free - free all list nodes
 *
 * complexity - O(1)
 * @param list
 */
void list_free(list_t *list);

/**
 * @brief list_map - apply given function for all list elements
 *
 * complexity - O(n)
 * @param list
 * @param func - function to apply for all list elements
 */
void list_map(list_t *list, void (*func)(list_node_t *));

/**
 * @brief list_tail - return length of list
 *
 * complexity - O(n)
 * @param list
 * @return length of list
 */
size_t list_length(const list_t *list);

/**
 * @brief list_tail - return last element in list
 *
 * complexity - O(n)
 * @param list
 * @return last element in list
 */
list_node_t *list_tail(const list_t *list);

/**
 * @brief list_push_back - insert node with given data to the end of list
 *
 * complexity - O(n)
 * @param list - list for inserting
 * @param data - pointer to data to save in node
 * @return if allocation was successful return pointer to new node in list else NULL
 */
list_node_t *list_push_back(list_t *list, void *data);

/**
 * @brief list_push_front - insert node with given data to the beginnig of list
 *
 * complexity - O(1)
 * @param list - list for inserting
 * @param data - pointer to data to save in node
 * @return if allocation was successful return pointer to new node in list else NULL
 */
list_node_t *list_push_front(list_t *list, void *data);

/**
 * @brief list_pop_back - delete node from end of list
 *
 * complexity - O(n)
 * @param list - list for deleting
 * @param data - pointer to memory contained deleted node data
 * @return if list is empty return NULL else data (but if data is NULL \
 * (you need to delete element but don't need data from node) and list isn't empty return list)
 */
void *list_pop_back(list_t *list, void *data);

/**
 * @brief list_pop_fromnt - delete node from beginning of list
 *
 * complexity - O(1)
 * @param list - list for deleting
 * @param data - pointer to memory contained deleted node data
 * @return if list is empty return NULL else data (but if data is NULL \
 * (you need to delete element but don't need data from node) and list isn't empty return list)
 */
void *list_pop_front(list_t *list, void *data);

list_node_t *list_insert_after(list_node_t *list_node, list_node_t *node);
#endif
