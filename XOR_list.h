#ifndef XOR_LIST_H
#define XOR_LIST_H


#define XOR(a, b) ((list *) ((uintptr_t)(a) ^ (uintptr_t)(b)))
#define XORSWAP_UNSAFE(a, b) ((a) ^= (b), (b) ^= (a), (a) ^= (b))

typedef struct __list list;
struct __list {
    int data;
    struct __list *addr;
};

void insert_node(list **l, int d);
void delete_list(list **l);
list *insertion_sort(list *start);
list *merge_sort(list *start);
void dump_list(list *l);

#endif
