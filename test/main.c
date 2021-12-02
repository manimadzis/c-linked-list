#include <stdio.h>
#include "linked-list.h"

void print_extend_list(list_node_t *node)
{
    printf("|--------------|\n");
    printf("|%p|\n", (void *)node);
    printf("|--------------|\n");
    printf("|%14d|\n", *(int *)&node->data);
    printf("|--------------|\n");
    printf("        |\n");
    if (node->next == NULL)
        printf("       NULL\n");
}

void print_node(list_node_t *node)
{
    printf("%d ", *(int *)&node->data);
}

void list_print(const list_t *list)
{
    list_map((list_t *)list, print_node);
}

int main(void)
{
    // CREATE LIST
    list_t list = list_new(sizeof(int));

    printf("EMPTY LIST: ");
    list_print(&list);
    printf("\n");

    // PUSH_BACK
    for (int i = 0; i < 6; i++)
        list_push_back(&list, &i);

    printf("PUSH_BACK: ");
    list_print(&list);
    printf("\n");

    // PUSH_FRONT
    for (int i = 1; i < 5; i++)
        list_push_front(&list, &i);

    printf("PUSH_FRONT: ");
    list_print(&list);
    printf("\n");

    // POP_FRONT
    printf("POP_FRONT: ");
    int data;
    while (list_pop_front(&list, &data))
        printf("%d ", data);
    printf("\n");

    // PUSH_FRONT
    for (int i = 0; i < 5; i++)
        list_push_front(&list, &i);

    printf("PUSH_FRONT: ");
    list_print(&list);
    printf("\n");

    // PUSH_FRONT
    for (int i = 1; i < 6; i++)
        list_push_back(&list, &i);

    printf("PUSH_BACK: ");
    list_print(&list);
    printf("\n");

    printf("LENGTH: %zu\n", list_length(&list));

    printf("TAIL: ");
    print_node(list_tail(&list));
    printf("\n");

    list_free(&list);
    printf("FREE: ");
    list_print(&list);
    printf("\n");

\
    return 0;
}
