#include "XOR_list.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void insert_node(list **l, int d)
{
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

void delete_list(list **l)
{
    while (*l) {
        list *next = (*l)->addr;
        if (next)
            next->addr = XOR(next->addr, *l);
        free(*l);
        *l = next;
    }
}


list *insertion_sort(list *start)
{
    if (!start || !(start->addr))
        return start;

    // take out the head node and make it a new list
    list *result = start;
    start = start->addr;
    start->addr = XOR(result, start->addr);
    result->addr = NULL;

    while (start) {
        list *tmp = start->addr;
        if (tmp)
            tmp->addr = XOR(tmp->addr, start);

        list *cur = result;
        list *prev = NULL;
        list *next = result->addr;

        while (cur && cur->data < start->data) {
            prev = cur;
            cur = next;
            if (next)
                next = XOR(next->addr, prev);
        }


        /* insert in between prev and cur */
        if (prev)
            prev->addr = XOR(XOR(prev->addr, cur), start);
        // if insert at head, change which result point to
        else
            result = start;

        if (cur)
            cur->addr = XOR(start, next);

        start->addr = XOR(prev, cur);
        start = tmp;
    }
    return result;
}


void FrontBackSplit(list *head, list **front_ref, list **back_ref)
{
    if (head == NULL || head->addr == NULL) {
        *front_ref = head;
        *back_ref = NULL;
        return;
    }

    list *slow_prev = NULL;
    list *slow = head;
    list *slow_next = head->addr;

    list *fast_prev = head;
    list *fast = head->addr;
    list *fast_next = XOR(fast->addr, fast_prev);


    while (fast != NULL) {
        fast_prev = fast;
        fast = fast_next;
        if (fast_next)
            fast_next = XOR(fast_next->addr, fast_prev);

        if (fast != NULL) {
            slow_prev = slow;
            slow = slow_next;
            if (slow_next)
                slow_next = XOR(slow_next->addr, slow_prev);

            fast_prev = fast;
            fast = fast_next;
            if (fast_next)
                fast_next = XOR(fast_next->addr, fast_prev);
        }
    }

    *front_ref = head;
    *back_ref = slow_next;

    slow_next->addr = XOR(slow_next->addr, slow);
    slow->addr = slow_prev;
}


list *merge_sort(list *start)
{
    if (!start || !start->addr)
        return start;


    list *left = NULL, *right = NULL;
    FrontBackSplit(start, &left, &right);

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
        printf("%d ", l->data);
        prev = l;
        l = next;
        if (next)
            next = XOR(next->addr, prev);
    }
    printf("\n");
}
