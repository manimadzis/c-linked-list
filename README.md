# Linked list

## Data structure

```c
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
```



## Insert node

### Insert to the beginning

```c
list_t list = list_new(sizeof(int));
int data = 10;

list_push_front(&list, &data);
```

### Insert to the end

```c
list_t list = list_new(sizeof(int));
int data = 10;

list_push_back(&list, &data);
```

### Insert after some node

```c
int data = 10;
list_node_t *node = list_node(&data, sizeof(int));
list_node_t *new_node = list_node(&data, sizeof(int));

list_insert_after(node, new_node); // node -> new_node -> NULL
```



## Delete node

### Delete from beginning

 ```c
 list_t list = list_new(sizeof(int));
 int data = 10;
 list_push_back(&list, &data);
 data = 3;
 list_push_back(&list, &data);
 data = 5;
 
 list_pop_front(&list, &data); // data = 10
 ```

### Delete from end

```c
list_t list = list_new(sizeof(int));
int data = 10;
list_push_back(&list, &data);
data = 3;
list_push_back(&list, &data);
data = 5;

list_pop_back(&list, &data); // data = 3
```



 ## Apply function to node

```c
void node_sqr(list_node_t *node)
{
	node->data = *(int *)(node->data) * *(int *)(node->data);
}

list_t list = list_new(sizeof(int));
int data = 10;
list_push_back(&list, &data);
data = 3;
list_push_back(&list, &data);
data = 5;

// list: 10 -> 3 ->
list_map(&list, node_sqr);
// list: 100 -> 9 ->
```



## List length

```c
list_t list = list_new(sizeof(int));
int data = 10;
list_push_back(&list, &data);
data = 3;
list_push_back(&list, &data);

size_t length = list_length(&list); // length = 2
```



## List tail (last node)

```c
list_t list = list_new(sizeof(int));
int data = 10;
list_push_back(&list, &data);
data = 3;
list_push_back(&list, &data);
// list: 10 -> 3 ->
list_node_t *tail = list_tail(&list); // tail: 3 ->
```

