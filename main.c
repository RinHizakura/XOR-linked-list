#include <stdio.h>
#include "XOR_list.h"

int main(){
    list *l = NULL;
    insert_node(&l, 5); 
    insert_node(&l, 3); 
    insert_node(&l, 10);
    insert_node(&l, 1); 
    
    
    printf("Before: "); 
    dump_list(l);
    insertion_sort(&l);
    printf("After: "); 
    dump_list(l);
    delete_list(l);
}

