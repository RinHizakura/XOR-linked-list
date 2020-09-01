#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "XOR_list.h"

#define NODE_NUM 5000
int THR;
int main()
{
    list *l = NULL;
    srand(time(NULL));

    for (int thr = 2; thr <= 500; thr++) {
        for (int i = 0; i < NODE_NUM; i++) {
            insert_node(&l, (rand() % 1000));
        }

        THR = thr;

        struct timespec tt1, tt2;
        clock_gettime(CLOCK_MONOTONIC, &tt1);
        l = merge_sort(l, NODE_NUM);
        clock_gettime(CLOCK_MONOTONIC, &tt2);

        long long time = (long long) (tt2.tv_sec * 1e9 + tt2.tv_nsec) -
                         (long long) (tt1.tv_sec * 1e9 + tt1.tv_nsec);

        printf("%d, %f\n", thr, time / 1e3);
        delete_list(&l);
    }
}
