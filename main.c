#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "XOR_list.h"

#define NODE 1000
int main()
{
    list *l = NULL;
    srand(time(NULL));

    for (int i = 0; i < NODE; i++) {
        insert_node(&l, (rand() % 1000));
    }

    struct timespec tt1, tt2;
    clock_gettime(CLOCK_MONOTONIC, &tt1);
    l = merge_sort(l, NODE);
    clock_gettime(CLOCK_MONOTONIC, &tt2);

    long long time = (long long) (tt2.tv_sec * 1e9 + tt2.tv_nsec) -
                     (long long) (tt1.tv_sec * 1e9 + tt1.tv_nsec);

    delete_list(&l);

    printf("%d, %lld\n", NODE, time);
}
