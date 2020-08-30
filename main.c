#include <stdio.h>
#include <stdlib.h>
#include "XOR_list.h"

int main()
{
    list *l = NULL;
    
    for (int i = 0; i < 50; i++) { 
        insert_node(&l, (rand() % 100));
    }
    

    printf("Before: ");
    dump_list(l);
    l = merge_sort(l);
    printf("After: ");
    dump_list(l);
    delete_list(&l);
}
