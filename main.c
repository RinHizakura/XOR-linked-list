#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "XOR_list.h"

int main()
{
    list *l = NULL;

    for (int cnt = 1000; cnt <= 10000; cnt += 1000) {
        for (int i = 0; i < cnt; i++) {
            insert_node(&l, (rand() % 100));
        }

        clock_t start, end;
        start = clock();
        l = merge_sort(l);
        end = clock();

        double time = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%d, %f\n", cnt, time);
        delete_list(&l);
    }
}
