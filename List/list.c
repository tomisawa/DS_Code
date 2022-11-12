//
//  list.c
//  List
//
//  Created by 冨澤眞樹 on 2022/11/08.
//  Copyright (C) 2022 Masaki Tomisawa. All rights reserved.
//

#include "list.h"

#include <assert.h>

void printList(Record *p) {
    if (p == NULL) {
        printf("()\n");
        return;
    }

    printf("( ");

    do {
#if DEBUG
        printf("%p:", p);
#endif
        printf("%d ", p->data);
    } while ((p = p->next) != NULL);
    printf(")\n");
}

void subfreeList(Record *p) {
    if (p->next != NULL) {
        subfreeList(p->next);
        free(p);
        return;
    }

    free(p);
    return;
}

Record *freeList(Record *head) {
    // FreeList() always returns NULL.
    if (head == NULL) {
        // printf("Empty List\n");
        return NULL;
    }

    subfreeList(head);
    return NULL;
}

// Algorithm 2.2
// 1 (2 3) → (1 2 3)
Record *insertFirst(Record *head, int data) {
    Record *new_r = (Record *)malloc(sizeof(Record));

    new_r->data = data;
    new_r->next = head;
    return new_r;
}

// Algorithm 2.3
// (1 2 3 4) → (2 3 4)
Record *deleteFirst(Record *head) {
    assert(head != NULL);
    Record *p = head;
#if DEBUG
    printf("%p:", p);
#endif
    head = head->next; // Save the return value
    free(p);
    return head;
}

int getData(Record *head) {
    assert(head != NULL);
    return head->data;
}

// If not found, returns NULL.
Record *findRecord(Record *head, int x) {
    while (head != (Record *)NULL) {
        if (head->data == x) {
            return head;
        }

        head = head->next;
    }
    return NULL;
}
