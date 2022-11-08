//
//  list.c
//  List
//
//  Created by 冨澤眞樹 on 2022/11/08.
//  Copyright (C) 2022 Masaki Tomisawa. All rights reserved.
//

#include <assert.h>
#include "list.h"

void PrintList(Record *p) {
    if (p == NULL) {
        printf("Empty List\n");
        return;
    }

    do {
        #if DEBUG
        printf("%p:", p);
        #endif
        printf("%d\t", p->data);
    } while ((p = p->next) != NULL);
    printf("\n");
}

void _FreeList(Record *p) {
    if (p->next != NULL) {
        _FreeList(p->next);
        free(p);
        return;
    }

    free(p);
    return;
}

Record * FreeList(Record *head) {
// FreeList() always returns NULL.
    if (head == NULL) {
        printf("Empty List\n");
        return NULL;
    }

    _FreeList(head);
//  Record *p = head;
//  Record *next_p;
//  do{
//    next_p = p->next;
//    free(p);
//  } while ((p = next_p) != NULL);
    return NULL;
}

Record * MakeList(int data[], int n) {
    if (n == 0) {
        return NULL;
    }

    // Make a list with only one element
    Record *ptr = (Record *)malloc(sizeof(Record));
    Record *head = ptr; // Save the return value
    ptr->data = data[0];
    ptr->next = NULL;

    // Add an element to the end of the list. Not the head!
    for (int i = 1; i < n; i++) {
        Record *new_r = (Record *)malloc(sizeof(Record));
        new_r->data = data[i];
        new_r->next = NULL;
        ptr->next = new_r;
        ptr = new_r;
    }

    return head;
}

// Algorithm 2.2
// In Lisp, (cons 1 '(2 3)) → (1 2 3)
Record * Cons(Record *head, int data) {
    Record *new_r = (Record *)malloc(sizeof(Record));

    new_r->data = data;
    new_r->next = head;
    return new_r;
}

// Algorithm 2.3
// In Lisp, (cdr '(1 2 3 4 )) → (2 3 4)
Record * Cdr(Record *head) {
    assert(head != NULL);
    Record *p = head;
    #if DEBUG
    printf("%p:", p);
    #endif
    head = head->next; // Save the return value
    free(p);
    return head;
}

int Car(Record *head) {
    assert(head != NULL);
    return head->data;
}

// Non-Recursive
Record * Find(Record *head, int x) {
    while (head != (Record *)NULL) {
        if (head->data == x) {
            return head;
        }

        head = head->next;
    }
    return NULL;
}

// Non-Recursive
Record * Delete(Record *head, Record *delete) {
    assert(head != NULL);
    assert(delete != NULL);

    // Case 1 : delete first element
    if (head == delete) {
        head = delete->next;
        delete->next = NULL;
        return head;
    }

    // Case 2 : Except for Case 1
    Record *prev = head;

    while (prev->next != delete) if ((prev = prev->next) == NULL) {
            break;
        }

    assert(prev->next != NULL);
    assert(prev->next == delete);
    prev->next = delete->next;
    delete->next = NULL;
    return head;
}
