#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "XOR_list.h"

void insert_node(list **l, int d) {
    list *tmp = malloc(sizeof(list));
    tmp->data = d;

    if (!(*l)) {
        tmp->addr = NULL;
    } else {
        (*l)->addr = XOR(tmp, (*l)->addr);
        tmp->addr = *l;
    }
    *l = tmp;
}

void delete_list(list *l) {
    while (l) {
        list *next = l->addr;
        if (next)
            next->addr = XOR(next->addr, l);
        free(l);
        l = next;
    }
}


void insertion_sort(list **start){
   if(!(*start) || !((*start)->addr)) 
   	return;

   list *target_prev = NULL;
   list *target = (*start);
   list *target_next = (*start)->addr;

   while(target != NULL){
   	int value = target->data;
	int found = 0;
	
        list *prev = NULL;	
	list *tmp = *start;
   	list *next = (*start)->addr;  
   	while(tmp != target){
		if(target->data < tmp->data && found == 0){
			value = tmp->data;
			tmp->data = target->data;
			
			prev = tmp;
			tmp = next;
			if(next)
				next = XOR(next->addr, prev);

			found = 1;
		}
		else{
			if(found == 1){
				XORSWAP_UNSAFE(value,tmp->data);
			}
			prev = tmp;
			tmp = next;
			if(next)
				next = XOR(next->addr, prev);
		}
	}
	tmp->data = value;
			
	target_prev = target;
	target = target_next;
	if(target_next)
		target_next = XOR(target_next->addr, target_prev);
   }   
}


list *merge_sort(list *start)
{
    if (!start || !start->addr)
        return start;

    list *left = start, *right = start->addr;
    left->addr = NULL;
    right->addr = XOR(right->addr, left);

    left = merge_sort(left);
    right = merge_sort(right);

    for (list *merge = NULL; left || right;) {
        if (!right || (left && left->data < right->data)) {
            list *next = left->addr;
            if (next)
                next->addr = XOR(left, next->addr);

            if (!merge) {
                start = merge = left;
                merge->addr = NULL;
            } else {
                merge->addr = XOR(merge->addr, left);
                left->addr = merge;
                merge = left;
            }
            left = next;
        } else {
            list *next = right->addr;
            if (next)
                next->addr = XOR(right, next->addr);

            if (!merge) {
                start = merge = right;
                merge->addr = NULL;
            } else {
                merge->addr = XOR(merge->addr, right);
                right->addr = merge;
                merge = right;
            }
            right = next;
        }
    }

    return start;
}

void dump_list(list *l)
{
    list *next = l->addr;
    list *prev = NULL;

    while (l != NULL) {
        printf("%d ",l->data);
	prev = l;
	l = next;
	if(next)
        	next = XOR(next->addr, prev); 
    }
    printf("\n");
}
